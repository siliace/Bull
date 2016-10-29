#include <iostream>

#include <Bull/Window/X11/ErrorHandler.hpp>

namespace Bull
{
    namespace prv
    {
        Mutex ErrorHandler::s_mutex;

        /*! \brief Handle Xlib errors
         *
         * \param display The connection where the error was sent
         * \param error   The error
         *
         * \return Return always 0
         *
         */
        int ErrorHandler::handle(::Display* display, XErrorEvent* error)
        {
            ErrorHandler::Instance handler = ErrorHandler::get();

            handler->m_code = error->error_code;
            handler->m_message.reserve(256);

            XGetErrorText(display, error->error_code, &handler->m_message[0], handler->m_message.getSize());

            return 0;
        }

        /*! \brief Constructor
         *
         */
        ErrorHandler::ErrorHandler() :
            m_lock(s_mutex),
            m_code(0)
        {
            m_previousHandler = XSetErrorHandler(&ErrorHandler::handle);
        }

        /*! \brief Destructor
         *
         */
        ErrorHandler::~ErrorHandler()
        {
            XSync(Display::get()->getHandler(), False);
            XSetErrorHandler(m_previousHandler);
        }

        /*! \brief Get the message associated to the last error
         *
         * \return Return the message
         *
         */
        String ErrorHandler::getMessage() const
        {
            return m_message;
        }

        /*! \brief Get the code of the last error
         *
         * \return Return the code
         *
         */
        unsigned int ErrorHandler::getCode() const
        {
            return m_code;
        }
    }
}
