#include <Bull/Hardware/Win32/KeyboardImpl.hpp>

/// GCC missing define
#ifndef VK_OEM_PLUS
    #define VK_OEM_PLUS 0xBB
#endif
#ifndef VK_OEM_COMMA
    #define VK_OEM_COMMA 0xBC
#endif
#ifndef VK_OEM_PERIOD
    #define VK_OEM_PERIOD 0xBE
#endif
#ifndef VK_OEM_102
    #define VK_OEM_102 0xE2
#endif

namespace Bull
{
    namespace prv
    {
        bool KeyboardImpl::isKeyPressed(Keyboard::Key key)
        {
            if(key == Keyboard::Key::Control)
            {
                return Keyboard::isKeyPressed(Keyboard::LeftControl) || Keyboard::isKeyPressed(Keyboard::RightControl);
            }
            else if(key == Keyboard::Key::Alt)
            {
                return Keyboard::isKeyPressed(Keyboard::LeftAlt) || Keyboard::isKeyPressed(Keyboard::RightAlt);
            }
            else if(key == Keyboard::Key::System)
            {
                return Keyboard::isKeyPressed(Keyboard::LeftSystem) || Keyboard::isKeyPressed(Keyboard::RightSystem);
            }

            return GetAsyncKeyState(convertBullkeyToVK(key));
        }

