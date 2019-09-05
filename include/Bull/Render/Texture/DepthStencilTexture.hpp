#ifndef BULL_RENDER_TEXTURE_DEPTHSTENCILTEXTURE_HPP
#define BULL_RENDER_TEXTURE_DEPTHSTENCILTEXTURE_HPP

#include <Bull/Render/Texture/Texture.hpp>

namespace Bull
{
    class BULL_RENDER_API DepthStencilTexture : public Texture
    {
    public:

        /** \brief Constructor
         *
         * \param size The Size of the DepthStencilTexture
         *
         */
        explicit DepthStencilTexture(const Size<std::size_t>& size);

        /** \brief Constructor by movement semantic
         *
         * \param depthStencilTexture The DepthStencilTexture to move
         *
         */
        DepthStencilTexture(DepthStencilTexture&& depthStencilTexture) noexcept;

        /** \brief Assignment operator by movement semantic
         *
         * \param depthStencilTexture The DepthStencilTexture to move
         *
         * \return This
         *
         */
        DepthStencilTexture& operator=(DepthStencilTexture&& depthStencilTexture) noexcept;

        /** \brief Create the DepthStencilTexture with a given Size
         *
         * \param size The Size
         *
         */
        void create(const Size<std::size_t>& size) override;
    };
}

#endif // BULL_RENDER_TEXTURE_DEPTHSTENCILTEXTURE_HPP
