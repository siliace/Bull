#include <iostream>

#include <Bull/Core/Log.hpp>
#include <Bull/Core/String.hpp>

#include <Bull/Utility/Window/X11/ErrorHandler.hpp>

namespace Bull
{
    namespace prv
    {
        Mutex ErrorHandler::s_mutex;

        int ErrorHandler::handle(::Display* display, XErrorEvent* error)
        {
            String errorMessage;
            errorMessage.reserve(256);

            XGetErrorText(display, error->error_code, &errorMessage[0], errorMessage.getCapacity());

            Log::get()->write(errorMessage, Log::Error);

            return 0;
        }

        ErrorHandler::ErrorHandler() :
            m_lock(s_mutex),
            m_isBinded(false)
        {
            listen();
        }

        ErrorHandler::~ErrorHandler()
        {
            close();
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
