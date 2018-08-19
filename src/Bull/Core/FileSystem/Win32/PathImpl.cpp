#include <Bull/Core/FileSystem/Win32/PathImpl.hpp>
#include <Bull/Core/Support/Win32/Windows.hpp>
#include <Bull/Core/Utility/StringUtils.hpp>

namespace Bull
{
    namespace prv
    {
        String PathImpl::realPath(const String& relative)
        {
            String absolute = StringUtils::ofSize(MAX_PATH);

            GetFullPathName(relative.getBuffer(), absolute.getSize(), &absolute[0], nullptr);

            return absolute;
        }
    }
}