#include <Bull/Core/System/LastError.hpp>
#include <Bull/Core/System/LastErrorImpl.hpp>

namespace Bull
{
    /*! \brief Get the last error code sent by the OS
     *
     * \return Return the code of the last error
     *
     */
    unsigned int LastError::getCode()
    {
        return prv::LastErrorImpl::getCode();
    }

    /*! \brief Get the message associated to the last error
     *
     * \return Return the message associated to the last error
     *
     */
    String LastError::getMessage()
    {
        return prv::LastErrorImpl::getMessage();
    }
}
