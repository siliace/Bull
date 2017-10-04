#ifndef BULL_CORE_JOYSTICK_HPP
#define BULL_CORE_JOYSTICK_HPP

#include <array>

#include <Bull/Core/Configuration/Integer.hpp>
#include <Bull/Core/Memory/String.hpp>
#include <Bull/Core/Time/Time.hpp>

#include <Bull/Core/Export.hpp>

namespace Bull
{
    struct BULL_CORE_API Joystick
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

        /*! \brief Enable or disable the key repeat
         *
         * \param enable The state of the key repeat
         *
         */
        static void enableKeyRepeat(bool enable);

        /*! \brief Get the state of the key repeat
         *
         * \param Return true if the key repeat is enable, false otherwise
         *
         */
        static bool isKeyRepeatEnable();

        /*! \brief Set the threshold of an axis movement to trigger an event
         *
         * \param threshold The threshold to use
         *
         */
        static void setThreshold(float threshold);

        /*! \brief Get the threshold of an axis movement to trigger an event
         *
         * \return threshold The threshold used
         *
         */
        static float getThreshold();

        /*! \brief Set the delay between two key repeat
         *
         * \param delay The delay between two key repeat
         *
         */
        static void setRepeatDelay(const Time& delay);

        /*! \brief Get the delay between two key repeat
         *
         * \return delay The delay between two key repeat
         *
         */
        static const Time& getRepeatDelay();
    };
}

#endif // BULL_CORE_JOYSTICK_HPP
