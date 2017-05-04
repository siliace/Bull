#ifndef BULL_CONTEXTRESOURCE_HPP
#define BULL_CONTEXTRESOURCE_HPP

#include <Bull/Render/Export.hpp>

namespace Bull
{
    class BULL_RENDER_API ContextResource
    {
    protected:

        /*! \brief Ensure there is an active OpenGL context in this thread
         *
         */
        static void ensureContext();

    private:

        static unsigned int s_instanceCount; /*!< Count every instances to perform initialization and cleanup */

    protected:

        /*! \brief Constructor
         *
         * Initialize a render context if needed
         *
         */
        ContextResource();

        /*! \brief Destructor
         *
         * Clean up contexts if needed
         *
         */
        virtual ~ContextResource();
    };
}

#endif // BULL_CONTEXTRESOURCE_HPP
