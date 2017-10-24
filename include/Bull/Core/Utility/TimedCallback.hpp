#ifndef BULL_CORE_UTILITY_TIMEDCALLBACK_HPP
#define BULL_CORE_UTILITY_TIMEDCALLBACK_HPP

#include <Bull/Core/Thread/Thread.hpp>

namespace Bull
{
    class BULL_CORE_API TimedCallback
    {
    private:

        static void loop(const Functor<void>& functor, const Time& timeout);

    public:

        /*! \brief
         *
         * \param functor
         * \param timeout
         *
         */
        TimedCallback(const Functor<void>& functor, const Time& timeout);

        /*! \brief
         *
         */
        ~TimedCallback();

    private:

        Thread m_worker;
    };
}

#endif // BULL_CORE_UTILITY_TIMEDCALLBACK_HPP
