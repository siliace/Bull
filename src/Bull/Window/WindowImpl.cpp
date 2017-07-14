#include <Bull/Core/Thread/Thread.hpp>

#include <Bull/Hardware/Mouse.hpp>

#include <Bull/Window/JoystickManager.hpp>
#include <Bull/Window/WindowImpl.hpp>

#if defined BULL_OS_WINDOWS
    #include <Bull/Window/Win32/WindowImplWin32.hpp>
    typedef Bull::prv::WindowImplWin32 WindowImplType;
#elif defined BULL_OS_GNU_LINUX
    #if defined BULL_XLIB
        #include <Bull/Window/Xlib/WindowImplXlib.hpp>
        typedef Bull::prv::WindowImplXlib WindowImplType;
    #elif defined BULL_XCB
        #include <Bull/Window/XCB/WindowImplXCB.hpp>
        typedef Bull::prv::WindowImplXCB WindowImplType;
    #elif defined BULL_WAYLAND
        #error Todo
    #endif
#else
    #error System not supported
#endif

namespace Bull
{
    namespace prv
    {
        WindowImpl* WindowImpl::createInstance(const VideoMode& mode, const String& title, Uint32 style)
        {
            return new WindowImplType(mode, title, style);
        }

        WindowImpl::~WindowImpl()
        {
            /// Nothing
        }

        bool WindowImpl::popEvent(Window::Event& e, bool block)
        {
            JoystickManager::Instance manager = JoystickManager::get();

            if(m_events.empty())
            {
                startProcessEvents();
                manager->processEvents(m_events);

                if(m_events.empty() && block)
                {
                    do
                    {
                        startProcessEvents();
                        manager->processEvents(m_events);
                        Thread::sleep(Time::milliseconds(10));
                    }while(m_events.empty());
                }
            }

            if(!m_events.empty())
            {
                e = m_events.front();
                m_events.pop();

                return true;
            }

            return false;
        }

        void WindowImpl::enableKeyRepeat(bool enable)
        {
            m_keyrepeat = enable;
        }

        bool WindowImpl::isKeyRepeatEnable() const
        {
            return m_keyrepeat;
        }

        WindowImpl::WindowImpl() :
            m_keyrepeat(true),
            m_cursorPosition(Mouse::getPosition())
        {
            /// Nothing
        }

        void WindowImpl::pushEvent(const Window::Event& e)
        {
            if(e.type == Window::Event::MouseMoved)
            {
                m_cursorPosition = Vector2I(e.mouseMove.x, e.mouseMove.y);
            }

            m_events.push(e);
        }

        const Vector2I& WindowImpl::getCursorPosition() const
        {
            return m_cursorPosition;
        }
    }
}
