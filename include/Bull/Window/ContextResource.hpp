#ifndef Bull_ContextResource_hpp
#define Bull_ContextResource_hpp

#include <Bull/Core/System/Export.hpp>

namespace Bull
{
    class BULL_API ContextResource
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

#endif // Bull_ContextResource_hpp
