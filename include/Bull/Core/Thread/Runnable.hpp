#ifndef BULL_CORE_THREAD_RUNNABLE_HPP
#define BULL_CORE_THREAD_RUNNABLE_HPP

#include <Bull/Core/Export.hpp>

namespace Bull
{
    class Thread;

    class BULL_CORE_API Runnable
    {
    private:

        friend class Thread;

        /*! \brief The function to run in the Thread
         *
         */
        virtual void run() const = 0;
    };
}

#endif // BULL_CORE_THREAD_RUNNABLE_HPP
