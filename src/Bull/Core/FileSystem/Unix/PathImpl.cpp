#include <cstdlib>

#include <Bull/Core/FileSystem/Win32/PathImpl.hpp>

namespace Bull
{
    namespace prv
    {
        std::string PathImpl::realPath(const std::string& relative)
        {
            return realpath(relative.getBuffer(), nullptr);
        }
    }
}