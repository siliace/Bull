#include <Bull/Window/XCB/WindowImplXCB.hpp>

namespace Bull
{
    namespace prv
    {
        WindowImplXCB::WindowImplXCB(const VideoMode &mode, const String &title, Uint32 style)
        {

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

        WindowHandler WindowImplXCB::getSystemHandler() const
        {
            return m_window;
        }
    }
}