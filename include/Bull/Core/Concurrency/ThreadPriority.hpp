#ifndef BULL_CORE_CONCURRENCY_THREADPRIORITY_HPP
#define BULL_CORE_CONCURRENCY_THREADPRIORITY_HPP

namespace Bull
{
    enum ThreadPriority
    {
        ThreadPriority_Idle        = 0, /*!< Scheduled only when no other threads are running */
        ThreadPriority_Lowest      = 1, /*!< Scheduled less often than LowPriority */
        ThreadPriority_Low         = 2, /*!< Scheduled less often than NormalPriority */
        ThreadPriority_Normal      = 3, /*!< The default priority of the operating system */
        ThreadPriority_High        = 4, /*!< Scheduled more often than NormalPriority */
        ThreadPriority_Highest     = 5, /*!< Scheduled more often than HighPriority */
        ThreadPriority_TimeCritial = 6, /*!< Scheduled as often as possible */
        ThreadPriority_Inherit     = 7  /*!< Use the same priority as the creating thread */
    };
}

#endif // BULL_CORE_CONCURRENCY_THREADPRIORITY_HPP
