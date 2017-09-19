#include <Bull/Core/Exception/RuntimeError.hpp>

#include <Bull/System/Win32/WindowImplWin32.hpp>

/// GCC missing define
#ifndef WM_XBUTTONDOWN
    #define WM_XBUTTONDOWN 0x020B
#endif
#ifndef WM_XBUTTONUP
    #define WM_XBUTTONUP 0x020C
#endif
#ifndef XBUTTON1
    #define XBUTTON1 0x0001
#endif
#ifndef XBUTTON2
    #define XBUTTON2 0x0002
#endif
#ifndef VK_OEM_PLUS
    #define VK_OEM_PLUS 0xBB
#endif
#ifndef VK_OEM_COMMA
    #define VK_OEM_COMMA 0xBC
#endif
#ifndef VK_OEM_PERIOD
    #define VK_OEM_PERIOD 0xBE
#endif
#ifndef VK_OEM_102
    #define VK_OEM_102 0xE2
#endif
#ifndef GWL_USERDATA
    #define GWL_USERDATA -21
#endif

namespace Bull
{
    namespace prv
    {
        namespace
        {
            HINSTANCE instance           = GetModuleHandle(nullptr);
            LPCWSTR   windowClassName    = L"BullWindow";
            unsigned int instanceCounter = 0;
        }

        bool WindowImplWin32::registerWindowClass()
        {
            WNDCLASSEXW winClass;

            winClass.cbSize        = sizeof(WNDCLASSEXW);
            winClass.style         = CS_DBLCLKS;
            winClass.lpfnWndProc   = WindowImplWin32::globalEvent;
            winClass.cbClsExtra    = 0;
            winClass.cbWndExtra    = 0;
            winClass.hInstance     = instance;
            winClass.hIcon         = LoadIcon(instance, IDI_APPLICATION);
            winClass.hCursor       = nullptr;
            winClass.hbrBackground = nullptr;
            winClass.lpszMenuName  = nullptr;
            winClass.lpszClassName = windowClassName;
            winClass.hIconSm       = nullptr;

            return RegisterClassExW(&winClass) == TRUE;
        }

        LRESULT CALLBACK WindowImplWin32::globalEvent(HWND handler, UINT message, WPARAM wParam, LPARAM lParam)
        {
            if(message == WM_CREATE)
            {
                WindowImplWin32* createdImpl  = static_cast<WindowImplWin32*>(reinterpret_cast<CREATESTRUCT*>(lParam)->lpCreateParams);

                SetWindowLongPtr(handler, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(createdImpl));
            }

            WindowImplWin32* window = reinterpret_cast<WindowImplWin32*>(GetWindowLongPtrW(handler, GWL_USERDATA));

            if(window)
            {
                window->processEvent(message, wParam, lParam);
            }

            if(message == WM_CLOSE)
            {
                return 0;
            }

            return DefWindowProc(handler, message, wParam, lParam);
        }

