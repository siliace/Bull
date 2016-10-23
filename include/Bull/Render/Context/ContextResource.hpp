#ifndef Bull_ContextResource_hpp
#define Bull_ContextResource_hpp

namespace Bull
{
    class ContextResource
    {
    protected:

        /*! \brief Constructor
         *
         * Initialize a render context if needed
         *
         */
        ContextResource();

        /*! \brief Ensure there is an active OpenGL context in this thead
         *
         */
        void ensureContext();
    };
}

#endif // Bull_ContextResource_hpp
