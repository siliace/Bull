#ifndef BULL_WINDOWIMPLXLIB_HPP
#define BULL_WINDOWIMPLXLIB_HPP

#include <Bull/Core/Support/Xlib/Display.hpp>

#include <Bull/Math/Vector/Vector2.hpp>

#include <Bull/Core/Window/WindowImpl.hpp>

namespace Bull
{
    namespace prv
    {
        class WindowImplXlib : public WindowImpl
        {
        protected:

            static constexpr long EventsMasks = KeyPressMask         | KeyReleaseMask    | /// Keyboard events
                                                PointerMotionMask    | ButtonMotionMask  | /// Mouse move events
                                                ButtonPressMask      | ButtonReleaseMask | /// Mouse buttons events
                                                FocusChangeMask      |                     /// Focus events
                                                StructureNotifyMask  |                     /// Resize events
                                                VisibilityChangeMask |                     /// Visibility change (internal uses only)
                                                EnterWindowMask      | LeaveWindowMask;    /// Mouse Enter/Leave

        private:

            /*! \brief Convert a Xlib key value to a Bull::Keyboard::Key
             *
             * \param xkey The Xlib keycode to convert
             *
             * \return Return the Bull::Keyboard::Key equivalent
             *
             */
            static KeyboardKey convertXKToBullkey(KeySym xkey);

            /*! \brief Create an hidden cursor
             *
             * \param display A display connection
             * \param window  The window related to the cursor to create
             *
             * \return The hidden cursor
             *
             */
            static XCursor createHiddenCursor(Display& display, XWindow window);

        public:

            /*! \brief Constructor
             *
             * \param mode The VideoMode to use to create the window
             * \param title The title of the window
             * \param WindowStyle The WindowStyle to use to create the window
             *
             */
            WindowImplXlib(const VideoMode& mode, const String& title, Uint32 WindowStyle);

            /*! \brief Destructor
             *
             */
            virtual ~WindowImplXlib();

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

            /*! \brief Set the size of the window
             *
             * \param size The new size of the window
             *
             */
            void setPosition(const SizeI& position) override;

            /*! \brief Set the size of the window
             *
             * \param x The new width of the window
             * \param y The new height of the window
             *
             */
            SizeI getPosition() const override;

            /*! \brief Set the minimal size of the window
             *
             * \param size The minimal size of the window
             *
             */
            void setMinSize(const SizeUI& size) override;

            /*! \brief Get the minimal size of the window
             *
             * \return The minimal size
             *
             */
            SizeUI getMinSize() const override;

            /*! \brief Set the maximal size of the window
             *
             * \param size The maximal size of the window
             *
             */
            void setMaxSize(const SizeUI& size) override;

            /*! \brief Get the maximal size of the window
             *
             * \return The maximal size
             *
             */
            SizeUI getMaxSize() const override;

            /*! \brief Set the size of the window
             *
             * \param size The new size of the window
             *
             */
            void setSize(const SizeUI& size) override;

            /*! \brief Get the size of the window
             *
             * \return Return the size of the window
             *
             */
            SizeUI getSize() const override;

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
             * \param fullscreen False to leave the fullscreen mode, true to enter the fullscreen mode
             *
             */
            void switchFullscreen(bool fullscreen) override;

            /*! \brief Show or hide the window
             *
             * \param visible True to show the window, false to hide the window
             *
             */
            void setVisible(bool visible) override;

            /*! \brief Set the icon of the Window
             *
             * \param icon The icon
             *
             */
            void setIcon(const Image& icon) override;

            /*! \brief Set the mouse cursor of the Window
             *
             * \param cursor The cursor
             *
             */
            void setMouseCursor(const CursorImpl& cursor) override;

            /*! \brief Toggle cursor visibility
             *
             * \param visible True to show the cursor, false to hide
             *
             */
            void setMouseCursorVisible(bool visible) override;

            /*! \brief Check whether the mouse cursor is visible
             *
             * \return True if the mouse cursor is visible
             *
             */
            bool isMouseCursorVisible() const override;

            /*! \brief Get the window system handler
             *
             * \return Return the native window system handler
             *
             */
            WindowHandler getSystemHandler() const override;

        protected:

            /*! \brief Default constructor
             *
             */
            WindowImplXlib();

            /*! \brief Open the window
             *
             * \param mode  The VideoMode of the Window
             * \param title The title of the Window
             * \param style The decoration of the Window
             *
             */
            void open(const VideoMode& mode, const String& title, Uint32 style);

            /*! \brief Open the window
             *
             * \param size  The Size of the Window
             * \param title The title of the Window
             * \param style The decoration of the Window
             * \param vi    The VisualInfo parameters to use to open
             *
             */
            void open(const SizeUI& size, const String& title, Uint32 style, XVisualInfo* vi);

        private:

            /*! \brief Perform internal initialization
             *
             * \param title The title of the window to create
             * \param style The decoration of the window
             *
             */
            void initialize(const String& title, Uint32 style);

            /*! \brief Set Window manager protocols supported
             *
             */
            void setProtocols();

            XPixmap   m_icon;
            XScreen*  m_screen;
            Display&  m_display;
            XWindow   m_handler;
            XPixmap   m_iconMask;
            SizeUI    m_lastSize;
            bool      m_isMapped;
            XColormap m_colormap;
            XCursor   m_hiddenCursor;
            bool      m_cursorVisible;
            bool      m_captureCursor;
        };
    }
}

#endif // BULL_WINDOWIMPLXLIB_HPP