        Keyboard::Key WindowImplWin32::convertVKToBullkey(WPARAM vkey)
        {
            switch(vkey)
            {
                case 'A':           return Keyboard::Key::A;
                case 'B':           return Keyboard::Key::B;
                case 'C':           return Keyboard::Key::C;
                case 'D':           return Keyboard::Key::D;
                case 'E':           return Keyboard::Key::E;
                case 'F':           return Keyboard::Key::F;
                case 'G':           return Keyboard::Key::G;
                case 'H':           return Keyboard::Key::H;
                case 'I':           return Keyboard::Key::I;
                case 'J':           return Keyboard::Key::J;
                case 'K':           return Keyboard::Key::K;
                case 'L':           return Keyboard::Key::L;
                case 'M':           return Keyboard::Key::M;
                case 'N':           return Keyboard::Key::N;
                case 'O':           return Keyboard::Key::O;
                case 'P':           return Keyboard::Key::P;
                case 'Q':           return Keyboard::Key::Q;
                case 'R':           return Keyboard::Key::R;
                case 'S':           return Keyboard::Key::S;
                case 'T':           return Keyboard::Key::T;
                case 'U':           return Keyboard::Key::U;
                case 'V':           return Keyboard::Key::V;
                case 'W':           return Keyboard::Key::W;
                case 'X':           return Keyboard::Key::X;
                case 'Y':           return Keyboard::Key::Y;
                case 'Z':           return Keyboard::Key::Z;
                case '0':           return Keyboard::Key::Num0;
                case '1':           return Keyboard::Key::Num1;
                case '2':           return Keyboard::Key::Num2;
                case '3':           return Keyboard::Key::Num3;
                case '4':           return Keyboard::Key::Num4;
                case '5':           return Keyboard::Key::Num5;
                case '6':           return Keyboard::Key::Num6;
                case '7':           return Keyboard::Key::Num7;
                case '8':           return Keyboard::Key::Num8;
                case '9':           return Keyboard::Key::Num9;
                case VK_NUMLOCK:    return Keyboard::Key::NumLock;
                case VK_NUMPAD0:    return Keyboard::Key::NumPad0;
                case VK_NUMPAD1:    return Keyboard::Key::NumPad1;
                case VK_NUMPAD2:    return Keyboard::Key::NumPad2;
                case VK_NUMPAD3:    return Keyboard::Key::NumPad3;
                case VK_NUMPAD4:    return Keyboard::Key::NumPad4;
                case VK_NUMPAD5:    return Keyboard::Key::NumPad5;
                case VK_NUMPAD6:    return Keyboard::Key::NumPad6;
                case VK_NUMPAD7:    return Keyboard::Key::NumPad7;
                case VK_NUMPAD8:    return Keyboard::Key::NumPad8;
                case VK_NUMPAD9:    return Keyboard::Key::NumPad9;
                case VK_DECIMAL:    return Keyboard::Key::NumPadDot;
                case VK_ADD:        return Keyboard::Key::Add;
                case VK_SUBTRACT:   return Keyboard::Key::Substract;
                case VK_MULTIPLY:   return Keyboard::Key::Multiply;
                case VK_DIVIDE:     return Keyboard::Key::Divide;
                case VK_F1:         return Keyboard::Key::F1;
                case VK_F2:         return Keyboard::Key::F2;
                case VK_F3:         return Keyboard::Key::F3;
                case VK_F4:         return Keyboard::Key::F4;
                case VK_F5:         return Keyboard::Key::F5;
                case VK_F6:         return Keyboard::Key::F6;
                case VK_F7:         return Keyboard::Key::F7;
                case VK_F8:         return Keyboard::Key::F8;
                case VK_F9:         return Keyboard::Key::F9;
                case VK_F10:        return Keyboard::Key::F10;
                case VK_F11:        return Keyboard::Key::F11;
                case VK_F12:        return Keyboard::Key::F12;
                case VK_F13:        return Keyboard::Key::F13;
                case VK_F14:        return Keyboard::Key::F14;
                case VK_F15:        return Keyboard::Key::F15;
                case VK_F16:        return Keyboard::Key::F16;
                case VK_F17:        return Keyboard::Key::F17;
                case VK_F18:        return Keyboard::Key::F18;
                case VK_F19:        return Keyboard::Key::F19;
                case VK_F20:        return Keyboard::Key::F20;
                case VK_F21:        return Keyboard::Key::F21;
                case VK_F22:        return Keyboard::Key::F22;
                case VK_F23:        return Keyboard::Key::F23;
                case VK_F24:        return Keyboard::Key::F24;
                case VK_LEFT:       return Keyboard::Key::Left;
                case VK_RIGHT:      return Keyboard::Key::Right;
                case VK_UP:         return Keyboard::Key::Up;
                case VK_DOWN:       return Keyboard::Key::Down;
                case VK_SPACE:      return Keyboard::Key::Space;
                case VK_ESCAPE:     return Keyboard::Key::Escape;
                case VK_CONTROL:    return Keyboard::isKeyPressed(Keyboard::LeftControl) ? Keyboard::LeftControl : Keyboard::RightControl;
                case VK_LCONTROL:   return Keyboard::Key::LeftControl;
                case VK_RCONTROL:   return Keyboard::Key::RightControl;
                case VK_MENU:       return Keyboard::isKeyPressed(Keyboard::LeftAlt) ? Keyboard::LeftAlt : Keyboard::RightAlt;
                case VK_LMENU:      return Keyboard::Key::LeftAlt;
                case VK_RMENU:      return Keyboard::Key::RightAlt;
                case VK_LWIN:       return Keyboard::Key::LeftSystem;
                case VK_RWIN:       return Keyboard::Key::RightSystem;
                case VK_SHIFT:      return Keyboard::isKeyPressed(Keyboard::LeftShift) ? Keyboard::LeftShift : Keyboard::RightShift;
                case VK_LSHIFT:     return Keyboard::Key::LeftShift;
                case VK_RSHIFT:     return Keyboard::Key::RightShift;
                case VK_OEM_1:      return Keyboard::Key::OEM1;
                case VK_OEM_PERIOD: return Keyboard::Key::OEMPeriod;
                case VK_OEM_2:      return Keyboard::Key::OEM2;
                case VK_OEM_3:      return Keyboard::Key::OEM3;
                case VK_OEM_4:      return Keyboard::Key::OEM4;
                case VK_OEM_5:      return Keyboard::Key::OEM5;
                case VK_OEM_6:      return Keyboard::Key::OEM6;
                case VK_OEM_7:      return Keyboard::Key::OEM7;
                case VK_OEM_8:      return Keyboard::Key::OEM8;
                case VK_OEM_102:    return Keyboard::Key::OEM9;
                case VK_OEM_PLUS:   return Keyboard::Key::OEMPlus;
                case VK_OEM_COMMA:  return Keyboard::Key::OEMComma;
                case VK_TAB:        return Keyboard::Key::Tab;
                case VK_BACK:       return Keyboard::Key::Back;
                case VK_RETURN:     return Keyboard::Key::Enter;
                case VK_CAPITAL:    return Keyboard::Key::CapsLock;
                case VK_APPS:       return Keyboard::Key::Apps;
                case VK_DELETE:     return Keyboard::Key::Delete;
                case VK_INSERT:     return Keyboard::Key::Insert;
                case VK_PRIOR:      return Keyboard::Key::PageUp;
                case VK_NEXT:       return Keyboard::Key::PageDown;
                case VK_END:        return Keyboard::Key::End;
                case VK_HOME:       return Keyboard::Key::Home;
                case VK_PAUSE:      return Keyboard::Key::Pause;
                case VK_SNAPSHOT:   return Keyboard::Key::ScreenShot;
                case VK_SCROLL:     return Keyboard::Key::Scroll;
                default:            return Keyboard::Key::Unknown;
            }
        }

