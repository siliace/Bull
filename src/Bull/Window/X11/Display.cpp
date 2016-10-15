#include <Bull/Window/X11/Display.hpp>

namespace Bull
{
    namespace prv
    {
        /*! \brief Default constructor
         *
         */
        Display::Display() :
            m_display(XOpenDisplay(nullptr))
        {
            if(!m_display)
            {
                ThrowException(FailToOpenDisplay);
            }
        }

        /*! \brief Destructor
         *
         */
        Display::~Display()
        {
            XCloseDisplay(m_display);
        }

        /*! \brief Flush the display
         *
         */
        void Display::flush()
        {
            XFlush(m_display);
        }

        /*! \brief Get the default screen
         *
         * \return Return the ID of the default render screen
         *
         */
        int Display::getDefaultScreen() const
        {
            return DefaultScreen(m_display);
        }

        /*! \brief Get the root window the a screen
         *
         * \return Return the root window of the default screen
         *
         */
        ::Window Display::getRootWindow() const
        {
            return RootWindow(m_display, getDefaultScreen());
        }

        /*! \brief Get the root window the a screen
         *
         * \param screen The screen
         *
         * \return Return the root window of the specified screen
         *
         */
        ::Window Display::getRootWindow(int screen) const
        {
            return RootWindow(m_display, screen);
        }

        /*! \brief Get the default color depth of the default screen
         *
         * \return Return the depth
         *
         */
        int Display::getDefaultDepth() const
        {
            return DefaultDepth(m_display, getDefaultScreen());
        }

        /*! \brief Get the default color depth of the specified screen
         *
         * \param screen The screen
         *
         * \return Return the depth
         *
         */
        int Display::getDefaultDepth(int screen)
        {
            return DefaultDepth(m_display, screen);
        }

        /*! \brief Check whether an extension is supported
         *
         * \param name The name of the extension
         *
         * \return Return true if the extension is supported, false otherwise
         *
         */
        bool Display::isSupportedExtension(const String& name) const
        {
            int version;
            return XQueryExtension(m_display, name, &version, &version, &version);
        }

        /*! \brief Get the X11 display
         *
         * \return Return the X11 display
         *
         */
        ::Display* Display::getHandler()
        {
            return m_display;
        }
    }
}
