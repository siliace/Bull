#ifndef Bull_Window_hpp
#define Bull_Window_hpp

#include <memory>

#include <Bull/Core/System/Export.hpp>
#include <Bull/Core/Integer.hpp>
#include <Bull/Core/Pattern/NonCopyable.hpp>
#include <Bull/Core/String.hpp>

#include <Bull/Hardware/Joystick.hpp>
#include <Bull/Hardware/Keyboard.hpp>
#include <Bull/Hardware/Mouse.hpp>

#include <Bull/Math/Vector/Vector2.hpp>

#include <Bull/Render/Context/ContextResource.hpp>
#include <Bull/Render/Context/ContextSettings.hpp>

#include <Bull/Window/VideoMode.hpp>
#include <Bull/Window/WindowHandler.hpp>

#ifdef None
    #undef None
#endif

namespace Bull
{
    namespace prv
    {
        class WindowImpl;
        class GlContext;
    }

    class BULL_API Window : public ContextResource, public NonCopyable
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
                KeyDown,
                KeyUp,
                MouseMoved,
                MouseButtonUp,
                MouseButtonDown,
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
                int x;
                int y;
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
                int x;
                int y;
            };

            struct MouseButtonEvent
            {
                Mouse::Button button;

                int x;
                int y;
            };

            struct MouseWheelEvent
            {
                Mouse::Wheel wheel;

                bool up;

                int x;
                int y;
            };

            struct JoystickConnectionEvent
            {
                Uint8 joystick;
            };

            struct JoystickMovedEvent
            {
                Uint8 joystick;
                Joystick::Axis axis;
                float position;
                float relative;
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

    private:

        static Window* m_fullscreen;

    public:

        /*! \brief Default constructor
         *
         */
        Window();

        /*! \brief Constructor
         *
         * \param mode The VideoMode desired
         * \param title The title of the window
         * \param style The window decoration desired
         * \param settings Parameters to create the OpenGL context
         *
         */
        Window(const VideoMode& mode, const String& title, Uint32 style = Style::Default, const ContextSettings& settings = ContextSettings());

        /*! \brief Destructor
         *
         */
        virtual ~Window();

        /*! \brief Open the window. If a window was already opened, its closed
         *
         * \param mode The VideoMode of desired
         * \param title The title of the window
         * \param style The window decoration desired
         * \param settings Parameters to create the OpenGL context
         *
         * \return Return true if the window was open successfully
         *
         */
        bool open(const VideoMode& mode, const String& title, Uint32 style = Style::Default, const ContextSettings& settings = ContextSettings());

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

        /*! \brief Activate or deactivate the context
         *
         * \param active True to activate, false to deactivate the context
         *
         * \return Return true if the context's status changed successfully, false otherwise
         *
         */
        bool setActive(bool active = true);

        /*! \brief Display what has been rendered so far
         *
         */
        void display();

        /*! \brief Enable or disable the capture of the cursor inside the window
         *
         * \param enable The state of the capture
         *
         */
        void enableCaptureCursor(bool enable = true);

        /*! \brief Hide or the cursor
         *
         * \param enable The state of the cursor
         *
         */
        void showCursor(bool enable = true);

        /*! \brief Minimize a window
         *
         */
        void minimize();

        /*! \brief Check if the window is minimized
         *
         * \return Return true if the window is minimized, false otherwise
         *
         */
        bool isMinimized() const;

        /*! \brief Maximize a window
         *
         */
        void maximize();

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
        void setPosition(const Vector2I& position);

        /*! \brief Set the window position
         *
         * \param x The new position of the left side of the window in the screen
         * \param y The new position of the top of the window in the screen
         *
         */
        void setPosition(int x, int y);

        /*! \brief Get the position in the screen of the window
         *
         * \return Return the window position
         *
         */
        Vector2I getPosition() const;

        /*! \brief Set the size of the window
         *
         * \param size The new size of the window
         *
         */
        void setSize(const Vector2UI& size);

        /*! \brief Set the size of the window
         *
         * \param x The new width of the window
         * \param y The new height of the window
         *
         */
        void setSize(unsigned int x, unsigned int y);

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
        void setTitle(const String& title);

        /*! \brief Get the title of the window
         *
         * \return Return the title of the window
         *
         */
        String getTitle() const;

        /*! \brief Get ContextSettings used to create the context
         *
         * \return Return the ContextSettings
         *
         */
        const ContextSettings& getSettings() const;

        /*! \brief Enable or disable the key repeat
         *
         * \param enable The state of the key repeat
         *
         */
        void enableKeyRepeat(bool enable = true);

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
        void setVisible(bool visible = true);

        /*! \brief Check if a window is in fullscreen
         *
         * \return Return true if the window is in fullscreen, false otherwise
         *
         */
        bool isFullscreen() const;

        /*! \brief Enter or leave the fullscreen mode
         *
         * \param mode The VideoMode to use
         * \param fullscreen False to leave the fullscreen mode, true to enter the fullscreen mode
         *
         * \return Return true if the switch was done successfully, false otherwise
         *
         */
        bool switchFullscreen(const VideoMode& mode = VideoMode::getCurrent(), bool fullscreen = true);

        /*! \brief Get the window system handler
         *
         * \return Return the native window system handler
         *
         */
        WindowHandler getSystemHandler() const;

    private:

        std::unique_ptr<prv::WindowImpl> m_impl;    /*!< The OS specific implementation of the window */
        std::unique_ptr<prv::GlContext>  m_context; /*!< The OS specific implementation of the OpenGL context */
    };
}

#endif // Bull_Window_hpp
