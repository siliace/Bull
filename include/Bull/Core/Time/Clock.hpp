#ifndef BULL_CORE_TIME_CLOCK_HPP
#define BULL_CORE_TIME_CLOCK_HPP

#include <Bull/Core/Time/Duration.hpp>

namespace Bull
{
    class BULL_CORE_API Clock
    {
    public:

        /** \brief Default constructor
         *
         */
        Clock();

        /** \brief Compare two Clock
         *
         * \param right The clock to compare to this
         *
         * \return True if this and right are equal
         *
         */
        bool operator==(const Clock& right) const;

        /** \brief Compare two Clock
         *
         * \param right The clock to compare to this
         *
         * \return True if this and right are equal
         *
         */
        bool operator!=(const Clock& right) const;

        /** \brief Start the clock
         *
         */
        void start();

        /** \brief Stop the clock
         *
         */
        void pause();

        /** \brief Resume the clock
         *
         */
        void resume();

        /** \brief Get the elapsed time since the clock is started
         *
         * \return Return the time since the clock is started
         *
         */
        Duration getElapsedTime() const;

        /** \brief Get the state of the clock
         *
         * \return Return true if the clock is running, else otherwise
         *
         */
        bool isRunning() const;

        /** \brief Restart the clock
         *
         * \return Return the time since the clock is started before restart
         *
         */
        Duration restart();

    private:

        Duration m_start;
        Duration m_pause;
        Duration m_totalPause;

        bool m_isRunning;
    };
}

#endif // BULL_CORE_TIME_CLOCK_HPP