        UINT KeyboardImpl::convertBullkeyToVK(Keyboard::Key key)
        {
            switch(key)
            {
                case Keyboard::Key::A:            return 'A';
                case Keyboard::Key::B:            return 'B';
                case Keyboard::Key::C:            return 'C';
                case Keyboard::Key::D:            return 'D';
                case Keyboard::Key::E:            return 'E';
                case Keyboard::Key::F:            return 'F';
                case Keyboard::Key::G:            return 'G';
                case Keyboard::Key::H:            return 'H';
                case Keyboard::Key::I:            return 'I';
                case Keyboard::Key::J:            return 'J';
                case Keyboard::Key::K:            return 'K';
                case Keyboard::Key::L:            return 'L';
                case Keyboard::Key::M:            return 'M';
                case Keyboard::Key::N:            return 'N';
                case Keyboard::Key::O:            return 'O';
                case Keyboard::Key::P:            return 'P';
                case Keyboard::Key::Q:            return 'Q';
                case Keyboard::Key::R:            return 'R';
                case Keyboard::Key::S:            return 'S';
                case Keyboard::Key::T:            return 'T';
                case Keyboard::Key::U:            return 'U';
                case Keyboard::Key::V:            return 'V';
                case Keyboard::Key::W:            return 'W';
                case Keyboard::Key::X:            return 'X';
                case Keyboard::Key::Y:            return 'Y';
                case Keyboard::Key::Z:            return 'Z';
                case Keyboard::Key::Num0:         return '0';
                case Keyboard::Key::Num1:         return '1';
                case Keyboard::Key::Num2:         return '2';
                case Keyboard::Key::Num3:         return '3';
                case Keyboard::Key::Num4:         return '4';
                case Keyboard::Key::Num5:         return '5';
                case Keyboard::Key::Num6:         return '6';
                case Keyboard::Key::Num7:         return '7';
                case Keyboard::Key::Num8:         return '8';
                case Keyboard::Key::Num9:         return '9';
                case Keyboard::Key::NumPad0:      return VK_NUMPAD0;
                case Keyboard::Key::NumPad1:      return VK_NUMPAD1;
                case Keyboard::Key::NumPad2:      return VK_NUMPAD2;
                case Keyboard::Key::NumPad3:      return VK_NUMPAD3;
                case Keyboard::Key::NumPad4:      return VK_NUMPAD4;
                case Keyboard::Key::NumPad5:      return VK_NUMPAD5;
                case Keyboard::Key::NumPad6:      return VK_NUMPAD6;
                case Keyboard::Key::NumPad7:      return VK_NUMPAD7;
                case Keyboard::Key::NumPad8:      return VK_NUMPAD8;
                case Keyboard::Key::NumPad9:      return VK_NUMPAD9;
                case Keyboard::Key::NumLock:      return VK_NUMLOCK;
                case Keyboard::Key::NumPadDot:    return VK_DECIMAL;
                case Keyboard::Key::Add:          return VK_ADD;
                case Keyboard::Key::Substract:    return VK_SUBTRACT;
                case Keyboard::Key::Multiply:     return VK_MULTIPLY;
                case Keyboard::Key::Divide:       return VK_DIVIDE;
                case Keyboard::Key::F1:           return VK_F1;
                case Keyboard::Key::F2:           return VK_F2;
                case Keyboard::Key::F3:           return VK_F3;
                case Keyboard::Key::F4:           return VK_F4;
                case Keyboard::Key::F5:           return VK_F5;
                case Keyboard::Key::F6:           return VK_F6;
                case Keyboard::Key::F7:           return VK_F7;
                case Keyboard::Key::F8:           return VK_F8;
                case Keyboard::Key::F9:           return VK_F9;
                case Keyboard::Key::F10:          return VK_F10;
                case Keyboard::Key::F11:          return VK_F11;
                case Keyboard::Key::F12:          return VK_F12;
                case Keyboard::Key::F13:          return VK_F13;
                case Keyboard::Key::F14:          return VK_F14;
                case Keyboard::Key::F15:          return VK_F15;
                case Keyboard::Key::F16:          return VK_F16;
                case Keyboard::Key::F17:          return VK_F17;
                case Keyboard::Key::F18:          return VK_F18;
                case Keyboard::Key::F19:          return VK_F19;
                case Keyboard::Key::F20:          return VK_F20;
                case Keyboard::Key::F21:          return VK_F21;
                case Keyboard::Key::F22:          return VK_F22;
                case Keyboard::Key::F23:          return VK_F23;
                case Keyboard::Key::F24:          return VK_F24;
                case Keyboard::Key::Left:         return VK_LEFT;
                case Keyboard::Key::Right:        return VK_RIGHT;
                case Keyboard::Key::Up:           return VK_UP;
                case Keyboard::Key::Down:         return VK_DOWN;
                case Keyboard::Key::Space:        return VK_SPACE;
                case Keyboard::Key::Escape:       return VK_ESCAPE;
                case Keyboard::Key::LeftControl:  return VK_LCONTROL;
                case Keyboard::Key::RightControl: return VK_RCONTROL;
                case Keyboard::Key::LeftAlt:      return VK_LMENU;
                case Keyboard::Key::RightAlt:     return VK_RMENU;
                case Keyboard::Key::LeftSystem:   return VK_LWIN;
                case Keyboard::Key::RightSystem:  return VK_RWIN;
                case Keyboard::Key::LeftShift:    return VK_LSHIFT;
                case Keyboard::Key::RightShift:   return VK_RSHIFT;
                case Keyboard::Key::OEM1:         return VK_OEM_1;
                case Keyboard::Key::OEMPeriod:    return VK_OEM_PERIOD;
                case Keyboard::Key::OEM2:         return VK_OEM_2;
                case Keyboard::Key::OEM3:         return VK_OEM_3;
                case Keyboard::Key::OEM4:         return VK_OEM_4;
                case Keyboard::Key::OEM5:         return VK_OEM_5;
                case Keyboard::Key::OEM6:         return VK_OEM_6;
                case Keyboard::Key::OEM7:         return VK_OEM_7;
                case Keyboard::Key::OEM8:         return VK_OEM_8;
                case Keyboard::Key::OEM9:         return VK_OEM_102;
                case Keyboard::Key::OEMPlus:      return VK_OEM_PLUS;
                case Keyboard::Key::OEMComma:     return VK_OEM_COMMA;
                case Keyboard::Key::Tab:          return VK_TAB;
                case Keyboard::Key::Back:         return VK_BACK;
                case Keyboard::Key::Enter:        return VK_RETURN;
                case Keyboard::Key::CapsLock:     return VK_CAPITAL;
                case Keyboard::Key::Apps:         return VK_APPS;
                case Keyboard::Key::Delete:       return VK_DELETE;
                case Keyboard::Key::Insert:       return VK_INSERT;
                case Keyboard::Key::PageUp:       return VK_PRIOR;
                case Keyboard::Key::PageDown:     return VK_NEXT;
                case Keyboard::Key::End:          return VK_END;
                case Keyboard::Key::Home:         return VK_HOME;
                case Keyboard::Key::Pause:        return VK_PAUSE;
                case Keyboard::Key::ScreenShot:   return VK_SNAPSHOT;
                case Keyboard::Key::Scroll:       return VK_SCROLL;
                default:                          return 0;
            }

            return 0;
        }
    }
}
