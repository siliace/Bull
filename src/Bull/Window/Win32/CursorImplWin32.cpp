#include <iostream>

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
                case Cursor::Hand:       shape = IDC_HAND;        break;
                case Cursor::Help:       shape = IDC_HELP;        break;
                case Cursor::None:       shape = nullptr;         break;
                case Cursor::Progress:   shape = IDC_APPSTARTING; break;
                case Cursor::Pointer:    shape = IDC_ARROW;       break;
                case Cursor::ResizeE:    shape = IDC_SIZE;        break;
                case Cursor::ResizeN:    shape = IDC_SIZE;        break;
                case Cursor::ResizeNE:   shape = IDC_SIZE;        break;
                case Cursor::ResizeNW:   shape = IDC_SIZE;        break;
                case Cursor::ResizeS:    shape = IDC_SIZE;        break;
                case Cursor::ResizeSE:   shape = IDC_SIZE;        break;
                case Cursor::ResizeSW:   shape = IDC_SIZE;        break;
                case Cursor::ResizeW:    shape = IDC_SIZE;        break;
                case Cursor::Text:       shape = IDC_IBEAM;       break;
                case Cursor::Wait:       shape = IDC_WAIT;        break;
                case Cursor::NotAllowed: shape = IDC_NO;          break;
                default: return false;
            }

            std::cout << GetLastError() << std::endl;

            HCURSOR handler = LoadCursor(GetModuleHandle(nullptr), shape);

            std::cout << GetLastError() << std::endl;

            m_handler = CopyCursor(handler);

            std::cout << GetLastError() << std::endl;

            if(!m_handler)
            {
                throw std::runtime_error("Failed to create cursor");
            }

            return true;
        }

        bool CursorImplWin32::loadFromImage(const Image& cursor, const Vector2UI& hotSpot)
        {

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