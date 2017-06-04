#include <Bull/Window/Cursor.hpp>
#include <Bull/Window/CursorImpl.hpp>

namespace Bull
{
    Cursor::Cursor() :
        m_impl(prv::CursorImpl::createInstance())
    {
        /// Nothing
    }

    Cursor::~Cursor()
    {
        /// Nothing
    }

    bool Cursor::loadFromSystem(Type cursor)
    {
        m_impl->loadFromSystem(cursor);
    }

    bool Cursor::loadFromImage(const Image& image, const Vector2UI& hotSpot)
    {
        if(image.getSize().x == 0 || image.getSize().y == 0)
        {
            return false;
        }

        return m_impl->loadFromImage(image, hotSpot);
    }

    const std::unique_ptr<prv::CursorImpl>& Cursor::getImpl() const
    {
        return m_impl;
    }
}