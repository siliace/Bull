#include <Bull/Core/Log/Log.hpp>
#include <Bull/Core/Utility/StringUtils.hpp>

#include <Bull/Core/Support/Xlib/ErrorHandler.hpp>

namespace Bull
{
    namespace prv
    {
        std::mutex ErrorHandler::s_mutex;
        bool ErrorHandler::s_errorOccurred = false;

        int ErrorHandler::handle(XDisplay* display, XErrorEvent* error)
        {
            String errorMessage = StringUtils::ofSize(256);

            XGetErrorText(display, error->error_code, &errorMessage[0], errorMessage.getSize());

            s_errorOccurred = true;

            Log::getInstance().debug(errorMessage);

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
                XSync(Display::getInstance().getHandler(), False);
                XSetErrorHandler(m_previousHandler);
                m_isBound = false;
            }
        }
    }
}
