#include <Bull/Core/Configuration/OS.hpp>
#include <Bull/Core/Exception/RuntimeError.hpp>

#include <Bull/Network/Socket/SocketImpl.hpp>

#if defined BULL_OS_WINDOWS
    #include <Bull/Network/Socket/Win32/SocketImplWin32.hpp>
    typedef Bull::prv::SocketImplWin32 SocketImplType;
#else
    #error Lack of implemenation : SocketImpl
#endif

namespace Bull
{
    namespace prv
    {
        ImplPtr<SocketImpl> SocketImpl::createInstance()
        {
            return ImplPtr<SocketImpl>::make<SocketImplType>();
        }

        SocketHandler SocketImpl::getInvalidSocket()
        {
            return SocketImplType::InvalidHandler;
        }

        int SocketImpl::convertSocketType(SocketType type)
        {
            switch(type)
            {
                case SocketType_Tcp: return SOCK_STREAM;
                case SocketType_Udp: return SOCK_DGRAM;
                case SocketType_Raw: return SOCK_RAW;
            }
        }

        int SocketImpl::convertNetProtocol(NetProtocol protocol)
        {
            switch(protocol)
            {
                case NetProtocol_Ipv4: return AF_INET;
                case NetProtocol_Ipv6: return AF_INET6;
            }
        }

        SocketError SocketImpl::getLastError()
        {
            return SocketImplType::getLastError();
        }

        SocketImpl::~SocketImpl() = default;

        bool SocketImpl::create(NetProtocol protocol, SocketType type)
        {
            m_handler = socket(convertNetProtocol(protocol), convertSocketType(type), 0);

            return isValid();
        }

        bool SocketImpl::create(SocketHandler handler)
        {
            m_handler = handler;

            return isValid();
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