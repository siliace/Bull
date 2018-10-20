#ifndef BULL_RENDER_TEXTURE_TEXTURE_HPP
#define BULL_RENDER_TEXTURE_TEXTURE_HPP

#include <memory>

#include <Bull/Core/Image/Image.hpp>
#include <Bull/Core/Pattern/NonCopyable.hpp>

#include <Bull/Math/Polygon/Rectangle.hpp>
#include <Bull/Math/Vector/Vector2.hpp>

#include <Bull/Render/Context/ContextResource.hpp>

namespace Bull
{
    class BULL_RENDER_API Texture : public ContextResource, public NonCopyable
    {
    public:

        static void bind(const Texture& texture);

        static void unbind();

    public:

        Texture();

        Texture(Texture&& texture) noexcept;

        virtual ~Texture();

        Texture& operator=(Texture&& texture) noexcept;

        bool isValid() const;

        Size getSize() const;

    protected:

        void create(const Size& size, PixelFormat pixelFormat);

        void setPixels(unsigned int xOffset, unsigned int yOffset, const ByteArray& pixels, const Size& size, PixelFormat pixelFormat);

        inline unsigned int getSystemHandle() const
        {
            return m_handle;
        }

    private:

        unsigned int m_handle;
    };
}

#endif // BULL_RENDER_TEXTURE_TEXTURE_HPP
