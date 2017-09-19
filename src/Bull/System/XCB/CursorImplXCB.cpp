#include <Bull/System/XCB/CursorImplXCB.hpp>

namespace Bull
{
    namespace prv
    {
        CursorImplXCB::CursorImplXCB()
        {

        }

        CursorImplXCB::~CursorImplXCB()
        {

        }

        bool CursorImplXCB::loadFromSystem(Cursor::Type cursor)
        {

        }

        bool CursorImplXCB::loadFromImage(const Image& cursor, const Vector2UI& hotSpot)
        {

        }

        CursorHandler CursorImplXCB::getSystemHandler() const
        {
            return m_handler;
        }
    }
}