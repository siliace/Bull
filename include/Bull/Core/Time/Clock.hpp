#ifndef Bull_Clock_hpp
#define Bull_Clock_hpp

#include <Bull/Core/Time/Time.hpp>

namespace Bull
{
    class BULL_CORE_API Clock
    {
    public:

        /*! \brief Default constructor
         *
         */
        Clock();

        /*! \brief == operator override
         *
         * \param right The clock to test
         *
         * \return Return true if this and right are equal, false otherwise
         *
         */
        bool operator==(const Clock& right) const;

        /*! \brief != operator override
         *
         * \param right The clock to test
         *
         * \return Return true if this and right are not equal, false otherwise
         *
         */
        bool operator!=(const Clock& right) const;

        /*! \brief Start the clock
         *
         */
        void start();

        /*! \brief Stop the clock
         *
         */
        void pause();

        /*! \brief Resume the clock
         *
         */
        void resume();

        /*! \brief Get the elapsed time since the clock is started
         *
         * \return Return the time since the clock is started
         *
         */
        Time getElapsedTime() const;

        /*! \brief Get the state of the clock
         *
         * \return Return true if the clock is running, else otherwise
         *
         */
        bool isRunning() const;

        /*! \brief Restart the clock
         *
         * \return Return the time since the clock is started before restart
         *
         */
        Time restart();

    private:

        Time m_start;
        Time m_pause;
        Time m_totalPause;

        bool m_isRunning;
    };
}

#endif // Bull_Clock_hpp
