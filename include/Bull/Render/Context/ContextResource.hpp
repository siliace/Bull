#ifndef Bull_ContextResource_hpp
#define Bull_ContextResource_hpp

#include <Bull/Core/System/Export.hpp>

namespace Bull
{
    class BULL_API ContextResource
    {
    private:

        static unsigned int s_instanceCount;

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

        /*! \brief Ensure there is an active OpenGL context in this thead
         *
         */
        void ensureContext();

    };
}

#endif // Bull_ContextResource_hpp
