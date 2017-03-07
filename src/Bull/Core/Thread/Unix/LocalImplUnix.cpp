#include <Bull/Core/Thread/Unix/LocalImplUnix.hpp>

namespace Bull
{
    namespace prv
    {
        /*! \brief Default destructor
         *
         */
        LocalImplUnix::LocalImplUnix() :
            m_handler(0)
        {
            pthread_key_create(&m_handler, nullptr);
        }

        /*! \brief Destructor
         *
         */
        LocalImplUnix::~LocalImplUnix()
        {
            pthread_key_delete(m_handler);
        }

        /*! \brief Set the value
         *
         * \param value The new value of the variable
         *
         */
        void LocalImplUnix::set(void* value)
        {
            pthread_setspecific(m_handler, value);
        }

        /*! \brief Get the value
         *
         * \return Return the value of the variable
         *
         */
        void* LocalImplUnix::get() const
        {
            return pthread_getspecific(m_handler);
        }
    }
}
