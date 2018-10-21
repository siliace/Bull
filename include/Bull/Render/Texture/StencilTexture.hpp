#ifndef BULL_RENDER_TEXTURE_STENCILTEXTURE_HPP
#define BULL_RENDER_TEXTURE_STENCILTEXTURE_HPP

#include <Bull/Render/Texture/Texture.hpp>

namespace Bull
{
    enum StencilValue
    {
        StencilValue_1,
        StencilValue_4,
        StencilValue_8,
        StencilValue_16,
    };

    class BULL_RENDER_API StencilTexture : public Texture
    {
    public:

        explicit StencilTexture(StencilValue stencilValue);

        StencilTexture(const Size& size, StencilValue stencilValue);

        StencilTexture(StencilTexture&& depthTexture) noexcept;

        StencilTexture& operator=(StencilTexture&& depthTexture) noexcept;

        void create(const Size& size);

        inline StencilValue getStencilValue() const
        {
            return m_stencilValue;
        }

    private:

        StencilValue m_stencilValue;
    };
}

#endif // BULL_RENDER_TEXTURE_STENCILTEXTURE_HPP
