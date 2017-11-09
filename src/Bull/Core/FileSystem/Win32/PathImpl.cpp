#include <Bull/Core/FileSystem/Win32/PathImpl.hpp>
#include <Bull/Core/Support/Win32/Windows.hpp>

namespace Bull
{
    namespace prv
    {
        String PathImpl::realPath(const String& relative)
        {
            String absolute;
            absolute.create(MAX_PATH);

            GetFullPathName(relative.getBuffer(), absolute.getCapacity(), &absolute[0], nullptr);

            return absolute;
        }
    }
}