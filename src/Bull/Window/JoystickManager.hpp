#ifndef Bull_JoystickManager_hpp
#define Bull_JoystickManager_hpp

#include <array>
#include <queue>
#include <utility>

#include <Bull/Core/Pattern/Singleton.hpp>
#include <Bull/Core/Time/Clock.hpp>

#include <Bull/Hardware/Joystick.hpp>

#include <Bull/Window/Window.hpp>

namespace Bull
{
    namespace prv
    {
        class JoystickManager : public Singleton<JoystickManager>
        {
        public:

            /*! \brief Default constructor
             *
             */
            JoystickManager();

            /*! \brief Process events for every joysticks
             *
             * \param eventQueue The event queue to fill
             *
             */
            void processEvents(std::queue<Window::Event>& eventQueue);

            /*! \brief Enable or disable the key repeat
             *
             * \param enable The state of the key repeat
             *
             */
            void enableKeyRepeat(bool enable);

            /*! \brief Get the state of the key repeat
             *
             * \param Return true if the key repeat is enable, false otherwise
             *
             */
            bool isKeyRepeatEnable() const;

            /*! \brief Set the threshold of an axis movement to trigger an event
             *
             * \param threshold The threshold to use
             *
             */
            void setThreshold(float threshold);

            /*! \brief Get the threshold of an axis movement to trigger an event
             *
             * \return threshold The threshold used
             *
             */
            float getThreshold() const;

            /*! \brief Set the delay between two key repeat
             *
             * \param delay The delay between two key repeat
             *
             */
            void setRepeatDelay(const Time& delay);

            /*! \brief Get the delay between two key repeat
             *
             * \return delay The delay between two key repeat
             *
             */
            const Time& getRepeatDelay();

        private:

            /*! \brief Update joystick events
             *
             * \param id The id of the joystick
             * \param eventQueue The event queue to fill
             *
             */
            void processJoystick(Uint8 joystick, std::queue<Window::Event>& eventQueue);

            struct JoystickState
            {
                /*! \brief Default constructor
                 *
                 */
                JoystickState();

                /*! \brief Default constructor
                 *
                 * \param joystick The ID of the joystick
                 *
                 */
                JoystickState(Uint8 joystick);

                /*! \brief == operator override
                 *
                 * \param right The JoystickState to compare
                 *
                 * \return Return true if this and right are equal, false otherwise
                 *
                 */
                bool operator==(const JoystickState& right) const;

                /*! \brief != operator override
                 *
                 * \param right The JoystickState to compare
                 *
                 * \return Return true if this and right are not equal, false otherwise
                 *
                 */
                bool operator!=(const JoystickState& right) const;

                std::array<std::pair<bool, Clock>, Joystick::CountButton> buttons;
                std::array<float, Joystick::CountAxis> axes;
                bool connected;
            };

            std::array<JoystickState, Joystick::CountButton> m_stateCache;

            bool m_keyrepeat;

            float m_threshold;

            Time m_repeatDelay;
        };
    }
}

#endif // Bull_JoystickManager_hpp
