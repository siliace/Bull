#ifndef Bull_ErrorHandler_hpp
#define Bull_ErrorHandler_hpp

#include <X11/Xlib.h>

#include <Bull/Core/Thread/Lock.hpp>
#include <Bull/Core/Pattern/NonCopyable.hpp>

#include <Bull/Utility/Window/X11/Display.hpp>

namespace Bull
{
    namespace prv
    {
        class ErrorHandler : public NonCopyable
        {
        public:

            /*! \brief Handle Xlib errors
             *
             * \param display The connection where the error was sent
             * \param error   The error
             *
             * \return Return always 0
             *
             */
            static int handle(::Display* display, XErrorEvent* error);

        private:

            static Mutex s_mutex;

        public:

            /*! \brief Default constructor
             *
             */
            ErrorHandler();

            /*! \brief Destructor
             *
             */
            ~ErrorHandler();

        private:

            /*! \brief Start to listen errors to handle
             *
             */
            void listen();

            /*! \brief Stop to listen errors
             *
             */
            void close();

            Lock          m_lock;
            bool          m_isBinded;
            XErrorHandler m_previousHandler;
        };
    }
}

#endif // Bull_ErrorHandler_hpp

