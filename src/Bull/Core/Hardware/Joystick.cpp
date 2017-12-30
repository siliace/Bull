#include <Bull/Core/Hardware/Joystick.hpp>
#include <Bull/Core/Hardware/JoystickImpl.hpp>
#include <Bull/Core/Window/JoystickManager.hpp>

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

    float Joystick::getAxisPosition(JoystickAxis axis, Uint8 joystick)
    {
        return prv::JoystickImpl::getAxisPosition(axis, joystick);
    }

    void Joystick::enableKeyRepeat(bool enable)
    {
        prv::JoystickManager::getInstance()->enableKeyRepeat(enable);
    }

    bool Joystick::isKeyRepeatEnable()
    {
        return prv::JoystickManager::getInstance()->isKeyRepeatEnable();
    }

    void Joystick::setThreshold(float threshold)
    {
        prv::JoystickManager::getInstance()->setThreshold(threshold);
    }

    float Joystick::getThreshold()
    {
        return prv::JoystickManager::getInstance()->getThreshold();
    }

    void Joystick::setRepeatDelay(const Duration& delay)
    {
        prv::JoystickManager::getInstance()->setRepeatDelay(delay);
    }

    const Duration& Joystick::getRepeatDelay()
    {
        return prv::JoystickManager::getInstance()->getRepeatDelay();
    }
}
