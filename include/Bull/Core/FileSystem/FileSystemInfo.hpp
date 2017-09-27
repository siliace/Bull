#ifndef BULL_CORE_FILESYSTEM_FILESYSTEMINFO_HPP
#define BULL_CORE_FILESYSTEM_FILESYSTEMINFO_HPP

#include <Bull/Core/Configuration/Integer.hpp>
#include <Bull/Core/Export.hpp>

namespace Bull
{
    struct BULL_CORE_API FileSystemInfo
    {
        Uint64 free;
        Uint64 capacity;
        Uint64 available;
    };
}


#endif // BULL_CORE_FILESYSTEM_FILESYSTEMINFO_HPP
