#ifndef BULL_RENDER_TEXTURE_DEPTHTEXTURE_HPP
#define BULL_RENDER_TEXTURE_DEPTHTEXTURE_HPP

#include <Bull/Render/Context/Context.hpp>
#include <Bull/Render/Texture/Texture.hpp>

namespace Bull
{
    enum DepthValue
    {
        DepthValue_16,
        DepthValue_24,
        DepthValue_32,
    };

    class BULL_RENDER_API DepthTexture : public Texture
    {
    public:

        /*! \brief Constructor
         *
         */
        explicit DepthTexture(const Size& size, DepthValue depth);

        DepthTexture(DepthTexture&& depthTexture) noexcept;

        DepthTexture& operator=(DepthTexture&& depthTexture) noexcept;

        /*! \brief Create the DepthTexture
         *
         */
        void create(const Size& size);

        inline DepthValue getDepthValue() const
        {
            return m_depthValue;
        }

    private:

        DepthValue m_depthValue;
    };
}

#endif // BULL_RENDER_TEXTURE_DEPTHTEXTURE_HPP
