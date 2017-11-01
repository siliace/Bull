#include <Bull/Core/FileSystem/Win32/PathImpl.hpp>
#include <Bull/Core/Support/Win32/Windows.hpp>

namespace Bull
{
    namespace prv
    {
        String PathImpl::realPath(const String& relative)
        {
            String absolute(static_cast<std::size_t>(MAX_PATH));

            GetFullPathName(relative.getBuffer(), static_cast<DWORD>(absolute.getCapacity()), &absolute[0], nullptr);

            return absolute;
        }
    }
}