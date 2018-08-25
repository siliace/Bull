#ifndef BULL_CORE_FILESYSTEM_FILEOPENINGMODE_HPP
#define BULL_CORE_FILESYSTEM_FILEOPENINGMODE_HPP

namespace Bull
{
    enum FileOpeningMode
    {
        FileOpeningMode_Append    = 0x01,
        FileOpeningMode_Write     = 0x02,
        FileOpeningMode_Exists    = 0x04,
        FileOpeningMode_Truncate  = 0x08,
        FileOpeningMode_Read      = 0x16,
    };
}

#endif // BULL_CORE_FILESYSTEM_FILEOPENINGMODE_HPP
