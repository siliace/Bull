#include <utility>

#include <Bull/Core/Exception/InternalError.hpp>
#include <Bull/Core/Exception/InvalidParameter.hpp>
#include <Bull/Core/Exception/LogicError.hpp>

#include <Bull/Render/Texture/DepthTexture.hpp>
#include <Bull/Render/Context/GlFunctions.hpp>

namespace Bull
{
    DepthTexture::DepthTexture(DepthValue depthValue) :
        m_depthValue(depthValue)
    {
        /// Nothing
    }

    DepthTexture::DepthTexture(const Size& size, DepthValue depth) :
        m_depthValue(depth)
    {
        create(size);
    }

    DepthTexture::DepthTexture(DepthTexture&& depthTexture) noexcept :
        Texture(static_cast<Texture&&>(depthTexture))
    {
        std::swap(m_depthValue, depthTexture.m_depthValue);
    }

    DepthTexture& DepthTexture::operator=(DepthTexture&& depthTexture) noexcept
    {
        std::swap(m_depthValue, depthTexture.m_depthValue);

        Texture::operator=(static_cast<Texture&&>(depthTexture));

        return *this;
    }

    void DepthTexture::create(const Size& size)
    {
        switch(m_depthValue)
        {
            case DepthValue_16: Texture::create(size, PixelFormat_Depth16); break;
            case DepthValue_24: Texture::create(size, PixelFormat_Depth24); break;
            case DepthValue_32: Texture::create(size, PixelFormat_Depth32); break;
        }
    }
}