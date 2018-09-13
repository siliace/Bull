#ifndef BULL_RENDER_TEXTURE_TEXTURE_HPP
#define BULL_RENDER_TEXTURE_TEXTURE_HPP

#include <Bull/Core/Assets/Asset.hpp>
#include <Bull/Core/Image/Image.hpp>
#include <Bull/Core/Pattern/NonCopyable.hpp>

#include <Bull/Math/Polygon/Rectangle.hpp>
#include <Bull/Math/Vector/Vector2.hpp>

#include <Bull/Render/Context/ContextResource.hpp>

namespace Bull
{
    class BULL_RENDER_API Texture : public ContextResource, public NonCopyable, public AbstractImage, public Asset
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

        /*! \brief Constructor
         *
         * \param image The image to load
         *
         */
        explicit Texture(const Image& image);

        /*! \brief Constructor
         *
         * \param size The size of the Texture
         *
         */
        explicit Texture(const Size& size, PixelFormat pixelFormat = PixelFormat_Rgb8Alpha8);

        /*! \brief Constructor
         *
         * \param pixels Pixels of the Texture
         * \param size   The size of the Texture
         *
         */
        explicit Texture(const ByteArray& pixels, const Size& size, PixelFormat pixelFormat = PixelFormat_Rgb8Alpha8);

        /*! \brief Constructor by movement
         *
         * \param right The Texture to move
         *
         */
        Texture(Texture&& right) noexcept;

        /*! \brief Destructor
         *
         */
        ~Texture();

        /*! \brief Basic assignment operator by movement
         *
         * \param right The Texture to move
         *
         * \return This
         *
         */
        Texture& operator=(Texture&& right) noexcept;

        /*! \brief Load a Texture form an Image
         *
         * \param image The Image to load
         *
         */
        void create(const Image& image);

        /*! \brief Create an empty Texture
         *
         * \param size The size of the Texture to create
         *
         */
        void create(const Size& size, PixelFormat pixelFormat = PixelFormat_Rgb8Alpha8) override;

        /*! \brief Create a Texture
         *
         * \param pixels Pixels of the Texture
         * \param size   The size of the Texture
         *
         */
        void create(const ByteArray& pixels, const Size& size, PixelFormat pixelFormat = PixelFormat_Rgb8Alpha8) override;

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
        Size getSize() const override;

        /*! \brief Get pixels of the Texture
         *
         * \return Pixels
         *
         */
        ByteArray getPixels() const override;

        /*! \brief Get the PixelFormat used by the Texture
         *
         * \return The PixelFormat
         *
         */
        PixelFormat getPixelFormat() const override;

    private:

        unsigned int m_id;
        bool         m_isSmooth;
        bool         m_isRepeated;
        PixelFormat  m_pixelFormat;
    };
}

#endif // BULL_RENDER_TEXTURE_TEXTURE_HPP
