#include <Bull/Utility/Window/X11/ErrorHandler.hpp>

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

            XGetErrorText(display, error->error_code, &handler->m_message[0], handler->m_message.getCapacity());

            return 0;
        }

        /*! \brief Default constructor
         *
         */
        ErrorHandler::ErrorHandler() :
            m_lock(s_mutex),
            m_code(0),
            m_isBinded(false)
        {
            /// Nothing
        }

        /*! \brief Destructor
         *
         */
        ErrorHandler::~ErrorHandler()
        {
            close();
        }

        /*! \brief Start to listen errors to handle
         *
         */
        void ErrorHandler::listen()
        {
            if(!m_isBinded)
            {
                m_previousHandler = XSetErrorHandler(&ErrorHandler::handle);
                m_isBinded = true;
            }
        }

        /*! \brief Stop to listen errors
         *
         */
        void ErrorHandler::close()
        {
            if(m_isBinded)
            {
                XSync(Display::get()->getHandler(), False);
                XSetErrorHandler(m_previousHandler);
                m_isBinded = false;
            }
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
