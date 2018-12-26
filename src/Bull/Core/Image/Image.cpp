#include <Bull/Core/Exception/InvalidParameter.hpp>
#include <Bull/Core/Image/Image.hpp>
#include <Bull/Core/Image/PixelFormatUtils.hpp>

namespace Bull
{
    Image::Image(PixelFormat pixelFormat) :
        m_pixelFormat(pixelFormat)
    {
        /// Nothing
    }

    Image::Image(const AbstractImage::Size& size, PixelFormat pixelFormat) :
        m_pixelFormat(pixelFormat)
    {
        create(size);
    }

    Image::Image(const ByteArray& pixels, const Size& size, PixelFormat pixelFormat) :
        m_pixelFormat(pixelFormat)
    {
        create(pixels, size);
    }

    void Image::create(const Size& size)
    {
        Expect(size.width > 0 && size.height > 0, Throw(InvalidParameter, "Invalid image size"));

        m_size = size;

        m_pixels.create(PixelFormatUtils::getImageByteCount(m_size, m_pixelFormat));
    }

    void Image::create(const ByteArray& pixels, const Size& size)
    {
        Expect(size.width > 0 && size.height > 0, Throw(InvalidParameter, "Invalid image size"));

        m_size = size;
        m_pixels = pixels;

        std::size_t bytes = PixelFormatUtils::getImageByteCount(m_size, m_pixelFormat);

        if(m_pixels.getCapacity() != bytes)
        {
            m_pixels.resize(bytes);
        }
    }

    AbstractImage::Size Image::getSize() const
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
