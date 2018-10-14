#include <Bull/Core/Exception/InvalidParameter.hpp>
#include <Bull/Core/Image/Image.hpp>

namespace Bull
{
    Image::Image(const Size& size, PixelFormat pixelFormat)
    {
        create(size, pixelFormat);
    }

    Image::Image(const ByteArray& pixels, const Size& size, PixelFormat pixelFormat)
    {
        create(pixels, size, pixelFormat);
    }

    void Image::create(const Size& size, PixelFormat pixelFormat)
    {
        Expect(size.width > 0 && size.height > 0, Throw(InvalidParameter, "Image::create", "Invalid image size"));

        m_size = size;
        m_pixelFormat = pixelFormat;

        m_pixels.create(PixelFormatUtils::getImageByteCount(m_size, m_pixelFormat));
    }

    void Image::create(const ByteArray& pixels, const Size& size, PixelFormat pixelFormat)
    {
        Expect(size.width > 0 && size.height > 0, Throw(InvalidParameter, "Image::create", "Invalid image size"));

        m_size = size;
        m_pixels = pixels;
        m_pixelFormat = pixelFormat;

        std::size_t bytes = PixelFormatUtils::getImageByteCount(m_size, m_pixelFormat);

        if(m_pixels.getCapacity() != bytes)
        {
            m_pixels.resize(bytes);
        }
    }

    Size Image::getSize() const
    {
        return m_size;
    }

    ByteArray Image::getPixels() const
    {
        return m_pixels;
    }

    PixelFormat Image::getPixelFormat() const
    {
        return m_pixelFormat;
    }
}
