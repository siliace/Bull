#include <Bull/Utility/Window/X11/Display.hpp>

namespace Bull
{
    namespace prv
    {
        Display::Display() :
            m_display(XOpenDisplay(nullptr))
        {
            /// Nothing
        }

        Display::~Display()
        {
            XCloseDisplay(m_display);
        }

        void Display::flush()
        {
            XFlush(m_display);
        }

        int Display::getDefaultScreen() const
        {
            return DefaultScreen(m_display);
        }

        ::Window Display::getRootWindow() const
        {
            return RootWindow(m_display, getDefaultScreen());
        }

        ::Window Display::getRootWindow(int screen) const
        {
            return RootWindow(m_display, screen);
        }

        int Display::getDefaultDepth() const
        {
            return DefaultDepth(m_display, getDefaultScreen());
        }

        int Display::getDefaultDepth(int screen)
        {
            return DefaultDepth(m_display, screen);
        }

        bool Display::isSupportedExtension(const String& name) const
        {
            int version;
            return XQueryExtension(m_display, name, &version, &version, &version);
        }

        Atom Display::getAtom(const String& name, bool mustExists)
        {
            std::map<String, Atom>::const_iterator iterator = m_atoms.find(name);

            if(iterator != m_atoms.end())
            {
                return iterator->second;
            }

            Atom atom = XInternAtom(getHandler(), name, mustExists ? True : False);

            m_atoms[name] = atom;

            return atom;
        }

        ::Display* Display::getHandler()
        {
            return m_display;
        }
    }
}
