#include <Bull/Core/Image/Image.hpp>

namespace Bull
{
    bool Image::create(const Vector2UI& size)
    {
        if(size.x() && size.y())
        {
            m_size   = size;
            m_pixels = ByteArray(m_size.x() * m_size.y() * 4);

            return true;
        }

        return false;
    }

    bool Image::create(const ByteArray& pixels, const Vector2UI& size)
    {
        if(size.x() && size.y() && pixels.getCapacity() == size.x() * size.y() * 4)
        {
            m_size   = size;
            m_pixels = pixels;

            return true;
        }

        return false;
    }

    const Vector2UI& Image::getSize() const
    {
        return m_size;
    }

    const ByteArray& Image::getPixels() const
    {
        return m_pixels;
    }
}
