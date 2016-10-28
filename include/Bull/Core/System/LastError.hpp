#ifndef Bull_LastError_hpp
#define Bull_LastError_hpp

#include <Bull/Core/String.hpp>

namespace Bull
{
    struct BULL_API  LastError
    {
        /*! \brief Get the last error code sent by the OS
         *
         * \return Return the code of the last error
         *
         */
        static unsigned int getCode();

        /*! \brief Get the message associated to the last error
         *
         * \return Return the message associated to the last error
         *
         */
        static String getMessage();
    };
}

#endif // Bull_LastError_hpp