        DWORD WindowImplWin32::computeWindowStyle(Uint32 WindowStyle)
        {
            DWORD windowWindowStyle = 0;

            if(WindowStyle & (WindowStyle::Visible) || WindowStyle == WindowStyle::Fullscreen)
            {
                windowWindowStyle |= WS_VISIBLE;
            }

            if(WindowStyle & (WindowStyle::Closable))
            {
                windowWindowStyle |= WS_SYSMENU;
            }

            if(WindowStyle & (WindowStyle::Maximizable))
            {
                windowWindowStyle |= WS_MAXIMIZEBOX;
            }

            if(WindowStyle & (WindowStyle::Minimizable))
            {
                windowWindowStyle |= WS_MINIMIZEBOX;
            }

            if(WindowStyle & (WindowStyle::Resizable))
            {
                windowWindowStyle |= WS_THICKFRAME;
            }

            return windowWindowStyle;
        }

        WindowImplWin32::WindowImplWin32(const VideoMode& mode, const String& title, Uint32 style) :
            m_icon(nullptr),
            m_cursor(LoadCursor(nullptr, IDC_ARROW)),
            m_isResizing(false),
            m_minSize(-1, -1),
            m_maxSize(-1, -1),
            m_cursorVisible(true)
        {
            unsigned int width, height;
            DWORD winWindowStyle = computeWindowStyle(style);

            if(instanceCounter == 0)
            {
                registerWindowClass();
            }

            if(!(style & WindowStyle::Fullscreen))
            {
                RECT rectangle = {0, 0,
                                  static_cast<LONG>(mode.width),
                                  static_cast<LONG>(mode.height)};

                AdjustWindowRect(&rectangle, winWindowStyle, false);
                width  = static_cast<unsigned int>(rectangle.right - rectangle.left);
                height = static_cast<unsigned int>(rectangle.bottom - rectangle.top);
            }
            else
            {
                width  = mode.width;
                height = mode.height;
            }

            m_handler = CreateWindowExW(0,
                                        windowClassName,
                                        reinterpret_cast<LPCWSTR>(title.getBuffer()),
                                        winWindowStyle,
                                        CW_USEDEFAULT, CW_USEDEFAULT,
                                        width, height,
                                        nullptr,
                                        nullptr,
                                        instance,
                                        this);

            UpdateWindow(m_handler);

            m_lastSize     = getSize();
            m_lastPosition = getPosition();

            instanceCounter += 1;
        }

