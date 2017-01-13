#ifndef Bull_RenderTarget_hpp
#define Bull_RenderTarget_hpp

#include <memory>

#include <Bull/Core/Integer.hpp>

#include <Bull/Math/Vector/Vector2.hpp>

#include <Bull/Render/Context/Context.hpp>
#include <Bull/Render/Color.hpp>
#include <Bull/Render/Viewport.hpp>

#include <Bull/Utility/Window/VideoMode.hpp>
#include <Bull/Utility/Window/WindowHandler.hpp>

namespace Bull
{
    namespace prv
    {
        class GlContext;
    }

    class BULL_API RenderTarget : public Context
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

        /*! \brief Change the viewport of the RenderTarget
         *
         * \param viewport The viewport
         *
         */
        void setViewport(const Viewport& viewport);

        /*! \brief Get the current viewport of the RenderTarget
         *
         * \return Return the viewport
         *
         */
        const Viewport& getViewport() const;

        /*! \brief Get the default viewport of the RenderTarget
         *
         * \return Return the viewport
         *
         */
        virtual Viewport getDefaultViewport() const = 0;

        /*! \brief Reset the viewport by the default one
         *
         */
        void resetViewport();

        /*! \brief Display what have been rendered so far
         *
         */
        virtual void display() = 0;

    protected:

        /*! \brief Default constructor
         *
         */
        RenderTarget();

    private:

        Viewport m_currentViewport;
    };
}

#endif // Bull_RenderTarget_hp
