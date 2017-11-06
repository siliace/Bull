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
        SocketPollerImpl* SocketPollerImpl::createInstance()
        {
            return new SocketPollerImplType();
        }

        void SocketPollerImpl::add(SocketHandler socket, SocketPollerEvent event)
        {
            SocketPollDescriptor descriptor;
            descriptor.fd = socket;
            descriptor.revents = 0;

            switch(event)
            {
                case SocketPollerEvent_Read: descriptor.events = POLLRDNORM; break;
                case SocketPollerEvent_Write: descriptor.events = POLLWRNORM; break;
                case SocketPollerEvent_All: descriptor.events = POLLRDNORM | POLLWRNORM; break;
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

        bool SocketPollerImpl::isAdded(SocketHandler socket)
        {
            return getSocketPoll(socket) != m_sockets.end();
        }

        bool SocketPollerImpl::isReadyToRead(SocketHandler socket)
        {
            return (getSocketPoll(socket)->revents & POLLRDNORM) > 0;
        }

        bool SocketPollerImpl::isReadyToWrite(SocketHandler socket)
        {
            return (getSocketPoll(socket)->revents & POLLWRNORM) > 0;
        }

        SocketPollerImpl::SocketPollDescriptorList::iterator SocketPollerImpl::getSocketPoll(SocketHandler socket)
        {
            return std::find_if(m_sockets.begin(), m_sockets.end(), [socket](SocketPollDescriptor descriptor){
                return descriptor.fd == socket;
            });
        }
    }
}