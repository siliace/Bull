#include <Bull/Core/Window/Cursor.hpp>
#include <Bull/Core/Window/CursorImpl.hpp>

namespace Bull
{
    Cursor::Cursor() :
        m_impl(prv::CursorImpl::createInstance())
    {
        /// Nothing
    }

    Cursor::~Cursor() = default;

    bool Cursor::create(CursorType cursor)
    {
        return m_impl->create(cursor);
    }

    bool Cursor::create(const Image& image, const Vector2UI& hotSpot)
    {
        if(image.getSize().x() && image.getSize().y())
        {
            return m_impl->create(image, hotSpot);
        }

        return false;
    }

    const ImplPtr<prv::CursorImpl>& Cursor::getImpl() const
    {
        return m_impl;
    }
}