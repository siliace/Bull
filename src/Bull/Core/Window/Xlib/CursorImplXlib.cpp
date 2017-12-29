#include <X11/cursorfont.h>
#include <X11/Xutil.h>

#include <Bull/Core/Window/Xlib/CursorImplXlib.hpp>

namespace Bull
{
    namespace prv
    {
        CursorImplXlib::CursorImplXlib() :
            m_cursor(XNone),
            m_display(Display::get())
        {
            /// Nothing
        }

        CursorImplXlib::~CursorImplXlib()
        {
            destroy();
        }

        bool CursorImplXlib::create(CursorType cursor)
        {
            unsigned int shape;

            destroy();

            switch(cursor)
            {
                case CursorType_Crosshair: shape = XC_crosshair;           break;
                case CursorType_Default:   shape = XC_cross;               break;
                case CursorType_Hand:      shape = XC_hand1;               break;
                case CursorType_Help:      shape = XC_question_arrow;      break;
                case CursorType_Move:      shape = XC_fleur;               break;
                case CursorType_None:      shape = XNone;                  break;
                case CursorType_Pointer:   shape = XC_hand1;               break;
                case CursorType_Progress:  shape = XC_watch;               break;
                case CursorType_ResizeE:   shape = XC_right_side;          break;
                case CursorType_ResizeN:   shape = XC_top_side;            break;
                case CursorType_ResizeNE:  shape = XC_top_right_corner;    break;
                case CursorType_ResizeNW:  shape = XC_top_left_corner;     break;
                case CursorType_ResizeS:   shape = XC_bottom_side;         break;
                case CursorType_ResizeSE:  shape = XC_bottom_right_corner; break;
                case CursorType_ResizeSW:  shape = XC_bottom_left_corner;  break;
                case CursorType_ResizeW:   shape = XC_left_side;           break;
                case CursorType_Text:      shape = XC_xterm;               break;
                case CursorType_Wait:      shape = XC_watch;               break;
                default: return false;
            }

            m_cursor = XCreateFontCursor(m_display->getHandler(), shape);

            return true;
        }

        bool CursorImplXlib::create(const Image& cursor, const Vector2UI& hotSpot)
        {
            // Todo

            return false;
        }

        CursorHandler CursorImplXlib::getSystemHandler() const
        {
            return m_cursor;
        }

        void CursorImplXlib::destroy()
        {
            if(m_cursor != XNone)
            {
                XFreeCursor(m_display->getHandler(), m_cursor);
                m_cursor = XNone;
            }
        }
    }
}