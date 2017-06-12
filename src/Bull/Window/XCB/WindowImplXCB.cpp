#include <Bull/Window/XCB/WindowImplXCB.hpp>

namespace Bull
{
    namespace prv
    {
        WindowImplXCB::WindowImplXCB(const VideoMode &mode, const String &title, Uint32 style) :
            m_window(0)
        {
            Uint32 parameters[2];
            xcb_screen_iterator_t iterator;
            xcb_screen_t* screen = xcb_setup_roots_iterator(xcb_get_setup(m_connection)).data;

            m_window = xcb_generate_id(m_connection);

            xcb_create_window(m_connection,
                              XCB_COPY_FROM_PARENT,
                              m_window,
                              screen->root,
                              0, 0,
                              mode.width, mode.height,
                              0,
                              XCB_WINDOW_CLASS_INPUT_OUTPUT,
                              screen->root_visual,
                              XCB_CW_EVENT_MASK,
                              nullptr);

            xcb_map_window(m_connection, m_window);

            xcb_flush(m_connection);
        }

        WindowImplXCB::~WindowImplXCB()
        {

        }

        void WindowImplXCB::startProcessEvents()
        {

        }

        void WindowImplXCB::minimize()
        {

        }

        bool WindowImplXCB::isMinimized() const
        {
            return false;
        }

        void WindowImplXCB::maximize()
        {

        }

        bool WindowImplXCB::isMaximized() const
        {
            return false;
        }

        void WindowImplXCB::enableCaptureCursor(bool capture)
        {

        }

        void WindowImplXCB::showCursor(bool enable)
        {

        }

        void WindowImplXCB::setPosition(const Vector2I& position)
        {

        }

        Vector2I WindowImplXCB::getPosition() const
        {
            return Vector2I();
        }

        void WindowImplXCB::setMinSize(const Vector2UI& size)
        {

        }

        Vector2UI WindowImplXCB::getMinSize() const
        {
            return Vector2UI();
        }

        void WindowImplXCB::setMaxSize(const Vector2UI& size)
        {

        }

        Vector2UI WindowImplXCB::getMaxSize() const
        {
            return Vector2UI();
        }

        void WindowImplXCB::setSize(const Vector2UI& size)
        {

        }

        Vector2UI WindowImplXCB::getSize() const
        {
            return Vector2UI();
        }

        void WindowImplXCB::setTitle(const String& title)
        {

        }

        String WindowImplXCB::getTitle() const
        {
            return "";
        }

        bool WindowImplXCB::hasFocus() const
        {
            return false;
        }

        void WindowImplXCB::switchFullscreen(bool fullscreen)
        {

        }

        void WindowImplXCB::setVisible(bool visible)
        {

        }

        void WindowImplXCB::setMouseCursor(const std::unique_ptr<CursorImpl>& cursor)
        {

        }

        void WindowImplXCB::setMouseCursorVisible(bool visible)
        {

        }

        bool WindowImplXCB::isMouseCursorVisible() const
        {
            return false;
        }

        WindowHandler WindowImplXCB::getSystemHandler() const
        {
            return m_window;
        }
    }
}