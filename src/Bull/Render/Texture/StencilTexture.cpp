#include <algorithm>

#include <Bull/Render/Texture/StencilTexture.hpp>

namespace Bull
{
    StencilTexture::StencilTexture(StencilValue stencilValue) :
        m_stencilValue(stencilValue)
    {
        /// Nothing
    }

    StencilTexture::StencilTexture(const Size<std::size_t>& size, StencilValue stencilValue) :
        m_stencilValue(stencilValue)
    {
        create(size);
    }

    StencilTexture::StencilTexture(StencilTexture&& stencilTexture) noexcept :
        Texture(static_cast<Texture&&>(stencilTexture))
    {
        std::swap(m_stencilValue, stencilTexture.m_stencilValue);
    }

    StencilTexture& StencilTexture::operator=(StencilTexture&& stencilTexture) noexcept
    {
        std::swap(m_stencilValue, stencilTexture.m_stencilValue);

        Texture::operator=(static_cast<Texture&&>(stencilTexture));

        return *this;
    }

    void StencilTexture::create(const Size<std::size_t>& size)
    {
        switch(m_stencilValue)
        {
            case StencilValue_1: Texture::create(size, PixelFormat_Stencil1); break;
            case StencilValue_4: Texture::create(size, PixelFormat_Stencil4); break;
            case StencilValue_8: Texture::create(size, PixelFormat_Stencil8); break;
            case StencilValue_16: Texture::create(size, PixelFormat_Stencil16); break;
        }
    }

    StencilValue StencilTexture::getStencilValue() const
    {
        return m_stencilValue;
    }
}