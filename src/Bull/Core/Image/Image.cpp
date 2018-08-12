#include <Bull/Core/Exception/InvalidParameter.hpp>
#include <Bull/Core/Image/Image.hpp>

namespace Bull
{
    void Image::create(const Size& size)
    {
        Expect(size.width > 0 && size.height > 0, Throw(InvalidParameter, "Image::create", "Invalid image size"));

        m_size   = size;
        m_pixels = std::vector<Uint8>(m_size.width * m_size.height * 4);
    }

    void Image::create(const std::vector<Uint8>& pixels, const Size& size)
    {
        Expect(size.width > 0 && size.height > 0, Throw(InvalidParameter, "Image::create", "Invalid image size"));

        std::size_t pixelsCount = size.width * size.height * 4;

        m_size   = size;
        m_pixels = pixels;

        if(m_pixels.capacity() != pixelsCount)
        {
            m_pixels.resize(pixelsCount);
        }
    }

    bool Image::isLoaded() const
    {
        return m_pixels.capacity() > 0 && m_size.width > 0 && m_size.height > 0;
    }

    Image& Image::fill(const Color& color)
    {
        for(std::size_t i = 0; i < m_pixels.capacity() / 4; i++)
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

    const std::vector<Uint8>& Image::getPixels() const
    {
        return m_pixels;
    }
}
