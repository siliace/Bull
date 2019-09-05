#include <Bull/Render/Texture/DepthStencilTexture.hpp>

namespace Bull
{
    DepthStencilTexture::DepthStencilTexture(const Size<std::size_t>& size)
    {
        create(size);
    }

    DepthStencilTexture::DepthStencilTexture(DepthStencilTexture&& depthStencilTexture) noexcept :
            Texture(static_cast<Texture&&>(depthStencilTexture))
    {
        /// Nothing
    }

    DepthStencilTexture& DepthStencilTexture::operator=(DepthStencilTexture&& depthStencilTexture) noexcept
    {
        Texture::operator=(static_cast<Texture&&>(depthStencilTexture));

        return *this;
    }

    void DepthStencilTexture::create(const Size<std::size_t>& size)
    {
        Texture::create(size, PixelFormat_Depth24Stencil8);
    }
}