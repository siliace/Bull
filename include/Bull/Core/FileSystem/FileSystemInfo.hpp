#ifndef BULL_CORE_FILESYSTEM_FILESYSTEMINFO_HPP
#define BULL_CORE_FILESYSTEM_FILESYSTEMINFO_HPP

#include <Bull/Core/Export.hpp>

namespace Bull
{
    struct BULL_CORE_API FileSystemInfo
    {
        Uint64 free = 0;
        Uint64 capacity = 0;
        Uint64 available = 0;
    };
}


#endif // BULL_CORE_FILESYSTEM_FILESYSTEMINFO_HPP
