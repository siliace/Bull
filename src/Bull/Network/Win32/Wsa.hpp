#ifndef BULL_WSA_HPP
#define BULL_WSA_HPP

#include <winsock2.h>

#include <Bull/Core/Exception.hpp>

namespace Bull
{
    namespace prv
    {
        struct Wsa
        {
            enum Error
            {
                Ok,
                SystemNotReady,
                VersionNotSupported,
                InProgress,
                EFault,
                Unknown,
            };

            /*! \brief Get the last WSA error
             *
             * \return Return the error
             *
             */
            static Error getLastError();
        };
    }
}

#endif // BULL_WSA_HPP
