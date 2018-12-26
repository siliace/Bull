#ifndef BULL_CORE_WINDOW_WINDOWSIMPL_HPP
#define BULL_CORE_WINDOW_WINDOWSIMPL_HPP

#include <memory>
#include <queue>

#include <Bull/Core/Memory/String.hpp>
#include <Bull/Core/Window/CursorImpl.hpp>
#include <Bull/Core/Window/VideoMode.hpp>
#include <Bull/Core/Window/WindowHandler.hpp>
#include <Bull/Core/Window/WindowEvent.hpp>

namespace Bull
{
    namespace prv
    {
        class WindowImpl : public NonCopyable
        {
        public:

            /*! \brief Create a OS specific WindowImpl instance
             *
             * \param mode  The VideoMode to use to create the window
             * \param title The title of the window
             * \param WindowStyle The WindowStyle to use to create the window
             *
             * \return Return the created instance
             *
             */
            static std::unique_ptr<WindowImpl> createInstance(const VideoMode& mode, const String& title, Uint32 WindowStyle);

        public:

            /*! \brief Destructor
             *
             */
            virtual ~WindowImpl();

            /*! \brief Start to process events to fill event queue
             *
             */
            virtual void startProcessEvents() = 0;

            /*! \brief Get the first event of the event queue
             *
             * \param e The event to fill
             * \param block If the event queue is empty, block the thread while an event has been not pushed
             *
             * \return Return true if the event is usable, otherwise false (if block is true, always return true)
             *
             */
            bool popEvent(WindowEvent& e, bool block);

            /*! \brief Minimize a window
             *
             */
            virtual void minimize() = 0;

            /*! \brief Check if the window is minimized
             *
             * \return Return true if the window is minimized, false otherwise
             *
             */
            virtual bool isMinimized() const = 0;

            /*! \brief Maximize a window
             *
             */
            virtual void maximize() = 0;

            /*! \brief Check if the window is maximized
             *
             * \return Return true if the window is maximized, false otherwise
             *
             */
            virtual bool isMaximized() const = 0;

            /*! \brief Enable or disable the capture of the cursor inside the window
             *
             * \param enable The state of the capture
             *
             */
            virtual void enableCaptureCursor(bool capture) = 0;

            /*! \brief Set the size of the window
             *
             * \param size The new size of the window
             *
             */
            virtual void setPosition(const SizeI& position) = 0;

            /*! \brief Set the size of the window
             *
             * \param x The new width of the window
             * \param y The new height of the window
             *
             */
            virtual SizeI getPosition() const = 0;

            /*! \brief Set the minimal size of the window
             *
             * \param size The minimal size of the window
             *
             */
            virtual void setMinSize(const SizeUI& size) = 0;

            /*! \brief Get the minimal size of the window
             *
             * \return The minimal size
             *
             */
            virtual SizeUI getMinSize() const = 0;

            /*! \brief Set the maximal size of the window
             *
             * \param size The maximal size of the window
             *
             */
            virtual void setMaxSize(const SizeUI& size) = 0;

            /*! \brief Get the maximal size of the window
             *
             * \return The maximal size
             *
             */
            virtual SizeUI getMaxSize() const = 0;

            /*! \brief Set the size of the window
             *
             * \param size The new size of the window
             *
             */
            virtual void setSize(const SizeUI& size) = 0;

            /*! \brief Get the size of the window
             *
             * \return Return the size of the window
             *
             */
            virtual SizeUI getSize() const = 0;

            /*! \brief Set the title of the window
             *
             * \param title The title to set to the window
             *
             */
            virtual void setTitle(const String& title) = 0;

            /*! \brief Get the title of the window
             *
             * \return Return the title of the window
             *
             */
            virtual String getTitle() const = 0;

            /*! \brief Enable or disable the key repeat
             *
             * \param enable The state of the key repeat
             *
             */
            void enableKeyRepeat(bool enable);

            /*! \brief Get the state of the key repeat
             *
             * \param Return true if the key repeat is enable, false otherwise
             *
             */
            bool isKeyRepeatEnable() const;

            /*! \brief Check if the window has the focus
             *
             * \param Return true if the window has the focus, false otherwise
             *
             */
            virtual bool hasFocus() const = 0;

            /*! \brief Enter or leave the fullscreen mode
             *
             * \param fullscreen False to leave the fullscreen mode, true to enter the fullscreen mode
             *
             */
            virtual void switchFullscreen(bool fullscreen) = 0;

            /*! \brief Show or hide the window
             *
             * \param visible True to show the window, false to hide the window
             *
             */
            virtual void setVisible(bool visible) = 0;

            /*! \brief Set the icon of the Window
             *
             * \param icon The icon
             *
             */
            virtual void setIcon(const Image& icon) = 0;

            /*! \brief Set the mouse cursor of the Window
             *
             * \param cursor The cursor
             *
             */
            virtual void setMouseCursor(const CursorImpl& cursor) = 0;

            /*! \brief Toggle cursor visibility
             *
             * \param visible True to show the cursor, false to hide
             *
             */
            virtual void setMouseCursorVisible(bool visible) = 0;

            /*! \brief Check whether the mouse cursor is visible
             *
             * \return True if the mouse cursor is visible
             *
             */
            virtual bool isMouseCursorVisible() const = 0;

            /*! \brief Get the window system handler
             *
             * \return Return the native window system handler
             *
             */
            virtual WindowHandler getSystemHandler() const = 0;

        protected:

            /*! \brief Constructor
             *
             * Set m_keyrepeat to true
             *
             */
            WindowImpl();

            /*! \brief Add an event to add at the end of the event queue
             *
             * \param e The event to add at the end of the event queue
             *
             */
            void pushEvent(const WindowEvent& e);

            /*! \brief Get the position of the cursor in the Window
             *
             * \return The position of the cursor
             */
            const SizeI& getCursorPosition() const;

        private:

            std::queue<WindowEvent> m_events;         /*!< The event queue */
            bool                    m_keyrepeat;      /*!< Does the key repeat is enable? */
            SizeI                   m_cursorPosition; /*!< The position of the cursor in the window */
        };
    }
}

#endif // BULL_CORE_WINDOW_WINDOWSIMPL_HPP
