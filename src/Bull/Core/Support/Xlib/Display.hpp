#ifndef BULL_DISPLAY_HPP
#define BULL_DISPLAY_HPP

#include <map>

#include <X11/Xlib.h>

#include <Bull/Core/Memory/String.hpp>

namespace Bull
{
    namespace prv
    {
        class Display
        {
        public:

            typedef ::Display* XDisplay;

        private:

            static std::map<String, Atom> s_atoms;
            static XDisplay               s_display;
            static unsigned int           s_instanceCounter;

        public:

            /*! \brief Default constructor
             *
             */
            Display();

            /*! \brief Copy constructor
             *
             * \param copy The Display to copy
             *
             */
            Display(const Display& copy);

            /*! \brief Destructor
             *
             */
            ~Display();

            /*! \brief Basic assignment operator
             *
             * \param copy The Display to copy
             *
             * \return This
             *
             */
            Display& operator=(const Display& copy);

            /*! \brief Flush the display
             *
             */
            void flush();

            /*! \brief Get the default screen
             *
             * \return Return the ID of the default render screen
             *
             */
            int getDefaultScreen() const;

            /*! \brief Get the root window the a screen
             *
             * \return Return the root window of the default screen
             *
             */
            ::Window getRootWindow() const;

            /*! \brief Get the root window the a screen
             *
             * \param screen The screen
             *
             * \return Return the root window of the specified screen
             *
             */
            ::Window getRootWindow(int screen) const;

            /*! \brief Get the default color depth of the default screen
             *
             * \return Return the depth
             *
             */
            int getDefaultDepth() const;

            /*! \brief Get the default color depth of the specified screen
             *
             * \param screen The screen
             *
             * \return Return the depth
             *
             */
            int getDefaultDepth(int screen);

            /*! \brief Check whether an extension is supported
             *
             * \param name The name of the extension
             *
             * \return Return true if the extension is supported, false otherwise
             *
             */
            bool isSupportedExtension(const String& name) const;

            /*! \brief Get an atom
             *
             * \param name The name of the atom
             * \param mustExists If false and the atom does not exists, the atom is created
             *
             * \return Return the atom
             *
             */
            Atom getAtom(const String& name, bool mustExists = false);

            /*! \brief Convert the display to a Xlib display
             *
             * \return
             *
             */
            operator XDisplay() const;
        };
    }
}

#endif // BULL_DISPLAY_HPP
