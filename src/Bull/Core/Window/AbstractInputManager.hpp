#ifndef BULL_CORE_WINDOW_ABSTRACTINPUTMANAGER_HPP
#define BULL_CORE_WINDOW_ABSTRACTINPUTMANAGER_HPP

#include <queue>

#include <Bull/Core/Time/Duration.hpp>
#include <Bull/Core/Window/WindowEvent.hpp>

namespace Bull
{
    namespace prv
    {
        class AbstractInputManager
        {
        public:

            /** \brief Process events for every joysticks
             *
             * \param eventQueue The event queue to fill
             *
             */
            virtual void processEvents(std::queue<WindowEvent>& eventQueue) = 0;

            /** \brief Enable or disable the key repeat
             *
             * \param enable The state of the key repeat
             *
             */
            virtual void enableKeyRepeat(bool enable) = 0;

            /** \brief Get the state of the key repeat
             *
             * \param Return true if the key repeat is enable, false otherwise
             *
             */
            virtual bool isKeyRepeatEnable() const = 0;

            /** \brief Set the delay between two key repeat
             *
             * \param delay The delay between two key repeat
             *
             */
            virtual void setRepeatDelay(const Duration& delay) = 0;

            /** \brief Get the delay between two key repeat
             *
             * \return delay The delay between two key repeat
             *
             */
            virtual const Duration& getRepeatDelay() = 0;
        };
    }
}

#endif // BULL_CORE_WINDOW_ABSTRACTINPUTMANAGER_HPP
