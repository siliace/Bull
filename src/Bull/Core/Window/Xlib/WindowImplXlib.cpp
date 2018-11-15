#include <thread>

#include <Bull/Core/Exception/InternalError.hpp>
#include <Bull/Core/Support/Xlib/ErrorHandler.hpp>
#include <Bull/Core/Support/Xlib/WMHints.hpp>
#include <Bull/Core/Window/WindowStyle.hpp>
#include <Bull/Core/Window/Xlib/WindowImplXlib.hpp>

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
        KeyboardKey WindowImplXlib::convertXKToBullkey(KeySym xkey)
        {
            switch(xkey)
            {
                case XK_a:           return KeyboardKey_A;
                case XK_b:           return KeyboardKey_B;
                case XK_c:           return KeyboardKey_C;
                case XK_d:           return KeyboardKey_D;
                case XK_e:           return KeyboardKey_E;
                case XK_f:           return KeyboardKey_F;
                case XK_g:           return KeyboardKey_G;
                case XK_h:           return KeyboardKey_H;
                case XK_i:           return KeyboardKey_I;
                case XK_j:           return KeyboardKey_J;
                case XK_k:           return KeyboardKey_K;
                case XK_l:           return KeyboardKey_L;
                case XK_m:           return KeyboardKey_M;
                case XK_n:           return KeyboardKey_N;
                case XK_o:           return KeyboardKey_O;
                case XK_p:           return KeyboardKey_P;
                case XK_q:           return KeyboardKey_Q;
                case XK_r:           return KeyboardKey_R;
                case XK_s:           return KeyboardKey_S;
                case XK_t:           return KeyboardKey_T;
                case XK_u:           return KeyboardKey_U;
                case XK_v:           return KeyboardKey_V;
                case XK_w:           return KeyboardKey_W;
                case XK_x:           return KeyboardKey_X;
                case XK_y:           return KeyboardKey_Y;
                case XK_z:           return KeyboardKey_Z;
                case XK_0:           return KeyboardKey_Num0;
                case XK_1:           return KeyboardKey_Num1;
                case XK_2:           return KeyboardKey_Num2;
                case XK_3:           return KeyboardKey_Num3;
                case XK_4:           return KeyboardKey_Num4;
                case XK_5:           return KeyboardKey_Num5;
                case XK_6:           return KeyboardKey_Num6;
                case XK_7:           return KeyboardKey_Num7;
                case XK_8:           return KeyboardKey_Num8;
                case XK_9:           return KeyboardKey_Num9;
                case XK_Num_Lock:    return KeyboardKey_NumLock;
                case XK_KP_0:        return KeyboardKey_NumPad0;
                case XK_KP_1:        return KeyboardKey_NumPad1;
                case XK_KP_2:        return KeyboardKey_NumPad2;
                case XK_KP_3:        return KeyboardKey_NumPad3;
                case XK_KP_4:        return KeyboardKey_NumPad4;
                case XK_KP_5:        return KeyboardKey_NumPad5;
                case XK_KP_6:        return KeyboardKey_NumPad6;
                case XK_KP_7:        return KeyboardKey_NumPad7;
                case XK_KP_8:        return KeyboardKey_NumPad8;
                case XK_KP_9:        return KeyboardKey_NumPad9;
                case XK_KP_Add:      return KeyboardKey_Add;
                case XK_KP_Subtract: return KeyboardKey_Subtract;
                case XK_KP_Multiply: return KeyboardKey_Multiply;
                case XK_KP_Divide:   return KeyboardKey_Divide;
                case XK_F1:          return KeyboardKey_F1;
                case XK_F2:          return KeyboardKey_F2;
                case XK_F3:          return KeyboardKey_F3;
                case XK_F4:          return KeyboardKey_F4;
                case XK_F5:          return KeyboardKey_F5;
                case XK_F6:          return KeyboardKey_F6;
                case XK_F7:          return KeyboardKey_F7;
                case XK_F8:          return KeyboardKey_F8;
                case XK_F9:          return KeyboardKey_F9;
                case XK_F10:         return KeyboardKey_F10;
                case XK_F11:         return KeyboardKey_F11;
                case XK_F12:         return KeyboardKey_F12;
                case XK_F13:         return KeyboardKey_F13;
                case XK_F14:         return KeyboardKey_F14;
                case XK_F15:         return KeyboardKey_F15;
                case XK_F16:         return KeyboardKey_F16;
                case XK_F17:         return KeyboardKey_F17;
                case XK_F18:         return KeyboardKey_F18;
                case XK_F19:         return KeyboardKey_F19;
                case XK_F20:         return KeyboardKey_F20;
                case XK_F21:         return KeyboardKey_F21;
                case XK_F22:         return KeyboardKey_F22;
                case XK_F23:         return KeyboardKey_F23;
                case XK_F24:         return KeyboardKey_F24;
                case XK_Left:        return KeyboardKey_Left;
                case XK_Right:       return KeyboardKey_Right;
                case XK_Up:          return KeyboardKey_Up;
                case XK_Down:        return KeyboardKey_Down;
                case XK_space:       return KeyboardKey_Space;
                case XK_Escape:      return KeyboardKey_Escape;
                case XK_Control_L:   return KeyboardKey_LeftControl;
                case XK_Control_R:   return KeyboardKey_RightControl;
                case XK_Alt_L:       return KeyboardKey_LeftAlt;
                case XK_Alt_R:       return KeyboardKey_RightAlt;
                case XK_Super_L:     return KeyboardKey_LeftSystem;
                case XK_Super_R:     return KeyboardKey_RightSystem;
                case XK_Shift_L:     return KeyboardKey_LeftShift;
                case XK_Shift_R:     return KeyboardKey_RightShift;
                default:             return KeyboardKey_Unknown;
            }
        }

        XCursor WindowImplXlib::createHiddenCursor(Display& display, XWindow window)
        {
            XPixmap cursorPixmap = XCreatePixmap(display.getHandler(), window, 1, 1, 1);
            XGC graphicsContext = XCreateGC(display.getHandler(), cursorPixmap, 0, nullptr);
            XDrawPoint(display.getHandler(), cursorPixmap, graphicsContext, 0, 0);
            XFreeGC(display.getHandler(), graphicsContext);

            XColor color;
            color.flags = DoRed | DoGreen | DoBlue;
            color.red = color.blue = color.green = 0;
            XCursor hidden = XCreatePixmapCursor(display.getHandler(), cursorPixmap, cursorPixmap, &color, &color, 0, 0);

            XFreePixmap(display.getHandler(), cursorPixmap);

            return hidden;
        }

        WindowImplXlib::WindowImplXlib(const VideoMode& mode, const String& title, Uint32 WindowStyle) :
            WindowImplXlib()
        {
            open(mode, title, WindowStyle);
        }

        WindowImplXlib::~WindowImplXlib()
        {
            if(m_colormap)
            {
                XFreeColormap(m_display.getHandler(), m_colormap);
            }

            if(m_hiddenCursor)
            {
                XFreeCursor(m_display.getHandler(), m_hiddenCursor);
            }

            if(m_handler)
            {
                XDestroyWindow(m_display.getHandler(), m_handler);
                m_display.flush();
            }
        }

        void WindowImplXlib::startProcessEvents()
        {
            XEvent e;
            while(XPending(m_display.getHandler()))
            {
                XNextEvent(m_display.getHandler(), &e);
                switch(e.type)
                {
                    case ClientMessage:
                    {
                        static XAtom atomDelete = m_display.getAtom("WM_DELETE_WINDOW");

                        if(e.xclient.message_type == m_display.getAtom("WM_PROTOCOLS"))
                        {
                            if(e.xclient.data.l[0] == static_cast<long>(atomDelete))
                            {
                                WindowEvent event;

                                event.type = WindowEventType_Closed;

                                pushEvent(event);
                            }
                        }
                    }
                    break;

                    case KeyPress:
                    {
                        WindowEvent event;
                        KeyboardKey key = KeyboardKey_Unknown;

                        for(int i = 0; i < 4 && key == KeyboardKey_Unknown; i++)
                        {
                            key = convertXKToBullkey(XLookupKeysym(&e.xkey, i));
                        }

                        event.type        = WindowEventType_KeyDown;
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
                        WindowEvent event;
                        KeyboardKey key = KeyboardKey_Unknown;

                        for(int i = 0; i < 4 && key == KeyboardKey_Unknown; i++)
                        {
                            key = convertXKToBullkey(XLookupKeysym(&e.xkey, i));
                        }

                        event.type        = WindowEventType_KeyUp;
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
                        WindowEvent event;

                        event.type           = WindowEventType_MouseMoved;
                        event.mouseMove.x    = e.xmotion.x;
                        event.mouseMove.y    = e.xmotion.y;
                        event.mouseMove.xRel = event.mouseMove.x - getCursorPosition().width;
                        event.mouseMove.yRel = event.mouseMove.y - getCursorPosition().height;

                        pushEvent(event);
                    }
                    break;

                    case ButtonPress:
                    {
                        WindowEvent event;

                        if(e.xbutton.button <= Button3 || e.xbutton.button >= Button8)
                        {
                            event.type = WindowEventType_MouseButtonDown;

                            event.mouseButton.x = e.xbutton.x;
                            event.mouseButton.y = e.xbutton.y;
                        }
                        else
                        {
                            event.type = WindowEventType_MouseWheel;

                            event.mouseWheel.x = e.xbutton.x;
                            event.mouseWheel.y = e.xbutton.y;
                        }

                        switch(e.xbutton.button)
                        {
                            case Button1:
                                event.mouseButton.button = MouseButton_Left;
                            break;
                            case Button2:
                                event.mouseButton.button = MouseButton_Middle;
                            break;
                            case Button3:
                                event.mouseButton.button = MouseButton_Right;
                            break;
                            case Button4:
                                event.mouseWheel.up      = true;
                                event.mouseWheel.wheel   = MouseWheel_Vertical;
                            break;
                            case Button5:
                                event.mouseWheel.up      = false;
                                event.mouseWheel.wheel   = MouseWheel_Vertical;
                            break;
                            case Button6:
                                event.mouseWheel.up      = true;
                                event.mouseWheel.wheel   = MouseWheel_Horizontal;
                            break;
                            case Button7:
                                event.mouseWheel.up      = false;
                                event.mouseWheel.wheel   = MouseWheel_Horizontal;
                            break;
                            case Button8:
                                event.mouseButton.button = MouseButton_Extra1;
                            break;
                            case Button9:
                                event.mouseButton.button = MouseButton_Extra2;
                            break;
                        }

                        pushEvent(event);
                    }
                    break;

                    case ButtonRelease:
                    {
                        if(e.xbutton.button <= Button3 || e.xbutton.button >= Button8)
                        {
                            WindowEvent event;
                            event.type = WindowEventType_MouseButtonUp;

                            switch(e.xbutton.button)
                            {
                                case Button1: event.mouseButton.button = MouseButton_Left;   break;
                                case Button2: event.mouseButton.button = MouseButton_Middle; break;
                                case Button3: event.mouseButton.button = MouseButton_Right;  break;
                                case Button8: event.mouseButton.button = MouseButton_Extra1; break;
                                case Button9: event.mouseButton.button = MouseButton_Extra2; break;
                            }

                            event.mouseButton.x = e.xbutton.x;
                            event.mouseButton.y = e.xbutton.y;

                            pushEvent(event);
                        }
                    }
                    break;

                    case FocusIn:
                    {
                        WindowEvent event;

                        event.type = WindowEventType_GainFocus;

                        if(m_captureCursor)
                        {
                            bool grabbed;

                            do
                            {
                                grabbed = XGrabPointer(m_display.getHandler(), m_handler,
                                                       True,
                                                       XNone,
                                                       GrabModeAsync, GrabModeAsync,
                                                       m_handler,
                                                       XNone,
                                                       CurrentTime) == GrabSuccess;

                                if(!grabbed)
                                {
                                    std::this_thread::sleep_for(std::chrono::milliseconds(10));
                                }
                            }while(!grabbed);
                        }

                        pushEvent(event);
                    }
                    break;

                    case FocusOut:
                    {
                        WindowEvent event;

                        event.type = WindowEventType_LostFocus;

                        if(m_captureCursor)
                        {
                            XUndefineCursor(m_display.getHandler(), CurrentTime);
                            m_display.flush();
                        }

                        pushEvent(event);
                    }
                    break;

                    case ConfigureNotify:
                    {
                        WindowEvent event;
                        Size size(e.xconfigure.width, e.xconfigure.height);
                        Size  position(e.xconfigure.x, e.xconfigure.y);

                        if(size != m_lastSize)
                        {
                            event.type                = WindowEventType_Resized;
                            event.windowResize.width  = size.width;
                            event.windowResize.height = size.height;

                            m_lastSize = size;
                        }
                        else
                        {
                            event.type         = WindowEventType_Moved;
                            event.windowMove.x = position.width;
                            event.windowMove.y = position.height;
                        }

                        pushEvent(event);
                    }
                    break;

                    case EnterNotify:
                    {
                        WindowEvent event;

                        event.type = WindowEventType_MouseEnter;

                        pushEvent(event);
                    }
                    break;

                    case LeaveNotify:
                    {
                        WindowEvent event;

                        event.type = WindowEventType_MouseLeave;

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

        void WindowImplXlib::minimize()
        {

        }

        bool WindowImplXlib::isMinimized() const
        {
            return false;
        }

        void WindowImplXlib::maximize()
        {

        }

        bool WindowImplXlib::isMaximized() const
        {
            return false;
        }

        void WindowImplXlib::enableCaptureCursor(bool capture)
        {
            m_captureCursor = capture;

            if(m_captureCursor)
            {
                bool grabbed;

                do
                {
                    grabbed = XGrabPointer(m_display.getHandler(), m_handler,
                                           True,
                                           XNone,
                                           GrabModeAsync, GrabModeAsync,
                                           m_handler,
                                           XNone,
                                           CurrentTime) == GrabSuccess;

                    if(!grabbed)
                    {
                        std::this_thread::sleep_for(std::chrono::milliseconds(10));
                    }
                }while(!grabbed);
            }
            else
            {
                XUngrabPointer(m_display.getHandler(), CurrentTime);
                m_display.flush();
            }
        }

        void WindowImplXlib::setPosition(const Size& position)
        {
            XMoveWindow(m_display.getHandler(), m_handler, position.width, position.height);
            m_display.flush();
        }

        Size WindowImplXlib::getPosition() const
        {
            XWindow root, child;
            int localX, localY, x, y;
            unsigned int width, height, border, depth;

            XGetGeometry(m_display.getHandler(), m_handler, &root, &localX, &localY, &width, &height, &border, &depth);
            XTranslateCoordinates(m_display.getHandler(), m_handler, root, localX, localY, &x, &y, &child);

            return { x, y };
        }

        void WindowImplXlib::setMinSize(const Size& size)
        {
            XSizeHints hints;

            hints.max_width  = (size.width > 0) ? size.width : 0;
            hints.max_height = (size.height > 0) ? size.height : 0;
            hints.flags      = PMinSize;

            XSetNormalHints(m_display.getHandler(), m_handler, &hints);
        }

        Size WindowImplXlib::getMinSize() const
        {
            XSizeHints hints;

            XGetNormalHints(m_display.getHandler(), m_handler, &hints);

            return { hints.min_width, hints.min_height };
        }

        void WindowImplXlib::setMaxSize(const Size& size)
        {
            XSizeHints hints;

            hints.max_width  = (size.width > 0) ? size.width : m_screen->width;
            hints.max_height = (size.height > 0) ? size.height : m_screen->height;
            hints.flags      = PMaxSize;

            XSetNormalHints(m_display.getHandler(), m_handler, &hints);
        }

        Size WindowImplXlib::getMaxSize() const
        {
            XSizeHints hints;

            XGetNormalHints(m_display.getHandler(), m_handler, &hints);

            return { hints.max_width, hints.max_height };
        }

        void WindowImplXlib::setSize(const Size& size)
        {
            XResizeWindow(m_display.getHandler(), m_handler, size.width, size.height);
            m_lastSize = size;
            m_display.flush();
        }

        Size WindowImplXlib::getSize() const
        {
            XWindowAttributes attributes;

            XGetWindowAttributes(m_display.getHandler(), m_handler, &attributes);

            return { attributes.width, attributes.height };
        }

        void WindowImplXlib::setTitle(const String& title)
        {
            XStoreName(m_display.getHandler(), m_handler, title.getBuffer());
        }

        String WindowImplXlib::getTitle() const
        {
            String title;
            char* buffer = new char[256];

            XFetchName(m_display.getHandler(), m_handler, &buffer);

            title = buffer;

            XFree(buffer);

            return title;
        }

        bool WindowImplXlib::hasFocus() const
        {
            return false;
        }

        void WindowImplXlib::switchFullscreen(bool fullscreen)
        {

        }

        void WindowImplXlib::setVisible(bool visible)
        {
            if(visible)
            {
                XMapWindow(m_display.getHandler(), m_handler);
                m_display.flush();

                while(!m_isMapped)
                {
                    startProcessEvents();
                }
            }
            else
            {
                XUnmapWindow(m_display.getHandler(), m_handler);
                m_display.flush();

                while(m_isMapped)
                {
                    startProcessEvents();
                }
            }
        }

        void WindowImplXlib::setIcon(const Image& icon)
        {
            XImage* image;
            XGCValues values;
            XGC iconGraphicContext;

            unsigned int width        = icon.getSize().width;
            unsigned int height       = icon.getSize().height;
            unsigned int defaultDepth = m_display.getDefaultDepth();
            XVisual* defaultVisual    = DefaultVisual(m_display.getHandler(), m_display.getDefaultScreen());

            std::vector<Uint8> pixels(icon.getPixels().getCapacity());

            for(std::size_t i = 0; i < icon.getSize().width * icon.getSize().height; i++)
            {
                pixels.at(i * 4 + 0) = icon.getPixels().at(i * 4 + 2);
                pixels.at(i * 4 + 1) = icon.getPixels().at(i * 4 + 1);
                pixels.at(i * 4 + 2) = icon.getPixels().at(i * 4 + 0);
                pixels.at(i * 4 + 3) = icon.getPixels().at(i * 4 + 3);
            }

            image = XCreateImage(m_display.getHandler(), defaultVisual,defaultDepth, ZPixmap, 0, reinterpret_cast<char*>(&pixels[0]), width, height, 32, 0);

            Expect(image, Throw(InternalError, "Failed to set window's icon"));

            if(m_icon)
            {
                XFreePixmap(m_display.getHandler(), m_icon);
            }

            if(m_iconMask)
            {
                XFreePixmap(m_display.getHandler(), m_iconMask);
            }

            m_icon = XCreatePixmap(m_display.getHandler(), m_display.getRootWindow(), width, height, defaultDepth);
            iconGraphicContext = XCreateGC(m_display.getHandler(), m_icon, 0, &values);

            XPutImage(m_display.getHandler(), m_icon, iconGraphicContext, image, 0, 0, 0, 0, width, height);
            XFreeGC(m_display.getHandler(), iconGraphicContext);
            XDestroyImage(image);

            std::size_t pitch = (width + 7 / 8);
            std::vector<Uint8> pixelMask(pitch * height);

            for(std::size_t j = 0; j < height; j++)
            {
                for(std::size_t i = 0; i < pitch; i++)
                {
                    for(std::size_t k = 0; k < 8; k++)
                    {
                        Uint8 opacity = (pixels.at((i * 8 + k + j * width) * 3 + 4) > 0) ? 1 : 0;
                        pixelMask.at(i + j * pitch) |= (opacity << k);
                    }
                }
            }

            m_iconMask = XCreatePixmapFromBitmapData(m_display.getHandler(), m_handler, reinterpret_cast<char*>(&pixels[0]), width, height, 1, 0, 1);

            XWMHints* hints = XAllocWMHints();
            hints->icon_pixmap = m_icon;
            hints->icon_mask   = m_iconMask;
            hints->flags       = IconPixmapHint | IconMaskHint;
            XSetWMHints(m_display.getHandler(), m_handler, hints);
            XFree(hints);

            std::vector<unsigned long> icccmPixels(width * height + 2);
            icccmPixels[0] = width;
            icccmPixels[1] = height;

            for(std::size_t i = 0; i < width * height; i++)
            {
                icccmPixels[i + 2] = (pixels[i * 4 + 2] << 0)  |
                                     (pixels[i * 4 + 1] << 8)  |
                                     (pixels[i * 4 + 0] << 16) |
                                     (pixels[i * 4 + 3] << 24);
            }

            XChangeProperty(m_display.getHandler(), m_handler,
                            m_display.getAtom("_NET_WM_ICON"), XA_CARDINAL, 32, PropModeReplace,
                            reinterpret_cast<const unsigned char*>(&icccmPixels[0]), icccmPixels.size());

            m_display.flush();
        }

        void WindowImplXlib::setMouseCursor(const CursorImpl& cursor)
        {
            XDefineCursor(m_display.getHandler(), m_handler, cursor.getSystemHandler());
        }

        void WindowImplXlib::setMouseCursorVisible(bool visible)
        {
            if(m_hiddenCursor == 0 && !visible)
            {
                m_hiddenCursor = createHiddenCursor(m_display, m_handler);
            }

            XDefineCursor(m_display.getHandler(), m_handler, visible ? XNone : m_hiddenCursor);
            m_display.flush();

            m_cursorVisible = visible;
        }

        bool WindowImplXlib::isMouseCursorVisible() const
        {
            return m_cursorVisible;
        }

        WindowHandler WindowImplXlib::getSystemHandler() const
        {
            return m_handler;
        }

        WindowImplXlib::WindowImplXlib() :
            m_display(Display::getInstance()),
            m_handler(0),
            m_isMapped(false),
            m_hiddenCursor(0),
            m_cursorVisible(true),
            m_captureCursor(false)
        {
            m_screen = ScreenOfDisplay(m_display.getHandler(), m_display.getDefaultScreen());
        }

        void WindowImplXlib::open(const VideoMode& mode, const String& title, Uint32 style)
        {
            ErrorHandler         handler;
            XSetWindowAttributes attributes;
            int                  screen     = m_display.getDefaultScreen();
            Visual*              visual     = XDefaultVisual(m_display.getHandler(), screen);

            m_colormap = XCreateColormap(m_display.getHandler(),
                                         m_display.getRootWindow(screen),
                                         visual,
                                         AllocNone);

            attributes.border_pixel      = 0;
            attributes.background_pixmap = XNone;
            attributes.colormap          = m_colormap;
            attributes.event_mask        = WindowImplXlib::EventsMasks;

            m_handler = XCreateWindow(m_display.getHandler(),
                                      m_display.getRootWindow(screen),
                                      0, 0,
                                      mode.width, mode.height,
                                      0,
                                      mode.bitsPerPixel,
                                      InputOutput,
                                      visual,
                                      CWColormap | CWEventMask | CWBorderPixel,
                                      &attributes);

            Expect(m_handler, Throw(InternalError, "Failed to create window"));

            initialize(title, style);
        }

        void WindowImplXlib::open(unsigned int width, unsigned int height, const String& title, Uint32 style, XVisualInfo* vi)
        {
            ErrorHandler         handler;
            XSetWindowAttributes attributes;

            m_colormap = XCreateColormap(m_display.getHandler(),
                                         m_display.getRootWindow(vi->screen),
                                         vi->visual,
                                         AllocNone);

            attributes.border_pixel      = 0;
            attributes.background_pixmap = XNone;
            attributes.colormap          = m_colormap;
            attributes.event_mask        = WindowImplXlib::EventsMasks;

            m_handler = XCreateWindow(m_display.getHandler(),
                                      m_display.getRootWindow(vi->screen),
                                      0, 0,
                                      width, height,
                                      0,
                                      vi->depth,
                                      InputOutput,
                                      vi->visual,
                                      CWColormap | CWEventMask | CWBorderPixel,
                                      &attributes);

            Expect(m_handler, Throw(InternalError, "Failed to create window"));

            initialize(title, style);
        }

        void WindowImplXlib::initialize(const String& title, Uint32 style)
        {
            setProtocols();

            setTitle(title);

            if(style != WindowStyle_Fullscreen)
            {
                XAtom hintsAtom = m_display.getAtom("_MOTIF_WM_HINTS", false);
                if(hintsAtom)
                {
                    WMHints hints;

                    if(style != WindowStyle_None)
                    {
                        hints.decorations |= WMHints::Decor_Menu | WMHints::Decor_Title;
                        hints.functions   |= WMHints::Function_Move;
                    }

                    if(style & WindowStyle_Resizable)
                    {
                        hints.decorations |= WMHints::Decor_ResizeH;
                        hints.functions   |= WMHints::Function_Resize;
                    }

                    if(style & WindowStyle_Minimizable)
                    {
                        hints.decorations |= WMHints::Decor_Minimize;
                        hints.functions   |= WMHints::Function_Minimize;
                    }

                    if(style & WindowStyle_Maximizable)
                    {
                        hints.decorations |= WMHints::Decor_Maximize;
                        hints.functions   |= WMHints::Function_Maximize;
                    }

                    if(style & WindowStyle_Closable)
                    {
                        hints.decorations |= 0;
                        hints.functions   |= WMHints::Function_Close;
                    }

                    XChangeProperty(m_display.getHandler(),
                                    m_handler,
                                    hintsAtom,
                                    hintsAtom,
                                    32,
                                    PropModeReplace,
                                    reinterpret_cast<const unsigned char*>(&hints),
                                    5);
                }
            }

            m_lastSize = getSize();

            setVisible(true);
        }

        void WindowImplXlib::setProtocols()
        {
            Atom wmDeleteWindow = m_display.getAtom("WM_DELETE_WINDOW");

            XSetWMProtocols(m_display.getHandler(), m_handler, &wmDeleteWindow, 1);
        }
    }
}
