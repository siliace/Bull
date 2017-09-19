#include <cmath>

#include <Bull/System/JoystickManager.hpp>

namespace Bull
{
    namespace prv
    {
        JoystickManager::JoystickManager() :
            m_keyrepeat(true),
            m_threshold(0.f),
            m_repeatDelay(0.f)
        {
            /// Nothing
        }

        void JoystickManager::processEvents(std::queue<WindowEvent>& eventQueue)
        {
            for(Uint8 i = 0; i < Joystick::Count; i++)
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

        void JoystickManager::processJoystick(Uint8 joystick, std::queue<WindowEvent>& eventQueue)
        {
            JoystickState state(joystick);
            JoystickState cached = m_stateCache[joystick];

            if(!state.connected && !cached.connected)
            {
                return;
            }

            if(state.connected != cached.connected)
            {
                WindowEvent e;

                e.type = (state.connected) ? WindowEvent::JoystickConnected : WindowEvent::JoystickDisconnected;

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
                    WindowEvent e;
                    e.type = (state.buttons[i].first) ? WindowEvent::JoystickButtonDown : WindowEvent::JoystickButtonUp;

                    e.joystickButton.joystick = joystick;
                    e.joystickButton.button   = static_cast<Uint8>(i);

                    eventQueue.push(e);

                    if(e.type == WindowEvent::JoystickButtonDown)
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
                    WindowEvent e;
                    e.type = WindowEvent::JoystickButtonDown;

                    e.joystickButton.joystick = joystick;
                    e.joystickButton.button   = static_cast<Uint8>(i);

                    eventQueue.push(e);

                    state.buttons[i].second.restart();
                }
            }

            for(unsigned int i = 0; i < state.axes.size(); i++)
            {
                float relative = state.axes[i] - cached.axes[i];

                if(state.axes[i] != cached.axes[i] && std::abs(relative) > m_threshold)
                {
                    WindowEvent e;

                    e.type = WindowEvent::JoystickMoved;

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
