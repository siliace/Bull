#ifndef Bull_ErrorHandler_hpp
#define Bull_ErrorHandler_hpp

#include <X11/Xlib.h>

#include <Bull/Core/Thread/Lock.hpp>

#include <Bull/Window/X11/Display.hpp>

namespace Bull
{
    namespace prv
    {
        class ErrorHandler
        {
        private:

            static Mutex s_mutex;

        public:

            /*! \brief Default constructor
             *
             */
            ErrorHandler();

            /*! \brief Start to listen errors to handle
             *
             */
            void listen();

            /*! \brief Handle Xlib errors
             *
             * \param display The connection where the error was sent
             * \param error   The error
             *
             * \return Return always 0
             *
             */
            int handle(::Display* display, XErrorEvent* error);

            /*! \brief Stop to handle errors
             *
             */
            void stop();

            /*! \brief Destructor
             *
             */
            ~ErrorHandler();

            /*! \brief Get the message associated to the last error
             *
             * \return Return the message
             *
             */
            String getMessage() const;

            /*! \brief Get the code of the last error
             *
             * \return Return the code
             *
             */
            unsigned int getCode() const;

        private:

            Lock          m_lock;
            String        m_message;
            unsigned int  m_code;
            XErrorHandler m_previousHandler;
        };
    }
}

#endif // Bull_ErrorHandler_hpp

