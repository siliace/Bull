#include <Bull/Core/System/Config.hpp>
#include <Bull/Core/Thread/Thread.hpp>

#include <Bull/Utility/Window/JoystickManager.hpp>
#include <Bull/Utility/Window/WindowImpl.hpp>

#if defined BULL_OS_WINDOWS
    #include <Bull/Utility/Window/Win32/WindowImplWin32.hpp>
    typedef Bull::prv::WindowImplWin32 WindowImplType;
#else
    #include <Bull/Utility/Window/X11/WindowImplX11.hpp>
    typedef Bull::prv::WindowImplX11 WindowImplType;
#endif

namespace Bull
{
    namespace prv
    {
        WindowImpl* WindowImpl::createInstance(const VideoMode& mode, const String& title, Uint32 style, const ContextSettings& settings)
        {
            return new WindowImplType(mode, title, style, settings);
        }

        WindowImpl::~WindowImpl()
        {
            /// Nothing
        }

        bool WindowImpl::popEvent(Window::Event& e, bool block)
        {
            //JoystickManager::Instance manager = JoystickManager::get();

            if(m_events.empty())
            {
                startProcessEvents();
                //manager->processEvents(m_events);

                if(m_events.empty() && block)
                {
                    do
                    {
                        startProcessEvents();
                        //manager->processEvents(m_events);
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
            m_keyrepeat(true)
        {
            /// Nothing
        }

        void WindowImpl::pushEvent(const Window::Event& e)
        {
            if(!((e.type == Window::Event::KeyDown || e.type == Window::Event::KeyUp) && e.key.code == Keyboard::Key::Unknown))
            {
                m_events.push(e);
            }
        }
    }
}
