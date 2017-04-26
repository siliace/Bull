#include <Bull/Core/Thread/Win32/SemaphoreImplWin32.hpp>

namespace Bull
{
    namespace prv
    {
        SemaphoreImplWin32::SemaphoreImplWin32(unsigned int count)
        {
            m_handler = CreateSemaphore(nullptr, count, count, nullptr);
        }

        SemaphoreImplWin32::~SemaphoreImplWin32()
        {
            CloseHandle(m_handler);
        }

        void SemaphoreImplWin32::wait()
        {
            WaitForSingleObject(m_handler, INFINITE);
        }

        bool SemaphoreImplWin32::wait(const Time& timeout)
        {
            return WaitForSingleObject(m_handler, timeout.asMilliseconds()) == WAIT_OBJECT_0;
        }

        unsigned int SemaphoreImplWin32::getCount() const
        {
            LONG count;

            ReleaseSemaphore(m_handler, 0, &count);

            return count;
        }

        void SemaphoreImplWin32::release()
        {
            ReleaseSemaphore(m_handler, 1, nullptr);
        }
    }
}
