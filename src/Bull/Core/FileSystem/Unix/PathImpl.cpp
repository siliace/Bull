#include <cstdlib>

#include <Bull/Core/FileSystem/Win32/PathImpl.hpp>

namespace Bull
{
    namespace prv
    {
        String PathImpl::realPath(const String& relative)
        {
            return realpath(relative.getBuffer(), nullptr);
        }
    }
}