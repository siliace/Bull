#include <Bull/Core/Exception/LogicError.hpp>
#include <Bull/Core/Support/Win32/Win32Error.hpp>
#include <Bull/Core/Support/Win32/Windows.hpp>

namespace Bull
{
    namespace prv
    {
        Win32Error::Win32Error(const std::string& file, Uint64 line, const std::string& source, const std::string& description) :
                Exception(file, line, "Win32Error", source, description + " - " + createDescription())
        {
            /// Nothing
        }

        std::string Win32Error::createDescription() const
        {
            DWORD error = GetLastError();

            if(!error)
            {
                Throw(LogicError, "No error occurred");
            }

            char* messageBuffer = nullptr;
            size_t size = FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
                                         nullptr, error, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPSTR) &messageBuffer, 0, nullptr);

            std::string message(messageBuffer, size);

            LocalFree(messageBuffer);

            return message;
        }
    }
}