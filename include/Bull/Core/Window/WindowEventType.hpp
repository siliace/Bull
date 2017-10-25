#ifndef BULL_CORE_WINDOW_WINDOWEVENTTYPE_HPP
#define BULL_CORE_WINDOW_WINDOWEVENTTYPE_HPP

namespace Bull
{
    enum WindowEventType
    {
        WindowEventType_None,
        WindowEventType_Closed,
        WindowEventType_Resized,
        WindowEventType_Moved,
        WindowEventType_KeyUp,
        WindowEventType_KeyDown,
        WindowEventType_Character,
        WindowEventType_MouseEnter,
        WindowEventType_MouseLeave,
        WindowEventType_MouseMoved,
        WindowEventType_MouseButtonUp,
        WindowEventType_MouseButtonDown,
        WindowEventType_MouseButtonDoubleClicked,
        WindowEventType_MouseWheel,
        WindowEventType_LostFocus,
        WindowEventType_GainFocus,
        WindowEventType_JoystickButtonUp,
        WindowEventType_JoystickButtonDown,
        WindowEventType_JoystickMoved,
        WindowEventType_JoystickConnected,
        WindowEventType_JoystickDisconnected,
    };
}

#endif // BULL_CORE_WINDOW_WINDOWEVENTTYPE_HPP
