#include <Bull/Core/Exception/Expect.hpp>
#include <Bull/Core/Exception/InternalError.hpp>
#include <Bull/Core/Exception/InvalidParameter.hpp>
#include <Bull/Core/Exception/Throw.hpp>

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
        gl::genTextures(1, &m_id);

        Expect(m_id, Throw(InternalError, "Texture::Texture", "Failed to create the texture"));
    }

    Texture::~Texture()
    {
        gl::deleteTextures(1, &m_id);
    }

    void Texture::create(const Image& image)
    {
        create(image.getPixels(), image.getSize());
    }

    void Texture::create(const Size& size)
    {
        Expect(size.width > 0 && size.height > 0, Throw(InvalidParameter, "Texture::create", "Invalid texture size"));

        ensureContext();

        m_size = size;

        gl::bindTexture(GL_TEXTURE_2D, m_id);
        gl::texImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_size.width , m_size.height , 0, GL_RGBA, GL_UNSIGNED_BYTE, nullptr);
        gl::texParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, m_isSmooth ? GL_LINEAR : GL_NEAREST);
        gl::texParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, m_isSmooth ? GL_LINEAR : GL_NEAREST);
        gl::texParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, m_isRepeated ? GL_REPEAT : GL_CLAMP_TO_BORDER);
        gl::texParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, m_isRepeated ? GL_REPEAT : GL_CLAMP_TO_BORDER);
    }

    void Texture::create(const std::vector<Uint8>& pixels, const Size& size)
    {
        create(size);

        gl::bindTexture(GL_TEXTURE_2D, m_id);

        for(unsigned int i = 0; i < m_size.height ; i++)
        {
            gl::texSubImage2D(GL_TEXTURE_2D, 0, 0, i, m_size.width , 1, GL_RGBA, GL_UNSIGNED_BYTE, &pixels[m_size.width * (m_size.height - i - 1) * 4]);
        }

        gl::generateMipmap(GL_TEXTURE_2D);
    }

    bool Texture::isLoaded() const
    {
        int width, height;

        bind();

        gl::getTexParameteriv(GL_TEXTURE_2D, GL_TEXTURE_WIDTH, &width);
        gl::getTexParameteriv(GL_TEXTURE_2D, GL_TEXTURE_HEIGHT, &height);

        return width && height;
    }

    void Texture::bind() const
    {
        ensureContext();

        gl::bindTexture(GL_TEXTURE_2D, m_id);
    }

    void Texture::enableRepeat(bool enable)
    {
        m_isRepeated = enable;

        bind();

        gl::bindTexture(GL_TEXTURE_2D, m_id);
        gl::texParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, m_isRepeated ? GL_REPEAT : GL_CLAMP_TO_BORDER);
        gl::texParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, m_isRepeated ? GL_REPEAT : GL_CLAMP_TO_BORDER);
    }

    bool Texture::isEnableRepeat() const
    {
        return m_isRepeated;
    }

    void Texture::enableSmooth(bool enable)
    {
        m_isSmooth = enable;

        bind();

        gl::texParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, m_isSmooth ? GL_LINEAR : GL_NEAREST);
        gl::texParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, m_isSmooth ? GL_LINEAR : GL_NEAREST);
    }

    bool Texture::isEnableSmooth() const
    {
        return m_isSmooth;
    }

    Image Texture::getImage() const
    {
        Image image;
        std::vector<Uint8> pixels(m_size.width * m_size.height * 4);

        bind();

        gl::getTexImage(GL_TEXTURE_2D, 0, GL_RGBA, GL_UNSIGNED_BYTE, &pixels[0]);

        image.create(pixels, m_size);

        return image;
    }

    const Size& Texture::getSize() const
    {
        return m_size;
    }
}
