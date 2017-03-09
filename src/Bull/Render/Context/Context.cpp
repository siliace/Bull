#include <Bull/Render/Context/Context.hpp>
#include <Bull/Render/Context/GlContext.hpp>

namespace Bull
{
    LocalPtr<Context> Context::s_active;

    const Context* Context::getActive()
    {
        return s_active;
    }

    Context::Context() :
        m_context(prv::GlContext::createInstance())
    {
        setActive();
    }

    Context::Context(const VideoMode& mode, const ContextSettings& settings) :
        m_context(prv::GlContext::createInstance(mode, settings))
    {
        setActive();
    }

    Context::Context(unsigned int bitsPerPixel, const ContextSettings& settings) :
        m_context(prv::GlContext::createInstance(bitsPerPixel, settings))
    {
        setActive();
    }

    Context::~Context()
    {
        setActive(false);
    }

    bool Context::setActive(bool active)
    {
        bool result = m_context->setActive(active);

        if(result)
        {
            s_active = active ? this : nullptr;
        }

        return result;
    }

    const ContextSettings& Context::getSettings() const
    {
        if(m_context)
        {
            return m_context->getSettings();
        }

        return ContextSettings::Empty;
    }
}
