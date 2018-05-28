#ifndef BULL_CORE_TIME_UNIX_TIMEIMPL_HPP
#define BULL_CORE_TIME_UNIX_TIMEIMPL_HPP

#include <Bull/Core/Time/Time.hpp>

namespace Bull
{
    namespace prv
    {
        struct TimeImpl
        {

            /*! \brief Create a Time of now
             *
             * \return The created time
             *
             */
            static Time now();
        };
    }
}

#endif // BULL_CORE_TIME_UNIX_TIMEIMPL_HPP
