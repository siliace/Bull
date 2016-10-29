#ifndef Bull_RenderTarget_hpp
#define Bull_RenderTarget_hpp

#include <Bull/Core/Integer.hpp>
#include <Bull/Core/Pattern/NonCopyable.hpp>

namespace Bull
{
    class RenderTarget : public NonCopyable
    {
    public:

        /*! \brief Destructor
         *
         */
        virtual ~RenderTarget();

        /*! \brief Clear the RenderTarget with the specified color
         *
         * \param red   The red component of the color
         * \param green The green component of the color
         * \param blue  The blue component of the color
         * \param alpha The alpha component of the color
         *
         */
        void clear(Uint8 red = 0, Uint8 green = 0, Uint8 blue = 0, Uint8 alpha = 255);

    protected:

        /*! \brief Activate or deactivate the context
         *
         * \param active True to activate, false to deactivate the context
         *
         * \return Return true if the context's status changed successfully, false otherwise
         *
         */
        virtual bool setActive(bool active = true) = 0;
    };
}

#endif // Bull_RenderTarget_hp
