#include <Bull/Core/Support/Win32/Windows.hpp>

#include <Bull/Core/Hardware/Win32/KeyboardImpl.hpp>

namespace Bull
{
    namespace prv
    {
        bool KeyboardImpl::isKeyPressed(KeyboardKey key)
        {
            if(key == KeyboardKey_Control)
            {
                return Keyboard::isKeyPressed(KeyboardKey_LeftControl) || Keyboard::isKeyPressed(KeyboardKey_RightControl);
            }
            else if(key == KeyboardKey_Alt)
            {
                return Keyboard::isKeyPressed(KeyboardKey_LeftAlt) || Keyboard::isKeyPressed(KeyboardKey_RightAlt);
            }
            else if(key == KeyboardKey_System)
            {
                return Keyboard::isKeyPressed(KeyboardKey_LeftSystem) || Keyboard::isKeyPressed(KeyboardKey_RightSystem);
            }

            return (GetAsyncKeyState(convertBullkeyToVK(key)) & 0x8000) != FALSE;
        }

        int KeyboardImpl::convertBullkeyToVK(KeyboardKey key)
        {
            switch(key)
            {
                case KeyboardKey_A:            return 'A';
                case KeyboardKey_B:            return 'B';
                case KeyboardKey_C:            return 'C';
                case KeyboardKey_D:            return 'D';
                case KeyboardKey_E:            return 'E';
                case KeyboardKey_F:            return 'F';
                case KeyboardKey_G:            return 'G';
                case KeyboardKey_H:            return 'H';
                case KeyboardKey_I:            return 'I';
                case KeyboardKey_J:            return 'J';
                case KeyboardKey_K:            return 'K';
                case KeyboardKey_L:            return 'L';
                case KeyboardKey_M:            return 'M';
                case KeyboardKey_N:            return 'N';
                case KeyboardKey_O:            return 'O';
                case KeyboardKey_P:            return 'P';
                case KeyboardKey_Q:            return 'Q';
                case KeyboardKey_R:            return 'R';
                case KeyboardKey_S:            return 'S';
                case KeyboardKey_T:            return 'T';
                case KeyboardKey_U:            return 'U';
                case KeyboardKey_V:            return 'V';
                case KeyboardKey_W:            return 'W';
                case KeyboardKey_X:            return 'X';
                case KeyboardKey_Y:            return 'Y';
                case KeyboardKey_Z:            return 'Z';
                case KeyboardKey_Num0:         return '0';
                case KeyboardKey_Num1:         return '1';
                case KeyboardKey_Num2:         return '2';
                case KeyboardKey_Num3:         return '3';
                case KeyboardKey_Num4:         return '4';
                case KeyboardKey_Num5:         return '5';
                case KeyboardKey_Num6:         return '6';
                case KeyboardKey_Num7:         return '7';
                case KeyboardKey_Num8:         return '8';
                case KeyboardKey_Num9:         return '9';
                case KeyboardKey_NumPad0:      return VK_NUMPAD0;
                case KeyboardKey_NumPad1:      return VK_NUMPAD1;
                case KeyboardKey_NumPad2:      return VK_NUMPAD2;
                case KeyboardKey_NumPad3:      return VK_NUMPAD3;
                case KeyboardKey_NumPad4:      return VK_NUMPAD4;
                case KeyboardKey_NumPad5:      return VK_NUMPAD5;
                case KeyboardKey_NumPad6:      return VK_NUMPAD6;
                case KeyboardKey_NumPad7:      return VK_NUMPAD7;
                case KeyboardKey_NumPad8:      return VK_NUMPAD8;
                case KeyboardKey_NumPad9:      return VK_NUMPAD9;
                case KeyboardKey_NumLock:      return VK_NUMLOCK;
                case KeyboardKey_NumPadDot:    return VK_DECIMAL;
                case KeyboardKey_Add:          return VK_ADD;
                case KeyboardKey_Subtract:     return VK_SUBTRACT;
                case KeyboardKey_Multiply:     return VK_MULTIPLY;
                case KeyboardKey_Divide:       return VK_DIVIDE;
                case KeyboardKey_F1:           return VK_F1;
                case KeyboardKey_F2:           return VK_F2;
                case KeyboardKey_F3:           return VK_F3;
                case KeyboardKey_F4:           return VK_F4;
                case KeyboardKey_F5:           return VK_F5;
                case KeyboardKey_F6:           return VK_F6;
                case KeyboardKey_F7:           return VK_F7;
                case KeyboardKey_F8:           return VK_F8;
                case KeyboardKey_F9:           return VK_F9;
                case KeyboardKey_F10:          return VK_F10;
                case KeyboardKey_F11:          return VK_F11;
                case KeyboardKey_F12:          return VK_F12;
                case KeyboardKey_F13:          return VK_F13;
                case KeyboardKey_F14:          return VK_F14;
                case KeyboardKey_F15:          return VK_F15;
                case KeyboardKey_F16:          return VK_F16;
                case KeyboardKey_F17:          return VK_F17;
                case KeyboardKey_F18:          return VK_F18;
                case KeyboardKey_F19:          return VK_F19;
                case KeyboardKey_F20:          return VK_F20;
                case KeyboardKey_F21:          return VK_F21;
                case KeyboardKey_F22:          return VK_F22;
                case KeyboardKey_F23:          return VK_F23;
                case KeyboardKey_F24:          return VK_F24;
                case KeyboardKey_Left:         return VK_LEFT;
                case KeyboardKey_Right:        return VK_RIGHT;
                case KeyboardKey_Up:           return VK_UP;
                case KeyboardKey_Down:         return VK_DOWN;
                case KeyboardKey_Space:        return VK_SPACE;
                case KeyboardKey_Escape:       return VK_ESCAPE;
                case KeyboardKey_LeftControl:  return VK_LCONTROL;
                case KeyboardKey_RightControl: return VK_RCONTROL;
                case KeyboardKey_LeftAlt:      return VK_LMENU;
                case KeyboardKey_RightAlt:     return VK_RMENU;
                case KeyboardKey_LeftSystem:   return VK_LWIN;
                case KeyboardKey_RightSystem:  return VK_RWIN;
                case KeyboardKey_LeftShift:    return VK_LSHIFT;
                case KeyboardKey_RightShift:   return VK_RSHIFT;
                case KeyboardKey_OEM1:         return VK_OEM_1;
                case KeyboardKey_OEMPeriod:    return VK_OEM_PERIOD;
                case KeyboardKey_OEM2:         return VK_OEM_2;
                case KeyboardKey_OEM3:         return VK_OEM_3;
                case KeyboardKey_OEM4:         return VK_OEM_4;
                case KeyboardKey_OEM5:         return VK_OEM_5;
                case KeyboardKey_OEM6:         return VK_OEM_6;
                case KeyboardKey_OEM7:         return VK_OEM_7;
                case KeyboardKey_OEM8:         return VK_OEM_8;
                case KeyboardKey_OEM9:         return VK_OEM_102;
                case KeyboardKey_OEMPlus:      return VK_OEM_PLUS;
                case KeyboardKey_OEMComma:     return VK_OEM_COMMA;
                case KeyboardKey_Tab:          return VK_TAB;
                case KeyboardKey_Back:         return VK_BACK;
                case KeyboardKey_Enter:        return VK_RETURN;
                case KeyboardKey_CapsLock:     return VK_CAPITAL;
                case KeyboardKey_Apps:         return VK_APPS;
                case KeyboardKey_Delete:       return VK_DELETE;
                case KeyboardKey_Insert:       return VK_INSERT;
                case KeyboardKey_PageUp:       return VK_PRIOR;
                case KeyboardKey_PageDown:     return VK_NEXT;
                case KeyboardKey_End:          return VK_END;
                case KeyboardKey_Home:         return VK_HOME;
                case KeyboardKey_Pause:        return VK_PAUSE;
                case KeyboardKey_ScreenShot:   return VK_SNAPSHOT;
                case KeyboardKey_Scroll:       return VK_SCROLL;
            }

            return 0;
        }
    }
}
