#include <Bull/Render/Context/GlFunctions.hpp>
#include <Bull/Render/Texture/Texture.hpp>

namespace Bull
{
    unsigned int Texture::getMaximumSize()
    {
        int size;

        gl::getIntegerv(GL_MAX_TEXTURE_SIZE, &size);

        return static_cast<unsigned int>(size);
    }

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

    bool Texture::create(const Size& size)
    {
        if(size.width && size.height)
        {
            ensureContext();

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
            gl::texImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_size.width , m_size.height , 0, GL_RGBA, GL_UNSIGNED_BYTE, nullptr);
            gl::texParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, m_isSmooth ? GL_LINEAR : GL_NEAREST);
            gl::texParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, m_isSmooth ? GL_LINEAR : GL_NEAREST);
            gl::texParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, m_isRepeated ? GL_REPEAT : GL_CLAMP_TO_BORDER);
            gl::texParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, m_isRepeated ? GL_REPEAT : GL_CLAMP_TO_BORDER);

            return true;
        }

        return false;
    }

    bool Texture::create(const ByteArray& pixels, const Size& size)
    {
        if(create(size))
        {
            ensureContext();

            gl::bindTexture(GL_TEXTURE_2D, m_id);

            for(unsigned int i = 0; i < m_size.height ; i++)
            {
                gl::texSubImage2D(GL_TEXTURE_2D, 0, 0, i, m_size.width , 1, GL_RGBA, GL_UNSIGNED_BYTE, &pixels[m_size.width * (m_size.height - i - 1) * 4]);
            }

            gl::generateMipmap(GL_TEXTURE_2D);

            return true;
        }

        return false;
    }

    bool Texture::isLoaded() const
    {
        return gl::isTexture(m_id);
    }

    void Texture::bind() const
    {
        if(m_id)
        {
            ensureContext();

            gl::bindTexture(GL_TEXTURE_2D, m_id);
        }
    }

    void Texture::enableRepeat(bool enable)
    {
        m_isRepeated = enable;

        if(m_id)
        {
            ensureContext();

            gl::bindTexture(GL_TEXTURE_2D, m_id);
            gl::texParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, m_isRepeated ? GL_REPEAT : GL_CLAMP_TO_BORDER);
            gl::texParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, m_isRepeated ? GL_REPEAT : GL_CLAMP_TO_BORDER);
        }
    }

    bool Texture::isEnableRepeat() const
    {
        return m_isRepeated;
    }

    void Texture::enableSmooth(bool enable)
    {
        m_isSmooth = enable;

        if(m_id)
        {
            ensureContext();

            gl::bindTexture(GL_TEXTURE_2D, m_id);
            gl::texParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, m_isSmooth ? GL_LINEAR : GL_NEAREST);
            gl::texParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, m_isSmooth ? GL_LINEAR : GL_NEAREST);
        }
    }

    bool Texture::isEnableSmooth() const
    {
        return m_isSmooth;
    }

    Image Texture::getImage() const
    {
        if(m_id)
        {
            Image image;
            ByteArray pixels(m_size.width * m_size.height * 4);

            ensureContext();

            gl::bindTexture(GL_TEXTURE_2D, m_id);
            gl::getTexImage(GL_TEXTURE_2D, 0, GL_RGBA, GL_UNSIGNED_BYTE, &pixels[0]);

            if(image.create(pixels, m_size))
            {
                return image;
            }
        }

        return Image();
    }

    const Size& Texture::getSize() const
    {
        return m_size;
    }
}
