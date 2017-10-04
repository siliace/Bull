#ifndef BULL_CORE_HARDWARE_JOYSTICKIMPL_HPP
#define BULL_CORE_HARDWARE_JOYSTICKIMPL_HPP

#include <Bull/Core/Configuration/Integer.hpp>
#include <Bull/Core/Hardware/Joystick.hpp>

namespace Bull
{
    namespace prv
    {
        class JoystickImpl
        {
        public:

            /*! \brief Check if a joystick is connected
             *
             * \param id The unique ID of the joystick
             *
             * \return Return true if the joystick is connected, false otherwise
             *
             */
            static bool isConnected(Uint8 id);

            /*! \brief Check if a joystick is connected
             *
             * \param id The unique ID of the joystick
             *
             * \return Return the capabilities of the joystick
             *
             */
            static Joystick::Capabilities getCapabilities(Uint8 id);

            /*! \brief Check if a button is pressed on a joystick
             *
             * \param button The ID of the button to check
             * \param joystick The unique ID of the joystick
             *
             * \param Return true if the button is pressed, false otherwise
             *
             */
            static bool isButtonPressed(unsigned int button, Uint8 joystick);

            /*! \brief Get the state of an axis
             *
             * \param axis The axis to check
             * \param joystick The joystick to check
             *
             * \return Return the position of the axis
             *
             */
            static float getAxisPosition(Joystick::Axis axis, Uint8 joystick);
        };
    }
}

#endif // BULL_CORE_HARDWARE_JOYSTICKIMPL_HPP

