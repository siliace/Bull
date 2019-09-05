#ifndef BULL_RENDER_TEXTURE_IMAGETEXTURE_HPP
#define BULL_RENDER_TEXTURE_IMAGETEXTURE_HPP

#include <Bull/Core/Image/AbstractImage.hpp>

#include <Bull/Render/Texture/Texture.hpp>

namespace Bull
{
    class BULL_RENDER_API ImageTexture : public Texture, public AbstractImage
    {
    public:

        /** \brief Constructor
         *
         * \param pixelFormat The PixelFormat of the ImageTexture
         *
         */
        explicit ImageTexture(PixelFormat pixelFormat);

        /** \brief Constructor
         *
         * \param image The AbstractImage to copy
         *
         */
        explicit ImageTexture(const AbstractImage& image);

        /** \brief Constructor
         *
         * \param size        The Size of the ImageTexture
         * \param pixelFormat The PixelFormat of the ImageTexture
         *
         */
        ImageTexture(const Size<std::size_t>& size, PixelFormat pixelFormat);

        /** \brief Constructor
         *
         * \param pixels      Pixels of the ImageTexture
         * \param size        The Size of the ImageTexture
         * \param pixelFormat The PixelFormat of the ImageTexture
         *
         */
        ImageTexture(const ByteArray& pixels, const Size<std::size_t>& size, PixelFormat pixelFormat);

        /** \brief Constructor by movement semantic
         *
         * \param imageTexture The ImageTexture to move
         *
         */
        ImageTexture(ImageTexture&& imageTexture) noexcept;

        /** \brief Assignment operator by movement semantic
         *
         * \param imageTexture The ImageTexture to move
         *
         * \return This
         *
         */
        ImageTexture& operator=(ImageTexture&& imageTexture) noexcept;

        /** \brief Create the ImageTexture with a given Size
         *
         * \param size The Size
         *
         */
        void create(const Size<std::size_t>& size) override;

        /** \brief Create the ImageTexture from pixels
         *
         * \param pixels Pixels of the ImageTexture
         * \param size   The Size of the pixels
         *
         */
        void create(const ByteArray& pixels, const Size<std::size_t>& size) override;

        /** \brief Get the Size of the ImageTexture
         *
         * \return The Size
         *
         */
        Size<std::size_t> getSize() const override;

        /** \brief Get the pixels of the ImageTexture
         *
         * \return Pixels
         *
         */
        ByteArray getPixels() const override;

        /** \brief Get the PixelFormat of the ImageTexture
         *
         * \return The PixelFormat
         *
         */
        inline PixelFormat getPixelFormat() const override
        {
            return m_pixelFormat;
        }

    private:

        PixelFormat m_pixelFormat;
    };
}

#endif // BULL_RENDER_TEXTURE_IMAGETEXTURE_HPP
