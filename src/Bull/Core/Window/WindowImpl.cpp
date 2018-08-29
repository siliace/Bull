#include <thread>

#include <Bull/Core/Hardware/Mouse.hpp>
#include <Bull/Core/Window/JoystickManager.hpp>
#include <Bull/Core/Window/WindowImpl.hpp>

#if defined BULL_OS_WINDOWS
    #include <Bull/Core/Window/Win32/WindowImplWin32.hpp>
    typedef Bull::prv::WindowImplWin32 WindowImplType;
#elif defined BULL_OS_GNU_LINUX
    #include <Bull/Core/Window/Xlib/WindowImplXlib.hpp>
    typedef Bull::prv::WindowImplXlib WindowImplType;
#else
    #error System not supported
#endif

namespace Bull
{
    namespace prv
    {
        std::unique_ptr<WindowImpl> WindowImpl::createInstance(const VideoMode& mode, const String& title, Uint32 WindowStyle)
        {
            return std::make_unique<WindowImplType>(mode, title, WindowStyle);
        }

        WindowImpl::~WindowImpl() = default;

        bool WindowImpl::popEvent(WindowEvent& e, bool block)
        {
            JoystickManager& manager = JoystickManager::getInstance();

            if(m_events.empty())
            {
                startProcessEvents();
                manager.processEvents(m_events);

                if(m_events.empty() && block)
                {
                    do
                    {
                        startProcessEvents();
                        manager.processEvents(m_events);

                        std::this_thread::sleep_for(std::chrono::milliseconds(20));
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

        void WindowImpl::pushEvent(const WindowEvent& e)
        {
            if(e.type == WindowEventType_MouseMoved)
            {
                m_cursorPosition = Size(e.mouseMove.x, e.mouseMove.y);
            }

            m_events.push(e);
        }

        const Size& WindowImpl::getCursorPosition() const
        {
            return m_cursorPosition;
        }
    }
}
