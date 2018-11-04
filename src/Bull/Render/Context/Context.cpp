#include <Bull/Render/Context/Context.hpp>
#include <Bull/Render/Context/GlContext.hpp>

namespace Bull
{
    namespace
    {
        thread_local const Context* g_active = nullptr;
    }

    const Context* Context::getActive()
    {
        return g_active;
    }

    void Context::ensureContext()
    {
        prv::GlContext::ensureContext();
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

        g_active = active ? this : nullptr;
    }

    const ContextSettings& Context::getSettings() const
    {
        return m_context->getSettings();
    }
}
