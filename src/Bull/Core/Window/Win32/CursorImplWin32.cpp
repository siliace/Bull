#include <Bull/Core/Exception/InternalError.hpp>
#include <Bull/Core/Exception/Throw.hpp>
#include <Bull/Core/Window/Win32/CursorImplWin32.hpp>

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

        bool CursorImplWin32::create(CursorType cursor)
        {
            LPCSTR shape;

            destroy();

            switch(cursor)
            {
                case CursorType_Crosshair:  shape = IDC_CROSS;       break;
                case CursorType_Default:    shape = IDC_ARROW;       break;
                case CursorType_Hand:       shape = IDC_HAND;        break;
                case CursorType_Help:       shape = IDC_HELP;        break;
                case CursorType_Move:       shape = IDC_SIZEALL;     break;
                case CursorType_None:       shape = nullptr;         break;
                case CursorType_Pointer:    shape = IDC_HAND;        break;
                case CursorType_Progress:   shape = IDC_APPSTARTING; break;
                case CursorType_ResizeE:    shape = IDC_SIZEWE;      break;
                case CursorType_ResizeN:    shape = IDC_SIZENS;      break;
                case CursorType_ResizeNE:   shape = IDC_SIZENESW;    break;
                case CursorType_ResizeNW:   shape = IDC_SIZENWSE;    break;
                case CursorType_ResizeS:    shape = IDC_SIZENS;      break;
                case CursorType_ResizeSE:   shape = IDC_SIZENWSE;    break;
                case CursorType_ResizeSW:   shape = IDC_SIZENESW;    break;
                case CursorType_ResizeW:    shape = IDC_SIZEWE;      break;
                case CursorType_Text:       shape = IDC_IBEAM;       break;
                case CursorType_Wait:       shape = IDC_WAIT;        break;
                case CursorType_NotAllowed: shape = IDC_NO;          break;
                default: return false;
            }

            m_handler = CopyCursor(LoadCursor(nullptr, shape));

            if(!m_handler)
            {
                Throw(InternalError, "CursorImplWin32::create", "Failed to create cursor");
            }

            return true;
        }

        bool CursorImplWin32::create(const Image& cursor, const Size& hotSpot)
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