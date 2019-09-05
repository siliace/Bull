#ifndef BULL_CORE_WINDOW_WINDOW_HPP
#define BULL_CORE_WINDOW_WINDOW_HPP

#include <memory>

#include <Bull/Core/Image/Image.hpp>
#include <Bull/Core/Window/Cursor.hpp>
#include <Bull/Core/Window/VideoMode.hpp>
#include <Bull/Core/Window/WindowEvent.hpp>
#include <Bull/Core/Window/WindowStyle.hpp>

namespace Bull
{
    class MessageWindow;

    namespace prv
    {
        class WindowImpl;
    }

    class BULL_CORE_API Window : public NonCopyable
    {
    public:

        /** \brief Get the fullscreen window
         *
         * \return Return a pointer to the window in fullscreen
         *
         */
        static const Window* getFullscreen();

    protected:

        static Window* s_fullscreen;

    public:

        /** \brief Default constructor
         *
         */
        Window();

        /** \brief Constructor
         *
         * \param mode  The VideoMode
         * \param title The title of the window
         * \param style The window decorations
         *
         */
        Window(const VideoMode& mode, const std::string& title, Uint32 style = WindowStyle_Default);

        /** \brief Constructor by movement
         *
         * \param window The Window to move
         *
         */
        Window(Window&& window) noexcept = default;

        /** \brief Destructor
         *
         */
        virtual ~Window();

        /** \brief Basic assignment operator by movement
         *
         * \param window The Window to move
         *
         * \return This
         *
         */
        Window& operator=(Window&& window) noexcept = default;

        /** \brief Create the window
         *
         * \param mode  The VideoMode
         * \param title The title of the window
         * \param style The window decorations
         *
         */
        void create(const VideoMode& mode, const std::string& title, Uint32 style = WindowStyle_Default);

        /** \brief Check if the window is open
         *
         * \return Return true if the window is open, else return false
         *
         */
        bool isOpen() const;

        /** \brief Close the window
         *
         */
        void close();

        /** \brief Get the first event on the stack without blocking the current thread
         *
         * \param e An event to fill
         *
         * \return Return true if the event stack was not empty, else return false
         *
         */
        bool pollEvent(WindowEvent& e);

        /** \brief Get the first event on the stack and blocking the current thread
         *
         * \return Return the first event of the stack
         *
         */
        WindowEvent nextEvent();

        /** \brief Enable or disable the capture of the cursor inside the window
         *
         * \param enable The state of the capture
         *
         */
        void enableCaptureCursor(bool enable = true);

        /** \brief Minimize a window
         *
         */
        void minimize();

        /** \brief Check if the window is minimized
         *
         * \return True if the window is minimized
         *
         */
        bool isMinimized() const;

        /** \brief Maximize a window
         *
         */
        void maximize();

        /** \brief Check if the window is maximized
         *
         * \return Return true if the window is maximized, false otherwise
         *
         */
        bool isMaximized() const;

        /** \brief Set the window position
         *
         * \param position The new position of the window
         *
         */
        void setPosition(const Size<int>& position);

        /** \brief Get the position in the screen of the window
         *
         * \return Return the window position
         *
         */
        Size<int> getPosition() const;

        /** \brief Set the minimal size of the window
         *
         * \param size The minimal size of the window
         *
         */
        void setMinSize(const Size<unsigned int>& size);

        /** \brief Get the minimal size of the window
         *
         * \return The minimal size
         *
         */
        Size<unsigned int> getMinSize() const;

        /** \brief Set the maximal size of the window
         *
         * \param size The maximal size of the window
         *
         */
        void setMaxSize(const Size<unsigned int>& size);

        /** \brief Get the maximal size of the window
         *
         * \return The maximal size
         *
         */
        Size<unsigned int> getMaxSize() const;

        /** \brief Set the size of the window
         *
         * \param size The new size of the window
         *
         */
        void setSize(const Size<unsigned int>& size);

        /** \brief Get the size of the window
         *
         * \return Return the size of the window
         *
         */
        Size<unsigned int> getSize() const;

        /** \brief Set the title of the window
         *
         * \param title The new title of the window
         *
         */
        void setTitle(const std::string& title);

        /** \brief Get the title of the window
         *
         * \return Return the title of the window
         *
         */
        std::string getTitle() const;

        /** \brief Enable or disable the key repeat
         *
         * \param enable The state of the key repeat
         *
         */
        void enableKeyRepeat(bool enable = true);

        /** \brief Get the state of the key repeat
         *
         * \return True if the key repeat is enable
         *
         */
        bool isKeyRepeatEnable() const;

        /** \brief Check if the window has the focus
         *
         * \return True if the window has the focus
         *
         */
        bool hasFocus() const;

        /** \brief Show or hide the window
         *
         * \param visible True to show the window, false to hide the window
         *
         */
        void setVisible(bool visible = true);

        /** \brief Set the icon of the Window
         *
         * \param icon The icon
         *
         */
        void setIcon(const Image& icon);

        /** \brief Set the mouse cursor of the Window
         *
         * \param cursor The cursor
         *
         */
        void setMouseCursor(const Cursor& cursor);

        /** \brief Toggle cursor visibility
         *
         * \param visible True to show the cursor, false to hide
         *
         */
        void setMouseCursorVisible(bool visible = false);

        /** \brief Check whether the mouse cursor is visible
         *
         * \return True if the mouse cursor is visible
         *
         */
        bool isMouseCursorVisible() const;

        /** \brief Enter or leave the fullscreen mode
         *
         * \param enable False to leave the fullscreen mode, true to enter the fullscreen mode
         *
         */
        void enableFullscreen(bool enable = true);

        /** \brief Check if a window is in fullscreen
         *
         * \return Return true if the window is in fullscreen, false otherwise
         *
         */
        bool isFullscreenEnable() const;

    protected:

        /** \brief Open the Window
         *
         * \param impl The implementation to use
         *
         */
        void create(std::unique_ptr<prv::WindowImpl>&& impl, const std::string& title, Uint32 style);

        /** \brief Function called when the Window is opened
         *
         */
        virtual void onOpen()
        {}

        /** \brief Function called when the Window is resized
         *
         */
        virtual void onResize()
        {}

        /** \brief Function called when the Window is closed
         *
         */
        virtual void onClose()
        {}

        std::unique_ptr<prv::WindowImpl> m_impl; /**< The OS specific implementation of the window */

    private:

        friend class Mouse;

        /** \brief Ignore the next mouse event that the window will receive
         *
         */
        void ignoreNextMouseEvent() const;

    private:

        friend class MessageWindow;

        /** \brief Get the implementation of the Window
         *
         * \return The implementation
         *
         */
        const prv::WindowImpl* getImpl() const;

    private:

        /** \brief Filter events to start callbacks
         *
         * \param e The event to filter
         *
         */
        bool filterEvent(const WindowEvent& e);

        mutable bool m_ignoreNextMouse; /**< True to ignore the mouse event due to cursor centering */
    };
}

#endif // BULL_CORE_WINDOW_WINDOW_HPP
