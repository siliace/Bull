#include <Bull/Core/Thread/Win32/LocalImplWin32.hpp>

namespace Bull
{
    namespace prv
    {
        LocalImplWin32::LocalImplWin32()
        {
            m_id = TlsAlloc();
        }

        LocalImplWin32::~LocalImplWin32()
        {
            m_id = TlsFree(m_id);
        }

        void LocalImplWin32::set(void* value)
        {
            TlsSetValue(m_id, value);
        }

        void* LocalImplWin32::get() const
        {
            return TlsGetValue(m_id);
        }
    }
}
