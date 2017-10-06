#ifndef BULL_JOYSTICKSTATE_HPP
#define BULL_JOYSTICKSTATE_HPP

#include <array>

#include <Bull/Core/Configuration/Integer.hpp>
#include <Bull/Core/Hardware/Joystick.hpp>
#include <Bull/Core/Time/Clock.hpp>

namespace Bull
{
    namespace prv
    {
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
            explicit JoystickState(Uint8 joystick);

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

            std::array<float, Joystick::CountAxis>                    axes;
            std::array<std::pair<bool, Clock>, Joystick::CountButton> buttons;
            bool                                                      connected;
        };
    }
}

#endif // BULL_JOYSTICKSTATE_HPP