        WindowImplWin32::~WindowImplWin32()
        {
            instanceCounter -= 1;

            if(m_icon)
            {
                DestroyIcon(m_icon);
            }

            if(instanceCounter == 0)
            {
                UnregisterClassW(windowClassName, instance);
            }

            DestroyWindow(m_handler);
        }

        void WindowImplWin32::startProcessEvents()
        {
            MSG message;

            while(PeekMessage(&message, m_handler, 0, 0, PM_REMOVE))
            {
                TranslateMessage(&message);
                DispatchMessage(&message);
            }
        }

        void WindowImplWin32::minimize()
        {
            ShowWindow(m_handler, SW_SHOWMINIMIZED);
        }

        bool WindowImplWin32::isMinimized() const
        {
            return IsIconic(m_handler) == TRUE;
        }

        void WindowImplWin32::maximize()
        {
            ShowWindow(m_handler, SW_SHOWMAXIMIZED);
        }

        bool WindowImplWin32::isMaximized() const
        {
            WINDOWPLACEMENT placement;
            placement.length = sizeof(WINDOWPLACEMENT);

            GetWindowPlacement(m_handler, &placement);

            return placement.showCmd == SW_MAXIMIZE;
        }

        void WindowImplWin32::enableCaptureCursor(bool capture)
        {
            if(capture)
            {
                RECT winRect = {0, 0, 0, 0};

                GetClientRect(m_handler, &winRect);

                ClipCursor(&winRect);
            }
            else
            {
                ClipCursor(nullptr);
            }
        }

        void WindowImplWin32::setPosition(const Vector2I& position)
        {
            SetWindowPos(m_handler, nullptr, position.x, position.y, 0, 0, SWP_NOSIZE);
        }

        Vector2I WindowImplWin32::getPosition() const
        {
            RECT r = {0, 0, 0, 0};

            GetWindowRect(m_handler, &r);

            return Vector2I(r.left, r.top);
        }

        void WindowImplWin32::setMinSize(const Vector2I& size)
        {
            RECT r = {0, 0,
                      size.x,
                      size.y,
            };
            AdjustWindowRect(&r, static_cast<DWORD>(GetWindowLongPtr(m_handler, GWL_STYLE)), false);

            m_minSize.x = (size.x != -1) ? r.right  - r.left : -1;
            m_minSize.y = (size.y != -1) ? r.bottom - r.top  : -1;
        }

        Vector2I WindowImplWin32::getMinSize() const
        {
            return m_minSize;
        }

