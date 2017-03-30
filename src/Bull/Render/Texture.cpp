#include <Bull/Render/OpenGL.hpp>
#include <Bull/Render/Texture.hpp>
#include <Bull/Render/TextureStateSaver.hpp>

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
        if(m_id == 0)
        {
            gl::deleteTextures(1, &m_id);
        }
    }

    bool Texture::create(unsigned int width, unsigned int height)
    {
        return create(Vector2UI(width, height));
    }

    bool Texture::create(const Vector2UI& size)
    {
        if(size.x > 0 && size.y > 0)
        {
            TextureStateSaver saver;
            m_size = size;

            if(m_id == 0)
            {
                GLuint texture = 0;
                gl::genTextures(1, &texture);
                m_id = static_cast<unsigned int>(texture);

                if(m_id == 0)
                {
                    return false;
                }
            }

            gl::bindTexture(GL_TEXTURE_2D, m_id);
            gl::texImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_size.x, m_size.y, 0, GL_RGBA, GL_UNSIGNED_BYTE, nullptr);
            gl::texParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, m_isSmooth ? GL_LINEAR : GL_NEAREST);
            gl::texParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, m_isSmooth ? GL_LINEAR : GL_NEAREST);
            gl::texParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, m_isRepeated ? GL_REPEAT : GL_CLAMP_TO_BORDER);
            gl::texParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, m_isRepeated ? GL_REPEAT : GL_CLAMP_TO_BORDER);

            return true;
        }

        return false;
    }

    bool Texture::loadFromPath(const Path& path)
    {
        Image img;

        if(img.loadFromPath(path))
        {
            return loadFromImage(img);
        }

        return false;
    }

    bool Texture::loadFromImage(const Image& image)
    {
        return loadFromPixels(image.getPixels(), image.getSize());
    }

    bool Texture::loadFromPixels(const std::vector<Uint8>& pixels, const Vector2UI& size)
    {
        if(create(size))
        {
            TextureStateSaver saver;
            gl::bindTexture(GL_TEXTURE_2D, m_id);

            for(unsigned int i = 0; i < m_size.y; i++)
            {
                const Uint8* pixelsPointer = &pixels[m_size.x * (m_size.y - i - 1) * 4];

                gl::texSubImage2D(GL_TEXTURE_2D, 0, 0, i, m_size.x, 1, GL_RGBA, GL_UNSIGNED_BYTE, pixelsPointer);
            }

            return true;
        }

        return false;
    }

    void Texture::bind(Uint8 sampler) const
    {
        gl::activeTexture(GL_TEXTURE0 + sampler);
        gl::bindTexture(GL_TEXTURE_2D, m_id);
    }

    void Texture::enableRepeat(bool enable)
    {
        m_isRepeated = enable;

        if(m_id)
        {
            TextureStateSaver saver;

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
            TextureStateSaver saver;

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

    const Vector2UI& Texture::getSize() const
    {
        return m_size;
    }

    Image Texture::getImage() const
    {
        return getImage(RectangleUI(m_size));
    }

    Image Texture::getImage(const RectangleUI& rectangle) const
    {
        if(m_id)
        {
            TextureStateSaver saver;
            std::vector<Uint8> pixels(m_size.x * m_size.y * 4);

            ensureContext();

            gl::bindTexture(GL_TEXTURE_2D, m_id);
            gl::getTexImage(GL_TEXTURE_2D, 0, GL_RGBA, GL_UNSIGNED_BYTE, &pixels[0]);

            return Image(pixels, m_size);
        }

        return Image();
    }

    unsigned int Texture::getSystemHandler() const
    {
        return m_id;
    }
}
