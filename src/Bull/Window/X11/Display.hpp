#ifndef Bull_Display_hpp
#define Bull_Display_hpp

#include <X11/Xlib.h>

#include <Bull/Core/Exception.hpp>
#include <Bull/Core/Pattern/Singleton.hpp>

namespace Bull
{
    namespace prv
    {
        class Display : public Singleton<Display>
        {
        public:

            /*! \brief Default constructor
             *
             */
            Display();

            /*! \brief Destructor
             *
             */
            ~Display();

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

            /*! \brief Get the X11 display
             *
             * \return Return the X11 display
             *
             */
            ::Display* getHandler();

        private:

            ::Display* m_display;

            DeclarePublicException(FailToOpenDisplay, "Failed to open X11 display");
        };
    }
}

#endif // Bull_Display_hpp
