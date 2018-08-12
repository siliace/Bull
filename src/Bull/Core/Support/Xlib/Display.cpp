#include <Bull/Core/Exception/InternalError.hpp>

#include <Bull/Core/Support/Xlib/Display.hpp>

namespace Bull
{
    namespace prv
    {
        Display::Display()
        {
            XInitThreads();

            m_display = XOpenDisplay(nullptr);

            if(!m_display)
            {
                Throw(InternalError, "Display::Display", "Failed to open display");
            }
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

        XWindow Display::getRootWindow() const
        {
            return RootWindow(m_display, getDefaultScreen());
        }

        XWindow Display::getRootWindow(int screen) const
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
            return XQueryExtension(m_display, name.getBuffer(), &version, &version, &version) == True;
        }

        Atom Display::getAtom(const String& name, bool mustExists)
        {
            XLockDisplay(m_display);

            std::map<String, XAtom>::const_iterator iterator = m_atoms.find(name);

            if(iterator != m_atoms.end())
            {
                return iterator->second;
            }

            XAtom atom = XInternAtom(m_display, name.getBuffer(), mustExists ? True : False);

            XUnlockDisplay(m_display);

            m_atoms[name] = atom;

            return atom;
        }

        XDisplay* Display::getHandler()
        {
            return m_display;
        }
    }
}
