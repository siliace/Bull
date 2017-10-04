#include <Bull/Core/Hardware/Unix/JoystickImpl.hpp>

namespace Bull
{
    namespace prv
    {
        bool JoystickImpl::isConnected(Uint8 id)
        {
            return false;
        }

        Joystick::Capabilities JoystickImpl::getCapabilities(Uint8 id)
        {
            Joystick::Capabilities caps;

            return caps;
        }

        bool JoystickImpl::isButtonPressed(unsigned int button, Uint8 joystick)
        {
            return false;
        }

        float JoystickImpl::getAxisPosition(Joystick::Axis axis, Uint8 joystick)
        {
            return 0;
        }
    }
}


