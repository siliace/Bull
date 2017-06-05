#include <X11/cursorfont.h>
#include <X11/Xutil.h>

#include <Bull/Window/Xlib/CursorImplXlib.hpp>

namespace Bull
{
    namespace prv
    {
        CursorImplXlib::CursorImplXlib() :
            m_cursor(XNone)
        {
            /// Nothing
        }

        CursorImplXlib::~CursorImplXlib()
        {
            destroy();
        }

        bool CursorImplXlib::loadFromSystem(Cursor::Type cursor)
        {
            unsigned int shape;

            destroy();

            switch(cursor)
            {
                case Cursor::Crosshair: shape = XC_crosshair;           break;
                case Cursor::Default:   shape = XC_cross;               break;
                case Cursor::Hand:      shape = XC_hand1;               break;
                case Cursor::Help:      shape = XC_question_arrow;      break;
                case Cursor::Move:      shape = XC_fleur;               break;
                case Cursor::None:      shape = XNone;                  break;
                case Cursor::Pointer:   shape = XC_hand1;               break;
                case Cursor::Progress:  shape = XC_watch;               break;
                case Cursor::ResizeE:   shape = XC_right_side;          break;
                case Cursor::ResizeN:   shape = XC_top_side;            break;
                case Cursor::ResizeNE:  shape = XC_top_right_corner;    break;
                case Cursor::ResizeNW:  shape = XC_top_left_corner;     break;
                case Cursor::ResizeS:   shape = XC_bottom_side;         break;
                case Cursor::ResizeSE:  shape = XC_bottom_right_corner; break;
                case Cursor::ResizeSW:  shape = XC_bottom_left_corner;  break;
                case Cursor::ResizeW:   shape = XC_left_side;           break;
                case Cursor::Text:      shape = XC_xterm;               break;
                case Cursor::Wait:      shape = XC_watch;               break;
                default: return false;
            }

            m_cursor = XCreateFontCursor(m_display, shape);

            return true;
        }

        bool CursorImplXlib::loadFromImage(const Image& cursor, const Vector2UI& hotSpot)
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
                XFreeCursor(m_display, m_cursor);
                m_cursor = XNone;
            }
        }
    }
}