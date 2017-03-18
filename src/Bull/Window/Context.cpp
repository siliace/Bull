#include <Bull/Window/Context.hpp>
#include <Bull/Window/GlContext.hpp>

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
