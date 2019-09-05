#include <X11/cursorfont.h>
#include <X11/Xutil.h>

#include <Bull/Core/Exception/InternalError.hpp>
#include <Bull/Core/Exception/LackOfImplementation.hpp>
#include <Bull/Core/Window/Xlib/CursorImplXlib.hpp>


namespace Bull
{
    namespace prv
    {
        CursorImplXlib::CursorImplXlib() :
                m_handler(XNone),
                m_display(Display::getInstance())
        {
            /// Nothing
        }

        CursorImplXlib::~CursorImplXlib()
        {
            destroy();
        }

        void CursorImplXlib::create(CursorType cursor)
        {
            unsigned int shape = XNone;

            destroy();

            switch(cursor)
            {
                case CursorType_Crosshair:
                    shape = XC_crosshair;
                    break;
                case CursorType_Default:
                    shape = XC_cross;
                    break;
                case CursorType_Hand:
                    shape = XC_hand1;
                    break;
                case CursorType_Help:
                    shape = XC_question_arrow;
                    break;
                case CursorType_Move:
                    shape = XC_fleur;
                    break;
                case CursorType_Pointer:
                    shape = XC_hand1;
                    break;
                case CursorType_Progress:
                    shape = XC_watch;
                    break;
                case CursorType_ResizeE:
                    shape = XC_right_side;
                    break;
                case CursorType_ResizeN:
                    shape = XC_top_side;
                    break;
                case CursorType_ResizeNE:
                    shape = XC_top_right_corner;
                    break;
                case CursorType_ResizeNW:
                    shape = XC_top_left_corner;
                    break;
                case CursorType_ResizeS:
                    shape = XC_bottom_side;
                    break;
                case CursorType_ResizeSE:
                    shape = XC_bottom_right_corner;
                    break;
                case CursorType_ResizeSW:
                    shape = XC_bottom_left_corner;
                    break;
                case CursorType_ResizeW:
                    shape = XC_left_side;
                    break;
                case CursorType_Text:
                    shape = XC_xterm;
                    break;
                case CursorType_Wait:
                    shape = XC_watch;
                    break;
            }

            m_handler = XCreateFontCursor(m_display.getHandler(), shape);

            Expect(m_handler, Throw(InternalError, "Failed to create cursor"));
        }

        void CursorImplXlib::create(const Image& cursor, const Size<unsigned int>& hotSpot)
        {
            Throw(LackOfImplementation, "Unimplemented method");
        }

        CursorHandler CursorImplXlib::getSystemHandler() const
        {
            return m_handler;
        }

        void CursorImplXlib::destroy()
        {
            if(m_handler != XNone)
            {
                XFreeCursor(m_display.getHandler(), m_handler);
                m_handler = XNone;
            }
        }
    }
}