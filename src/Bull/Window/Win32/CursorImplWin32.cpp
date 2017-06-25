#include <Bull/Window/Win32/CursorImplWin32.hpp>

namespace Bull
{
    namespace prv
    {
        CursorImplWin32::CursorImplWin32() :
            m_handler(nullptr)
        {
            /// Nothing
        }

        CursorImplWin32::~CursorImplWin32()
        {
            destroy();
        }

        bool CursorImplWin32::loadFromSystem(Cursor::Type cursor)
        {
            LPCSTR shape;

            destroy();

            switch(cursor)
            {
                case Cursor::Crosshair:  shape = IDC_CROSS;       break;
                case Cursor::Default:    shape = IDC_ARROW;       break;
                case Cursor::Hand:       shape = IDC_HAND;        break;
                case Cursor::Help:       shape = IDC_HELP;        break;
                case Cursor::Move:       shape = IDC_SIZEALL;     break;
                case Cursor::None:       shape = nullptr;         break;
                case Cursor::Pointer:    shape = IDC_HAND;        break;
                case Cursor::Progress:   shape = IDC_APPSTARTING; break;
                case Cursor::ResizeE:    shape = IDC_SIZEWE;      break;
                case Cursor::ResizeN:    shape = IDC_SIZENS;      break;
                case Cursor::ResizeNE:   shape = IDC_SIZENESW;    break;
                case Cursor::ResizeNW:   shape = IDC_SIZENWSE;    break;
                case Cursor::ResizeS:    shape = IDC_SIZENS;      break;
                case Cursor::ResizeSE:   shape = IDC_SIZENWSE;    break;
                case Cursor::ResizeSW:   shape = IDC_SIZENESW;    break;
                case Cursor::ResizeW:    shape = IDC_SIZEWE;      break;
                case Cursor::Text:       shape = IDC_IBEAM;       break;
                case Cursor::Wait:       shape = IDC_WAIT;        break;
                case Cursor::NotAllowed: shape = IDC_NO;          break;
                default: return false;
            }

            m_handler = CopyCursor(LoadCursor(nullptr, shape));

            if(!m_handler)
            {
                throw std::runtime_error("Failed to create cursor");
            }

            return true;
        }

        bool CursorImplWin32::loadFromImage(const Image& cursor, const Vector2UI& hotSpot)
        {
            return false;
        }

        CursorHandler CursorImplWin32::getSystemHandler() const
        {
            return m_handler;
        }

        void CursorImplWin32::destroy()
        {
            if(m_handler)
            {
                DestroyCursor(m_handler);
                m_handler = nullptr;
            }
        }
    }
}