#include <Bull/Core/Concurrency/Win32/SemaphoreImplWin32.hpp>
#include <Bull/Core/Exception/Expect.hpp>
#include <Bull/Core/Exception/InternalError.hpp>
#include <Bull/Core/Exception/Throw.hpp>

namespace Bull
{
    namespace prv
    {
        SemaphoreImplWin32::SemaphoreImplWin32(unsigned int count)
        {
            m_count = count;
            m_handler = CreateSemaphore(nullptr, m_count, MaxSemaphoreCount, nullptr);
            
            Expect(m_handler != INVALID_HANDLE_VALUE, Throw(InternalError, "SemaphoreImplWin32::SemaphoreImplWin32", "Failed to create semaphore"));
        }

        SemaphoreImplWin32::~SemaphoreImplWin32()
        {
            CloseHandle(m_handler);
        }

        void SemaphoreImplWin32::wait()
        {
            wait(Duration::Infinite);
        }

        bool SemaphoreImplWin32::wait(const Duration& timeout)
        {
            switch(WaitForSingleObject(m_handler, timeout.asMilliseconds()))
            {
                case WAIT_OBJECT_0:
                {
                    InterlockedDecrement(&m_count);
                    return true;
                }
                case WAIT_TIMEOUT:
                {
                    return false;
                }
                default:
                {
                    Throw(InternalError, "SemaphoreImplWin32::wait", "Failed to wait semaphore");
                }
            }
        }

        unsigned int SemaphoreImplWin32::getCount() const
        {
            return static_cast<unsigned int>(m_count);
        }

        void SemaphoreImplWin32::release()
        {
            InterlockedIncrement(&m_count);

            if(ReleaseSemaphore(m_handler, 1, nullptr) == FALSE)
            {
                InterlockedDecrement(&m_count);
                Throw(InternalError, "SemaphoreImplWin32::release", "Failed to release semaphore");
            }
        }
    }
}
