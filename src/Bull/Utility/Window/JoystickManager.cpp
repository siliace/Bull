#include <cmath>

#include <Bull/Utility/Window/JoystickManager.hpp>

namespace Bull
{
    namespace prv
    {
        JoystickManager::JoystickState::JoystickState() :
            connected(false)
        {
            buttons.fill(std::make_pair(false, Clock()));
            axes.fill(32767.f);
        }

        JoystickManager::JoystickState::JoystickState(Uint8 joystick) :
            JoystickState()
        {
            connected = Joystick::isConnected(joystick);

            if(connected)
            {
                for(unsigned int i = 0; i < Joystick::getCapabilities(joystick).countButtons; i++)
                {
                    buttons[i] = std::make_pair(Joystick::isButtonPressed(i, joystick), Clock());
                }

                for(unsigned int i = 0; i < Joystick::getCapabilities(joystick).countAxes; i++)
                {
                    axes[i] = Joystick::getAxisPosition(static_cast<Joystick::Axis>(i), joystick);
                }
            }
        }

        bool JoystickManager::JoystickState::operator==(const JoystickState& right) const
        {
            return (buttons == right.buttons) && (axes == right.axes) && (connected == right.connected);
        }

        bool JoystickManager::JoystickState::operator!=(const JoystickState& right) const
        {
            return !((*this) == right);
        }

        JoystickManager::JoystickManager() :
            m_keyrepeat(true),
            m_threshold(0.f),
            m_repeatDelay(0.f)
        {
            /// Nothing
        }

        void JoystickManager::processEvents(std::queue<Window::Event>& eventQueue)
        {
            for(unsigned int i = 0; i < Joystick::Count; i++)
            {
                processJoystick(i, eventQueue);
            }
        }

        void JoystickManager::enableKeyRepeat(bool enable)
        {
            m_keyrepeat = enable;
        }

        bool JoystickManager::isKeyRepeatEnable() const
        {
            return m_keyrepeat;
        }

        void JoystickManager::setThreshold(float threshold)
        {
            m_threshold = threshold;
        }

        float JoystickManager::getThreshold() const
        {
            return m_threshold;
        }

        void JoystickManager::setRepeatDelay(const Time& delay)
        {
            m_repeatDelay = delay;
        }

        const Time& JoystickManager::getRepeatDelay()
        {
            return m_repeatDelay;
        }

        void JoystickManager::processJoystick(Uint8 joystick, std::queue<Window::Event>& eventQueue)
        {
            JoystickState state(joystick);
            JoystickState cached = m_stateCache[joystick];

            if(!state.connected && !cached.connected)
            {
                return;
            }

            if(state.connected != cached.connected)
            {
                Window::Event e;

                e.type = (state.connected) ? Window::Event::JoystickConnected : Window::Event::JoystickDisconnected;

                e.joystickConnection.joystick = joystick;

                eventQueue.push(e);
            }

            for(unsigned int i = 0; i < state.buttons.size(); i++)
            {
                if(cached.buttons[i].second.isRunning())
                {
                    state.buttons[i].second = cached.buttons[i].second;
                }

                if(state.buttons[i].first != cached.buttons[i].first)
                {
                    Window::Event e;
                    e.type = (state.buttons[i].first) ? Window::Event::JoystickButtonDown : Window::Event::JoystickButtonUp;

                    e.joystickButton.joystick = joystick;
                    e.joystickButton.button   = i;

                    eventQueue.push(e);

                    if(e.type == Window::Event::JoystickButtonDown)
                    {
                        state.buttons[i].second.start();
                    }
                    else
                    {
                        state.buttons[i].second.restart();
                    }
                }
                else if(state.buttons[i].first &&
                        cached.buttons[i].first &&
                        m_keyrepeat &&
                        cached.buttons[i].second.getElapsedTime() > m_repeatDelay)
                {
                    Window::Event e;
                    e.type = Window::Event::JoystickButtonDown;

                    e.joystickButton.joystick = joystick;
                    e.joystickButton.button   = i;

                    eventQueue.push(e);

                    state.buttons[i].second.restart();
                }
            }

            for(unsigned int i = 0; i < state.axes.size(); i++)
            {
                float relative = state.axes[i] - cached.axes[i];

                if(state.axes[i] != cached.axes[i] && std::abs(relative) > m_threshold)
                {
                    Window::Event e;

                    e.type = Window::Event::JoystickMoved;

                    e.joystickMoved.joystick = joystick;
                    e.joystickMoved.axis     = static_cast<Joystick::Axis>(i);
                    e.joystickMoved.position = state.axes[i];
                    e.joystickMoved.relative = relative;

                    eventQueue.push(e);
                }
            }

            m_stateCache[joystick] = state;
        }
    }
}
