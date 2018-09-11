#include <utility>

#include <Bull/Core/Exception/InternalError.hpp>
#include <Bull/Core/Exception/InvalidParameter.hpp>
#include <Bull/Core/Exception/LogicError.hpp>

#include <Bull/Render/Texture/DepthTexture.hpp>
#include <Bull/Render/Context/GlFunctions.hpp>

namespace Bull
{
    DepthTexture::DepthTexture() :
            m_handler(0)
    {
        /// Nothing
    }

    DepthTexture::DepthTexture(const Size& size, unsigned int depth)
    {
        create(size, depth);
    }

    DepthTexture::DepthTexture(DepthTexture&& right) noexcept
    {
        std::swap(m_handler, right.m_handler);
    }

    DepthTexture::~DepthTexture()
    {
        if(isValid())
        {
            gl::deleteTextures(1, &m_handler);
        }
    }

    DepthTexture& DepthTexture::operator=(DepthTexture&& right) noexcept
    {
        std::swap(m_handler, right.m_handler);

        return *this;
    }

    void DepthTexture::create(const Size& size, unsigned int depth)
    {
        Expect(size.width > 0 && size.height > 0, Throw(InvalidParameter, "DepthTexture::create", "Invalid texture size"))
        Expect(depth == 16 || depth == 24 || depth == 32, Throw(InvalidParameter, "DepthTexture::create", "Invalid depth, must be either 16, 24 or 32"))

        if(!isValid())
        {
            gl::genTextures(1, &m_handler);

            Expect(m_handler, Throw(InternalError, "DepthTexture::create", "Failed to create the texture"));
        }

        GLenum format = 0;

        switch(depth)
        {
            case 16: format = GL_DEPTH_COMPONENT16; break;
            case 24: format = GL_DEPTH_COMPONENT24; break;
            case 32: format = GL_DEPTH_COMPONENT32; break;
        }

        gl::bindTexture(GL_TEXTURE_2D, m_handler);
        gl::texImage2D(GL_TEXTURE_2D, 0, format, size.width, size.height, 0, GL_DEPTH_COMPONENT, depth == 16 ? GL_UNSIGNED_SHORT : GL_UNSIGNED_INT, nullptr);
        gl::texParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
        gl::texParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
        gl::texParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        gl::texParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    }

    bool DepthTexture::isValid() const
    {
        ensureContext();

        return gl::isTexture(m_handler);
    }

    Size DepthTexture::getSize() const
    {
        Size size;

        Expect(isValid(), Throw(LogicError, "DepthTexture::getSize", "Invalid texture"));

        gl::getTexParameteriv(m_handler, GL_TEXTURE_WIDTH, &size.width);
        gl::getTexParameteriv(m_handler, GL_TEXTURE_WIDTH, &size.height);

        return size;
    }
}