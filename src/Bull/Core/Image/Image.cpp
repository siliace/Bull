#include <Bull/Core/Exception/InvalidParameter.hpp>
#include <Bull/Core/Image/Image.hpp>

namespace Bull
{
    void Image::create(const Size& size)
    {
        if(size.width < 0 || size.height < 0)
        {
            Throw(InvalidParameter, "Image::create", "Invalid image size");
        }

        m_size   = size;
        m_pixels = ByteArray(m_size.width * m_size.height * 4);
    }

    void Image::create(const ByteArray& pixels, const Size& size)
    {
        if(size.width < 0 || size.height < 0)
        {
            Throw(InvalidParameter, "Image::create", "Invalid image size");
        }

        std::size_t pixelsCount = size.width * size.height * 4;

        m_size   = size;
        m_pixels = pixels;

        if(m_pixels.getCapacity() != pixelsCount)
        {
            m_pixels.resize(pixelsCount);
        }
    }

    bool Image::isLoaded() const
    {
        return m_pixels.getCapacity() > 0 && m_size.width > 0 && m_size.height > 0;
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
