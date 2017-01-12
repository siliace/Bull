set (INCROOT ${PROJECT_SOURCE_DIR}/include/Bull/Core)
set (SRCROOT ${PROJECT_SOURCE_DIR}/src/Bull/Core)

set(SRC ${INCROOT}/AbstractLogger.hpp
        ${SRCROOT}/Exception.cpp
        ${INCROOT}/Exception.hpp
        ${INCROOT}/Functor.hpp
        ${INCROOT}/Functor/AbstractFunctor.hpp
        ${INCROOT}/Functor/FunctorMethodConstWithArgs.hpp
        ${INCROOT}/Functor/FunctorMethodConstWithoutArgs.hpp
        ${INCROOT}/Functor/FunctorMethodWithArgs.hpp
        ${INCROOT}/Functor/FunctorMethodWithoutArgs.hpp
        ${INCROOT}/Functor/FunctorWithArgs.hpp
        ${INCROOT}/Functor/FunctorWithoutArgs.hpp
        ${INCROOT}/Integer.hpp
        ${SRCROOT}/Log.cpp
        ${INCROOT}/Log.hpp
        ${SRCROOT}/String.cpp
        ${INCROOT}/String.hpp
        ${INCROOT}/Macro.hpp)
source_group("" FILES ${SRC})

set(SRC_FILESYSTEM ${SRCROOT}/FileSystem/Directory.cpp
                   ${INCROOT}/FileSystem/Directory.hpp
                   ${SRCROOT}/FileSystem/DirectoryImpl.cpp
                   ${SRCROOT}/FileSystem/DirectoryImpl.hpp
                   ${SRCROOT}/FileSystem/File.cpp
                   ${INCROOT}/FileSystem/File.hpp
                   ${SRCROOT}/FileSystem/FileImpl.cpp
                   ${SRCROOT}/FileSystem/FileImpl.hpp
                   ${INCROOT}/FileSystem/Path.hpp)

if(BULL_OS_WINDOWS)
    list(APPEND SRC_FILESYSTEM ${SRCROOT}/FileSystem/Win32/DirectoryImplWin32.cpp)
    list(APPEND SRC_FILESYSTEM ${SRCROOT}/FileSystem/Win32/DirectoryImplWin32.hpp)
    list(APPEND SRC_FILESYSTEM ${SRCROOT}/FileSystem/Win32/FileImplWin32.cpp)
    list(APPEND SRC_FILESYSTEM ${SRCROOT}/FileSystem/Win32/FileImplWin32.hpp)
else()
    list(APPEND SRC_FILESYSTEM ${SRCROOT}/FileSystem/Unix/DirectoryImplUnix.cpp)
    list(APPEND SRC_FILESYSTEM ${SRCROOT}/FileSystem/Unix/DirectoryImplUnix.hpp)
    list(APPEND SRC_FILESYSTEM ${SRCROOT}/FileSystem/Unix/FileImplUnix.cpp)
    list(APPEND SRC_FILESYSTEM ${SRCROOT}/FileSystem/Unix/FileImplUnix.hpp)
endif()

source_group("filesystem" FILES ${SRC_FILESYSTEM})

set(SRC_IO ${INCROOT}/IO/InOutStream.hpp
           ${SRCROOT}/IO/InStream.cpp
           ${INCROOT}/IO/InStream.hpp
           ${INCROOT}/IO/OutStream.hpp
           ${SRCROOT}/IO/StringStream.cpp
           ${INCROOT}/IO/StringStream.hpp)

source_group("io" FILES ${SRC_IO})

set(SRC_PATTERN ${INCROOT}/Pattern/NonCopyable.hpp
                ${INCROOT}/Pattern/Singleton.hpp)

source_group("pattern" FILES ${SRC_PATTERN})

set(SRC_SYSTEM ${INCROOT}/System/Config.hpp
               ${INCROOT}/System/Export.hpp
               ${SRCROOT}/System/Library.cpp
               ${INCROOT}/System/Library.hpp
               ${SRCROOT}/System/LibraryImpl.cpp
               ${SRCROOT}/System/LibraryImpl.hpp)

if(BULL_OS_WINDOWS)
    list(APPEND SRC_SYSTEM ${SRCROOT}/System/Win32/LibraryImplWin32.cpp)
    list(APPEND SRC_SYSTEM ${SRCROOT}/System/Win32/LibraryImplWin32.hpp)
else()
    list(APPEND SRC_SYSTEM ${SRCROOT}/System/Unix/LibraryImplUnix.cpp)
    list(APPEND SRC_SYSTEM ${SRCROOT}/System/Unix/LibraryImplUnix.hpp)
endif()

source_group("system" FILES ${SRC_SYSTEM})

