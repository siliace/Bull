#ifndef BULL_CORE_WINDOW_WINDOWEVENT_HPP
#define BULL_CORE_WINDOW_WINDOWEVENT_HPP

#include <Bull/Core/Export.hpp>
#include <Bull/Core/Hardware/Joystick.hpp>
#include <Bull/Core/Hardware/Keyboard.hpp>
#include <Bull/Core/Hardware/Mouse.hpp>
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

        WindowEventType type;
    };
}

#endif // BULL_CORE_WINDOW_WINDOWEVENT_HPP
