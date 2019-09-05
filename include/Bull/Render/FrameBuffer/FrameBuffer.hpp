#ifndef BULL_RENDER_FRAMEBUFFER_FRAMEBUFFER_HPP
#define BULL_RENDER_FRAMEBUFFER_FRAMEBUFFER_HPP

#include <map>

#include <Bull/Core/Pattern/NonCopyable.hpp>

#include <Bull/Render/Context/ContextResource.hpp>
#include <Bull/Render/FrameBuffer/AttachmentPoint.hpp>

namespace Bull
{
    class Texture;

    class BULL_RENDER_API FrameBuffer : public ContextResource, public NonCopyable
    {
    public:

        static void bind(const FrameBuffer& frameBuffer);

        static void unbind();

    public:

        FrameBuffer();

        ~FrameBuffer();

        void attach(const Texture& texture, AttachmentPoint attachmentPoint);

        bool isValid() const;

        bool canAttachColor();

    private:

        using ColorAttachmentMap = std::map<Uint8, bool>;

        ColorAttachmentMap::iterator getNextColorAttachment();

    private:

        unsigned int m_handle;
        ColorAttachmentMap m_colorAttachmentTable;
    };
}

#endif // BULL_RENDER_FRAMEBUFFER_FRAMEBUFFER_HPP