set(SRC_THREAD ${SRCROOT}/Thread/ConditionVariable.cpp
               ${INCROOT}/Thread/ConditionVariable.hpp
               ${SRCROOT}/Thread/ConditionVariableImpl.cpp
               ${SRCROOT}/Thread/ConditionVariableImpl.hpp
               ${SRCROOT}/Thread/Lock.cpp
               ${INCROOT}/Thread/Lock.hpp
               ${SRCROOT}/Thread/Mutex.cpp
               ${INCROOT}/Thread/Mutex.hpp
               ${SRCROOT}/Thread/MutexImpl.cpp
               ${SRCROOT}/Thread/MutexImpl.hpp
               ${SRCROOT}/Thread/Semaphore.cpp
               ${INCROOT}/Thread/Semaphore.hpp
               ${SRCROOT}/Thread/SemaphoreImpl.cpp
               ${SRCROOT}/Thread/SemaphoreImpl.hpp
               ${SRCROOT}/Thread/Thread.cpp
               ${INCROOT}/Thread/Thread.hpp
               ${SRCROOT}/Thread/ThreadImpl.cpp
               ${SRCROOT}/Thread/ThreadImpl.hpp)

if(BULL_OS_WINDOWS)
    list(APPEND SRC_THREAD ${SRCROOT}/Thread/Win32/ConditionVariableImplLegacy.cpp)
    list(APPEND SRC_THREAD ${SRCROOT}/Thread/Win32/ConditionVariableImplLegacy.cpp)
    list(APPEND SRC_THREAD ${SRCROOT}/Thread/Win32/ConditionVariableImplWin32.cpp)
    list(APPEND SRC_THREAD ${SRCROOT}/Thread/Win32/ConditionVariableImplWin32.cpp)
    list(APPEND SRC_THREAD ${SRCROOT}/Thread/Win32/MutexImplWin32.cpp)
    list(APPEND SRC_THREAD ${SRCROOT}/Thread/Win32/MutexImplWin32.cpp)
    list(APPEND SRC_THREAD ${SRCROOT}/Thread/Win32/SemaphoreImplWin32.cpp)
    list(APPEND SRC_THREAD ${SRCROOT}/Thread/Win32/SemaphoreImplWin32.cpp)
    list(APPEND SRC_THREAD ${SRCROOT}/Thread/Win32/ThreadImplWin32.cpp)
    list(APPEND SRC_THREAD ${SRCROOT}/Thread/Win32/ThreadImplWin32.hpp)
else()
    list(APPEND SRC_THREAD ${SRCROOT}/Thread/Unix/ConditionVariableImplUnix.cpp)
    list(APPEND SRC_THREAD ${SRCROOT}/Thread/Unix/ConditionVariableImplUnix.cpp)
    list(APPEND SRC_THREAD ${SRCROOT}/Thread/Unix/MutexImplUnix.cpp)
    list(APPEND SRC_THREAD ${SRCROOT}/Thread/Unix/MutexImplUnix.cpp)
    list(APPEND SRC_THREAD ${SRCROOT}/Thread/Unix/SemaphoreImplUnix.cpp)
    list(APPEND SRC_THREAD ${SRCROOT}/Thread/Unix/SemaphoreImplUnix.cpp)
    list(APPEND SRC_THREAD ${SRCROOT}/Thread/Unix/ThreadImplUnix.cpp)
    list(APPEND SRC_THREAD ${SRCROOT}/Thread/Unix/ThreadImplUnix.hpp)
endif()

set(SRC_TIME ${SRCROOT}/Time/Clock.cpp
             ${INCROOT}/Time/Clock.hpp
             ${SRCROOT}/Time/ClockImpl.hpp
             ${SRCROOT}/Time/Date.cpp
             ${INCROOT}/Time/Date.hpp
             ${SRCROOT}/Time/DateImpl.hpp
             ${SRCROOT}/Time/Time.cpp
             ${INCROOT}/Time/Time.hpp)

if(BULL_OS_WINDOWS)
    list(APPEND SRC_TIME ${SRCROOT}/Time/Win32/ClockImpl.cpp)
    list(APPEND SRC_TIME ${SRCROOT}/Time/Win32/ClockImpl.hpp)
    list(APPEND SRC_TIME ${SRCROOT}/Time/Win32/DateImpl.cpp)
    list(APPEND SRC_TIME ${SRCROOT}/Time/Win32/DateImpl.hpp)
else()
    list(APPEND SRC_TIME ${SRCROOT}/Time/Unix/ClockImpl.cpp)
    list(APPEND SRC_TIME ${SRCROOT}/Time/Unix/ClockImpl.hpp)
    list(APPEND SRC_TIME ${SRCROOT}/Time/Unix/DateImpl.cpp)
    list(APPEND SRC_TIME ${SRCROOT}/Time/Unix/DateImpl.hpp)
endif()

add_library(bull-core ${LIB_TYPE} ${SRC} ${SRC_FILESYSTEM} ${SRC_IO} ${SRC_PATTERN} ${SRC_SYSTEM} ${SRC_THREAD} ${SRC_TIME})

if(BULL_OS_UNIX)
    target_link_libraries(bull-core pthread)
endif()
