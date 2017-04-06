#ifndef Bull_RAMImpl_hpp
#define Bull_RAMImpl_hpp

#include <Bull/Core/System/Integer.hpp>

namespace Bull
{
    namespace prv
    {
        struct RAMImpl
        {
            /*! \brief Retrieves the amount of RAM that is physically installed on the computer
             *
             * \return Return the amount of RAM
             *
             */
            static Uint64 getSystemMemory();
        };
    }
}

#endif // Bull_RAMImpl_hpp
