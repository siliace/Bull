#ifndef BULL_CORE_TIME_UNIX_CLOCKIMPL_HPP
#define BULL_CORE_TIME_UNIX_CLOCKIMPL_HPP

#include <Bull/Core/Time/Duration.hpp>

namespace Bull
{
    namespace prv
    {
        class ClockImpl
        {
        public:

            /*! \brief Get the uptime
             *
             * \return Return the update
             *
             */
            static Duration uptime();
        };
    }
}

#endif // BULL_CORE_TIME_UNIX_CLOCKIMPL_HPP
