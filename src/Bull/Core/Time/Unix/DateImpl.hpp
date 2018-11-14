#ifndef BULL_CORE_TIME_UNIX_DATEIMPL_HPP
#define BULL_CORE_TIME_UNIX_DATEIMPL_HPP

#include <Bull/Core/Time/Date.hpp>

namespace Bull
{
    namespace prv
    {
        class DateImpl
        {
        public:

            /*! \brief Get the current date
             *
             * \return Return the current date
             *
             */
            static Date now();
        };
    }
}

#endif // BULL_CORE_TIME_UNIX_DATEIMPL_HPP
