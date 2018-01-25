#ifndef BULL_RENDER_TEXTURE_TEXTURE_HPP
#define BULL_RENDER_TEXTURE_TEXTURE_HPP

#include <Bull/Core/Image/Image.hpp>

#include <Bull/Math/Polygon/Rectangle.hpp>
#include <Bull/Math/Vector/Vector2.hpp>

#include <Bull/Render/Context/ContextResource.hpp>

namespace Bull
{
    class BULL_RENDER_API Texture : public ContextResource, public AbstractImage
    {
    public:

        /*! \brief Get the maximum size of a Texture
         *
         * \return The size
         *
         */
        static unsigned int getMaximumSize();

    public:

        /*! \brief Default constructor
         *
         */
        Texture();

        /*! \brief Destructor
         *
         */
        ~Texture();

        /*! \brief Load a Texture form an Image
         *
         * \param image The Image to load
         *
         * \return True if the Texture was loaded successfully
         *
         */
        bool create(const Image& image);

        /*! \brief Create an empty Texture
         *
         * \param size The size of the Texture to create
         *
         * \return True if the Texture was created successfully
         *
         */
        bool create(const Vector2UI& size) override;

        /*! \brief Create a Texture
         *
         * \param pixels Pixels of the Texture
         * \param size   The size of the Texture
         *
         * \return True if the Texture was created successfully
         *
         */
        bool create(const ByteVector& pixels, const Vector2UI& size) override;

        /*! \brief Tell whether an Asset is loaded
         *
         * \return True if the Asset is loaded
         *
         */
        bool isLoaded() const override;

        /*! \brief Bind the Texture
         *
         */
        void bind() const;

        /*! \brief Enable or disable the Texture repeat
         *
         * \param enable True to enable, false to disable
         *
         */
        void enableRepeat(bool enable = true);

        /*! \brief Check whether the Texture repeat is enable
         *
         * \return Return true if the Texture repeat is enable, false otherwise
         *
         */
        bool isEnableRepeat() const;

        /*! \brief Enable or disable the Texture smooth
         *
         * \param enable True to enable, false to disable
         *
         */
        void enableSmooth(bool enable = true);

        /*! \brief Check whether the Texture smooth is enable
         *
         * \return Return true if the Texture smooth is enable, false otherwise
         *
         */
        bool isEnableSmooth() const;

        /*! \brief Download the Texture from the VRAM
         *
         * \return Return return the image
         *
         */
        Image getImage() const;

        /*! \brief Get the size of the Image
         *
         * \return The size
         *
         */
        const Vector2UI& getSize() const override;

    private:

        unsigned int m_id;
        Vector2UI    m_size;
        bool         m_isSmooth;
        bool         m_isRepeated;
    };
}

#endif // BULL_RENDER_TEXTURE_TEXTURE_HPP
