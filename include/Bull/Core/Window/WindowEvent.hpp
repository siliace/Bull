#ifndef BULL_CORE_WINDOW_WINDOWEVENT_HPP
#define BULL_CORE_WINDOW_WINDOWEVENT_HPP

#include <Bull/Core/Hardware/Joystick.hpp>
#include <Bull/Core/Hardware/JoystickAxis.hpp>
#include <Bull/Core/Hardware/Keyboard.hpp>
#include <Bull/Core/Hardware/KeyboardKey.hpp>
#include <Bull/Core/Hardware/Mouse.hpp>
#include <Bull/Core/Hardware/MouseButton.hpp>
#include <Bull/Core/Hardware/MouseWheel.hpp>
#include <Bull/Core/Window/WindowEventType.hpp>

namespace Bull
{
    struct BULL_CORE_API WindowEvent
    {
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
            KeyboardKey code;
            bool        alt;
            bool        control;
            bool        shift;
            bool        system;
        };

        struct MouseMoveEvent
        {
            int x, y;
            int xRel, yRel;
        };

        struct MouseButtonEvent
        {
            int x, y;
            MouseButton button;
        };

        struct MouseWheelEvent
        {
            bool up;
            int x, y;
            MouseWheel wheel;
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
            JoystickAxis axis;
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

        WindowEventType type;
    };
}

#endif // BULL_CORE_WINDOW_WINDOWEVENT_HPP
