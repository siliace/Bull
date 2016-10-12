#include <windows.h>

#include <Bull/Core/System/Win32/LastErrorImpl.hpp>

namespace Bull
{
    namespace prv
    {
        unsigned int LastErrorImpl::m_lastError = 0;

        /*! \brief Get the last error code sent by the OS
         *
         * \return Return the code of the last error
         *
         */
        unsigned int LastErrorImpl::getCode()
        {
            m_lastError = GetLastError();

            return m_lastError;
        }

        /*! \brief Get the message associated to the last error
         *
         * \return Return the message associated to the last error
         *
         */
        String LastErrorImpl::getMessage()
        {
            if(m_lastError == 0)
            {
                m_lastError = GetLastError();
            }

            if(m_lastError == 0)
            {
                return "";
            }

            char buffer[256];
            size_t size = FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM, nullptr, m_lastError, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), buffer, 256, nullptr);

            return String(buffer);
        }
    }
}
