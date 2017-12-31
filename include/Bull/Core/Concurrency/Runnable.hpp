#ifndef BULL_CORE_CONCURRENCY_RUNNABLE_HPP
#define BULL_CORE_CONCURRENCY_RUNNABLE_HPP

#include <Bull/Core/Export.hpp>

namespace Bull
{
    struct BULL_CORE_API Runnable
    {
        /*! \brief The function to run in the Thread
         *
         */
        virtual void run() = 0;
    };
}

#endif // BULL_CORE_CONCURRENCY_RUNNABLE_HPP
