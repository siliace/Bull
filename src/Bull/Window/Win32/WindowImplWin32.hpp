#ifndef BULL_WINDOWIMPLWIN32_HPP
#define BULL_WINDOWIMPLWIN32_HPP

#include <windows.h>

#include <Bull/Window/WindowImpl.hpp>

namespace Bull
{
    namespace prv
    {
        class WindowImplWin32 : public WindowImpl
        {
        private:

            /*! \brief Register the window class
             *
             * \return Return true if the class was registered successfully, false otherwise
             *
             */
            static bool registerWindowClass();

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

            /*! \brief Convert a windows key value to a Bull::Keyboard::Key
             *
             * \param vkey To VK to convert
             *
             * \return Return the Bull::Keyboard::Key equivalent
             *
             */
            static Keyboard::Key convertVKToBullkey(WPARAM vkey);

            /*! \brief Convert a Bull::VideoStyle to a WS
             *
             * \param style The Bull::VideoStyle to convert
             *
             * \return Return the WS equivalent
             *
             */
            static DWORD computeStyle(Uint32 style);

        public:

            /*! \brief Constructor
             *
             * \param mode The VideoMode to use
             * \param title The title to use in the window
             * \param style The window decoration
             *
             */
            WindowImplWin32(const VideoMode& mode, const String& title, Uint32 style);

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

            /*! \brief Hide or show the cursor
             *
             * \param enable The state of the cursor
             *
             */
            void showCursor(bool enable) override;

            /*! \brief Set the size of the window
             *
             * \param size The new size of the window
             *
             */
            void setPosition(const Vector2I& position) override;

            /*! \brief Get the position in the screen of the window
             *
             * \return Return the window position
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
             *!
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
            void switchFullscreen(bool fullscreen);

            /*! \brief Show or hide the window
             *
             * \param visible True to show the window, false to hide the window
             *
             */
            void setVisible(bool visible);

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
             * \param wParam The WPARAM
             * \param lParam The LPARAM
             *
             */
            void processEvent(UINT message, WPARAM wParam, LPARAM lParam);

            HWND            m_handler;
            Vector2UI       m_lastSize;
            SavedWindowInfo m_savedInfo;
            bool            m_isResizing;
            Vector2I        m_lastPosition;
        };
    }
}

#endif // BULL_WINDOWIMPLWIN32_HPP
