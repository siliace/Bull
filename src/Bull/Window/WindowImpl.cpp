#include <Bull/Core/System/Config.hpp>
#include <Bull/Core/Thread/Thread.hpp>

#include <Bull/Window/JoystickManager.hpp>
#include <Bull/Window/WindowImpl.hpp>

#if defined BULL_OS_WINDOWS
    #include <Bull/Window/Win32/WindowImplWin32.hpp>
    typedef Bull::prv::WindowImplWin32 WindowImplType;
#else
    #include <Bull/Window/X11/WindowImplX11.hpp>
    typedef Bull::prv::WindowImplX11 WindowImplType;
#endif

namespace Bull
{
    namespace prv
    {
        /*! \brief Create a OS specific WindowImpl instance
         *
         * \param mode The VideoMode to use to create the window
         * \param title The title of the window
         * \param style The style to use to create the window
         * \param settings Parameters to create the OpenGL context
         *
         * \return Return the created instance
         *
         */
        WindowImpl* WindowImpl::createInstance(const VideoMode& mode, const String& title, Uint32 style, const ContextSettings& settings)
        {
            return new WindowImplType(mode, title, style, settings);
        }

        /*! \brief Destructor
         *
         */
        WindowImpl::~WindowImpl()
        {
            /// Nothing
        }

        /*! \brief Get the first event of the event queue
         *
         * \param e The event to fill
         * \param block If the event queue is empty, block the thread while an event has been not pushed
         *
         * \return Return true if the event is usable, otherwise false (if block is true, always return true)
         *
         */
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

        /*! \brief Enable or disable the key repeat
         *
         * \param enable The state of the key repeat
         *
         */
        void WindowImpl::enableKeyRepeat(bool enable)
        {
            m_keyrepeat = enable;
        }

        /*! \brief Get the state of the key repeat
         *
         * \param Return true if the key repeat is enable, false otherwise
         *
         */
        bool WindowImpl::isKeyRepeatEnable() const
        {
            return m_keyrepeat;
        }

        /*! \brief Constructor
         *
         * Set m_keyrepeat to true
         *
         */
        WindowImpl::WindowImpl() :
            m_keyrepeat(true)
        {
            /// Nothing
        }

        /*! \brief Add an event to add at the end of the event queue
         *
         * \param e The event to add at the end of the event queue
         *
         */
        void WindowImpl::pushEvent(const Window::Event& e)
        {
            m_events.push(e);
        }
    }
}
