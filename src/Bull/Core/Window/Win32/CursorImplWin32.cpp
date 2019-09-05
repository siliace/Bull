#include <Bull/Core/Exception/InternalError.hpp>
#include <Bull/Core/Exception/LackOfImplementation.hpp>

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

        void CursorImplWin32::create(CursorType cursor)
        {
            LPCSTR shape = nullptr;

            destroy();

            switch(cursor)
            {
                case CursorType_Crosshair:
                    shape = IDC_CROSS;
                    break;
                case CursorType_Default:
                    shape = IDC_ARROW;
                    break;
                case CursorType_Hand:
                    shape = IDC_HAND;
                    break;
                case CursorType_Help:
                    shape = IDC_HELP;
                    break;
                case CursorType_Move:
                    shape = IDC_SIZEALL;
                    break;
                case CursorType_Pointer:
                    shape = IDC_HAND;
                    break;
                case CursorType_Progress:
                    shape = IDC_APPSTARTING;
                    break;
                case CursorType_ResizeE:
                    shape = IDC_SIZEWE;
                    break;
                case CursorType_ResizeN:
                    shape = IDC_SIZENS;
                    break;
                case CursorType_ResizeNE:
                    shape = IDC_SIZENESW;
                    break;
                case CursorType_ResizeNW:
                    shape = IDC_SIZENWSE;
                    break;
                case CursorType_ResizeS:
                    shape = IDC_SIZENS;
                    break;
                case CursorType_ResizeSE:
                    shape = IDC_SIZENWSE;
                    break;
                case CursorType_ResizeSW:
                    shape = IDC_SIZENESW;
                    break;
                case CursorType_ResizeW:
                    shape = IDC_SIZEWE;
                    break;
                case CursorType_Text:
                    shape = IDC_IBEAM;
                    break;
                case CursorType_Wait:
                    shape = IDC_WAIT;
                    break;
                case CursorType_NotAllowed:
                    shape = IDC_NO;
                    break;
            }

            m_handler = CopyCursor(LoadCursor(nullptr, shape));

            if(!m_handler)
            {
                Throw(InternalError, "Failed to create cursor");
            }
        }

        void CursorImplWin32::create(const Image& cursor, const Size<unsigned int>& hotSpot)
        {
            BITMAPV5HEADER header;
            BULL_ZERO_MEMORY(header);

            Size<LONG> size(cursor.getSize().getWidth(), cursor.getSize().getHeight());

            destroy();

            header.bV5Planes = 1;
            header.bV5BitCount = 32;
            header.bV5AlphaMask = 0xff000000;
            header.bV5RedMask = 0x00ff0000;
            header.bV5GreenMask = 0x0000ff00;
            header.bV5BlueMask = 0x000000ff;
            header.bV5Width = size.getWidth();
            header.bV5Height = -size.getHeight();
            header.bV5Compression = BI_BITFIELDS;
            header.bV5Size = sizeof(BITMAPV5HEADER);

            Uint8* bitmap = nullptr;

            HDC device = GetDC(nullptr);
            HBITMAP color = CreateDIBSection(
                    device,
                    reinterpret_cast<const BITMAPINFO*>(&header),
                    DIB_RGB_COLORS,
                    reinterpret_cast<void**>(&bitmap),
                    nullptr,
                    0
            );
            ReleaseDC(nullptr, device);

            if(!color)
            {
                Throw(InternalError, "Failed to create color bitmaps");
            }

            std::memcpy(bitmap, cursor.getPixels().getBuffer(), size.getWidth() * size.getHeight() * 4);

            /// Create a dummy mask required in the ICONINFO by CreateIconIndirect
            HBITMAP mask = CreateBitmap(size.getWidth(), size.getHeight(), 1, 1, nullptr);

            if(!mask)
            {
                DeleteObject(color);

                Throw(InternalError, "Failed to create mask bitmaps");
            }

            ICONINFO iconInfo;
            BULL_ZERO_MEMORY(iconInfo);

            iconInfo.hbmMask = mask;
            iconInfo.hbmColor = color;
            iconInfo.fIcon = FALSE;
            iconInfo.xHotspot = hotSpot.getWidth();
            iconInfo.yHotspot = hotSpot.getHeight();

            m_handler = CreateIconIndirect(&iconInfo);

            /// These have been copied into m_handler
            DeleteObject(mask);
            DeleteObject(color);

            Expect(m_handler, Throw(InternalError, "Failed to create cursor from Image"));
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