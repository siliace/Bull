#include <Bull/Render/Context/Context.hpp>
#include <Bull/Render/Context/GlContext.hpp>

namespace Bull
{
    thread_local const Context* Context::s_active = nullptr;

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

    void Context::setActive(bool active)
    {
        m_context->setActive(active);

        s_active = active ? this : nullptr;
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
