#ifndef BULL_RENDER_TEXTURE_TEXTURE_HPP
#define BULL_RENDER_TEXTURE_TEXTURE_HPP

#include <Bull/Core/Image/PixelFormat.hpp>
#include <Bull/Core/Pattern/NonCopyable.hpp>
#include <Bull/Core/Utility/Size.hpp>

#include <Bull/Render/Context/ContextResource.hpp>

namespace Bull
{
    class ByteArray;

    class FrameBuffer;

    class BULL_RENDER_API Texture : public ContextResource, public NonCopyable
    {
    public:

        /** \brief Bind a Texture into the active Context
         *
         * \param texture The texture to bind
         *
         */
        static void bind(const Texture& texture);

        /** \brief Unbind any bound Texture
         *
         */
        static void unbind();

    public:

        /** \brief Default constructor
         *
         */
        Texture();

        /** \brief Constructor by movement semantic
         *
         * \param texture The Texture to move
         *
         */
        Texture(Texture&& texture) noexcept;

        /** \brief Destructor
         *
         */
        virtual ~Texture();

        /** \brief Assignment operator by movement semantic
         *
         * \param texture The Texture to move
         *
         * \return This
         *
         */
        Texture& operator=(Texture&& texture) noexcept;

        /** \brief Create the Texture with a given Size
         *
         * \param size The Size
         *
         */
        virtual void create(const Size<std::size_t>& size) = 0;

        /** \brief Create the Texture of a given Size with a PixelFormat
         *
         * \param size        The Size
         * \param pixelFormat The PixelFormat
         *
         */
        void create(const Size<std::size_t>& size, PixelFormat pixelFormat);

        /** \brief Set pixels of the Texture
         *
         * \param xOffset     The offset of the pixels on the abscissa axis
         * \param yOffset     The offset of the pixels on the ordinate axis
         * \param pixels      The pixels to set
         * \param size        The size of the pixels
         * \param pixelFormat The PixelFormat of the pixels
         *
         */
        void setPixels(unsigned int xOffset, unsigned int yOffset, const ByteArray& pixels, const Size<std::size_t>& size, PixelFormat pixelFormat);

        /** \brief Tell whether the Texture is valid (i.e has been created)
         *
         * \return True if valid
         *
         */
        bool isValid() const;

        /** \brief Get the Size of the Texture
         *
         * \return The Size
         *
         */
        Size<std::size_t> getSize() const;

        /** \brief Get the pixels of the Texture
         *
         * \return Pixels
         *
         */
        ByteArray getPixels(PixelFormat pixelFormat) const;

        /** \brief Get the handle of the Texture
         *
         * \return The handle
         *
         */
        unsigned int getSystemHandle() const;

    private:

        Size<std::size_t> m_size; /**< The size of the Texture */
        unsigned int m_handle; /**< The handle of the Texture into the VRAM */
    };
}

#endif // BULL_RENDER_TEXTURE_TEXTURE_HPP
