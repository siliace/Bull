#include <Bull/Window/X11/WindowImplX11.hpp>

namespace Bull
{
    namespace prv
    {
        /*! \brief Constructor
         *
         * \param mode The VideoMode to use to create the window
         * \param title The title of the window
         * \param style The style to use to create the window
         *
         */
        WindowImplX11::WindowImplX11(const VideoMode& mode, const String& title, Uint32 style) :
            m_display(Display::get()),
            m_handler(0)
        {
            XSetWindowAttributes attribs;
            attribs.event_mask = KeyPress | KeyRelease;

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

        }

        /*! \brief Set the size of the window
         *
         * \param x The new width of the window
         * \param y The new height of the window
         *
         */
        Vector2I WindowImplX11::getPosition() const
        {

        }

        /*! \brief Set the size of the window
         *
         * \param size The new size of the window
         *
         */
        void WindowImplX11::setSize(const Vector2UI& size)
        {

        }

        /*! \brief Get the size of the window
         *
         * \return Return the size of the window
         *
         */
        Vector2UI WindowImplX11::getSize() const
        {

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
