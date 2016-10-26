#ifndef Bull_FileSystemEntity_hpp
#define Bull_FileSystemEntity_hpp

#include <Bull/Core/Integer.hpp>
#include <Bull/Core/String.hpp>
#include <Bull/Core/Time/Date.hpp>

namespace Bull
{
    struct BULL_API FileSystemEntity
    {
        String name;
        bool   isFile;
        bool   isDirectory;
        Uint64 size;
        Date   creationDate;
        Date   lastAccessDate;
        Date   lastWriteDate;
    };
}

#endif // Bull_FileSystemEntity_hpp
