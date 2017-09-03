#ifndef BULL_WINDOWIMPLXCB_HPP
#define BULL_WINDOWIMPLXCB_HPP

#include <xcb/xcb.h>

#include <Bull/Core/Support/XCB/XCBConnection.hpp>

#include <Bull/Window/WindowImpl.hpp>

namespace Bull
{
    namespace prv
    {
        class WindowImplXCB : public WindowImpl
        {
        protected:

            static constexpr Uint32 EventsMaks = XCB_EVENT_MASK_BUTTON_PRESS | XCB_EVENT_MASK_BUTTON_RELEASE;

        public:

            /*! \brief Constructor
             *
             * \param mode
             * \param title
             * \param WindowStyle
             *
             */
            WindowImplXCB(const VideoMode& mode, const String& title, Uint32 WindowStyle);

            /*! \brief Destructor
             *
             */
            ~WindowImplXCB();

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

            /*! \brief Set the minimal size of the window
             *
             * \param size The minimal size of the window
             *
             */
            void setMinSize(const Vector2UI& size) override;

            /*! \brief Get the minimal size of the window
             *
             * \return The minimal size
             *
             */
            Vector2UI getMinSize() const override;

            /*! \brief Set the maximal size of the window
             *
             * \param size The maximal size of the window
             *
             */
            void setMaxSize(const Vector2UI& size) override;

            /*! \brief Get the maximal size of the window
             *
             * \return The maximal size
             *
             */
            Vector2UI getMaxSize() const override;

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

            /*! \brief Set the mouse cursor of the Window
             *
             * \param cursor The cursor
             *
             */
            void setMouseCursor(const std::unique_ptr<CursorImpl>& cursor) override;

            /*! \brief Toggle cursor visibility
             *
             * \param visible True to show the cursor, false to hide
             *
             */
            void setMouseCursorVisible(bool visible = false) override;

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
            WindowImplXCB() = default;

        private:

            xcb_window_t      m_window;
            XCBConnection     m_connection;
        };
    }
}

#endif //BULL_WINDOWIMPLXCB_HPP
