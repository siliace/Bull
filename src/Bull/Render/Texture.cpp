#include <Bull/Render/Context/TextureStateShader.hpp>
#include <Bull/Render/Texture.hpp>

namespace Bull
{
    /*! \brief Bind a texture
     *
     * \param texture The texture to bind
     *
     */
    void Texture::bind(const Texture& texture)
    {
        gl::bindTexture(GL_TEXTURE_2D, texture.m_id);
    }

    /*! \brief Unbind any texture
     *
     */
    void Texture::unbind()
    {
        gl::bindTexture(GL_TEXTURE_2D, 0);
    }

    /*! \brief Default constructor
     *
     */
    Texture::Texture() :
        m_id(0),
        m_size(0, 0)
    {
        enableRepeat(false);
        enableSmooth(false);
    }

    /*! \brief Destructor
     *
     */
    Texture::~Texture()
    {
        if(m_id == 0)
        {
            gl::deleteTextures(1, &m_id);
        }
    }

    /*! \brief Create an empty texture
     *
     * \param width  The width of the texture to create
     * \param height The height of the texture to create
     *
     * \return Return true if the texture was created successfully, false otherwise
     *
     */
    bool Texture::create(unsigned int width, unsigned int height)
    {
        return create(Vector2UI(width, height));
    }

    /*! \brief Create an empty texture
     *
     * \param size The size of the texture to create
     *
     * \return Return true if the texture was created successfully, false otherwise
     *
     */
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

    /*! \brief Load a texture form a file
     *
     * \param path The path to the image to load
     *
     * \return Return true if the texture was loaded successfully, false otherwise
     *
     */
    bool Texture::loadFromPath(const String& path)
    {
        Image img;

        if(img.load(path))
        {
            return loadFromImage(img);
        }

        return false;
    }

    /*! \brief Load a texture form an image
     *
     * \param path The image to load
     *
     * \return Return true if the texture was loaded successfully, false otherwise
     *
     */
    bool Texture::loadFromImage(const Image& image)
    {
        return loadFromPixels(image.getPixels(), image.getSize());
    }

    /*! \brief Load a texture form a pixels array
     *
     * \param path The pixels array to load
     *
     * \return Return true if the texture was loaded successfully, false otherwise
     *
     */
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

    /*! \brief Enable or disable the texture repeat
     *
     * \param enable True to enable, false to disable
     *
     */
    void Texture::enableRepeat(bool enable)
    {
        TextureStateSaver saver;
        m_isRepeated = enable;

        gl::bindTexture(GL_TEXTURE_2D, m_id);
        gl::texParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, m_isRepeated ? GL_REPEAT : GL_CLAMP_TO_BORDER);
        gl::texParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, m_isRepeated ? GL_REPEAT : GL_CLAMP_TO_BORDER);
    }

    /*! \brief Check whether the texture repeat is enable
     *
     * \return Return true if the texture repeat is enable, false otherwise
     *
     */
    bool Texture::isEnableRepeat() const
    {
        return m_isRepeated;
    }

    /*! \brief Enable or disable the texture smooth
     *
     * \param enable True to enable, false to disable
     *
     */
    void Texture::enableSmooth(bool enable)
    {
        TextureStateSaver saver;
        m_isSmooth = enable;

        gl::bindTexture(GL_TEXTURE_2D, m_id);
        gl::texParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, m_isSmooth ? GL_LINEAR : GL_NEAREST);
        gl::texParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, m_isSmooth ? GL_LINEAR : GL_NEAREST);
    }

    /*! \brief Check whether the texture smooth is enable
     *
     * \return Return true if the texture smooth is enable, false otherwise
     *
     */
    bool Texture::isEnableSmooth() const
    {
        return m_isSmooth;
    }

    /*! \brief Get the size of the texture
     *
     * \return Return the size of the texture
     *
     */
    const Vector2UI& Texture::getSize() const
    {
        return m_size;
    }

    /*! \brief Download the texture from the VRAM
     *
     * \return Return return the image
     *
     */
    Image Texture::getImage() const
    {
        return getImage(RectangleUI(m_size));
    }

    /*! \brief Download the texture from the VRAM
     *
     * \param rectangle The rectangle to use to crop the texture
     *
     * \return Return return the image
     *
     */
    Image Texture::getImage(const RectangleUI& rectangle) const
    {
        if(m_id)
        {
            TextureStateSaver saver;
            std::vector<Uint8> pixels(m_size.x * m_size.y * 4);

            gl::bindTexture(GL_TEXTURE_2D, m_id);
            gl::getTexImage(GL_TEXTURE_2D, 0, GL_RGBA, GL_UNSIGNED_BYTE, &pixels[0]);

            return Image(pixels, m_size);
        }

        return Image();
    }

    /*! \brief Get the system handler
     *
     * \return Return the native system texture handler
     *
     */
    unsigned int Texture::getSystemHandler() const
    {
        return m_id;
    }
}
