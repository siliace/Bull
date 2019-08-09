#ifndef BULL_COREWIN32_WINDOWIMPLWIN32_HPP
#define BULL_COREWIN32_WINDOWIMPLWIN32_HPP

#include <Bull/Core/Support/Win32/Windows.hpp>

#include <Bull/Core/Window/WindowImpl.hpp>

namespace Bull
{
    namespace prv
    {
        class WindowImplWin32 : public WindowImpl
        {
        public:

            /*! \brief Window callback event
             *
             * \param handler The window concerned by the event
             * \param message The windows message
             * \param wParam The WPARAM
             * \param lParam The LPARAM
             *
             * \return Return 0 if the message was WM_CLOSE, a value to continue otherwise
             *
             */
            static LRESULT CALLBACK globalEvent(HWND handler, UINT message, WPARAM wParam, LPARAM lParam);

        private:

            /*! \brief Convert a windows key value to a Bull::Keyboard::Key
             *
             * \param vkey To VK to convert
             *
             * \return Return the Bull::Keyboard::Key equivalent
             *
             */
            static KeyboardKey convertVKToBullkey(WPARAM vkey);

            /*! \brief Convert a Bull::WindowStyle to a WS
             *
             * \param style The Bull::WindowStyle to convert
             *
             * \return Return the WS equivalent
             *
             */
            static DWORD computeWindowStyle(Uint32 style);

            /*! \brief Calculates the required Size of the Window
             *
             * Calculates the required Size of the Window, based on the desired client-rectangle Size.
             * The Size can then be passed to the create the Window whose client area is the desired Size.
             *
             * \param size  The Size
             * \param style The WindowStyle of the window whose required size is to be calculated
             *
             * \return The adjusted Size
             *
             */
            static Size<unsigned int> getAdjustedSize(const Size<unsigned int>& size, DWORD style);

        public:

            /*! \brief Constructor
             *
             * \param mode The VideoMode to use
             * \param title The title to use in the window
             * \param WindowStyle The window decoration
             *
             */
            WindowImplWin32(const VideoMode& mode, const String& title, Uint32 WindowStyle);

            /*! \brief Destructor
             *
             */
            virtual ~WindowImplWin32();

            /*! \brief Process events stacked so far
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
             * \return Return true if the window is minimized, false otherwise
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
            void setPosition(const Size<int>& position) override;

            /*! \brief Get the position in the screen of the window
             *
             * \return Return the window position
             *
             */
            Size<int> getPosition() const override;

            /*! \brief Set the minimal size of the window
             *
             * \param size The minimal size of the window
             *
             */
            void setMinSize(const Size<unsigned int>& size) override;

            /*! \brief Get the minimal size of the window
             *
             * \return The minimal size
             *
             */
            Size<unsigned int> getMinSize() const override;

            /*! \brief Set the maximal size of the window
             *
             * \param size The maximal size of the window
             *
             */
            void setMaxSize(const Size<unsigned int>& size) override;

            /*! \brief Get the maximal size of the window
             *
             * \return The maximal size
             *
             */
            Size<unsigned int> getMaxSize() const override;

            /*! \brief Set the size of the window
             *
             * \param size The new size of the window
             *!
             */
            void setSize(const Size<unsigned int>& size) override;

            /*! \brief Get the size of the window
             *
             * \return Return the size of the window
             *
             */
            Size<unsigned int> getSize() const override;

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

        private:

            struct SavedWindowInfo
            {
                RECT rect;
                LONG style;
                LONG styleEx;
                bool maximized;
            };

            /*! \brief Process a single event
             *
             * \param message The windows message
             * \param wParam  The WPARAM
             * \param lParam  The LPARAM
             *
             */
            void processEvent(UINT message, WPARAM wParam, LPARAM lParam);

            HICON                   m_icon;
            HCURSOR                 m_cursor;
            HWND                    m_handler;
            std::unique_ptr<Size<unsigned int>> m_maxSize;
            std::unique_ptr<Size<unsigned int>> m_minSize;
            Size<unsigned int>                  m_lastSize;
            SavedWindowInfo         m_savedInfo;
            bool                    m_isResizing;
            bool                    m_isFullscreen;
            Size<int>                   m_lastPosition;
            bool                    m_cursorVisible;
        };
    }
}

#endif // BULL_COREWIN32_WINDOWIMPLWIN32_HPP
