#ifndef Bull_WindowImplX11_hpp
#define Bull_WindowImplX11_hpp

#include <X11/Xlib.h>

#include <Bull/Core/Exception.hpp>

#include <Bull/Math/Vector/Vector2.hpp>

#include <Bull/Window/WindowImpl.hpp>
#include <Bull/Window/X11/Display.hpp>

namespace Bull
{
    namespace prv
    {
        class WindowImplX11 : public WindowImpl
        {
        public:

            /*! \brief Default constructor
             *
             */
            WindowImplX11() = delete;

            /*! \brief Constructor
             *
             * \param mode The VideoMode to use to create the window
             * \param title The title of the window
             * \param style The style to use to create the window
             * \param settings Parameters to create the OpenGL context
             *
             */
            WindowImplX11(const VideoMode& mode, const String& title, Uint32 style, const ContextSettings& settings);

            /*! \brief Destructor
             *
             */
            ~WindowImplX11();

            /*! \brief Start to process events to fill event queue
             *
             */
            void startProcessEvents() override;

            /*! \brief Minimize a window
             *
             */
            void minimize() override;

            /*! \brief Check if the window is minimized
             *
             * \return Return true if the window is minimized, false otherwise
             *
             */
            bool isMinimized() const override;

            /*! \brief Maximize a window
             *
             */
            void maximize() override;

            /*! \brief Check if the window is maximized
             *
             * \return Return true if the window is maximized, false otherwise
             *
             */
            bool isMaximized() const override;

            /*! \brief Enable or disable the capture of the cursor inside the window
             *
             * \param enable The state of the capture
             *
             */
            void enableCaptureCursor(bool capture) override;

            /*! \brief Hide or show the cursor
             *
             * \param enable The state of the cursor
             *
             */
            void showCursor(bool enable = true) override;

            /*! \brief Set the size of the window
             *
             * \param size The new size of the window
             *
             */
            void setPosition(const Vector2I& position) override;

            /*! \brief Set the size of the window
             *
             * \param x The new width of the window
             * \param y The new height of the window
             *
             */
            Vector2I getPosition() const override;

            /*! \brief Set the size of the window
             *
             * \param size The new size of the window
             *
             */
            void setSize(const Vector2UI& size) override;

            /*! \brief Get the size of the window
             *
             * \return Return the size of the window
             *
             */
            Vector2UI getSize() const override;

            /*! \brief Set the title of the window
             *
             * \param title The title to set to the window
             *
             */
            void setTitle(const String& title) override;

            /*! \brief Get the title of the window
             *
             * \return Return the title of the window
             *
             */
            String getTitle() const override;

            /*! \brief Check if the window has the focus
             *
             * \param Return true if the window has the focus, false otherwise
             *
             */
            bool hasFocus() const override;

            /*! \brief Enter or leave the fullscreen mode
             *
             * \param mode The VideoMode to use
             * \param fullscreen False to leave the fullscreen mode, true to enter the fullscreen mode
             *
             * \return Return true if the switch was done successfully, false otherwise
             *
             */
            bool switchFullscreen(const VideoMode& mode, bool fullscreen) override;

            /*! \brief Show or hide the window
             *
             * \param visible True to show the window, false to hide the window
             *
             */
            void setVisible(bool visible) override;

            /*! \brief Get the window system handler
             *
             * \return Return the native window system handler
             *
             */
            WindowHandler getSystemHandler() const override;

        private:

            /*! \brief Set Window manager protocols supported
             *
             */
            void setProtocols();

            Display::Instance m_display;
            ::Window          m_handler;
            Vector2UI         m_lastSize;
            Vector2I          m_lastPosition;
            bool              m_isMapped;

            DeclarePublicException(FailToGetProtocolsAtom, "Failed to request WM_PROTOCOLS atom", Log::Critical);
        };
    }
}

#endif // Bull_WindowImplX11_hpp
