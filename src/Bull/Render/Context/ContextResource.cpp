#include <Bull/Render/Context/ContextResource.hpp>
#include <Bull/Render/Context/GlContext.hpp>
#include <Bull/Render/GlLoader.hpp>

namespace Bull
{
    unsigned int ContextResource::s_instanceCount = 0;

    /*! \brief Constructor
     *
     * Initialize a render context if needed
     *
     */
    ContextResource::ContextResource()
    {
        s_instanceCount += 1;

        if(s_instanceCount == 1)
        {
            prv::GlContext::globalInit();
            prv::GlLoader::load();
        }
    }

    /*! \brief Destructor
     *
     * Clean up contexts if needed
     *
     */
    ContextResource::~ContextResource()
    {
        s_instanceCount -= 1;

        if(s_instanceCount == 1)
        {
            prv::GlContext::globalCleanup();
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
