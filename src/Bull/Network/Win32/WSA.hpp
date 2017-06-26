#ifndef BULL_NETWORK_WIN32_WSA_HPP
#define BULL_NETWORK_WIN32_WSA_HPP

#include <winsock2.h>

namespace Bull
{
    namespace prv
    {
        class WSA
        {
        public:

            /*! \brief Default constructor
             *
             */
            WSA();

            /*! \brief Destructor
             *
             */
            ~WSA();

        private:

            WSAData m_data;
        };
    }
}

#endif // BULL_NETWORK_WIN32_WSA_HPP
