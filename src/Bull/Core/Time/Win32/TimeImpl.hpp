#ifndef BULL_CORE_TIME_WIN32_TIMEIMPL_HPP
#define BULL_CORE_TIME_WIN32_TIMEIMPL_HPP

#include <Bull/Core/Time/Time.hpp>

namespace Bull
{
    namespace prv
    {
        class TimeImpl
        {
        public:

            /*! \brief Create a Time of now
             *
             * \return The created time
             *
             */
            static Time now();
        };
    }
}

#endif // BULL_CORE_TIME_WIN32_TIMEIMPL_HPP
