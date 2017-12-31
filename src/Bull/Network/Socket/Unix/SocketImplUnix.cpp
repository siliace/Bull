#include <fcntl.h>
#include <sys/ioctl.h>
#include <unistd.h>

#include <Bull/Network/Socket/Unix/SocketImplUnix.hpp>

namespace Bull
{
    namespace prv
    {
        SocketError SocketImplUnix::getLastError()
        {
            return SocketError_Ok;
        }

        SocketImplUnix::~SocketImplUnix()
        {
            close(getHandler());
        }

        void SocketImplUnix::enableBlockingMode(bool enable)
        {
            if(isValid())
            {
                long yes = 1, no = 0;

                fcntl(getHandler(), O_NONBLOCK, enable ? &yes : &no);
            }
        }

        bool SocketImplUnix::isEnableBlockingMode() const
        {
            return m_blocking;
        }

        std::size_t SocketImplUnix::getPendingLength() const
        {
            if(isValid())
            {
                std::size_t pending;

                ioctl(getHandler(), FIONREAD, &pending);

                return pending;
            }

            return 0;
        }

        SocketImplUnix::SocketImplUnix() :
            m_blocking(true)
        {
            /// Nothing
        }
    }
}