#include <Bull/Window/Context.hpp>
#include <Bull/Window/GlContext.hpp>

namespace Bull
{
    unsigned int ContextResource::s_instanceCount = 0;

    void ContextResource::ensureContext()
    {
        prv::GlContext::ensureContext();
    }

    ContextResource::ContextResource()
    {
        s_instanceCount += 1;

        if(s_instanceCount == 1)
        {
            prv::GlContext::globalInit();
        }
    }

    ContextResource::~ContextResource()
    {
        /// Nothing
    }
}