        void WindowImplWin32::setMaxSize(const Vector2I& size)
        {
            RECT r = {0, 0,
                      size.x,
                      size.y,
            };
            AdjustWindowRect(&r, static_cast<DWORD>(GetWindowLongPtr(m_handler, GWL_STYLE)), false);

            m_maxSize.x = (size.x != -1) ? r.right  - r.left : -1;
            m_maxSize.y = (size.y != -1) ? r.bottom - r.top  : -1;
        }

        Vector2I WindowImplWin32::getMaxSize() const
        {
            return m_maxSize;
        }

        void WindowImplWin32::setSize(const Vector2UI& size)
        {
            RECT r = {0, 0,
                      static_cast<LONG>(size.x),
                      static_cast<LONG>(size.y),
            };
            AdjustWindowRect(&r, static_cast<DWORD>(GetWindowLongPtr(m_handler, GWL_STYLE)), false);
            SetWindowPos(m_handler, nullptr, 0, 0, r.right - r.left, r.bottom - r.top, SWP_NOMOVE);
        }

        Vector2UI WindowImplWin32::getSize() const
        {
            RECT r = {0, 0, 0, 0};

            GetClientRect(m_handler, &r);

            return Vector2UI(static_cast<unsigned int>(r.right - r.left), static_cast<unsigned int>(r.bottom - r.top));
        }

        void WindowImplWin32::setTitle(const String& title)
        {
            SetWindowTextW(m_handler, reinterpret_cast<LPCWSTR>(title.getBuffer()));
        }

        String WindowImplWin32::getTitle() const
        {
            wchar_t* titleBuffer = new wchar_t[1024];
            String title;

            GetWindowTextW(m_handler, titleBuffer, 1024);

            title = reinterpret_cast<char*>(titleBuffer);

            delete[] titleBuffer;

            return title;
        }

        bool WindowImplWin32::hasFocus() const
        {
            return GetFocus() == m_handler;
        }

        void WindowImplWin32::switchFullscreen(bool fullscreen)
        {
            if(fullscreen)
            {
                VideoMode current = VideoMode::getCurrent();

                m_savedInfo.maximized = isMaximized();
                GetWindowRect(m_handler, &m_savedInfo.rect);
                m_savedInfo.style     = GetWindowLong(m_handler, GWL_STYLE);
                m_savedInfo.styleEx   = GetWindowLong(m_handler, GWL_EXSTYLE);

                SetWindowLongPtr(m_handler, GWL_STYLE,   WS_POPUP        | WS_VISIBLE);
                SetWindowLongPtr(m_handler, GWL_EXSTYLE, WS_EX_APPWINDOW | WS_EX_TOPMOST);

                SetWindowPos(m_handler, HWND_TOPMOST, 0, 0, current.width, current.height, SWP_SHOWWINDOW);

                ShowWindow(m_handler, SW_MAXIMIZE);
            }
            else
            {
                SetWindowLongPtr(m_handler, GWL_STYLE,   m_savedInfo.style);
                SetWindowLongPtr(m_handler, GWL_EXSTYLE, m_savedInfo.styleEx);

                SetWindowPos(m_handler,
                             nullptr,
                             m_savedInfo.rect.left, m_savedInfo.rect.top,
                             m_savedInfo.rect.right - m_savedInfo.rect.left, m_savedInfo.rect.bottom - m_savedInfo.rect.top,
                             SWP_NOZORDER | SWP_NOACTIVATE | SWP_FRAMECHANGED);

                ShowWindow(m_handler, SW_RESTORE);

                if(m_savedInfo.maximized)
                {
                    maximize();
                }
            }
        }

        void WindowImplWin32::setVisible(bool visible)
        {
            ShowWindow(m_handler, (visible) ? SW_SHOW : SW_HIDE);
        }

