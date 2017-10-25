#ifndef BULL_CORE_FILESYSTEM_DIRECTORYSEARCHFLAGS_HPP
#define BULL_CORE_FILESYSTEM_DIRECTORYSEARCHFLAGS_HPP

namespace Bull
{
    enum DirectorySearchFlag
    {
        DirectorySearchFlag_None        = 0x00,
        DirectorySearchFlag_Files       = 0x01,
        DirectorySearchFlag_Directories = 0x02,
        DirectorySearchFlag_All         = DirectorySearchFlag_Files | DirectorySearchFlag_Directories
    };
}

#endif // BULL_CORE_FILESYSTEM_DIRECTORYSEARCHFLAGS_HPP
