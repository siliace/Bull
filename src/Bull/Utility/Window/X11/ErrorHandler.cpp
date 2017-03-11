#include <Bull/Core/Log.hpp>
#include <Bull/Core/String.hpp>

#include <Bull/Utility/Window/X11/ErrorHandler.hpp>

namespace Bull
{
    namespace prv
    {
        Mutex ErrorHandler::s_mutex;
        bool ErrorHandler::s_errorOccurred = false;

        int ErrorHandler::handle(::Display* display, XErrorEvent* error)
        {
            String errorMessage(nullptr, 256);

            XGetErrorText(display, error->error_code, &errorMessage[0], errorMessage.getCapacity());

            s_errorOccurred = true;

            Log::get()->write(errorMessage, Log::Debug);

            return 0;
        }

        ErrorHandler::ErrorHandler() :
            m_lock(s_mutex),
            m_isBinded(false)
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
            if(!m_isBinded)
            {
                m_previousHandler = XSetErrorHandler(&ErrorHandler::handle);
                m_isBinded = true;
            }
        }

        void ErrorHandler::close()
        {
            if(m_isBinded)
            {
                XSync(Display::get()->getHandler(), False);
                XSetErrorHandler(m_previousHandler);
                m_isBinded = false;
            }
        }
    }
}
