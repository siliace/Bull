#include <Bull/Render/Context/Context.hpp>
#include <Bull/Render/Context/GlContext.hpp>

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

    ContextResource::~ContextResource() = default;
}
