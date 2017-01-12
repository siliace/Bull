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
            /*! \brief Get the last WSA error
             *
             * \return Return the error
             *
             */
            static int getLastError();
        };
    }
}

#endif // BULL_WSA_HPP
