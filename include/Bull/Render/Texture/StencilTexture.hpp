#ifndef BULL_RENDER_TEXTURE_STENCILTEXTURE_HPP
#define BULL_RENDER_TEXTURE_STENCILTEXTURE_HPP

#include <Bull/Render/Texture/Texture.hpp>

namespace Bull
{
    enum StencilValue
    {
        StencilValue_1,  /**< 1 bit of stencil */
        StencilValue_4,  /**< 4 bits of stencil */
        StencilValue_8,  /**< 8 bits of stencil */
        StencilValue_16, /**< 16 bits of stencil */
    };

    class BULL_RENDER_API StencilTexture : public Texture
    {
    public:

        /** \brief Constructor
         *
         * \param stencilValue The StencilValue of the StencilTexture
         *
         */
        explicit StencilTexture(StencilValue stencilValue);

        /** \brief Constructor
         *
         * \param size         The Size of the StencilTexture
         * \param stencilValue The StencilValue of the StencilTexture
         *
         */
        StencilTexture(const Size<std::size_t>& size, StencilValue stencilValue);

        /** \brief Constructor by movement semantic
         *
         * \param stencilTexture The StencilTexture to move
         *
         */
        StencilTexture(StencilTexture&& stencilTexture) noexcept;

        /** \brief Assignment operator by movement semantic
         *
         * \param stencilTexture The StencilTexture to move
         *
         * \return This
         *
         */
        StencilTexture& operator=(StencilTexture&& stencilTexture) noexcept;

        /** \brief Create the StencilTexture with a given Size
         *
         * \param size The Size
         *
         */
        void create(const Size<std::size_t>& size) override;

        /** \brief Get the StencilValue of the StencilTexture
         *
         * \return The StencilValue
         *
         */
        StencilValue getStencilValue() const;

    private:

        StencilValue m_stencilValue;
    };
}

#endif // BULL_RENDER_TEXTURE_STENCILTEXTURE_HPP
