#include <iostream>

#include <Bull/Core/Image/Image.hpp>

namespace Bull
{
    bool Image::create(const Vector2UI& size)
    {
        if(size.x() && size.y())
        {
            m_size   = size;
            m_pixels = ByteVector(m_size.x() * m_size.y() * 4);

            return true;
        }

        return false;
    }

    bool Image::create(const ByteVector& pixels, const Vector2UI& size)
    {
        if(size.x() && size.y())
        {
            std::size_t pixelsCount = size.x() * size.y() * 4;

            m_size   = size;
            m_pixels = pixels;

            if(m_pixels.getCapacity() != pixelsCount)
            {
                m_pixels.resize(pixelsCount);
            }

            return true;
        }

        return false;
    }

    Image& Image::fill(const Color& color)
    {
        for(std::size_t i = 0; i < m_pixels.getCapacity() / 4; i++)
        {
            m_pixels[i * 4 + 0] = color.red;
            m_pixels[i * 4 + 1] = color.green;
            m_pixels[i * 4 + 2] = color.blue;
            m_pixels[i * 4 + 3] = color.alpha;
        }

        return (*this);
    }

    Image& Image::flipVertically()
    {
        ByteVector pixels(m_size.x() * m_size.y() * 4);

        for(unsigned int i = 0; i < m_size.y() ; i++)
        {
            std::memcpy(&m_pixels[i * m_size.x()], &pixels[m_size.x() * (m_size.y() - i - 1) * 4], m_size.y());
        }

        m_pixels = pixels;

        return (*this);
    }

    Image& Image::flipHorizontally()
    {
        ByteVector pixels(m_size.x() * m_size.y() * 4);

        for(unsigned int i = 0; i < m_size.y() ; i++)
        {
            std::memcpy(&m_pixels[i * m_size.y()], &pixels[m_size.y() * (m_size.x() - i - 1) * 4], m_size.x());
        }

        m_pixels = pixels;

        return (*this);
    }

    const Vector2UI& Image::getSize() const
    {
        return m_size;
    }

    const ByteVector& Image::getPixels() const
    {
        return m_pixels;
    }
}
