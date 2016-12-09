#include <Bull/Core/Thread/Win32/LocalImplWin32.hpp>

namespace Bull
{
    namespace prv
    {
        /*! \brief Default destructor
         *
         */
        LocalImplWin32::LocalImplWin32()
        {
            m_id = TlsAlloc();
        }

        /*! \brief Destructor
         *
         */
        LocalImplWin32::~LocalImplWin32()
        {
            m_id = TlsFree(m_id);
        }

        /*! \brief Set the value
         *
         * \param value The new value of the variable
         *
         */
        void LocalImplWin32::set(void* value)
        {
            TlsSetValue(m_id, value);
        }

        /*! \brief Get the value
         *
         * \return Return the value of the variable
         *
         */
        void* LocalImplWin32::get() const
        {
            return TlsGetValue(m_id);
        }
    }
}
