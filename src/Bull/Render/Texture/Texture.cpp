#include <Bull/Core/Exception/InternalError.hpp>
#include <Bull/Core/Exception/InvalidParameter.hpp>
#include <Bull/Core/Exception/LogicError.hpp>
#include <Bull/Core/Memory/ByteArray.hpp>
#include <Bull/Core/Utility/Size.hpp>

#include <Bull/Render/Texture/Texture.hpp>
#include <Bull/Render/Context/GlFunctions.hpp>

namespace Bull
{
    namespace
    {
        GLenum convertInternalFormat(PixelFormat pixelFormat)
        {
            switch(pixelFormat)
            {
                case PixelFormat_Rgb8:            return GL_RGB;
                case PixelFormat_Rgb8Alpha8:      return GL_RGBA;
                case PixelFormat_Depth16:         return GL_DEPTH_COMPONENT16;
                case PixelFormat_Depth24:         return GL_DEPTH_COMPONENT24;
                case PixelFormat_Depth32:         return GL_DEPTH_COMPONENT32;
                case PixelFormat_Stencil1:        return GL_STENCIL_INDEX1;
                case PixelFormat_Stencil4:        return GL_STENCIL_INDEX4;
                case PixelFormat_Stencil8:        return GL_STENCIL_INDEX8;
                case PixelFormat_Stencil16:       return GL_STENCIL_INDEX16;
                case PixelFormat_Depth24Stencil8: return GL_DEPTH24_STENCIL8;
            }

            return 0;
        }

        GLenum convertFormat(PixelFormat pixelFormat)
        {
            switch(pixelFormat)
            {
                case PixelFormat_Rgb8:            return GL_RGB;
                case PixelFormat_Rgb8Alpha8:      return GL_RGBA;
                case PixelFormat_Depth16:         return GL_DEPTH_COMPONENT;
                case PixelFormat_Depth24:         return GL_DEPTH_COMPONENT;
                case PixelFormat_Depth32:         return GL_DEPTH_COMPONENT;
                case PixelFormat_Stencil1:        return GL_STENCIL_INDEX;
                case PixelFormat_Stencil4:        return GL_STENCIL_INDEX;
                case PixelFormat_Stencil8:        return GL_STENCIL_INDEX;
                case PixelFormat_Stencil16:       return GL_STENCIL_INDEX;
                case PixelFormat_Depth24Stencil8: return GL_DEPTH_STENCIL;
            }

            return 0;
        }

        GLenum convertDataType(PixelFormat pixelFormat)
        {
            switch(pixelFormat)
            {
                case PixelFormat_Rgb8:            return GL_UNSIGNED_BYTE;
                case PixelFormat_Rgb8Alpha8:      return GL_UNSIGNED_BYTE;
                case PixelFormat_Depth16:         return GL_UNSIGNED_SHORT;
                case PixelFormat_Depth24:         return GL_UNSIGNED_INT;
                case PixelFormat_Depth32:         return GL_UNSIGNED_INT;
                case PixelFormat_Stencil1:        return GL_UNSIGNED_BYTE;
                case PixelFormat_Stencil4:        return GL_UNSIGNED_BYTE;
                case PixelFormat_Stencil8:        return GL_UNSIGNED_BYTE;
                case PixelFormat_Stencil16:       return GL_UNSIGNED_SHORT;
                case PixelFormat_Depth24Stencil8: return GL_UNSIGNED_INT_24_8;
            }

            return 0;
        }
    }

    void Texture::bind(const Texture& texture)
    {
        Expect(texture.isValid(), Throw(InvalidParameter, "Texture::bind", "Invalid texture"));

        gl::bindTexture(GL_TEXTURE_2D, texture.getSystemHandle());
    }

    void Texture::unbind()
    {
        gl::bindTexture(GL_TEXTURE_2D, 0);
    }

    Texture::Texture() :
        m_handle(0)
    {
        /// Nothing
    }

    Texture::Texture(Texture&& texture) noexcept
    {
        std::swap(m_handle, texture.m_handle);
    }

    Texture& Texture::operator=(Texture&& texture) noexcept
    {
        std::swap(m_handle, texture.m_handle);

        return *this;
    }

    Texture::~Texture()
    {
        if(isValid())
        {
            gl::deleteTextures(1, &m_handle);
        }
    }

    bool Texture::isValid() const
    {
        return gl::isTexture(m_handle);
    }

    Size Texture::getSize() const
    {
        Size size;

        gl::bindTexture(GL_TEXTURE_2D, m_handle);
        gl::getTexParameteriv(GL_TEXTURE_2D, GL_TEXTURE_WIDTH, &size.width);
        gl::getTexParameteriv(GL_TEXTURE_2D, GL_TEXTURE_HEIGHT, &size.height);

        return size;
    }

    void Texture::create(const Size& size, PixelFormat pixelFormat)
    {
        Expect(size.width > 0 && size.height > 0, Throw(InvalidParameter, "Texture::create", "Invalid texture size"));

        if(!isValid())
        {
            gl::genTextures(1, &m_handle);

            Expect(m_handle, Throw(InternalError, "Texture::create", "Failed to create texture"));
        }

        gl::bindTexture(GL_TEXTURE_2D, m_handle);
        gl::texImage2D(GL_TEXTURE_2D, 0, convertInternalFormat(pixelFormat), size.width, size.height, 0, convertFormat(pixelFormat), convertDataType(pixelFormat), nullptr);
    }

    void Texture::setPixels(unsigned int xOffset, unsigned int yOffset, const ByteArray& pixels, const Size& size, PixelFormat pixelFormat)
    {
        Expect(isValid(), Throw(LogicError, "Texture::setPixels", "Invalid texture"));

        gl::bindTexture(GL_TEXTURE_2D, m_handle);
        gl::texSubImage2D(GL_TEXTURE_2D, 0, xOffset, yOffset, size.width, size.height, convertFormat(pixelFormat), convertDataType(pixelFormat), pixels.getBuffer());
    }
}