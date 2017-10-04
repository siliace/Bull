#include <Bull/Core/Window/JoystickState.hpp>

namespace Bull
{
    namespace prv
    {
        JoystickState::JoystickState() :
            connected(false)
        {
            buttons.fill(std::make_pair(false, Clock()));
            axes.fill(32767.f);
        }

        JoystickState::JoystickState(Uint8 joystick) :
            JoystickState()
        {
            connected = Joystick::isConnected(joystick);

            if(connected)
            {
                for(unsigned int i = 0; i < Joystick::getCapabilities(joystick).countButtons; i++)
                {
                    buttons[i].first = Joystick::isButtonPressed(i, joystick);
                    buttons[i].second.restart();
                }

                for(unsigned int i = 0; i < Joystick::getCapabilities(joystick).countAxes; i++)
                {
                    axes[i] = Joystick::getAxisPosition(static_cast<Joystick::Axis>(i), joystick);
                }
            }
        }

        bool JoystickState::operator==(const JoystickState& right) const
        {
            return (buttons == right.buttons) && (axes == right.axes) && (connected == right.connected);
        }

        bool JoystickState::operator!=(const JoystickState& right) const
        {
            return !((*this) == right);
        }
    }
}