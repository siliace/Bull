#include <Bull/Core/Image/Image.hpp>

namespace Bull
{
    bool Image::create(const Size& size)
    {
        if(size.width && size.height)
        {
            m_size   = size;
            m_pixels = ByteArray(m_size.width * m_size.height * 4);

            return true;
        }

        return false;
    }

    bool Image::create(const ByteArray& pixels, const Size& size)
    {
        if(size.width && size.height)
        {
            std::size_t pixelsCount = size.width * size.height * 4;

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

    bool Image::isLoaded() const
    {
        return m_pixels.getCapacity() > 0;
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

    const Size& Image::getSize() const
    {
        return m_size;
    }

    const ByteArray& Image::getPixels() const
    {
        return m_pixels;
    }
}
