#include <Bull/Hardware/Joystick.hpp>
#include <Bull/Hardware/JoystickImpl.hpp>

#include <Bull/Window/JoystickManager.hpp>

namespace Bull
{
    /*! \brief Check if a joystick is connected
     *
     * \param id The unique ID of the joystick
     *
     * \return Return true if the joystick is connected, false otherwise
     *
     */
    bool Joystick::isConnected(Uint8 id)
    {
        return prv::JoystickImpl::isConnected(id);
    }

    /*! \brief Check if a joystick is connected
     *
     * \param id The unique ID of the joystick
     *
     * \return Return the capabilities of the joystick
     *
     */
    Joystick::Capabilities Joystick::getCapabilities(Uint8 id)
    {
        return prv::JoystickImpl::getCapabilities(id);
    }

    /*! \brief Check if a button is pressed on a joystick
     *
     * \param button The ID of the button to check
     * \param joystick The unique ID of the joystick
     *
     * \param Return true if the button is pressed, false otherwise
     *
     */
    bool Joystick::isButtonPressed(unsigned int button, Uint8 joystick)
    {
        return prv::JoystickImpl::isButtonPressed(button, joystick);
    }

    /*! \brief Get the state of an axis
     *
     * \param axis The axis to check
     * \param joystick The joystick to check
     *
     * \return Return the position of the axis
     *
     */
    float Joystick::getAxisPosition(Joystick::Axis axis, Uint8 joystick)
    {
        return prv::JoystickImpl::getAxisPosition(axis, joystick);
    }

    /*! \brief Set the threshold of an axis movement to trigger an event
     *
     * \param threshold The threshold to use
     *
     */
    void Joystick::setThreshold(float threshold)
    {
        prv::JoystickManager::get()->setThreshold(threshold);
    }

    /*! \brief Get the threshold of an axis movement to trigger an event
     *
     * \return threshold The threshold used
     *
     */
    float Joystick::getThreshold()
    {
        return prv::JoystickManager::get()->getThreshold();
    }

    /*! \brief Enable or disable the key repeat
     *
     * \param enable True to enable key repeat, false to disable it
     *
     */
    void Joystick::enableKeyRepeat(bool enable)
    {
        prv::JoystickManager::get()->enableKeyRepeat(enable);
    }

    /*! \brief Get the joystick key repeat state
     *
     * \return Return true if joystick key repeat is enable, false otherwise
     *
     */
    bool Joystick::isEnableKeyRepeat()
    {
        return prv::JoystickManager::get()->isKeyRepeatEnable();
    }

    /*! \brief Set the delay between two key repeat
     *
     * \param delay The delay between two key repeat
     *
     */
    void Joystick::setRepeatDelay(const Time& delay)
    {
        prv::JoystickManager::get()->setRepeatDelay(delay);
    }

    /*! \brief Get the delay between two key repeat
     *
     * \return delay The delay between two key repeat
     *
     */
    const Time& Joystick::getRepeatDelay()
    {
        return prv::JoystickManager::get()->getRepeatDelay();
    }
}