        void WindowImplWin32::setIcon(const Image& icon)
        {
            ByteArray pixels(icon.getSize().x * icon.getSize().y * 4);

            for(Index i = 0; i < pixels.getCapacity() / 4; i += 4)
            {
                pixels.at(i * 4 + 0) = icon.getPixels().at(i * 4 + 2);
                pixels.at(i * 4 + 1) = icon.getPixels().at(i * 4 + 1);
                pixels.at(i * 4 + 2) = icon.getPixels().at(i * 4 + 0);
                pixels.at(i * 4 + 3) = icon.getPixels().at(i * 4 + 3);
            }

            if(m_icon)
            {
                DestroyIcon(m_icon);
            }

            m_icon = CreateIcon(instance, icon.getSize().x, icon.getSize().y, 1, 32, nullptr, pixels.getBuffer());

            if(m_icon)
            {
                SendMessageW(m_handler, WM_SETICON, ICON_BIG,   (LPARAM)m_icon);
                SendMessageW(m_handler, WM_SETICON, ICON_SMALL, (LPARAM)m_icon);
            }
            else
            {
                throw RuntimeError("Failed to set window's icon");
            }
        }

        void WindowImplWin32::setMouseCursor(const std::unique_ptr<CursorImpl>& cursor)
        {
            m_cursor = cursor->getSystemHandler();
            SetCursor(m_cursor);
        }

        void WindowImplWin32::setMouseCursorVisible(bool visible)
        {
            if(visible != m_cursorVisible)
            {
                m_cursorVisible = visible;
                ShowCursor(visible);
            }
        }

        bool WindowImplWin32::isMouseCursorVisible() const
        {
            return m_cursorVisible;
        }

        WindowHandler WindowImplWin32::getSystemHandler() const
        {
            return m_handler;
        }

