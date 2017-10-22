#ifndef BULL_CORE_WINDOW_WINDOW_HPP
#define BULL_CORE_WINDOW_WINDOW_HPP

#include <memory>

#include <Bull/Core/Configuration/Integer.hpp>
#include <Bull/Core/Pattern/NonCopyable.hpp>
#include <Bull/Core/Memory/String.hpp>
#include <Bull/Core/Window/Cursor.hpp>
#include <Bull/Core/Window/VideoMode.hpp>
#include <Bull/Core/Window/WindowEvent.hpp>
#include <Bull/Core/Window/WindowStyle.hpp>

#include <Bull/Math/Vector/Vector2.hpp>

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

        /*! \brief Get the fullscreen window
         *
         * \return Return a pointer to the window in fullscreen
         *
         */
        static const Window* getFullscreen();

    protected:

        static Window* s_fullscreen;

    public:

        /*! \brief Default constructor
         *
         */
        Window();

        /*! \brief Constructor
         *
         * \param mode  The VideoMode
         * \param title The title of the window
         * \param style The window decorations
         *
         */
        Window(const VideoMode& mode, const String& title, Uint32 style = WindowStyle::Default);

        /*! \brief Destructor
         *
         */
        virtual ~Window();

        /*! \brief Open the window
         *
         * \param mode  The VideoMode
         * \param title The title of the window
         * \param style The window decorations
         *
         * \return Return true if the window was open successfully, false otherwise
         *
         */
        virtual bool open(const VideoMode& mode, const String& title, Uint32 style = WindowStyle::Default);

        /*! \brief Check if the window is open
         *
         * \return Return true if the window is open, else return false
         *
         */
        bool isOpen() const;

        /*! \brief Close the window
         *
         */
        void close();

        /*! \brief Get the first event on the stack without blocking the current thread
         *
         * \param e An event to fill
         *
         * \return Return true if the event stack was not empty, else return false
         *
         */
        bool pollEvent(WindowEvent& e);

        /*! \brief Get the first event on the stack and blocking the current thread
         *
         * \return Return the first event of the stack
         *
         */
        WindowEvent nextEvent();

        /*! \brief Enable or disable the capture of the cursor inside the window
         *
         * \param enable The state of the capture
         *
         * \return This
         *
         */
        Window& enableCaptureCursor(bool enable = true);

        /*! \brief Minimize a window
         *
         * \return This
         *
         */
        Window& minimize();

        /*! \brief Check if the window is minimized
         *
         * \return True if the window is minimized
         *
         */
        bool isMinimized() const;

        /*! \brief Maximize a window
         *
         * \return This
         *
         */
        Window& maximize();

        /*! \brief Check if the window is maximized
         *
         * \return Return true if the window is maximized, false otherwise
         *
         */
        bool isMaximized() const;

        /*! \brief Set the window position
         *
         * \param position The new position of the window
         *
         */
        Window& setPosition(const Vector2I& position);

        /*! \brief Set the window position
         *
         * \param x The new position of the left side of the window in the screen
         * \param y The new position of the top of the window in the screen
         *
         * \return This
         *
         */
        Window& setPosition(int x, int y);

        /*! \brief Get the position in the screen of the window
         *
         * \return Return the window position
         *
         */
        Vector2I getPosition() const;

        /*! \brief Set the minimal size of the window
         *
         * \param size The minimal size of the window
         *
         * \return This
         *
         */
        Window& setMinSize(const Vector2I& size);

        /*! \brief Set the minimal size of the window
         *
         * \param width  The minimal width of the window
         * \param height The minimal height of the window
         *
         * \return This
         *
         */
        Window& setMinSize(int width, int height);

        /*! \brief Get the minimal size of the window
         *
         * \return The minimal size
         *
         */
        Vector2I getMinSize() const;

        /*! \brief Set the maximal size of the window
         *
         * \param size The maximal size of the window
         *
         * \return This
         *
         */
        Window& setMaxSize(const Vector2I& size);

        /*! \brief Set the maximal size of the window
         *
         * \param width  The maximal width of the window
         * \param height The maximal height of the window
         *
         * \return This
         *
         */
        Window& setMaxSize(int width, int height);

        /*! \brief Get the maximal size of the window
         *
         * \return The maximal size
         *
         */
        Vector2I getMaxSize() const;

        /*! \brief Set the size of the window
         *
         * \param size The new size of the window
         *
         * \return This
         *
         */
        Window& setSize(const Vector2UI& size);

        /*! \brief Set the size of the window
         *
         * \param x The new width of the window
         * \param y The new height of the window
         *
         * \return This
         *
         */
        Window& setSize(unsigned int x, unsigned int y);

        /*! \brief Get the size of the window
         *
         * \return Return the size of the window
         *
         */
        Vector2UI getSize() const;

        /*! \brief Set the title of the window
         *
         * \param title The new title of the window
         *
         * \return This
         *
         */
        Window& setTitle(const String& title);

        /*! \brief Get the title of the window
         *
         * \return Return the title of the window
         *
         */
        String getTitle() const;

        /*! \brief Enable or disable the key repeat
         *
         * \param enable The state of the key repeat
         *
         * \return This
         *
         */
        Window& enableKeyRepeat(bool enable = true);

        /*! \brief Get the state of the key repeat
         *
         * \return True if the key repeat is enable
         *
         */
        bool isKeyRepeatEnable() const;

        /*! \brief Check if the window has the focus
         *
         * \return True if the window has the focus
         *
         */
        bool hasFocus() const;

        /*! \brief Show or hide the window
         *
         * \param visible True to show the window, false to hide the window
         *
         * \return This
         *
         */
        Window& setVisible(bool visible = true);

        /*! \brief Set the icon of the Window
         *
         * \param icon The icon
         *
         * \return This
         *
         */
        Window& setIcon(const Image& icon);

        /*! \brief Set the mouse cursor of the Window
         *
         * \param cursor The cursor
         *
         * \return This
         *
         */
        Window& setMouseCursor(const Cursor& cursor);

        /*! \brief Toggle cursor visibility
         *
         * \param visible True to show the cursor, false to hide
         *
         * \return This
         *
         */
        Window& setMouseCursorVisible(bool visible = false);

        /*! \brief Check whether the mouse cursor is visible
         *
         * \return True if the mouse cursor is visible
         *
         */
        bool isMouseCursorVisible() const;

        /*! \brief Enter or leave the fullscreen mode
         *
         * \param enable False to leave the fullscreen mode, true to enter the fullscreen mode
         *
         * \return True if the switch was done successfully
         *
         */
        bool enableFullscreen(bool enable = true);

        /*! \brief Check if a window is in fullscreen
         *
         * \return Return true if the window is in fullscreen, false otherwise
         *
         */
        bool isFullscreenEnable() const;

    protected:

        friend class MessageWindow;

        /*! \brief Function called when the Window is opened
         *
         */
        virtual void onOpen() {}

        /*! \brief Function called when the Window is resized
         *
         */
        virtual void onResize() {}

        /*! \brief Function called when the Window is closed
         *
         */
        virtual void onClose() {}

        /*! \brief Get the implementation of the Window
         *
         * \return The implementation
         *
         */
        const std::unique_ptr<prv::WindowImpl>& getImpl() const;

    private:

        /*! \brief Filter events to start callbacks
         *
         * \param e The event to filter
         *
         */
        void filterEvent(const WindowEvent& e);

        std::unique_ptr<prv::WindowImpl> m_impl;             /*!< The OS specific implementation of the window */
        bool                             m_ignoreNextMouse;  /*!< True to ignore the next mouse event due to cursor centering */
    };
}

#endif // BULL_CORE_WINDOW_WINDOW_HPP
