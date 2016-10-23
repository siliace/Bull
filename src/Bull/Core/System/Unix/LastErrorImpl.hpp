#ifndef Bull_LastErrorImpl_hpp
#define Bull_LastErrorImpl_hpp

#include <Bull/Core/String.hpp>

namespace Bull
{
    namespace prv
    {
        class LastErrorImpl
        {
        public:

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

        private:

            static unsigned int m_lastError;
        };
    }
}

#endif // Bull_LastErrorImpl_hpp
