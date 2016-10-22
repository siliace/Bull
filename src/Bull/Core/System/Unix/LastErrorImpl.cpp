#include <cerrno>
#include <cstring>

#include <Bull/Core/System/LastErrorImpl.hpp>

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
            m_lastError = errno;

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
                m_lastError = errno;
            }

            if(m_lastError == 0)
            {
                return "";
            }

            return strerror(m_lastError);
        }
    }
}
