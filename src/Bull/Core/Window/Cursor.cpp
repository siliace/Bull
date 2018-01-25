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

    bool Cursor::create(const Image& image, const Size& hotSpot)
    {
        if(image.getSize().width && image.getSize().height)
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