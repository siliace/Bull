#include <limits>

#include <Bull/Core/Exception/Expect.hpp>
#include <Bull/Core/Exception/Throw.hpp>
#include <Bull/Core/Support/Win32/Win32Error.hpp>
#include <Bull/Core/Window/Win32/WindowImplWin32.hpp>
#include <Bull/Core/Window/WindowStyle.hpp>

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

            WindowImplWin32* window = reinterpret_cast<WindowImplWin32*>(GetWindowLongPtrW(handler, GWLP_USERDATA));

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

        KeyboardKey WindowImplWin32::convertVKToBullkey(WPARAM vkey)
        {
            switch(vkey)
            {
                case 'A':           return KeyboardKey_A;
                case 'B':           return KeyboardKey_B;
                case 'C':           return KeyboardKey_C;
                case 'D':           return KeyboardKey_D;
                case 'E':           return KeyboardKey_E;
                case 'F':           return KeyboardKey_F;
                case 'G':           return KeyboardKey_G;
                case 'H':           return KeyboardKey_H;
                case 'I':           return KeyboardKey_I;
                case 'J':           return KeyboardKey_J;
                case 'K':           return KeyboardKey_K;
                case 'L':           return KeyboardKey_L;
                case 'M':           return KeyboardKey_M;
                case 'N':           return KeyboardKey_N;
                case 'O':           return KeyboardKey_O;
                case 'P':           return KeyboardKey_P;
                case 'Q':           return KeyboardKey_Q;
                case 'R':           return KeyboardKey_R;
                case 'S':           return KeyboardKey_S;
                case 'T':           return KeyboardKey_T;
                case 'U':           return KeyboardKey_U;
                case 'V':           return KeyboardKey_V;
                case 'W':           return KeyboardKey_W;
                case 'X':           return KeyboardKey_X;
                case 'Y':           return KeyboardKey_Y;
                case 'Z':           return KeyboardKey_Z;
                case '0':           return KeyboardKey_Num0;
                case '1':           return KeyboardKey_Num1;
                case '2':           return KeyboardKey_Num2;
                case '3':           return KeyboardKey_Num3;
                case '4':           return KeyboardKey_Num4;
                case '5':           return KeyboardKey_Num5;
                case '6':           return KeyboardKey_Num6;
                case '7':           return KeyboardKey_Num7;
                case '8':           return KeyboardKey_Num8;
                case '9':           return KeyboardKey_Num9;
                case VK_NUMLOCK:    return KeyboardKey_NumLock;
                case VK_NUMPAD0:    return KeyboardKey_NumPad0;
                case VK_NUMPAD1:    return KeyboardKey_NumPad1;
                case VK_NUMPAD2:    return KeyboardKey_NumPad2;
                case VK_NUMPAD3:    return KeyboardKey_NumPad3;
                case VK_NUMPAD4:    return KeyboardKey_NumPad4;
                case VK_NUMPAD5:    return KeyboardKey_NumPad5;
                case VK_NUMPAD6:    return KeyboardKey_NumPad6;
                case VK_NUMPAD7:    return KeyboardKey_NumPad7;
                case VK_NUMPAD8:    return KeyboardKey_NumPad8;
                case VK_NUMPAD9:    return KeyboardKey_NumPad9;
                case VK_DECIMAL:    return KeyboardKey_NumPadDot;
                case VK_ADD:        return KeyboardKey_Add;
                case VK_SUBTRACT:   return KeyboardKey_Subtract;
                case VK_MULTIPLY:   return KeyboardKey_Multiply;
                case VK_DIVIDE:     return KeyboardKey_Divide;
                case VK_F1:         return KeyboardKey_F1;
                case VK_F2:         return KeyboardKey_F2;
                case VK_F3:         return KeyboardKey_F3;
                case VK_F4:         return KeyboardKey_F4;
                case VK_F5:         return KeyboardKey_F5;
                case VK_F6:         return KeyboardKey_F6;
                case VK_F7:         return KeyboardKey_F7;
                case VK_F8:         return KeyboardKey_F8;
                case VK_F9:         return KeyboardKey_F9;
                case VK_F10:        return KeyboardKey_F10;
                case VK_F11:        return KeyboardKey_F11;
                case VK_F12:        return KeyboardKey_F12;
                case VK_F13:        return KeyboardKey_F13;
                case VK_F14:        return KeyboardKey_F14;
                case VK_F15:        return KeyboardKey_F15;
                case VK_F16:        return KeyboardKey_F16;
                case VK_F17:        return KeyboardKey_F17;
                case VK_F18:        return KeyboardKey_F18;
                case VK_F19:        return KeyboardKey_F19;
                case VK_F20:        return KeyboardKey_F20;
                case VK_F21:        return KeyboardKey_F21;
                case VK_F22:        return KeyboardKey_F22;
                case VK_F23:        return KeyboardKey_F23;
                case VK_F24:        return KeyboardKey_F24;
                case VK_LEFT:       return KeyboardKey_Left;
                case VK_RIGHT:      return KeyboardKey_Right;
                case VK_UP:         return KeyboardKey_Up;
                case VK_DOWN:       return KeyboardKey_Down;
                case VK_SPACE:      return KeyboardKey_Space;
                case VK_ESCAPE:     return KeyboardKey_Escape;
                case VK_CONTROL:    return Keyboard::isKeyPressed(KeyboardKey_LeftControl) ? KeyboardKey_LeftControl : KeyboardKey_RightControl;
                case VK_LCONTROL:   return KeyboardKey_LeftControl;
                case VK_RCONTROL:   return KeyboardKey_RightControl;
                case VK_MENU:       return Keyboard::isKeyPressed(KeyboardKey_LeftAlt) ? KeyboardKey_LeftAlt : KeyboardKey_RightAlt;
                case VK_LMENU:      return KeyboardKey_LeftAlt;
                case VK_RMENU:      return KeyboardKey_RightAlt;
                case VK_LWIN:       return KeyboardKey_LeftSystem;
                case VK_RWIN:       return KeyboardKey_RightSystem;
                case VK_SHIFT:      return Keyboard::isKeyPressed(KeyboardKey_LeftShift) ? KeyboardKey_LeftShift : KeyboardKey_RightShift;
                case VK_LSHIFT:     return KeyboardKey_LeftShift;
                case VK_RSHIFT:     return KeyboardKey_RightShift;
                case VK_OEM_1:      return KeyboardKey_OEM1;
                case VK_OEM_PERIOD: return KeyboardKey_OEMPeriod;
                case VK_OEM_2:      return KeyboardKey_OEM2;
                case VK_OEM_3:      return KeyboardKey_OEM3;
                case VK_OEM_4:      return KeyboardKey_OEM4;
                case VK_OEM_5:      return KeyboardKey_OEM5;
                case VK_OEM_6:      return KeyboardKey_OEM6;
                case VK_OEM_7:      return KeyboardKey_OEM7;
                case VK_OEM_8:      return KeyboardKey_OEM8;
                case VK_OEM_102:    return KeyboardKey_OEM9;
                case VK_OEM_PLUS:   return KeyboardKey_OEMPlus;
                case VK_OEM_COMMA:  return KeyboardKey_OEMComma;
                case VK_TAB:        return KeyboardKey_Tab;
                case VK_BACK:       return KeyboardKey_Back;
                case VK_RETURN:     return KeyboardKey_Enter;
                case VK_CAPITAL:    return KeyboardKey_CapsLock;
                case VK_APPS:       return KeyboardKey_Apps;
                case VK_DELETE:     return KeyboardKey_Delete;
                case VK_INSERT:     return KeyboardKey_Insert;
                case VK_PRIOR:      return KeyboardKey_PageUp;
                case VK_NEXT:       return KeyboardKey_PageDown;
                case VK_END:        return KeyboardKey_End;
                case VK_HOME:       return KeyboardKey_Home;
                case VK_PAUSE:      return KeyboardKey_Pause;
                case VK_SNAPSHOT:   return KeyboardKey_ScreenShot;
                case VK_SCROLL:     return KeyboardKey_Scroll;
                default:            return KeyboardKey_Unknown;
            }
        }

        DWORD WindowImplWin32::computeWindowStyle(Uint32 WindowStyle)
        {
            DWORD windowWindowStyle = WS_VISIBLE;

            if(WindowStyle & (WindowStyle_Closable))
            {
                windowWindowStyle |= WS_SYSMENU;
            }

            if(WindowStyle & (WindowStyle_Maximizable))
            {
                windowWindowStyle |= WS_MAXIMIZEBOX;
            }

            if(WindowStyle & (WindowStyle_Minimizable))
            {
                windowWindowStyle |= WS_MINIMIZEBOX;
            }

            if(WindowStyle & (WindowStyle_Resizable))
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
            m_isFullscreen = style & WindowStyle_Fullscreen;
            DWORD winWindowStyle = computeWindowStyle(style);

            if(instanceCounter == 0)
            {
                registerWindowClass();
            }

            if(m_isFullscreen)
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

            Expect(m_handler != INVALID_HANDLE_VALUE, Throw(Win32Error, "WindowImplWin32::WindowImplWin32", "Failed to create window"));

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
                RECT winRect;
                GetWindowRect(m_handler, &winRect);

                ClipCursor(&winRect);
            }
            else
            {
                ClipCursor(nullptr);
            }
        }

        void WindowImplWin32::setPosition(const Size& position)
        {
            SetWindowPos(m_handler, nullptr, position.width, position.height, 0, 0, SWP_NOSIZE);
        }

        Size WindowImplWin32::getPosition() const
        {
            RECT r = {0, 0, 0, 0};

            GetWindowRect(m_handler, &r);

            return Size(r.left, r.top);
        }

        void WindowImplWin32::setMinSize(const Size& size)
        {
            RECT r = {0, 0,
                      size.width,
                      size.height,
            };
            AdjustWindowRect(&r, static_cast<DWORD>(GetWindowLongPtr(m_handler, GWL_STYLE)), false);

            m_minSize.width = (size.width != -1) ? r.right  - r.left : -1;
            m_minSize.height = (size.height != -1) ? r.bottom - r.top  : -1;
        }

        Size WindowImplWin32::getMinSize() const
        {
            return m_minSize;
        }

        void WindowImplWin32::setMaxSize(const Size& size)
        {
            RECT r = {0, 0,
                      size.width,
                      size.height,
            };
            AdjustWindowRect(&r, static_cast<DWORD>(GetWindowLongPtr(m_handler, GWL_STYLE)), false);

            m_maxSize.width = (size.width != -1) ? r.right  - r.left : -1;
            m_maxSize.height = (size.height != -1) ? r.bottom - r.top  : -1;
        }

        Size WindowImplWin32::getMaxSize() const
        {
            return m_maxSize;
        }

        void WindowImplWin32::setSize(const Size& size)
        {
            RECT r = {0, 0,
                      static_cast<LONG>(size.width),
                      static_cast<LONG>(size.height),
            };
            AdjustWindowRect(&r, static_cast<DWORD>(GetWindowLongPtr(m_handler, GWL_STYLE)), false);
            SetWindowPos(m_handler, nullptr, 0, 0, r.right - r.left, r.bottom - r.top, SWP_NOMOVE);
        }

        Size WindowImplWin32::getSize() const
        {
            RECT r = {0, 0, 0, 0};

            GetClientRect(m_handler, &r);

            return Size(static_cast<unsigned int>(r.right - r.left), static_cast<unsigned int>(r.bottom - r.top));
        }

        void WindowImplWin32::setTitle(const String& title)
        {
            SetWindowTextW(m_handler, reinterpret_cast<LPCWSTR>(title.getBuffer()));
        }

        String WindowImplWin32::getTitle() const
        {
            ArrayList<wchar_t> buffer;

            buffer.create(GetWindowTextLengthW(m_handler) + 1);

            GetWindowTextW(m_handler, &buffer[0], buffer.getCapacity());

            return String(reinterpret_cast<const char*>(buffer.getBuffer()), buffer.getCapacity());
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

            m_isFullscreen = fullscreen;
        }

        void WindowImplWin32::setVisible(bool visible)
        {
            ShowWindow(m_handler, (visible) ? SW_SHOW : SW_HIDE);
        }

        void WindowImplWin32::setIcon(const Image& icon)
        {
            ByteArray pixels(icon.getSize().width * icon.getSize().height * 4);

            for(std::size_t i = 0; i < pixels.getCapacity() / 4; i += 4)
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

            m_icon = CreateIcon(instance, icon.getSize().width, icon.getSize().height, 1, 32, nullptr, pixels.getBuffer());

            Expect(m_icon, Throw(Win32Error, "WindowImplWin32::setIcon", "Failed to set window's icon"));

            SendMessageW(m_handler, WM_SETICON, ICON_BIG,   (LPARAM)m_icon);
            SendMessageW(m_handler, WM_SETICON, ICON_SMALL, (LPARAM)m_icon);
        }

        void WindowImplWin32::setMouseCursor(const CursorImpl& cursor)
        {
            m_cursor = cursor.getSystemHandler();
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

                    e.type = WindowEventType_Closed;

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

                        e.type                = WindowEventType_Resized;
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

                    e.type = WindowEventType_LostFocus;

                    pushEvent(e);
                }
                break;

                case WM_SETFOCUS:
                {
                    WindowEvent e;

                    e.type = WindowEventType_GainFocus;

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

                        e.type                = WindowEventType_Resized;
                        e.windowResize.width  = m_lastSize.width;
                        e.windowResize.height = m_lastSize.height;

                        pushEvent(e);
                    }

                    if(getPosition() != m_lastPosition)
                    {
                        WindowEvent e;
                        m_lastPosition = getPosition();

                        e.type         = WindowEventType_Moved;
                        e.windowMove.x = getPosition().width;
                        e.windowMove.y = getPosition().height;

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

                        e.type        = WindowEventType_KeyDown;
                        e.key.code    = convertVKToBullkey(wParam);
                        e.key.alt     = Keyboard::isKeyPressed(KeyboardKey_Alt);
                        e.key.control = Keyboard::isKeyPressed(KeyboardKey_Control);
                        e.key.shift   = Keyboard::isKeyPressed(KeyboardKey_Shift);
                        e.key.system  = Keyboard::isKeyPressed(KeyboardKey_System);

                        pushEvent(e);
                    }
                }
                break;

                case WM_KEYUP:
                case WM_SYSKEYUP:
                {
                    WindowEvent e;

                    e.type        = WindowEventType_KeyUp;
                    e.key.code    = convertVKToBullkey(wParam);
                    e.key.alt     = Keyboard::isKeyPressed(KeyboardKey_Alt);
                    e.key.control = Keyboard::isKeyPressed(KeyboardKey_Control);
                    e.key.shift   = Keyboard::isKeyPressed(KeyboardKey_Shift);
                    e.key.system  = Keyboard::isKeyPressed(KeyboardKey_System);

                    pushEvent(e);
                }
                break;

                case WM_CHAR:
                {
                    WindowEvent e;

                    e.type = WindowEventType_Character;
                    e.character = static_cast<Uint32>(wParam);

                    pushEvent(e);
                }
                break;

                case WM_MOUSEHOVER:
                {
                    WindowEvent e;

                    e.type = WindowEventType_MouseEnter;

                    pushEvent(e);
                }
                break;

                case WM_MOUSELEAVE:
                {
                    WindowEvent e;

                    e.type = WindowEventType_MouseLeave;

                    pushEvent(e);
                }
                break;

                case WM_MOUSEMOVE:
                {
                    WindowEvent e;

                    e.type           = WindowEventType_MouseMoved;
                    e.mouseMove.x    = GET_X_LPARAM(lParam);
                    e.mouseMove.y    = GET_Y_LPARAM(lParam);
                    e.mouseMove.xRel = e.mouseMove.x - getCursorPosition().width;
                    e.mouseMove.yRel = e.mouseMove.y - getCursorPosition().height;

                    pushEvent(e);
                }
                break;

                case WM_LBUTTONDOWN:
                case WM_LBUTTONDBLCLK:
                {
                    WindowEvent e;

                    e.type               = WindowEventType_MouseButtonDown;
                    e.mouseButton.button = MouseButton_Left;
                    e.mouseButton.y      = GET_Y_LPARAM(lParam);
                    e.mouseButton.x      = GET_X_LPARAM(lParam);

                    pushEvent(e);

                    if(message == WM_LBUTTONDBLCLK)
                    {
                        e.type = WindowEventType_MouseButtonDoubleClicked;

                        pushEvent(e);
                    }
                }
                break;

                case WM_LBUTTONUP:
                {
                    WindowEvent e;

                    e.type               = WindowEventType_MouseButtonUp;
                    e.mouseButton.button = MouseButton_Left;
                    e.mouseButton.x      = GET_X_LPARAM(lParam);
                    e.mouseButton.y      = GET_Y_LPARAM(lParam);

                    pushEvent(e);
                }
                break;

                case WM_MBUTTONDOWN:
                case WM_MBUTTONDBLCLK:
                {
                    WindowEvent e;

                    e.type               = WindowEventType_MouseButtonDown;
                    e.mouseButton.button = MouseButton_Middle;
                    e.mouseButton.x      = GET_X_LPARAM(lParam);
                    e.mouseButton.y      = GET_Y_LPARAM(lParam);

                    pushEvent(e);

                    if(message == WM_MBUTTONDBLCLK)
                    {
                        e.type = WindowEventType_MouseButtonDoubleClicked;

                        pushEvent(e);
                    }
                }
                break;

                case WM_MBUTTONUP:
                {
                    WindowEvent e;

                    e.type               = WindowEventType_MouseButtonUp;
                    e.mouseButton.button = MouseButton_Middle;
                    e.mouseButton.x      = GET_X_LPARAM(lParam);
                    e.mouseButton.y      = GET_Y_LPARAM(lParam);

                    pushEvent(e);
                }
                break;

                case WM_RBUTTONDOWN:
                case WM_RBUTTONDBLCLK:
                {
                    WindowEvent e;

                    e.type               = WindowEventType_MouseButtonDown;
                    e.mouseButton.button = MouseButton_Right;
                    e.mouseButton.x      = GET_X_LPARAM(lParam);
                    e.mouseButton.y      = GET_Y_LPARAM(lParam);

                    pushEvent(e);

                    if(message == WM_RBUTTONDBLCLK)
                    {
                        e.type = WindowEventType_MouseButtonDoubleClicked;

                        pushEvent(e);
                    }
                }
                break;

                case WM_RBUTTONUP:
                {
                    WindowEvent e;

                    e.type               = WindowEventType_MouseButtonUp;
                    e.mouseButton.button = MouseButton_Right;
                    e.mouseButton.x      = GET_X_LPARAM(lParam);
                    e.mouseButton.y      = GET_Y_LPARAM(lParam);

                    pushEvent(e);
                }
                break;

                case WM_XBUTTONDOWN:
                case WM_XBUTTONDBLCLK:
                {
                    WindowEvent e;

                    e.type               = WindowEventType_MouseButtonDown;
                    e.mouseButton.button = (HIWORD(wParam) == XBUTTON1) ? MouseButton_Extra1 : MouseButton_Extra2;
                    e.mouseButton.x      = GET_X_LPARAM(lParam);
                    e.mouseButton.y      = GET_Y_LPARAM(lParam);

                    pushEvent(e);

                    if(message == WM_XBUTTONDBLCLK)
                    {
                        e.type = WindowEventType_MouseButtonDoubleClicked;

                        pushEvent(e);
                    }
                }
                break;

                case WM_XBUTTONUP:
                {
                    WindowEvent e;

                    e.type               = WindowEventType_MouseButtonUp;
                    e.mouseButton.button = (HIWORD(wParam) == XBUTTON1) ? MouseButton_Extra1 : MouseButton_Extra2;
                    e.mouseButton.x      = GET_X_LPARAM(lParam);
                    e.mouseButton.y      = GET_Y_LPARAM(lParam);

                    pushEvent(e);
                }
                break;

                case WM_MOUSEWHEEL:
                {
                    WindowEvent e;

                    e.type              = WindowEventType_MouseWheel;
                    e.mouseWheel.wheel  = MouseWheel_Vertical;
                    e.mouseWheel.up     = (HIWORD(wParam) == 120);
                    e.mouseWheel.x      = GET_X_LPARAM(lParam);
                    e.mouseWheel.y      = GET_Y_LPARAM(lParam);

                    pushEvent(e);
                }
                break;

                case WM_MOUSEHWHEEL:
                {
                    WindowEvent e;

                    e.type              = WindowEventType_MouseWheel;
                    e.mouseWheel.wheel  = MouseWheel_Horizontal;
                    e.mouseWheel.up     = (HIWORD(wParam) == 120);
                    e.mouseWheel.x      = GET_X_LPARAM(lParam);
                    e.mouseWheel.y      = GET_Y_LPARAM(lParam);

                    pushEvent(e);
                }

                case WM_GETMINMAXINFO:
                {
                    if(!m_isFullscreen)
                    {
                        Size min               = getMinSize();
                        Size max               = getMaxSize();
                        MINMAXINFO* minmaxinfo = reinterpret_cast<MINMAXINFO*>(lParam);

                        minmaxinfo->ptMaxSize.x = std::numeric_limits<LONG>::max();
                        minmaxinfo->ptMaxSize.y = std::numeric_limits<LONG>::max();

                        if(min.width > -1)
                        {
                            minmaxinfo->ptMinTrackSize.x = min.width;
                        }

                        if(min.height > -1)
                        {
                            minmaxinfo->ptMinTrackSize.y = min.height;
                        }

                        if(max.width > -1)
                        {
                            minmaxinfo->ptMaxTrackSize.x = max.width;
                        }

                        if(max.height > -1)
                        {
                            minmaxinfo->ptMaxTrackSize.y = max.height;
                        }
                    }
                }
                break;
            }
        }
    }
}
