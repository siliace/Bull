#ifndef Bull_ErrorHandler_hpp
#define Bull_ErrorHandler_hpp

#include <X11/Xlib.h>

#include <Bull/Core/Thread/Lock.hpp>

#include <Bull/Window/X11/Display.hpp>

namespace Bull
{
    namespace prv
    {
        class ErrorHandler : public Singleton<ErrorHandler>
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

            /*! \brief Start to listen errors to handle
             *
             */
            void listen();

            /*! \brief Stop to listen errors
             *
             */
            void close();

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
            bool          m_isBinded;
        };
    }
}

#endif // Bull_ErrorHandler_hpp

