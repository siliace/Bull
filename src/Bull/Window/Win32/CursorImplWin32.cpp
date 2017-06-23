#include <Bull/Window/Win32/CursorImplWin32.hpp>

namespace Bull
{
    namespace prv
    {
        CursorImplWin32::CursorImplWin32()
        {

        }

        CursorImplWin32::~CursorImplWin32()
        {

        }

        bool CursorImplWin32::loadFromSystem(Cursor::Type cursor)
        {

        }

        bool CursorImplWin32::loadFromImage(const Image& cursor, const Vector2UI& hotSpot)
        {

        }

        CursorHandler CursorImplWin32::getSystemHandler() const
        {
            return m_handler;
        }
    }
}