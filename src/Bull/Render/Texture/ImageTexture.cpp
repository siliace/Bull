#include <Bull/Render/Texture/ImageTexture.hpp>
#include <Bull/Render/Context/GlFunctions.hpp>

namespace Bull
{
    ImageTexture::ImageTexture(PixelFormat pixelFormat) :
        m_pixelFormat(pixelFormat)
    {
        /// Nothing
    }

    ImageTexture::ImageTexture(const AbstractImage& image) :
        m_pixelFormat(image.getPixelFormat())
    {
        create(image.getPixels(), image.getSize());
    }

    ImageTexture::ImageTexture(const Size<std::size_t>& size, PixelFormat pixelFormat) :
        m_pixelFormat(pixelFormat)
    {
        create(size);
    }

    ImageTexture::ImageTexture(const ByteArray& pixels, const Size<std::size_t>& size, PixelFormat pixelFormat) :
        m_pixelFormat(pixelFormat)
    {
        create(pixels, size);
    }

    ImageTexture::ImageTexture(ImageTexture&& imageTexture) noexcept :
        Texture(static_cast<Texture&&>(imageTexture))
    {
        std::swap(m_pixelFormat, imageTexture.m_pixelFormat);
    }

    ImageTexture& ImageTexture::operator=(ImageTexture&& imageTexture) noexcept
    {
        std::swap(m_pixelFormat, imageTexture.m_pixelFormat);

        Texture::operator=(static_cast<Texture&&>(imageTexture));

        return *this;
    }

    void ImageTexture::create(const Size<std::size_t>& size)
    {
        Texture::create(size, m_pixelFormat);
    }

    void ImageTexture::create(const ByteArray& pixels, const Size<std::size_t>& size)
    {
        Texture::create(size, m_pixelFormat);
        Texture::setPixels(0, 0, pixels, size, m_pixelFormat);

        gl::generateMipmap(GL_TEXTURE_2D);
    }

    Size<std::size_t> ImageTexture::getSize() const
    {
        return Texture::getSize();
    }

    ByteArray ImageTexture::getPixels() const
    {
        return Texture::getPixels(m_pixelFormat);
    }
}