#include <bitset>

#include <Bull/Hardware/Win32/JoystickImpl.hpp>

#include <Bull/Math/Angle.hpp>

namespace Bull
{
    namespace prv
    {
        bool JoystickImpl::isConnected(Uint8 id)
        {
            JOYINFO joyInfo;

            return joyGetPos(id, &joyInfo) == JOYERR_NOERROR;
        }

        Joystick::Capabilities JoystickImpl::getCapabilities(Uint8 id)
        {
            Joystick::Capabilities caps;
            JOYCAPS              infoCaps;

            if(joyGetDevCaps(id, &infoCaps, sizeof(JOYCAPS)) == JOYERR_NOERROR)
            {
                caps.name = infoCaps.szPname;

                caps.axes[Joystick::Axis::X].exists    = true;
                caps.axes[Joystick::Axis::Y].exists    = true;
                caps.axes[Joystick::Axis::Z].exists    = infoCaps.wCaps & JOYCAPS_HASZ;
                caps.axes[Joystick::Axis::R].exists    = infoCaps.wCaps & JOYCAPS_HASR;
                caps.axes[Joystick::Axis::U].exists    = infoCaps.wCaps & JOYCAPS_HASU;
                caps.axes[Joystick::Axis::V].exists    = infoCaps.wCaps & JOYCAPS_HASV;
                caps.axes[Joystick::Axis::PovX].exists = infoCaps.wCaps & JOYCAPS_HASPOV;
                caps.axes[Joystick::Axis::PovY].exists = infoCaps.wCaps & JOYCAPS_HASPOV;

                caps.axes[Joystick::Axis::X].min    = infoCaps.wXmin;
                caps.axes[Joystick::Axis::Y].min    = infoCaps.wYmin;
                caps.axes[Joystick::Axis::Z].min    = infoCaps.wZmin;
                caps.axes[Joystick::Axis::R].min    = infoCaps.wRmin;
                caps.axes[Joystick::Axis::U].min    = infoCaps.wUmin;
                caps.axes[Joystick::Axis::V].min    = infoCaps.wVmin;
                caps.axes[Joystick::Axis::PovX].min = 90;
                caps.axes[Joystick::Axis::PovY].min = 90;

                caps.axes[Joystick::Axis::X].max    = infoCaps.wXmax;
                caps.axes[Joystick::Axis::Y].max    = infoCaps.wYmax;
                caps.axes[Joystick::Axis::Z].max    = infoCaps.wZmax;
                caps.axes[Joystick::Axis::R].max    = infoCaps.wRmax;
                caps.axes[Joystick::Axis::U].max    = infoCaps.wUmax;
                caps.axes[Joystick::Axis::V].max    = infoCaps.wVmax;
                caps.axes[Joystick::Axis::PovX].max = 9000;
                caps.axes[Joystick::Axis::PovY].max = 9000;

                caps.countButtons = infoCaps.wNumButtons;
                caps.countAxes    = infoCaps.wNumAxes;
            }

            return caps;
        }

        bool JoystickImpl::isButtonPressed(unsigned int button, Uint8 joystick)
        {
            return std::bitset<Joystick::CountButton>(getJoystickState(joystick).dwButtons).test(button);
        }

        float JoystickImpl::getAxisPosition(Joystick::Axis axis, Uint8 joystick)
        {
            JOYINFOEX joystickState = getJoystickState(joystick);

            switch(axis)
            {
                case Joystick::Axis::X:    return joystickState.dwXpos;
                case Joystick::Axis::Y:    return joystickState.dwYpos;
                case Joystick::Axis::Z:    return joystickState.dwZpos;
                case Joystick::Axis::R:    return joystickState.dwRpos;
                case Joystick::Axis::U:    return joystickState.dwUpos;
                case Joystick::Axis::V:    return joystickState.dwVpos;
                case Joystick::Axis::PovX: return std::cos(AngleUI::degree(joystickState.dwPOV));
                case Joystick::Axis::PovY: return std::sin(AngleUI::degree(joystickState.dwPOV));
            }

            return 0;
        }

        JOYINFOEX JoystickImpl::getJoystickState(Uint8 joystick, DWORD flag)
        {
            JOYINFOEX joystickState;

            ZeroMemory(&joystickState, sizeof(JOYINFOEX));

            joystickState.dwSize  = sizeof(JOYINFOEX);
            joystickState.dwFlags = JOY_RETURNALL;

            if(!isConnected(joystick) || joyGetPosEx(joystick, &joystickState) != JOYERR_NOERROR)
            {
                ZeroMemory(&joystickState, sizeof(JOYINFOEX));
            }

            return joystickState;
        }
    }
}


