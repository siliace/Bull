#ifndef BULL_JOYSTICK_HPP
#define BULL_JOYSTICK_HPP

#include <array>

#include <Bull/Core/Memory/String.hpp>
#include <Bull/Core/System/Integer.hpp>
#include <Bull/Core/Time/Time.hpp>

#include <Bull/Hardware/Export.hpp>

namespace Bull
{
    struct BULL_HARDWARE_API Joystick
    {
        enum
        {
            Count       = 16,
            CountButton = 32,
            CountAxis   = 8,
        };

        enum Axis
        {
            X,
            Y,
            Z,
            R,
            U,
            V,
            PovX,
            PovY
        };

        struct Capabilities
        {
            struct AxisCapabilites
            {
                Uint16 min;
                Uint16 max;
                bool   exists;
            };

            String                                           name;
            std::array<AxisCapabilites, Joystick::CountAxis> axes;
            unsigned int                                     countAxes;
            unsigned int                                     countButtons;
        };

        /*! \brief Check whether a joystick is connected
         *
         * \param joystick The ID of the joystick
         *
         * \return Return true if the joystick is connected, false otherwise
         *
         */
        static bool isConnected(Uint8 joystick);

        /*! \brief Get the capabilities of a joystick
         *
         * \param joystick The unique ID of the joystick
         *
         * \return Return the capabilities of the joystick
         *
         */
        static Capabilities getCapabilities(Uint8 joystick);

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

#endif // BULL_JOYSTICK_HPP
