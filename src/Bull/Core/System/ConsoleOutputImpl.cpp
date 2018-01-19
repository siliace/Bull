#include <memory>

#include <Bull/Core/Configuration/OS.hpp>
#include <Bull/Core/System/ConsoleOutputImpl.hpp>

#if defined BULL_OS_WINDOWS
    #include <Bull/Core/System/Win32/ConsoleOutputImplWin32.hpp>
    typedef Bull::prv::ConsoleOutputImplWin32 ConsoleOutputImplType;
#else
    #error Lack of implementation : ConsoleOutput
#endif

namespace Bull
{
    namespace prv
    {
        std::unique_ptr<ConsoleOutputImpl> ConsoleOutputImpl::createInstance()
        {
            return std::make_unique<ConsoleOutputImplType>();
        }

        ConsoleOutputImpl::~ConsoleOutputImpl() = default;
    }
}