#include <Bull/Core/FileSystem/Win32/PathImpl.hpp>
#include <Bull/Core/Support/Win32/Windows.hpp>
#include <Bull/Core/Utility/StringUtils.hpp>

namespace Bull
{
    namespace prv
    {
        void PathImpl::copy(const Path& path, const Path& newPath, bool failsIfExists)
        {
            CopyFile(path.toString().getBuffer(), newPath.toString().getBuffer(), failsIfExists);
        }

        void PathImpl::rename(const Path& path, const Path& newPath)
        {
            MoveFile(path.toString().getBuffer(), newPath.toString().getBuffer());
        }

        String PathImpl::realPath(const String& relative)
        {
            String absolute = StringUtils::ofSize(MAX_PATH);

            GetFullPathName(relative.getBuffer(), static_cast<DWORD>(absolute.getSize()), &absolute[0], nullptr);

            return absolute;
        }
    }
}