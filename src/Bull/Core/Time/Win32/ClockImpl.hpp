#ifndef Bull_ClockImpl_hpp
#define Bull_ClockImpl_hpp

#include <Bull/Core/Time/Time.hpp>

namespace Bull
{
    namespace prv
    {
        class ClockImpl
        {
        public:

            /*! @brief Get the uptime
             *
             * @return Return the update
             *
             */
            static Time uptime();
        };
    }
}

#endif // Bull_ClockImpl_hpp

