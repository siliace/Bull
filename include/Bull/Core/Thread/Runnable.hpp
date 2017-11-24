#ifndef BULL_CORE_THREAD_RUNNABLE_HPP
#define BULL_CORE_THREAD_RUNNABLE_HPP

#include <Bull/Core/Export.hpp>

namespace Bull
{
    class BULL_CORE_API Runnable
    {
    public:

        /*! \brief Call operator
         *
         */
        void operator()()
        {
            run();
        }

    protected:

        /*! \brief Default constructor
         *
         */
        Runnable() = default;

        /*! \brief The function to run in the Thread
         *
         */
        virtual void run() = 0;
    };
}

#endif // BULL_CORE_THREAD_RUNNABLE_HPP
