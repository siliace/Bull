#include <Bull/Hardware/Joystick.hpp>
#include <Bull/Hardware/JoystickImpl.hpp>

namespace Bull
{
    bool Joystick::isConnected(Uint8 id)
    {
        return prv::JoystickImpl::isConnected(id);
    }

    Joystick::Capabilities Joystick::getCapabilities(Uint8 id)
    {
        return prv::JoystickImpl::getCapabilities(id);
    }

    bool Joystick::isButtonPressed(unsigned int button, Uint8 joystick)
    {
        return prv::JoystickImpl::isButtonPressed(button, joystick);
    }

    float Joystick::getAxisPosition(Joystick::Axis axis, Uint8 joystick)
    {
        return prv::JoystickImpl::getAxisPosition(axis, joystick);
    }
}
