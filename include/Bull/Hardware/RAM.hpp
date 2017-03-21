#ifndef Bull_RAM_hpp
#define Bull_RAM_hpp

#include <Bull/Core/System/Export.hpp>
#include <Bull/Core/System/Integer.hpp>

namespace Bull
{
    struct BULL_API RAM
    {
        /*! \brief Retrieves the amount of RAM that is physically installed on the computer
         *
         * \return Return the amount of RAM
         *
         */
        static Uint64 getSystemMemory();
    };
}

#endif // Bull_RAM_hpp
