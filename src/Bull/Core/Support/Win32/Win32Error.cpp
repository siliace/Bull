#include <Bull/Core/Exception/LogicError.hpp>
#include <Bull/Core/Support/Win32/Win32Error.hpp>
#include <Bull/Core/Support/Win32/Windows.hpp>

namespace Bull
{
    namespace prv
    {
        Win32Error::Win32Error(const String& file, Uint64 line, const String& source, const String& description) :
                Exception(file, line, "Win32Error", source, description + " - " + createDescription())
        {
            /// Nothing
        }

        String Win32Error::createDescription() const
        {
            DWORD error = GetLastError();

            if(!error)
            {
                Throw(LogicError, "Win32Error::createDescription", "No error occurred");
            }

            char* messageBuffer = nullptr;
            size_t size = FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
                                         nullptr, error, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPSTR)&messageBuffer, 0, nullptr);

            String message(messageBuffer, size);

            LocalFree(messageBuffer);

            return message;
        }
    }
}