        void WindowImplWin32::processEvent(UINT message, WPARAM wParam, LPARAM lParam)
        {
            switch(message)
            {
                case WM_CLOSE:
                {
                    WindowEvent e;

                    e.type = WindowEvent::Closed;

                    pushEvent(e);
                }
                break;

                case WM_SETCURSOR:
                {
                    if(LOWORD(lParam) == HTCLIENT)
                    {
                        SetCursor(m_cursor);
                    }
                }
                break;

                case WM_SIZE:
                {
                    if(!m_isResizing && m_lastSize != getSize())
                    {
                        WindowEvent e;

                        e.type                = WindowEvent::Resized;
                        e.windowResize.width  = LOWORD(lParam);
                        e.windowResize.height = HIWORD(lParam);

                        m_lastSize = getSize();

                        pushEvent(e);
                    }
                }
                break;

                case WM_KILLFOCUS:
                {
                    WindowEvent e;

                    e.type = WindowEvent::LostFocus;

                    pushEvent(e);
                }
                break;

                case WM_SETFOCUS:
                {
                    WindowEvent e;

                    e.type = WindowEvent::GainFocus;

                    pushEvent(e);
                }
                break;

                case WM_ENTERSIZEMOVE:
                {
                    m_isResizing = true;
                }
                break;

                case WM_EXITSIZEMOVE:
                {
                    m_isResizing = false;

                    if(getSize() != m_lastSize)
                    {
                        WindowEvent e;
                        m_lastSize = getSize();

                        e.type                = WindowEvent::Resized;
                        e.windowResize.width  = m_lastSize.x;
                        e.windowResize.height = m_lastSize.y;

                        pushEvent(e);
                    }

                    if(getPosition() != m_lastPosition)
                    {
                        WindowEvent e;
                        m_lastPosition = getPosition();

                        e.type         = WindowEvent::Moved;
                        e.windowMove.x = getPosition().x;
                        e.windowMove.y = getPosition().y;

                        pushEvent(e);
                    }
                }
                break;

                case WM_KEYDOWN:
                case WM_SYSKEYDOWN:
                {
                    if(isKeyRepeatEnable() || ((HIWORD(lParam) & KF_REPEAT) == 0))
                    {
                        WindowEvent e;

                        e.type        = WindowEvent::KeyDown;
                        e.key.code    = convertVKToBullkey(wParam);
                        e.key.alt     = Keyboard::isKeyPressed(Keyboard::Key::Alt);
                        e.key.control = Keyboard::isKeyPressed(Keyboard::Key::Control);
                        e.key.shift   = Keyboard::isKeyPressed(Keyboard::Key::Shift);
                        e.key.system  = Keyboard::isKeyPressed(Keyboard::Key::System);

                        pushEvent(e);
                    }
                }
                break;

                case WM_KEYUP:
                case WM_SYSKEYUP:
                {
                    WindowEvent e;

                    e.type        = WindowEvent::KeyUp;
                    e.key.code    = convertVKToBullkey(wParam);
                    e.key.alt     = Keyboard::isKeyPressed(Keyboard::Key::Alt);
                    e.key.control = Keyboard::isKeyPressed(Keyboard::Key::Control);
                    e.key.shift   = Keyboard::isKeyPressed(Keyboard::Key::Shift);
                    e.key.system  = Keyboard::isKeyPressed(Keyboard::Key::System);

                    pushEvent(e);
                }
                break;

                case WM_CHAR:
                {
                    WindowEvent e;

                    e.type = WindowEvent::Character;
                    e.character = static_cast<Uint32>(wParam);

                    pushEvent(e);
                }
                break;

                case WM_MOUSEMOVE:
                {
                    WindowEvent e;

                    e.type           = WindowEvent::MouseMoved;
                    e.mouseMove.x    = GET_X_LPARAM(lParam);
                    e.mouseMove.y    = GET_Y_LPARAM(lParam);
                    e.mouseMove.xRel = e.mouseMove.x - getCursorPosition().x;
                    e.mouseMove.yRel = e.mouseMove.y - getCursorPosition().y;

                    pushEvent(e);
                }
                break;

                case WM_LBUTTONDOWN:
                case WM_LBUTTONDBLCLK:
                {
                    WindowEvent e;

                    e.type               = WindowEvent::MouseButtonDown;
                    e.mouseButton.button = Mouse::Button::Left;
                    e.mouseButton.y      = GET_Y_LPARAM(lParam);
                    e.mouseButton.x      = GET_X_LPARAM(lParam);

                    pushEvent(e);

                    if(message == WM_LBUTTONDBLCLK)
                    {
                        e.type = WindowEvent::MouseButtonDoubleClicked;

                        pushEvent(e);
                    }
                }
                break;

                case WM_LBUTTONUP:
                {
                    WindowEvent e;

                    e.type               = WindowEvent::MouseButtonUp;
                    e.mouseButton.button = Mouse::Button::Left;
                    e.mouseButton.x      = GET_X_LPARAM(lParam);
                    e.mouseButton.y      = GET_Y_LPARAM(lParam);

                    pushEvent(e);
                }
                break;

                case WM_MBUTTONDOWN:
                case WM_MBUTTONDBLCLK:
                {
                    WindowEvent e;

                    e.type               = WindowEvent::MouseButtonDown;
                    e.mouseButton.button = Mouse::Button::Middle;
                    e.mouseButton.x      = GET_X_LPARAM(lParam);
                    e.mouseButton.y      = GET_Y_LPARAM(lParam);

                    pushEvent(e);

                    if(message == WM_MBUTTONDBLCLK)
                    {
                        e.type = WindowEvent::MouseButtonDoubleClicked;

                        pushEvent(e);
                    }
                }
                break;

                case WM_MBUTTONUP:
                {
                    WindowEvent e;

                    e.type               = WindowEvent::MouseButtonUp;
                    e.mouseButton.button = Mouse::Button::Middle;
                    e.mouseButton.x      = GET_X_LPARAM(lParam);
                    e.mouseButton.y      = GET_Y_LPARAM(lParam);

                    pushEvent(e);
                }
                break;

                case WM_RBUTTONDOWN:
                case WM_RBUTTONDBLCLK:
                {
                    WindowEvent e;

                    e.type               = WindowEvent::MouseButtonDown;
                    e.mouseButton.button = Mouse::Button::Right;
                    e.mouseButton.x      = GET_X_LPARAM(lParam);
                    e.mouseButton.y      = GET_Y_LPARAM(lParam);

                    pushEvent(e);

                    if(message == WM_RBUTTONDBLCLK)
                    {
                        e.type = WindowEvent::MouseButtonDoubleClicked;

                        pushEvent(e);
                    }
                }
                break;

                case WM_RBUTTONUP:
                {
                    WindowEvent e;

                    e.type               = WindowEvent::MouseButtonUp;
                    e.mouseButton.button = Mouse::Button::Right;
                    e.mouseButton.x      = GET_X_LPARAM(lParam);
                    e.mouseButton.y      = GET_Y_LPARAM(lParam);

                    pushEvent(e);
                }
                break;

                case WM_XBUTTONDOWN:
                case WM_XBUTTONDBLCLK:
                {
                    WindowEvent e;

                    e.type               = WindowEvent::MouseButtonDown;
                    e.mouseButton.button = (HIWORD(wParam) == XBUTTON1) ? Mouse::Button::Extra1 : Mouse::Button::Extra2;
                    e.mouseButton.x      = GET_X_LPARAM(lParam);
                    e.mouseButton.y      = GET_Y_LPARAM(lParam);

                    pushEvent(e);

                    if(message == WM_XBUTTONDBLCLK)
                    {
                        e.type = WindowEvent::MouseButtonDoubleClicked;

                        pushEvent(e);
                    }
                }
                break;

                case WM_XBUTTONUP:
                {
                    WindowEvent e;

                    e.type               = WindowEvent::MouseButtonUp;
                    e.mouseButton.button = (HIWORD(wParam) == XBUTTON1) ? Mouse::Button::Extra1 : Mouse::Button::Extra2;
                    e.mouseButton.x      = GET_X_LPARAM(lParam);
                    e.mouseButton.y      = GET_Y_LPARAM(lParam);

                    pushEvent(e);
                }
                break;

                case WM_MOUSEWHEEL:
                {
                    WindowEvent e;

                    e.type              = WindowEvent::MouseWheel;
                    e.mouseWheel.wheel  = Mouse::Wheel::Vertical;
                    e.mouseWheel.up     = (HIWORD(wParam) == 120);
                    e.mouseWheel.x      = GET_X_LPARAM(lParam);
                    e.mouseWheel.y      = GET_Y_LPARAM(lParam);

                    pushEvent(e);
                }
                break;

                case WM_MOUSEHWHEEL:
                {
                    WindowEvent e;

                    e.type              = WindowEvent::MouseWheel;
                    e.mouseWheel.wheel  = Mouse::Wheel::Horizontal;
                    e.mouseWheel.up     = (HIWORD(wParam) == 120);
                    e.mouseWheel.x      = GET_X_LPARAM(lParam);
                    e.mouseWheel.y      = GET_Y_LPARAM(lParam);

                    pushEvent(e);
                }

                case WM_GETMINMAXINFO:
                {
                    Vector2I min           = getMinSize();
                    Vector2I max           = getMaxSize();
                    MINMAXINFO* minmaxinfo = reinterpret_cast<MINMAXINFO*>(lParam);

                    minmaxinfo->ptMaxSize.x = std::numeric_limits<LONG>::max();
                    minmaxinfo->ptMaxSize.y = std::numeric_limits<LONG>::max();

                    if(min.x > -1)
                    {
                        minmaxinfo->ptMinTrackSize.x = min.x;
                    }

                    if(min.y > -1)
                    {
                        minmaxinfo->ptMinTrackSize.y = min.y;
                    }

                    if(max.x > -1)
                    {
                        minmaxinfo->ptMaxTrackSize.x = max.x;
                    }

                    if(max.y > -1)
                    {
                        minmaxinfo->ptMaxTrackSize.y = max.y;
                    }
                }
                break;
            }
        }
    }
}
