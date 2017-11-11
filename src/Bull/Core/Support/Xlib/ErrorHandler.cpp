#include <Bull/Core/Log/Log.hpp>

#include <Bull/Core/Support/Xlib/ErrorHandler.hpp>

namespace Bull
{
    namespace prv
    {
        Mutex ErrorHandler::s_mutex;
        bool ErrorHandler::s_errorOccurred = false;

        int ErrorHandler::handle(XDisplay* display, XErrorEvent* error)
        {
            String errorMessage(nullptr, 256);

            XGetErrorText(display, error->error_code, &errorMessage[0], 256);

            s_errorOccurred = true;

            Log::get()->write(errorMessage, LogLevel_Debug);

            return 0;
        }

        ErrorHandler::ErrorHandler() :
            m_lock(s_mutex),
            m_isBound(false)
        {
            s_errorOccurred = false;

            listen();
        }

        ErrorHandler::~ErrorHandler()
        {
            close();
        }

        bool ErrorHandler::errorOccurred() const
        {
            return s_errorOccurred;
        }

        void ErrorHandler::resetError()
        {
            s_errorOccurred = false;
        }

        void ErrorHandler::listen()
        {
            if(!m_isBound)
            {
                m_previousHandler = XSetErrorHandler(&ErrorHandler::handle);
                m_isBound = true;
            }
        }

        void ErrorHandler::close()
        {
            if(m_isBound)
            {
                XSync(Display::get()->getHandler(), False);
                XSetErrorHandler(m_previousHandler);
                m_isBound = false;
            }
        }
    }
}
