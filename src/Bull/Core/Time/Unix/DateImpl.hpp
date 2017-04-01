#ifndef Bull_DateImpl_hpp
#define Bull_DateImpl_hpp

#include <Bull/Core/Time/Date.hpp>

namespace Bull
{
    namespace prv
    {
        struct DateImpl
        {
            /*! @brief Get the current date
             *
             * @return Return the current date
             *
             */
            static Date now();
        };
    }
}

#endif // Bull_DateImpl_hpp
