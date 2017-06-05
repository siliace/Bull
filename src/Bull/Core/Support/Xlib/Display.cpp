#include <Bull/Core/Support/Xlib/Display.hpp>

namespace Bull
{
    namespace prv
    {
        std::map<String, XAtom> Display::s_atoms;
        XDisplay*               Display::s_display = nullptr;
        unsigned int            Display::s_instanceCounter = 0;

        Display::Display()
        {
            if(s_instanceCounter == 0)
            {
                s_display = XOpenDisplay(nullptr);

                if(!s_display)
                {
                    throw std::runtime_error("Failed to open display");
                }
            }

            s_instanceCounter += 1;
        }

        Display::Display(const Display& copy) :
            Display()
        {
            /// Nothing
        }

        Display::~Display()
        {
            s_instanceCounter -= 1;

            if(s_instanceCounter == 0)
            {
                XCloseDisplay(s_display);
            }
        }

        Display& Display::operator=(const Display& copy)
        {
            s_instanceCounter += 1;

            return (*this);
        }

        void Display::flush()
        {
            XFlush(s_display);
        }

        int Display::getDefaultScreen() const
        {
            return DefaultScreen(s_display);
        }

        Window Display::getRootWindow() const
        {
            return RootWindow(s_display, getDefaultScreen());
        }

        Window Display::getRootWindow(int screen) const
        {
            return RootWindow(s_display, screen);
        }

        int Display::getDefaultDepth() const
        {
            return DefaultDepth(s_display, getDefaultScreen());
        }

        int Display::getDefaultDepth(int screen)
        {
            return DefaultDepth(s_display, screen);
        }

        bool Display::isSupportedExtension(const String& name) const
        {
            int version;
            return XQueryExtension(s_display, name.getBuffer(), &version, &version, &version) == True;
        }

        Atom Display::getAtom(const String& name, bool mustExists)
        {
            std::map<String, XAtom>::const_iterator iterator = s_atoms.find(name);

            if(iterator != s_atoms.end())
            {
                return iterator->second;
            }

            XAtom atom = XInternAtom(s_display, name.getBuffer(), mustExists ? True : False);

            s_atoms[name] = atom;

            return atom;
        }

        Display::operator XDisplay*() const
        {
            return s_display;
        }
    }
}
