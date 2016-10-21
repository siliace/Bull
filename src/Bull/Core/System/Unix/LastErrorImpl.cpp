#include <cerrno>

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
            return errno;
        }

        /*! \brief Get the message associated to the last error
         *
         * \return Return the message associated to the last error
         *
         */
        String LastErrorImpl::getMessage()
        {
            return String();
        }
    }
}
