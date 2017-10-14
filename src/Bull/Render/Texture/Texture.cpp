#include <Bull/Render/OpenGL.hpp>
#include <Bull/Render/Texture/Texture.hpp>

namespace Bull
{
    Texture::Texture() :
        m_id(0),
        m_size(0, 0),
        m_isSmooth(false),
        m_isRepeated(false)
    {
        /// Nothing
    }

    Texture::~Texture()
    {
        if(m_id != 0)
        {
            gl::deleteTextures(1, &m_id);
        }
    }

    bool Texture::create(const Image& image)
    {
        return create(image.getPixels(), image.getSize());
    }

    bool Texture::create(const Vector2UI& size)
    {
        if(size.x()  > 0 && size.y()  > 0)
        {
            m_size = size;

            if(!m_id)
            {
                gl::genTextures(1, &m_id);

                if(!m_id)
                {
                    return false;
                }
            }

            gl::bindTexture(GL_TEXTURE_2D, m_id);
            gl::texImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_size.x() , m_size.y() , 0, GL_RGBA, GL_UNSIGNED_BYTE, nullptr);
            gl::texParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, m_isSmooth ? GL_LINEAR : GL_NEAREST);
            gl::texParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, m_isSmooth ? GL_LINEAR : GL_NEAREST);
            gl::texParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, m_isRepeated ? GL_REPEAT : GL_CLAMP_TO_BORDER);
            gl::texParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, m_isRepeated ? GL_REPEAT : GL_CLAMP_TO_BORDER);

            return true;
        }

        return false;
    }

    bool Texture::create(const ByteArray& pixels, const Vector2UI& size)
    {
        if(create(size))
        {
            const ByteArray& pixels = pixels;

            gl::bindTexture(GL_TEXTURE_2D, m_id);

            for(unsigned int i = 0; i < m_size.y() ; i++)
            {
                gl::texSubImage2D(GL_TEXTURE_2D, 0, 0, i, m_size.x() , 1, GL_RGBA, GL_UNSIGNED_BYTE, &pixels[m_size.x()  * (m_size.y()  - i - 1) * 4]);
            }

            return true;
        }

        return false;
    }

    bool Texture::loadFromPath(const Path& path, const ImageParameters& parameters)
    {
        Image image;

        return image.loadFromPath(path) && create(image);
    }

    bool Texture::loadFromStream(InStream& stream, const ImageParameters& parameters)
    {
        Image image;

        return image.loadFromStream(stream) && create(image);
    }

    bool Texture::loadFromMemory(const void* data, Index length, const ImageParameters& parameters)
    {
        Image image;

        return image.loadFromMemory(data, length) && create(image);
    }

    bool Texture::saveToPath(const Path& path, const ImageParameters& parameters) const
    {
        return getImage().saveToPath(path, parameters);
    }

    bool Texture::saveToStream(OutStream& stream, const ImageParameters& parameters) const
    {
        return getImage().saveToStream(stream, parameters);
    }

    bool Texture::saveToMemory(void* data, Index length, const ImageParameters& parameters) const
    {
        return getImage().saveToMemory(data, length, parameters);
    }

    void Texture::bind() const
    {
        if(m_id)
        {
            gl::bindTexture(GL_TEXTURE_2D, m_id);
        }
    }

    void Texture::enableRepeat(bool enable)
    {
        m_isRepeated = enable;

        if(m_id)
        {
            gl::bindTexture(GL_TEXTURE_2D, m_id);
            gl::texParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, m_isRepeated ? GL_REPEAT : GL_CLAMP_TO_BORDER);
            gl::texParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, m_isRepeated ? GL_REPEAT : GL_CLAMP_TO_BORDER);
        }
    }

    void Texture::enableSmooth(bool enable)
    {
        m_isSmooth = enable;

        if(m_id)
        {
            gl::bindTexture(GL_TEXTURE_2D, m_id);
            gl::texParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, m_isSmooth ? GL_LINEAR : GL_NEAREST);
            gl::texParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, m_isSmooth ? GL_LINEAR : GL_NEAREST);
        }
    }

    Image Texture::getImage() const
    {
        if(m_id)
        {
            Image image;
            ByteArray pixels(m_size.x()  * m_size.y()  * 4);

            gl::bindTexture(GL_TEXTURE_2D, m_id);
            gl::getTexImage(GL_TEXTURE_2D, 0, GL_RGBA, GL_UNSIGNED_BYTE, &pixels[0]);

            if(image.create(pixels, m_size))
            {
                return image;
            }
        }

        return Image();
    }
}
