#include <Bull/Core/Exception/InvalidParameter.hpp>

#include <Bull/Network/Socket/SocketImpl.hpp>

#if defined BULL_OS_WINDOWS

    #include <Bull/Network/Socket/Win32/SocketImplWin32.hpp>

typedef Bull::prv::SocketImplWin32 SocketImplType;
#else
    #include <Bull/Network/Socket/Unix/SocketImplUnix.hpp>
typedef Bull::prv::SocketImplUnix SocketImplType;
#endif

namespace Bull
{
    namespace prv
    {
        std::unique_ptr<SocketImpl> SocketImpl::createInstance()
        {
            return std::make_unique<SocketImplType>();
        }

        SocketHandler SocketImpl::getInvalidSocket()
        {
            return SocketImplType::InvalidHandler;
        }

        int SocketImpl::convertSocketType(SocketType type)
        {
            switch(type)
            {
                case SocketType_Tcp:
                    return SOCK_STREAM;
                case SocketType_Udp:
                    return SOCK_DGRAM;
                case SocketType_Raw:
                    return SOCK_RAW;
            }

            return 0;
        }

        int SocketImpl::convertNetProtocol(NetProtocol protocol)
        {
            switch(protocol)
            {
                case NetProtocol_Ipv4:
                    return AF_INET;
                case NetProtocol_Ipv6:
                    return AF_INET6;
            }

            return 0;
        }

        SocketImpl::~SocketImpl() = default;

        void SocketImpl::create(NetProtocol protocol, SocketType type)
        {
            create(socket(convertNetProtocol(protocol), convertSocketType(type), 0));
        }

        void SocketImpl::create(SocketHandler handler)
        {
            Expect(handler != SocketImpl::getInvalidSocket(), Throw(InvalidParameter, "Invalid socket handler"));

            m_handler = handler;
        }

        bool SocketImpl::isValid() const
        {
            return m_handler != SocketImplType::InvalidHandler;
        }

        SocketHandler SocketImpl::getHandler() const
        {
            return m_handler;
        }

        SocketImpl::SocketImpl() :
                m_handler(SocketImplType::InvalidHandler)
        {
            /// Nothing
        }
    }
}