#include <Bull/Window/Cursor.hpp>
#include <Bull/Window/CursorImpl.hpp>

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
        if(image.getSize().x == 0 || image.getSize().y == 0)
        {
            return false;
        }

        return m_impl->create(image, hotSpot);
    }

    const std::unique_ptr<prv::CursorImpl>& Cursor::getImpl() const
    {
        return m_impl;
    }
}