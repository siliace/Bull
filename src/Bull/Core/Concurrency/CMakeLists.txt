set(BULL_INC_CORE_CONCURRENCY ${BULL_INC_CORE}/Concurrency)
set(BULL_SRC_CORE_CONCURRENCY ${BULL_SRC_CORE}/Concurrency)

target_sources(bull-core
        PUBLIC
            ${BULL_INC_CORE_CONCURRENCY}/ConditionVariable.hpp
            ${BULL_SRC_CORE_CONCURRENCY}/ConditionVariable.cpp
            ${BULL_INC_CORE_CONCURRENCY}/Lock.hpp
            ${BULL_SRC_CORE_CONCURRENCY}/Lock.cpp
            ${BULL_INC_CORE_CONCURRENCY}/Mutex.hpp
            ${BULL_SRC_CORE_CONCURRENCY}/Mutex.cpp
            ${BULL_INC_CORE_CONCURRENCY}/Runnable.hpp
            ${BULL_INC_CORE_CONCURRENCY}/Semaphore.hpp
            ${BULL_SRC_CORE_CONCURRENCY}/Semaphore.cpp
            ${BULL_INC_CORE_CONCURRENCY}/Thread.hpp
            ${BULL_SRC_CORE_CONCURRENCY}/Thread.cpp
            ${BULL_INC_CORE_CONCURRENCY}/ThreadPriority.hpp
            ${BULL_SRC_CORE_CONCURRENCY}/ConditionVariableImpl.cpp
            ${BULL_SRC_CORE_CONCURRENCY}/ConditionVariableImpl.hpp
            ${BULL_SRC_CORE_CONCURRENCY}/MutexHandler.hpp
            ${BULL_SRC_CORE_CONCURRENCY}/MutexImpl.cpp
            ${BULL_SRC_CORE_CONCURRENCY}/MutexImpl.hpp
            ${BULL_SRC_CORE_CONCURRENCY}/SemaphoreImpl.cpp
            ${BULL_SRC_CORE_CONCURRENCY}/SemaphoreImpl.hpp
            ${BULL_SRC_CORE_CONCURRENCY}/ThreadImpl.cpp
            ${BULL_SRC_CORE_CONCURRENCY}/ThreadImpl.hpp
        )

if(BULL_OS_WINDOWS)
    add_subdirectory(Win32)
else()
    add_subdirectory(Unix)
endif()