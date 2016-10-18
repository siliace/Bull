#include <Bull/Render/Context/ContextResource.hpp>
#include <Bull/Render/Context/GlContext.hpp>

namespace Bull
{
    /*! \brief Constructor
     *
     * Initialize a render context if needed
     *
     */
    ContextResource::ContextResource()
    {
        bool static initialized = false;

        if(!initialized)
        {
            initialized = true;
            prv::GlContext::globalInit();
        }
    }

    /*! \brief Ensure there is an active OpenGL context in this thead
     *
     */
    void ContextResource::ensureContext()
    {
        prv::GlContext::ensureContext();
    }
}
