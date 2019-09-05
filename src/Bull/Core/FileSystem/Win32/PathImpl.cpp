#include <Bull/Core/FileSystem/Win32/PathImpl.hpp>
#include <Bull/Core/Support/Win32/Windows.hpp>

namespace Bull
{
    namespace prv
    {
        void PathImpl::copy(const Path& path, const Path& newPath, bool failsIfExists)
        {
            CopyFile(path.toString().c_str(), newPath.toString().c_str(), failsIfExists);
        }

        void PathImpl::rename(const Path& path, const Path& newPath)
        {
            MoveFile(path.toString().c_str(), newPath.toString().c_str());
        }

        std::string PathImpl::realPath(const std::string& relative)
        {
            char buffer[MAX_PATH], absolute[MAX_PATH];

            GetFullPathName(buffer, MAX_PATH, absolute, nullptr);

            return absolute;
        }
    }
}