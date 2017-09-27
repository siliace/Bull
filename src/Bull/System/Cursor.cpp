#include <Bull/System/Cursor.hpp>
#include <Bull/System/CursorImpl.hpp>

namespace Bull
{
    Cursor::Cursor() :
        m_impl(prv::CursorImpl::createInstance())
    {
        /// Nothing
    }

    Cursor::~Cursor() = default;

    bool Cursor::create(Type cursor)
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

    const std::unique_ptr<prv::CursorImpl>& Cursor::getImpl() const
    {
        return m_impl;
    }
}