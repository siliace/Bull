#include <Bull/Core/Exception/InternalError.hpp>
#include <Bull/Core/Exception/InvalidParameter.hpp>

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
        m_isSmooth(false),
        m_isRepeated(false)
    {
        /// Nothing
    }

    Texture::Texture(const Image& image)
    {
        create(image);
    }

    Texture::Texture(const Size& size)
    {
        create(size);
    }

    Texture::Texture(const ByteArray& pixels, const Size& size)
    {
        create(pixels, size);
    }

    Texture::Texture(Texture&& right) noexcept
    {
        std::swap(m_id, right.m_id);
        std::swap(m_isSmooth, right.m_isSmooth);
        std::swap(m_isRepeated, right.m_isRepeated);
    }

    Texture::~Texture()
    {
        if(gl::isTexture(m_id))
        {
            gl::deleteTextures(1, &m_id);
        }
    }

    Texture& Texture::operator=(Texture&& right) noexcept
    {
        std::swap(m_id, right.m_id);
        std::swap(m_isSmooth, right.m_isSmooth);
        std::swap(m_isRepeated, right.m_isRepeated);

        return *this;
    }

    void Texture::create(const Image& image)
    {
        create(image.getPixels(), image.getSize());
    }

    void Texture::create(const Size& size)
    {
        Expect(size.width > 0 && size.height > 0, Throw(InvalidParameter, "Texture::create", "Invalid texture size"));

        ensureContext();

        if(!gl::isTexture(m_id))
        {
           gl::genTextures(1, &m_id);

            Expect(m_id, Throw(InternalError, "Texture::Texture", "Failed to create the texture"));
        }

        gl::bindTexture(GL_TEXTURE_2D, m_id);
        gl::texImage2D(GL_TEXTURE_2D, 0, GL_RGBA, size.width , size.height , 0, GL_RGBA, GL_UNSIGNED_BYTE, nullptr);
        gl::texParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, m_isSmooth ? GL_LINEAR : GL_NEAREST);
        gl::texParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, m_isSmooth ? GL_LINEAR : GL_NEAREST);
        gl::texParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, m_isRepeated ? GL_REPEAT : GL_CLAMP_TO_BORDER);
        gl::texParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, m_isRepeated ? GL_REPEAT : GL_CLAMP_TO_BORDER);
    }

    void Texture::create(const ByteArray& pixels, const Size& size)
    {
        create(size);

        gl::bindTexture(GL_TEXTURE_2D, m_id);

        for(unsigned int i = 0; i < size.height ; i++)
        {
            gl::texSubImage2D(GL_TEXTURE_2D, 0, 0, i, size.width , 1, GL_RGBA, GL_UNSIGNED_BYTE, &pixels[size.width * (size.height - i - 1) * 4]);
        }

        gl::generateMipmap(GL_TEXTURE_2D);
    }

    bool Texture::isLoaded() const
    {
        return gl::isTexture(m_id);
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
        return Image(getPixels(), getSize());
    }

    Size Texture::getSize() const
    {
        Size size;

        gl::getTexParameteriv(m_id, GL_TEXTURE_WIDTH, &size.width);
        gl::getTexParameteriv(m_id, GL_TEXTURE_WIDTH, &size.height);

        return size;
    }

    ByteArray Texture::getPixels() const
    {
        Size size = getSize();
        ByteArray pixels(size.width * size.height * 4);

        bind();

        gl::getTexImage(GL_TEXTURE_2D, 0, GL_RGBA, GL_UNSIGNED_BYTE, &pixels[0]);

        return pixels;
    }
}
