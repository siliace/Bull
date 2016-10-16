#include <Bull/Window/X11/WindowImplX11.hpp>

#ifndef Button6
    #define Button6 6
#endif // Button6

#ifndef Button7
    #define Button7 7
#endif // Button6

#ifndef Button8
    #define Button8 8
#endif // Button6

#ifndef Button9
    #define Button9 9
#endif // Button6

namespace Bull
{
    namespace prv
    {
        namespace
        {
            const long eventMasks = KeyPressMask        | KeyReleaseMask    | /// Keyboard events
                                    PointerMotionMask   | ButtonMotionMask  | /// Mouse move events
                                    ButtonPressMask     | ButtonReleaseMask | /// Mouse buttons events
                                    FocusChangeMask     |                     /// Focus events
                                    StructureNotifyMask;                      /// Resize events

        }
        /*! \brief Constructor
         *
         * \param mode The VideoMode to use to create the window
         * \param title The title of the window
         * \param style The style to use to create the window
         *
         */
        WindowImplX11::WindowImplX11(const VideoMode& mode, const String& title, Uint32 style) :
            m_display(Display::get()),
            m_handler(0),
            m_lastSize(mode.width, mode.height),
            m_lastPosition(0, 0)
        {
            XSetWindowAttributes attribs;
            attribs.event_mask = eventMasks;

            m_handler = XCreateWindow(m_display->getHandler(),
                                      m_display->getRootWindow(),
                                      0, 0,
                                      mode.width, mode.height,
                                      0,
                                      CopyFromParent,
                                      InputOutput,
                                      nullptr,
                                      CWEventMask | CWBackPixel,
                                      &attribs);

            setTitle(title);

            XMapWindow(m_display->getHandler(), m_handler);
            m_display->flush();
        }

        /*! \brief Destructor
         *
         */
        WindowImplX11::~WindowImplX11()
        {
            XDestroyWindow(m_display->getHandler(), m_handler);
        }

        /*! \brief Start to process events to fill event queue
         *
         */
        void WindowImplX11::startProcessEvents()
        {
            XEvent e;
            while(XPending(m_display->getHandler()))
            {
                XNextEvent(m_display->getHandler(), &e);
                switch(e.type)
                {
                    case KeyPress:
                    {
                        Window::Event event;

                        event.type = Window::Event::KeyDown;

                        pushEvent(event);
                    }
                    break;

                    case KeyRelease:
                    {
                        Window::Event event;

                        event.type = Window::Event::KeyUp;

                        pushEvent(event);
                    }
                    break;

                    case MotionNotify:
                    {
                        Window::Event event;

                        event.type        = Window::Event::MouseMoved;
                        event.mouseMove.x = e.xmotion.x;
                        event.mouseMove.y = e.xmotion.y;

                        pushEvent(event);
                    }
                    break;

                    case ButtonPress:
                    {
                        Window::Event event;

                        if(e.xbutton.button <= Button3 || e.xbutton.button >= Button8)
                        {
                            event.type          = Window::Event::MouseButtonDown;
                            event.mouseButton.x = e.xbutton.x;
                            event.mouseButton.y = e.xbutton.y;

                        }
                        else
                        {
                            event.type         = Window::Event::MouseWheel;
                            event.mouseWheel.x = e.xbutton.x;
                            event.mouseWheel.y = e.xbutton.y;
                        }

                        switch(e.xbutton.button)
                        {
                            case Button1:
                                event.mouseButton.button = Mouse::Left;
                            break;
                            case Button2:
                                event.mouseButton.button = Mouse::Middle;
                            break;
                            case Button3:
                                event.mouseButton.button = Mouse::Right;
                            break;
                            case Button4:
                                event.mouseWheel.up      = true;
                                event.mouseWheel.wheel   = Mouse::Vertical;
                            break;
                            case Button5:
                                event.mouseWheel.up      = false;
                                event.mouseWheel.wheel   = Mouse::Vertical;
                            break;
                            case Button6:
                                event.mouseWheel.up      = true;
                                event.mouseWheel.wheel   = Mouse::Horizontal;
                            break;
                            case Button7:
                                event.mouseWheel.up      = false;
                                event.mouseWheel.wheel   = Mouse::Horizontal;
                            break;
                            case Button8:
                                event.mouseButton.button = Mouse::Extra1;
                            break;
                            case Button9:
                                event.mouseButton.button = Mouse::Extra2;
                            break;
                        }

                        pushEvent(event);
                    }
                    break;

                    case ButtonRelease:
                    {
                        if(e.xbutton.button <= Button3 || e.xbutton.button >= Button8)
                        {
                            Window::Event event;
                            event.type = Window::Event::MouseButtonUp;

                            switch(e.xbutton.button)
                            {
                                case Button1:
                                    event.mouseButton.button = Mouse::Left;
                                break;
                                case Button2:
                                    event.mouseButton.button = Mouse::Middle;
                                break;
                                case Button3:
                                    event.mouseButton.button = Mouse::Right;
                                break;
                                case Button8:
                                    event.mouseButton.button = Mouse::Extra1;
                                break;
                                case Button9:
                                    event.mouseButton.button = Mouse::Extra2;
                                break;
                            }

                            event.mouseButton.x = e.xbutton.x;
                            event.mouseButton.y = e.xbutton.y;

                            pushEvent(event);
                        }
                    }
                    break;

                    case ConfigureNotify:
                    {
                        Window::Event event;
                        Vector2UI size(e.xconfigure.width, e.xconfigure.height);
                        Vector2I  position(e.xconfigure.x, e.xconfigure.y);

                        if(size != m_lastSize)
                        {
                            event.type                = Window::Event::Resized;
                            event.windowResize.width  = size.x;
                            event.windowResize.height = size.y;

                            m_lastSize = size;
                        }
                        else
                        {
                            event.type         = Window::Event::Moved;
                            event.windowMove.x = position.x;
                            event.windowMove.y = position.y;

                            m_lastPosition = position;
                        }

                        pushEvent(event);
                    }
                    break;
                }
            }
        }

