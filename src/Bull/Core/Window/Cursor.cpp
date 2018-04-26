#include <Bull/Core/Exception/InvalidParameter.hpp>
#include <Bull/Core/Exception/Throw.hpp>
#include <Bull/Core/Window/Cursor.hpp>
#include <Bull/Core/Window/CursorImpl.hpp>

namespace Bull
{
    Cursor::Cursor() :
        m_impl(prv::CursorImpl::createInstance())
    {
        /// Nothing
    }

    Cursor::Cursor(CursorType cursor)  :
        m_impl(prv::CursorImpl::createInstance())
    {
        create(cursor);
    }

    Cursor::Cursor(const Image& cursor, const Size& hotSpot) :
        m_impl(prv::CursorImpl::createInstance())
    {
        create(cursor, hotSpot);
    }

    Cursor::~Cursor() = default;

    void Cursor::create(CursorType cursor)
    {
        m_impl->create(cursor);
    }

    void Cursor::create(const Image& image, const Size& hotSpot)
    {
        if(image.getSize().width <= 0 || image.getSize().height <= 0)
        {
            Throw(InvalidParameter, "Cursor::create", "Can not create a Cursor with an Image of size zero or negative");
        }

        m_impl->create(image, hotSpot);
    }

    const prv::CursorImpl& Cursor::getImpl() const
    {
        return *m_impl;
    }
}