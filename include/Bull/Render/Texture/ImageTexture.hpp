#ifndef BULL_RENDER_TEXTURE_IMAGETEXTURE_HPP
#define BULL_RENDER_TEXTURE_IMAGETEXTURE_HPP

#include <Bull/Render/Texture/Texture.hpp>

namespace Bull
{
    class BULL_RENDER_API ImageTexture : public Texture, public AbstractImage
    {
    public:

        explicit ImageTexture(PixelFormat pixelFormat);

        ImageTexture(ImageTexture&& imageTexture) noexcept;

        ImageTexture& operator=(ImageTexture&& imageTexture) noexcept;

        void create(const Size& size) override;

        void create(const ByteArray& pixels, const Size& size) override;

        Size getSize() const override;

        ByteArray getPixels() const override;

        inline PixelFormat getPixelFormat() const override
        {
            return m_pixelFormat;
        }

    private:

        PixelFormat m_pixelFormat;
    };
}

#endif // BULL_RENDER_TEXTURE_IMAGETEXTURE_HPP
