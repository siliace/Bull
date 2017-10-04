#ifndef BULL_CORE_KEYBOARD_HPP
#define BULL_CORE_KEYBOARD_HPP

#include <Bull/Core/Export.hpp>

namespace Bull
{
    class BULL_CORE_API Keyboard
    {
    public:

        enum Key
        {
            A,
            B,
            C,
            D,
            E,
            F,
            G,
            H,
            I,
            J,
            K,
            L,
            M,
            N,
            O,
            P,
            Q,
            R,
            S,
            T,
            U,
            V,
            W,
            X,
            Y,
            Z,
            NumLock,
            Num0,
            Num1,
            Num2,
            Num3,
            Num4,
            Num5,
            Num6,
            Num7,
            Num8,
            Num9,
            NumPad0,
            NumPad1,
            NumPad2,
            NumPad3,
            NumPad4,
            NumPad5,
            NumPad6,
            NumPad7,
            NumPad8,
            NumPad9,
            NumPadDot,
            NumPadEnter,
            Add,
            Substract,
            Multiply,
            Divide,
            F1,
            F2,
            F3,
            F4,
            F5,
            F6,
            F7,
            F8,
            F9,
            F10,
            F11,
            F12,
            F13,
            F14,
            F15,
            F16,
            F17,
            F18,
            F19,
            F20,
            F21,
            F22,
            F23,
            F24,
            Left,
            Right,
            Up,
            Down,
            Space,
            Escape,
            Control,
            LeftControl,
            RightControl,
            Alt,
            LeftAlt,
            RightAlt,
            System,
            LeftSystem,
            RightSystem,
            Shift,
            LeftShift,
            RightShift,
            OEM1,
            OEMPeriod,
            OEM2,
            OEM3,
            OEM4,
            OEM5,
            OEM6,
            OEM7,
            OEM8,
            OEM9,
            OEMPlus,
            OEMComma,
            Tab,
            Back,
            Enter,
            CapsLock,
            Apps,
            Delete,
            Insert,
            PageUp,
            PageDown,
            End,
            Home,
            Pause,
            ScreenShot,
            Scroll,
            Unknown
        };

        /*! \brief Check if a key is pressed
         *
         * \param key To key to check the state
         *
         * \return Return true if the key is down, false otherwise
         *
         */
        static bool isKeyPressed(Keyboard::Key key);
    };
}

#endif // BULL_CORE_KEYBOARD_HPP
