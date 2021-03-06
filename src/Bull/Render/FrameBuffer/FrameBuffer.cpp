#include <algorithm>

#include <Bull/Core/Exception/LogicError.hpp>
#include <Bull/Core/Utility/MapUtils.hpp>

#include <Bull/Render/Context/GlFunctions.hpp>
#include <Bull/Render/FrameBuffer/FrameBuffer.hpp>
#include <Bull/Render/OpenGL.hpp>
#include <Bull/Render/Texture/Texture.hpp>

namespace Bull
{
    void FrameBuffer::bind(const FrameBuffer& frameBuffer)
    {
        ensureContext();

        gl::bindFramebuffer(GL_FRAMEBUFFER, frameBuffer.m_handle);
    }

    void FrameBuffer::unbind()
    {
        ensureContext();

        gl::bindFramebuffer(GL_FRAMEBUFFER, 0);
    }

    FrameBuffer::FrameBuffer()
    {
        gl::genFramebuffers(1, &m_handle);

        m_colorAttachmentTable = MapUtils::create<Uint8, bool>(16, [](std::size_t i)
        {
            return std::make_pair(i, true);
        });
    }

    FrameBuffer::~FrameBuffer()
    {
        ensureContext();

        gl::deleteFramebuffers(1, &m_handle);
    }

    void FrameBuffer::attach(const Texture& texture, AttachmentPoint attachmentPoint)
    {
        unsigned int target = OpenGL::attachmentPoint(attachmentPoint);

        if(attachmentPoint == AttachmentPoint::Color)
        {
            auto it = getNextColorAttachment();

            Expect(it != m_colorAttachmentTable.end(), Throw(LogicError, "No more color sampler available in the framebuffer"));

            target += it->first;
            it->second = false;
        }

        ensureContext();

        gl::bindFramebuffer(GL_FRAMEBUFFER, m_handle);
        gl::framebufferTexture2D(GL_FRAMEBUFFER, target, GL_TEXTURE_2D, texture.getSystemHandle(), 0);
    }

    bool FrameBuffer::isValid() const
    {
        ensureContext();

        gl::bindFramebuffer(GL_FRAMEBUFFER, m_handle);

        return gl::checkFramebufferStatus(GL_FRAMEBUFFER) == GL_FRAMEBUFFER_COMPLETE;
    }

    bool FrameBuffer::canAttachColor()
    {
        return getNextColorAttachment() != m_colorAttachmentTable.end();
    }

    FrameBuffer::ColorAttachmentMap::iterator FrameBuffer::getNextColorAttachment()
    {
        return std::find_if(m_colorAttachmentTable.begin(), m_colorAttachmentTable.end(), [](const std::pair<Uint8, bool>& pair) -> bool
        {
            return pair.second;
        });
    }
}