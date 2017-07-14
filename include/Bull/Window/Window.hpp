#ifndef BULL_WINDOW_WINDOW_HPP
#define BULL_WINDOW_WINDOW_HPP

#include <memory>

#include <Bull/Core/System/Integer.hpp>
#include <Bull/Core/Pattern/NonCopyable.hpp>
#include <Bull/Core/Memory/String.hpp>

#include <Bull/Hardware/Joystick.hpp>
#include <Bull/Hardware/Keyboard.hpp>
#include <Bull/Hardware/Mouse.hpp>

#include <Bull/Math/Vector/Vector2.hpp>

#include <Bull/Window/Cursor.hpp>
#include <Bull/Window/VideoMode.hpp>

namespace Bull
{
    class ContextSettings;

    namespace prv
    {
        class WindowImpl;
    }

    class BULL_WINDOW_API Window : public NonCopyable
    {
    public:

        /*! \brief Get the fullscreen window
         *
         * \return Return a pointer to the window in fullscreen
         *
         */
        static const Window* getFullscreen();

        struct Event
        {
            enum Type
            {
                Closed,
                Resized,
                Moved,
                KeyUp,
                KeyDown,
                Character,
                MouseEnter,
                MouseLeave,
                MouseMoved,
                MouseButtonUp,
                MouseButtonDown,
                MouseButtonDoubleClicked,
                MouseWheel,
                LostFocus,
                GainFocus,
                JoystickButtonUp,
                JoystickButtonDown,
                JoystickMoved,
                JoystickConnected,
                JoystickDisconnected,
            };

            struct WindowResizedEvent
            {
                unsigned int width;
                unsigned int height;
            };

            struct WindowMovedEvent
            {
                int x, y;
                int xRel, yRel;
            };

            struct KeyEvent
            {
                Keyboard::Key code;
                bool          alt;
                bool          control;
                bool          shift;
                bool          system;
            };

            struct MouseMoveEvent
            {
                int x, y;
                int xRel, yRel;
            };

            struct MouseButtonEvent
            {
                int x, y;
                Mouse::Button button;
            };

            struct MouseWheelEvent
            {
                bool up;
                int x, y;
                Mouse::Wheel wheel;
            };

            struct JoystickConnectionEvent
            {
                Uint8 joystick;
            };

            struct JoystickMovedEvent
            {
                Uint8 joystick;
                float position;
                float relative;
                Joystick::Axis axis;
            };

            struct JoystickButtonEvent
            {
                Uint8 joystick;
                Uint8 button;
            };

            union
            {
                WindowResizedEvent      windowResize;
                WindowMovedEvent        windowMove;
                KeyEvent                key;
                Uint32                  character;
                MouseMoveEvent          mouseMove;
                MouseButtonEvent        mouseButton;
                MouseWheelEvent         mouseWheel;
                JoystickConnectionEvent joystickConnection;
                JoystickMovedEvent      joystickMoved;
                JoystickButtonEvent     joystickButton;
            };

            Type type;
        };

        enum Style
        {
            None        = 0x0,  /*!< The Window do not have any decoration */

            Visible     = 0x1,  /*!< The Window is visible */
            Closable    = 0x2,  /*!< The Window has a exit button */
            Minimizable = 0x4,  /*!< The Window has a minimize button */
            Maximizable = 0x8,  /*!< The Window has a maximize button */
            Resizable   = 0x16, /*!< The Window is resizable with drag&drop */

            Fullscreen  = 0x32, /*!< The Window is in full screen */

            Default     = Visible | Closable | Minimizable | Maximizable | Resizable
        };

    protected:

        static Window* s_fullscreen;

    public:

        /*! \brief Default constructor
         *
         */
        Window() = default;

        /*! \brief Constructor
         *
         * \param mode  The VideoMode
         * \param title The title of the window
         * \param style The window decorations
         *
         */
        Window(const VideoMode& mode, const String& title, Uint32 style = Style::Default);

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
        virtual bool open(const VideoMode& mode, const String& title, Uint32 style = Style::Default);

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
        bool pollEvent(Event& e);

        /*! \brief Get the first event on the stack and blocking the current thread
         *
         * \return Return the first event of the stack
         *
         */
        Event nextEvent();

        /*! \brief Enable or disable the capture of the cursor inside the window
         *
         * \param enable The state of the capture
         *
         */
        Window& enableCaptureCursor(bool enable = true);

        /*! \brief Minimize a window
         *
         */
        Window& minimize();

        /*! \brief Check if the window is minimized
         *
         * \return Return true if the window is minimized, false otherwise
         *
         */
        bool isMinimized() const;

        /*! \brief Maximize a window
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
         */
        Window& setSize(const Vector2UI& size);

        /*! \brief Set the size of the window
         *
         * \param x The new width of the window
         * \param y The new height of the window
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
         */
        Window& enableKeyRepeat(bool enable = true);

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
        bool hasFocus() const;

        /*! \brief Show or hide the window
         *
         * \param visible True to show the window, false to hide the window
         *
         */
        Window& setVisible(bool visible = true);

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
         * \param fullscreen False to leave the fullscreen mode, true to enter the fullscreen mode
         *
         * \return Return true if the switch was done successfully, false otherwise
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
        void filterEvent(const Event& e);

        std::unique_ptr<prv::WindowImpl> m_impl; /*!< The OS specific implementation of the window */
    };
}

#endif // BULL_WINDOW_WINDOW_HPP
