#ifndef BULL_RENDER_TARGET_RENDERTARGET_HPP
#define BULL_RENDER_TARGET_RENDERTARGET_HPP

#include <memory>

#include <Bull/Core/Configuration/Integer.hpp>
#include <Bull/Core/Pattern/NonCopyable.hpp>
#include <Bull/Core/Utility/Color.hpp>
#include <Bull/Core/Window/VideoMode.hpp>

#include <Bull/Math/Vector/Vector2.hpp>

#include <Bull/Render/Context/ContextResource.hpp>
#include <Bull/Render/Context/ContextSettings.hpp>
#include <Bull/Render/Target/Viewport.hpp>

namespace Bull
{
    namespace prv
    {
        class GlContext;
    }

    class BULL_RENDER_API RenderTarget : public ContextResource, public NonCopyable
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

        /*! \brief Activate or deactivate the context
         *
         * \param active True to activate, false to deactivate the context
         *
         * \return Return true if the context's status changed successfully, false otherwise
         *
         */
        bool setActive(bool active = true);

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

        /*! \brief Get the ContextSettings of the context
         *
         * \return Return the ContextSettings
         *
         */
        const ContextSettings& getSettings() const;

    protected:

        /*! \brief Default constructor
         *
         */
        RenderTarget() = default;

        /*! \brief Constructor by movement
         *
         * \param renderTarget The RenderTarget to move
         *
         */
        RenderTarget(RenderTarget&& renderTarget) noexcept = default;

        /*! \brief Basic assignment operator by movement
         *
         * \param move The RenderTarget to renderTarget
         *
         * \return This
         *
         */
        RenderTarget& operator=(RenderTarget&& renderTarget) noexcept = default;

        ImplPtr<prv::GlContext> m_context;

    private:

        Viewport m_currentViewport;
    };
}

#endif // BULL_RENDER_TARGET_RENDERTARGET_HPP
