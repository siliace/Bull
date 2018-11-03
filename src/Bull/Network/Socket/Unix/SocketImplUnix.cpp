#include <fcntl.h>
#include <sys/ioctl.h>
#include <unistd.h>

#include <Bull/Core/Exception/InternalError.hpp>
#include <Bull/Network/Socket/Unix/SocketImplUnix.hpp>

namespace Bull
{
    namespace prv
    {
        SocketImplUnix::~SocketImplUnix()
        {
            close(getHandler());
        }

        void SocketImplUnix::enableBlockingMode(bool enable)
        {      
            int flags = fcntl(getHandler(), F_GETFL, 0);
            
            if(flags == -1)
            {
                Throw(InternalError, "SocketImplUnix::enableBlockingMode", "Failed to get socket flags");
            }

            if(enable && !m_blocking)
            {
                if(fcntl(getHandler(), F_SETFL, flags & ~O_NONBLOCK) == -1)
                {
                    Throw(InternalError, "SocketImplUnix::enableBlockingMode", "Failed to enable blocking mode");
                }
            }
            else if(!enable && m_blocking)
            {
                if(fcntl(getHandler(), F_SETFL, flags | O_NONBLOCK) == -1)
                {
                    Throw(InternalError, "SocketImplUnix::enableBlockingMode", "Failed to disable blocking mode");
                }
            }

            m_blocking = enable;
        }

        bool SocketImplUnix::isEnableBlockingMode() const
        {
            return m_blocking;
        }

        std::size_t SocketImplUnix::getPendingLength() const
        {
            std::size_t pending;

            if(ioctl(getHandler(), FIONREAD, &pending) == -1)
            {
                Throw(InternalError, "SocketImplUnix::getPendingLength", "Failed to perform IO operation on socket");
            }

            return pending;
        }

        SocketImplUnix::SocketImplUnix() :
            m_blocking(true)
        {
            /// Nothing
        }
    }
}