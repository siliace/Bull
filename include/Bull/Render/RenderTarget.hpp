#ifndef Bull_RenderTarget_hpp
#define Bull_RenderTarget_hpp

#include <Bull/Core/Integer.hpp>
#include <Bull/Core/Pattern/NonCopyable.hpp>
#include <Bull/Core/System/Config.hpp>

#include <Bull/Render/Color.hpp>

namespace Bull
{
    class BULL_API RenderTarget : public NonCopyable
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
        void clear(Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha = 255);

        /*! \brief Clear the RenderTarget with the specified color
         *
         * \param color The color to use
         *
         */
        void clear(const Color& color = Color::Black);

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
