#include <bitset>

#include <Bull/Core/Hardware/Win32/JoystickImpl.hpp>

#include <Bull/Math/Angle.hpp> /// TODO: should not be here!

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
            JOYCAPS                infoCaps;

            BULL_ZERO_MEMORY(caps);

            if(joyGetDevCaps(id, &infoCaps, sizeof(JOYCAPS)) == JOYERR_NOERROR)
            {
                caps.name = infoCaps.szPname;

                caps.axes[JoystickAxis_X].exists    = true;
                caps.axes[JoystickAxis_Y].exists    = true;
                caps.axes[JoystickAxis_Z].exists    = infoCaps.wCaps & JOYCAPS_HASZ;
                caps.axes[JoystickAxis_R].exists    = infoCaps.wCaps & JOYCAPS_HASR;
                caps.axes[JoystickAxis_U].exists    = infoCaps.wCaps & JOYCAPS_HASU;
                caps.axes[JoystickAxis_V].exists    = infoCaps.wCaps & JOYCAPS_HASV;
                caps.axes[JoystickAxis_PovX].exists = infoCaps.wCaps & JOYCAPS_HASPOV;
                caps.axes[JoystickAxis_PovY].exists = infoCaps.wCaps & JOYCAPS_HASPOV;

                caps.axes[JoystickAxis_X].min    = infoCaps.wXmin;
                caps.axes[JoystickAxis_Y].min    = infoCaps.wYmin;
                caps.axes[JoystickAxis_Z].min    = infoCaps.wZmin;
                caps.axes[JoystickAxis_R].min    = infoCaps.wRmin;
                caps.axes[JoystickAxis_U].min    = infoCaps.wUmin;
                caps.axes[JoystickAxis_V].min    = infoCaps.wVmin;
                caps.axes[JoystickAxis_PovX].min = 90;
                caps.axes[JoystickAxis_PovY].min = 90;

                caps.axes[JoystickAxis_X].max    = infoCaps.wXmax;
                caps.axes[JoystickAxis_Y].max    = infoCaps.wYmax;
                caps.axes[JoystickAxis_Z].max    = infoCaps.wZmax;
                caps.axes[JoystickAxis_R].max    = infoCaps.wRmax;
                caps.axes[JoystickAxis_U].max    = infoCaps.wUmax;
                caps.axes[JoystickAxis_V].max    = infoCaps.wVmax;
                caps.axes[JoystickAxis_PovX].max = 9000;
                caps.axes[JoystickAxis_PovY].max = 9000;

                caps.countButtons = infoCaps.wNumButtons;
                caps.countAxes    = infoCaps.wNumAxes;
            }

            return caps;
        }

        bool JoystickImpl::isButtonPressed(unsigned int button, Uint8 joystick)
        {
            return std::bitset<Joystick::CountButton>(getJoystickState(joystick).dwButtons).test(button);
        }

        float JoystickImpl::getAxisPosition(JoystickAxis axis, Uint8 joystick)
        {
            JOYINFOEX joystickState = getJoystickState(joystick);

            switch(axis)
            {
                case JoystickAxis_X:    return joystickState.dwXpos;
                case JoystickAxis_Y:    return joystickState.dwYpos;
                case JoystickAxis_Z:    return joystickState.dwZpos;
                case JoystickAxis_R:    return joystickState.dwRpos;
                case JoystickAxis_U:    return joystickState.dwUpos;
                case JoystickAxis_V:    return joystickState.dwVpos;
                case JoystickAxis_PovX: return std::cos(AngleUI::degree(joystickState.dwPOV));
                case JoystickAxis_PovY: return std::sin(AngleUI::degree(joystickState.dwPOV));
            }

            return 0;
        }

        JOYINFOEX JoystickImpl::getJoystickState(Uint8 joystick, DWORD flag)
        {
            JOYINFOEX joystickState;

            BULL_ZERO_MEMORY(joystickState);

            joystickState.dwSize  = sizeof(JOYINFOEX);
            joystickState.dwFlags = flag;

            if(!isConnected(joystick) || joyGetPosEx(joystick, &joystickState) != JOYERR_NOERROR)
            {
                BULL_ZERO_MEMORY(joystickState);
            }

            return joystickState;
        }
    }
}


