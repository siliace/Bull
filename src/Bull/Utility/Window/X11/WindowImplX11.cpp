#include <X11/keysym.h>

#include <Bull/Core/Thread/Thread.hpp>

#include <Bull/Render/Context/Glx/GlxContext.hpp>

#include <Bull/Utility/Window/X11/ErrorHandler.hpp>
#include <Bull/Utility/Window/X11/WindowImplX11.hpp>

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
            const long eventMasks = KeyPressMask         | KeyReleaseMask    | /// Keyboard events
                                    PointerMotionMask    | ButtonMotionMask  | /// Mouse move events
                                    ButtonPressMask      | ButtonReleaseMask | /// Mouse buttons events
                                    FocusChangeMask      |                     /// Focus events
                                    StructureNotifyMask  |                     /// Resize events
                                    VisibilityChangeMask |                     /// Visibility change (internal uses only)
                                    EnterWindowMask      | LeaveWindowMask;    /// Mouse Enter/Leave

        }

        Keyboard::Key WindowImplX11::convertXKToBullkey(KeySym xkey)
        {
            switch(xkey)
            {
                case XK_a:           return Keyboard::Key::A;
                case XK_b:           return Keyboard::Key::B;
                case XK_c:           return Keyboard::Key::C;
                case XK_d:           return Keyboard::Key::D;
                case XK_e:           return Keyboard::Key::E;
                case XK_f:           return Keyboard::Key::F;
                case XK_g:           return Keyboard::Key::G;
                case XK_h:           return Keyboard::Key::H;
                case XK_i:           return Keyboard::Key::I;
                case XK_j:           return Keyboard::Key::J;
                case XK_k:           return Keyboard::Key::K;
                case XK_l:           return Keyboard::Key::L;
                case XK_m:           return Keyboard::Key::M;
                case XK_n:           return Keyboard::Key::N;
                case XK_o:           return Keyboard::Key::O;
                case XK_p:           return Keyboard::Key::P;
                case XK_q:           return Keyboard::Key::Q;
                case XK_r:           return Keyboard::Key::R;
                case XK_s:           return Keyboard::Key::S;
                case XK_t:           return Keyboard::Key::T;
                case XK_u:           return Keyboard::Key::U;
                case XK_v:           return Keyboard::Key::V;
                case XK_w:           return Keyboard::Key::W;
                case XK_x:           return Keyboard::Key::X;
                case XK_y:           return Keyboard::Key::Y;
                case XK_z:           return Keyboard::Key::Z;
                case XK_0:           return Keyboard::Key::Num0;
                case XK_1:           return Keyboard::Key::Num1;
                case XK_2:           return Keyboard::Key::Num2;
                case XK_3:           return Keyboard::Key::Num3;
                case XK_4:           return Keyboard::Key::Num4;
                case XK_5:           return Keyboard::Key::Num5;
                case XK_6:           return Keyboard::Key::Num6;
                case XK_7:           return Keyboard::Key::Num7;
                case XK_8:           return Keyboard::Key::Num8;
                case XK_9:           return Keyboard::Key::Num9;
                case XK_Num_Lock:    return Keyboard::Key::NumLock;
                case XK_KP_0:        return Keyboard::Key::NumPad0;
                case XK_KP_1:        return Keyboard::Key::NumPad1;
                case XK_KP_2:        return Keyboard::Key::NumPad2;
                case XK_KP_3:        return Keyboard::Key::NumPad3;
                case XK_KP_4:        return Keyboard::Key::NumPad4;
                case XK_KP_5:        return Keyboard::Key::NumPad5;
                case XK_KP_6:        return Keyboard::Key::NumPad6;
                case XK_KP_7:        return Keyboard::Key::NumPad7;
                case XK_KP_8:        return Keyboard::Key::NumPad8;
                case XK_KP_9:        return Keyboard::Key::NumPad9;
                case XK_KP_Enter:    return Keyboard::Key::NumPadEnter;
                case XK_KP_Add:      return Keyboard::Key::Add;
                case XK_KP_Subtract: return Keyboard::Key::Substract;
                case XK_KP_Multiply: return Keyboard::Key::Multiply;
                case XK_KP_Divide:   return Keyboard::Key::Divide;
                case XK_F1:          return Keyboard::Key::F1;
                case XK_F2:          return Keyboard::Key::F2;
                case XK_F3:          return Keyboard::Key::F3;
                case XK_F4:          return Keyboard::Key::F4;
                case XK_F5:          return Keyboard::Key::F5;
                case XK_F6:          return Keyboard::Key::F6;
                case XK_F7:          return Keyboard::Key::F7;
                case XK_F8:          return Keyboard::Key::F8;
                case XK_F9:          return Keyboard::Key::F9;
                case XK_F10:         return Keyboard::Key::F10;
                case XK_F11:         return Keyboard::Key::F11;
                case XK_F12:         return Keyboard::Key::F12;
                case XK_F13:         return Keyboard::Key::F13;
                case XK_F14:         return Keyboard::Key::F14;
                case XK_F15:         return Keyboard::Key::F15;
                case XK_F16:         return Keyboard::Key::F16;
                case XK_F17:         return Keyboard::Key::F17;
                case XK_F18:         return Keyboard::Key::F18;
                case XK_F19:         return Keyboard::Key::F19;
                case XK_F20:         return Keyboard::Key::F20;
                case XK_F21:         return Keyboard::Key::F21;
                case XK_F22:         return Keyboard::Key::F22;
                case XK_F23:         return Keyboard::Key::F23;
                case XK_F24:         return Keyboard::Key::F24;
                case XK_Left:        return Keyboard::Key::Left;
                case XK_Right:       return Keyboard::Key::Right;
                case XK_Up:          return Keyboard::Key::Up;
                case XK_Down:        return Keyboard::Key::Down;
                case XK_space:       return Keyboard::Key::Space;
                case XK_Escape:      return Keyboard::Key::Escape;
                case XK_Control_L:   return Keyboard::Key::LeftControl;
                case XK_Control_R:   return Keyboard::Key::RightControl;
                case XK_Alt_L:       return Keyboard::Key::LeftAlt;
                case XK_Alt_R:       return Keyboard::Key::RightAlt;
                case XK_Super_L:     return Keyboard::Key::LeftSystem;
                case XK_Super_R:     return Keyboard::Key::RightSystem;
                case XK_Shift_L:     return Keyboard::Key::LeftShift;
                case XK_Shift_R:     return Keyboard::Key::RightShift;
                default:             return Keyboard::Key::Unknown;
            }
        }

        WindowImplX11::WindowImplX11(const VideoMode& mode, const String& title, Uint32 style, const ContextSettings& settings) :
            m_display(Display::get()),
            m_handler(0),
            m_isMapped(false),
            m_captureCursor(false)
        {
            XVisualInfo*         vi;
            GLXFBConfig          config;
            ErrorHandler         handler;
            XSetWindowAttributes attributes;

            config = GlxContext::chooseBestConfig(m_display, settings, mode.bitsPerPixel);

            vi = glXGetVisualFromFBConfig(m_display->getHandler(), config);

            m_colormap = XCreateColormap(m_display->getHandler(), m_display->getRootWindow(vi->screen), vi->visual, AllocNone);

            attributes.background_pixmap = XNone;
            attributes.colormap          = m_colormap;
            attributes.border_pixel      = 0;
            attributes.event_mask        = eventMasks;

            m_handler = XCreateWindow(m_display->getHandler(),
                                      m_display->getRootWindow(vi->screen),
                                      0, 0,
                                      mode.width, mode.height,
                                      0,
                                      vi->depth,
                                      InputOutput,
                                      vi->visual,
                                      CWColormap | CWEventMask | CWBorderPixel,
                                      &attributes);
            setProtocols();

            setTitle(title);

            m_lastPosition = getPosition();
            m_lastSize     = getSize();

            setVisible(true);
        }

        WindowImplX11::~WindowImplX11()
        {
            if(m_handler)
            {
                XDestroyWindow(m_display->getHandler(), m_handler);
            }

            XFreeColormap(m_display->getHandler(), m_colormap);
        }

        void WindowImplX11::startProcessEvents()
        {
            XEvent e;
            while(XPending(m_display->getHandler()))
            {
                XNextEvent(m_display->getHandler(), &e);
                switch(e.type)
                {
                    case ClientMessage:
                    {
                        static Atom atomDelete = m_display->getAtom("WM_DELETE_WINDOW");

                        if(e.xclient.message_type == m_display->getAtom("WM_PROTOCOLS"))
                        {
                            if(e.xclient.data.l[0] == static_cast<long>(atomDelete))
                            {
                                Window::Event e;

                                e.type = Window::Event::Closed;

                                pushEvent(e);
                            }
                        }
                    }
                    break;

                    case KeyPress:
                    {
                        Window::Event event;
                        Keyboard::Key key = Keyboard::Key::Unknown;

                        for(int i = 0; i < 4 && key == Keyboard::Key::Unknown; i++)
                        {
                            key = convertXKToBullkey(XLookupKeysym(&e.xkey, i));
                        }

                        event.type        = Window::Event::KeyDown;
                        event.key.code    = key;
                        event.key.alt     = e.xkey.state & Mod1Mask;
                        event.key.control = e.xkey.state & ControlMask;
                        event.key.shift   = e.xkey.state & ShiftMask;
                        event.key.system  = e.xkey.state & Mod4Mask;

                        pushEvent(event);
                    }
                    break;

                    case KeyRelease:
                    {
                        Window::Event event;
                        Keyboard::Key key = Keyboard::Key::Unknown;

                        for(int i = 0; i < 4 && key == Keyboard::Key::Unknown; i++)
                        {
                            key = convertXKToBullkey(XLookupKeysym(&e.xkey, i));
                        }

                        event.type        = Window::Event::KeyUp;
                        event.key.code    = key;
                        event.key.alt     = e.xkey.state & Mod1Mask;
                        event.key.control = e.xkey.state & ControlMask;
                        event.key.shift   = e.xkey.state & ShiftMask;
                        event.key.system  = e.xkey.state & Mod4Mask;

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

                    case FocusIn:
                    {
                        Window::Event event;

                        event.type = Window::Event::GainFocus;

                        if(m_captureCursor)
                        {
                            bool grabbed = false;

                            do
                            {
                                grabbed = XGrabPointer(m_display->getHandler(), m_handler, True, XNone, GrabModeAsync, GrabModeAsync, m_handler, XNone, CurrentTime) != GrabSuccess;

                                if(!grabbed)
                                {
                                    Thread::sleep(Time::milliseconds(10.f));
                                }
                            }while(!grabbed);
                        }

                        pushEvent(event);
                    }
                    break;

                    case FocusOut:
                    {
                        Window::Event event;

                        event.type = Window::Event::LostFocus;

                        if(m_captureCursor)
                        {
                            XUndefineCursor(m_display->getHandler(), CurrentTime);
                            m_display->flush();
                        }

                        pushEvent(event);
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

                    case EnterNotify:
                    {
                        Window::Event event;

                        event.type = Window::Event::MouseEnter;

                        pushEvent(event);
                    }
                    break;

                    case LeaveNotify:
                    {
                        Window::Event event;

                        event.type = Window::Event::MouseLeave;

                        pushEvent(event);
                    }
                    break;

                    case UnmapNotify:
                    {
                        if(e.xunmap.window == m_handler)
                        {
                            m_isMapped = false;
                        }
                    }
                    break;

                    case VisibilityNotify:
                    {
                        if(e.xvisibility.state != VisibilityFullyObscured)
                        {
                            m_isMapped = true;
                        }
                    }
                    break;
                }
            }
        }

        void WindowImplX11::minimize()
        {

        }

        bool WindowImplX11::isMinimized() const
        {
            return false;
        }

        void WindowImplX11::maximize()
        {

        }

        bool WindowImplX11::isMaximized() const
        {
            return false;
        }

        void WindowImplX11::enableCaptureCursor(bool capture)
        {
            m_captureCursor = capture;

            if(m_captureCursor)
            {
                bool grabbed = false;

                do
                {
                    grabbed = XGrabPointer(m_display->getHandler(), m_handler, True, XNone, GrabModeAsync, GrabModeAsync, m_handler, XNone, CurrentTime) != GrabSuccess;

                    if(!grabbed)
                    {
                        Thread::sleep(Time::milliseconds(10.f));
                    }
                }while(!grabbed);
            }
            else
            {
                XUngrabPointer(m_display->getHandler(), CurrentTime);
                m_display->flush();
            }
        }

        void WindowImplX11::showCursor(bool enable)
        {

        }

        void WindowImplX11::setPosition(const Vector2I& position)
        {
            XMoveWindow(m_display->getHandler(), m_handler, position.x, position.y);
            m_lastPosition = position;
            m_display->flush();
        }

        Vector2I WindowImplX11::getPosition() const
        {
            ::Window root, child;
            int localX, localY, x, y;
            unsigned int width, height, border, depth;

            XGetGeometry(m_display->getHandler(), m_handler, &root, &localX, &localY, &width, &height, &border, &depth);
            XTranslateCoordinates(m_display->getHandler(), m_handler, root, localX, localY, &x, &y, &child);

            return Vector2I(x, y);
        }

        void WindowImplX11::setSize(const Vector2UI& size)
        {
            XResizeWindow(m_display->getHandler(), m_handler, size.x, size.y);
            m_lastSize = size;
            m_display->flush();
        }

        Vector2UI WindowImplX11::getSize() const
        {
            XWindowAttributes attributes;

            XGetWindowAttributes(m_display->getHandler(), m_handler, &attributes);

            return Vector2UI(attributes.width, attributes.height);
        }

        void WindowImplX11::setTitle(const String& title)
        {
            XStoreName(m_display->getHandler(), m_handler, title);
        }

        String WindowImplX11::getTitle() const
        {
            String title;
            char* buffer = new char[256];

            XFetchName(m_display->getHandler(), m_handler, &buffer);

            title.set(buffer);

            XFree(buffer);

            return title;
        }

        bool WindowImplX11::hasFocus() const
        {
            return false;
        }

        void WindowImplX11::switchFullscreen(bool fullscreen)
        {

        }

        void WindowImplX11::setVisible(bool visible)
        {
            if(visible)
            {
                XMapWindow(m_display->getHandler(), m_handler);
                m_display->flush();

                while(!m_isMapped)
                {
                    startProcessEvents();
                }
            }
            else
            {
                XUnmapWindow(m_display->getHandler(), m_handler);
                m_display->flush();

                while(m_isMapped)
                {
                    startProcessEvents();
                }
            }
        }

        WindowHandler WindowImplX11::getSystemHandler() const
        {
            return m_handler;
        }

        void WindowImplX11::setProtocols()
        {
            Atom wmDeleteWindow = m_display->getAtom("WM_DELETE_WINDOW");

            XSetWMProtocols(m_display->getHandler(), m_handler, &wmDeleteWindow, 1);
        }
    }
}
