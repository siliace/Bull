#ifndef BULL_SYSTEM_WINDOWEVENT_HPP
#define BULL_SYSTEM_WINDOWEVENT_HPP

#include <Bull/System/Joystick.hpp>
#include <Bull/System/Keyboard.hpp>
#include <Bull/System/Mouse.hpp>

#include <Bull/System/Export.hpp>

namespace Bull
{
    struct BULL_SYSTEM_API WindowEvent
    {
        enum Type
        {
            None,
            Closed,
            Resized,
            Moved,
            KeyUp,
            KeyDown,
            Character,
            MouseEnter,
            MouseLeave,
            MouseMoved,
            MouseButtonUp,
            MouseButtonDown,
            MouseButtonDoubleClicked,
            MouseWheel,
            LostFocus,
            GainFocus,
            JoystickButtonUp,
            JoystickButtonDown,
            JoystickMoved,
            JoystickConnected,
            JoystickDisconnected,
        };

        struct WindowResizedEvent
        {
            unsigned int width;
            unsigned int height;
        };

        struct WindowMovedEvent
        {
            int x, y;
            int xRel, yRel;
        };

        struct KeyEvent
        {
            Keyboard::Key code;
            bool          alt;
            bool          control;
            bool          shift;
            bool          system;
        };

        struct MouseMoveEvent
        {
            int x, y;
            int xRel, yRel;
        };

        struct MouseButtonEvent
        {
            int x, y;
            Mouse::Button button;
        };

        struct MouseWheelEvent
        {
            bool up;
            int x, y;
            Mouse::Wheel wheel;
        };

        struct JoystickConnectionEvent
        {
            Uint8 joystick;
        };

        struct JoystickMovedEvent
        {
            Uint8 joystick;
            float position;
            float relative;
            Joystick::Axis axis;
        };

        struct JoystickButtonEvent
        {
            Uint8 joystick;
            Uint8 button;
        };

        union
        {
            WindowResizedEvent      windowResize;
            WindowMovedEvent        windowMove;
            KeyEvent                key;
            Uint32                  character;
            MouseMoveEvent          mouseMove;
            MouseButtonEvent        mouseButton;
            MouseWheelEvent         mouseWheel;
            JoystickConnectionEvent joystickConnection;
            JoystickMovedEvent      joystickMoved;
            JoystickButtonEvent     joystickButton;
        };

        /*! \brief Default constructor
         *
         */
        WindowEvent();

        Type type;
    };
}

#endif // BULL_SYSTEM_WINDOWEVENT_HPP
