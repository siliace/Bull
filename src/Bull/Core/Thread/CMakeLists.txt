set(BULL_INC_CORE_THREAD ${BULL_INC_CORE}/Thread)
set(BULL_SRC_CORE_THREAD ${BULL_SRC_CORE}/Thread)

target_sources(bull-core
        PUBLIC
            ${BULL_INC_CORE_THREAD}/ConditionVariable.hpp
            ${BULL_SRC_CORE_THREAD}/ConditionVariable.cpp
            ${BULL_INC_CORE_THREAD}/Lock.hpp
            ${BULL_SRC_CORE_THREAD}/Lock.cpp
            ${BULL_INC_CORE_THREAD}/Mutex.hpp
            ${BULL_SRC_CORE_THREAD}/Mutex.cpp
            ${BULL_INC_CORE_THREAD}/Semaphore.hpp
            ${BULL_SRC_CORE_THREAD}/Semaphore.cpp
            ${BULL_INC_CORE_THREAD}/Thread.hpp
            ${BULL_SRC_CORE_THREAD}/Thread.cpp
            ${BULL_INC_CORE_THREAD}/ThreadPriority.hpp
        PRIVATE
            ${BULL_SRC_CORE_THREAD}/ConditionVariableImpl.cpp
            ${BULL_SRC_CORE_THREAD}/ConditionVariableImpl.hpp
            ${BULL_SRC_CORE_THREAD}/MutexHandler.hpp
            ${BULL_SRC_CORE_THREAD}/MutexImpl.cpp
            ${BULL_SRC_CORE_THREAD}/MutexImpl.hpp
            ${BULL_SRC_CORE_THREAD}/SemaphoreImpl.cpp
            ${BULL_SRC_CORE_THREAD}/SemaphoreImpl.hpp
            ${BULL_SRC_CORE_THREAD}/ThreadImpl.cpp
            ${BULL_SRC_CORE_THREAD}/ThreadImpl.hpp
        )

if(BULL_OS_WINDOWS)
    add_subdirectory(Win32)
else()
    add_subdirectory(Unix)
endif()