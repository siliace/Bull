#include <algorithm>

#include <Bull/Core/Configuration/OS.hpp>

#include <Bull/Network/Socket/SocketPollerImpl.hpp>

#if defined BULL_OS_WINDOWS
    #include <Bull/Network/Socket/Win32/SocketPollerImplWin32.hpp>
    typedef Bull::prv::SocketPollerImplWin32 SocketPollerImplType;
#else
    #error Lack of implementation : SocketPoller
#endif

namespace Bull
{
    namespace prv
    {
        ImplPtr<SocketPollerImpl> SocketPollerImpl::createInstance()
        {
            return ImplPtr<SocketPollerImpl>::make<SocketPollerImplType>(SocketPollerImplType());
        }

        void SocketPollerImpl::add(SocketHandler socket, SocketPollerEvent event)
        {
            SocketPollDescriptor descriptor = {socket, 0, 0};

            if(event & SocketPollerEvent_Read)
            {
                descriptor.events |= POLLRDNORM;
            }

            if(event & SocketPollerEvent_Write)
            {
                descriptor.events |= POLLWRNORM;
            }

            m_sockets.emplace_back(descriptor);
        }

        void SocketPollerImpl::remove(SocketHandler socket)
        {
            m_sockets.erase(getSocketPoll(socket));
        }

        void SocketPollerImpl::clear()
        {
            m_sockets.clear();
        }

        bool SocketPollerImpl::wait()
        {
            if(!m_sockets.empty())
            {
                int result = poll(m_sockets, -1);

                if(result != SocketPollerImplType::SocketError)
                {
                    return result > 0;
                }
            }

            return false;
        }

        bool SocketPollerImpl::wait(const Time& timeout)
        {
            if(!m_sockets.empty())
            {
                int result = poll(m_sockets, static_cast<int>(timeout.asMilliseconds()));

                if(result != SocketPollerImplType::SocketError)
                {
                    return result > 0;
                }
            }

            return false;
        }

        bool SocketPollerImpl::isAdded(SocketHandler socket)
        {
            return getSocketPoll(socket) != m_sockets.end();
        }

        bool SocketPollerImpl::isReadyToRead(SocketHandler socket)
        {
            return (getSocketPoll(socket)->revents & (POLLRDNORM | POLLHUP | POLLERR)) > 0;
        }

        bool SocketPollerImpl::isReadyToWrite(SocketHandler socket)
        {
            return (getSocketPoll(socket)->revents & (POLLWRNORM | POLLERR)) > 0;
        }

        SocketPollerImpl::SocketPollDescriptorList::iterator SocketPollerImpl::getSocketPoll(SocketHandler socket)
        {
            return std::find_if(m_sockets.begin(), m_sockets.end(), [socket](SocketPollDescriptor descriptor){
                return descriptor.fd == socket;
            });
        }
    }
}