        /*! \brief Minimize a window
         *
         */
        void WindowImplX11::minimize()
        {

        }

        /*! \brief Check if the window is minimized
         *
         * \return Return true if the window is minimized, false otherwise
         *
         */
        bool WindowImplX11::isMinimized() const
        {

        }

        /*! \brief Maximize a window
         *
         */
        void WindowImplX11::maximize()
        {

        }

        /*! \brief Check if the window is maximized
         *
         * \return Return true if the window is maximized, false otherwise
         *
         */
        bool WindowImplX11::isMaximized() const
        {

        }

        /*! \brief Enable or disable the capture of the cursor inside the window
         *
         * \param enable The state of the capture
         *
         */
        void WindowImplX11::enableCaptureCursor(bool capture)
        {

        }

        /*! \brief Hide or show the cursor
         *
         * \param enable The state of the cursor
         *
         */
        void WindowImplX11::showCursor(bool enable)
        {

        }

        /*! \brief Set the size of the window
         *
         * \param size The new size of the window
         *
         */
        void WindowImplX11::setPosition(const Vector2I& position)
        {
            XMoveWindow(m_display->getHandler(), m_handler, position.x, position.y);
            m_lastPosition = position;
            m_display->flush();
        }

        /*! \brief Set the size of the window
         *
         * \param x The new width of the window
         * \param y The new height of the window
         *
         */
        Vector2I WindowImplX11::getPosition() const
        {
            return m_lastPosition;
        }

        /*! \brief Set the size of the window
         *
         * \param size The new size of the window
         *
         */
        void WindowImplX11::setSize(const Vector2UI& size)
        {
            XResizeWindow(m_display->getHandler(), m_handler, size.x, size.y);
            m_lastSize = size;
            m_display->flush();
        }

        /*! \brief Get the size of the window
         *
         * \return Return the size of the window
         *
         */
        Vector2UI WindowImplX11::getSize() const
        {
            return m_lastSize;
        }

        /*! \brief Set the title of the window
         *
         * \param title The title to set to the window
         *
         */
        void WindowImplX11::setTitle(const String& title)
        {
            XStoreName(m_display->getHandler(), m_handler, title);
        }

        /*! \brief Get the title of the window
         *
         * \return Return the title of the window
         *
         */
        String WindowImplX11::getTitle() const
        {

        }

        /*! \brief Check if the window has the focus
         *
         * \param Return true if the window has the focus, false otherwise
         *
         */
        bool WindowImplX11::hasFocus() const
        {

        }

        /*! \brief Enter or leave the fullscreen mode
         *
         * \param mode The VideoMode to use
         * \param fullscreen False to leave the fullscreen mode, true to enter the fullscreen mode
         *
         * \return Return true if the switch was done successfully, false otherwise
         *
         */
        bool WindowImplX11::switchFullscreen(const VideoMode& mode, bool fullscreen)
        {

        }

        /*! \brief Show or hide the window
         *
         * \param visible True to show the window, false to hide the window
         *
         */
        void WindowImplX11::setVisible(bool visible)
        {

        }

        /*! \brief Get the window system handler
         *
         * \return Return the native window system handler
         *
         */
        WindowHandler WindowImplX11::getSystemHandler() const
        {
            return m_handler;
        }
    }
}
