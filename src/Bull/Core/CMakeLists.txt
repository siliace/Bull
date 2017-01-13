set (INC_ROOT ${PROJECT_SOURCE_DIR}/include/Bull/Core)
set (SRC_ROOT ${PROJECT_SOURCE_DIR}/src/Bull/Core)

########################################################################################################################
# Core files                                                                                                           #
########################################################################################################################
set(SRC ${INC_ROOT}/AbstractLogger.hpp
        ${SRC_ROOT}/Exception.cpp
        ${INC_ROOT}/Exception.hpp
        ${INC_ROOT}/Functor.hpp
        ${INC_ROOT}/Functor/AbstractFunctor.hpp
        ${INC_ROOT}/Functor/FunctorMethodConstWithArgs.hpp
        ${INC_ROOT}/Functor/FunctorMethodConstWithoutArgs.hpp
        ${INC_ROOT}/Functor/FunctorMethodWithArgs.hpp
        ${INC_ROOT}/Functor/FunctorMethodWithoutArgs.hpp
        ${INC_ROOT}/Functor/FunctorWithArgs.hpp
        ${INC_ROOT}/Functor/FunctorWithoutArgs.hpp
        ${INC_ROOT}/Integer.hpp
        ${SRC_ROOT}/Log.cpp
        ${INC_ROOT}/Log.hpp
        ${SRC_ROOT}/String.cpp
        ${INC_ROOT}/String.hpp
        ${INC_ROOT}/Macro.hpp)

source_group("" FILES ${SRC})

########################################################################################################################
# Core/FileSystem files                                                                                                #
########################################################################################################################

set(SRC_FILESYSTEM ${SRC_ROOT}/FileSystem/Directory.cpp
                   ${INC_ROOT}/FileSystem/Directory.hpp
                   ${SRC_ROOT}/FileSystem/DirectoryImpl.cpp
                   ${SRC_ROOT}/FileSystem/DirectoryImpl.hpp
                   ${SRC_ROOT}/FileSystem/File.cpp
                   ${INC_ROOT}/FileSystem/File.hpp
                   ${SRC_ROOT}/FileSystem/FileImpl.cpp
                   ${SRC_ROOT}/FileSystem/FileImpl.hpp
                   ${INC_ROOT}/FileSystem/Path.hpp)

if(BULL_OS_WINDOWS)
    list(APPEND SRC_FILESYSTEM ${SRC_ROOT}/FileSystem/Win32/DirectoryImplWin32.cpp)
    list(APPEND SRC_FILESYSTEM ${SRC_ROOT}/FileSystem/Win32/DirectoryImplWin32.hpp)
    list(APPEND SRC_FILESYSTEM ${SRC_ROOT}/FileSystem/Win32/FileImplWin32.cpp)
    list(APPEND SRC_FILESYSTEM ${SRC_ROOT}/FileSystem/Win32/FileImplWin32.hpp)
else()
    list(APPEND SRC_FILESYSTEM ${SRC_ROOT}/FileSystem/Unix/DirectoryImplUnix.cpp)
    list(APPEND SRC_FILESYSTEM ${SRC_ROOT}/FileSystem/Unix/DirectoryImplUnix.hpp)
    list(APPEND SRC_FILESYSTEM ${SRC_ROOT}/FileSystem/Unix/FileImplUnix.cpp)
    list(APPEND SRC_FILESYSTEM ${SRC_ROOT}/FileSystem/Unix/FileImplUnix.hpp)
endif()

source_group("filesystem" FILES ${SRC_FILESYSTEM})

########################################################################################################################
# Core/IO files                                                                                                        #
########################################################################################################################

set(SRC_IO ${INC_ROOT}/IO/InOutStream.hpp
           ${SRC_ROOT}/IO/InStream.cpp
           ${INC_ROOT}/IO/InStream.hpp
           ${INC_ROOT}/IO/OutStream.hpp
           ${SRC_ROOT}/IO/StringStream.cpp
           ${INC_ROOT}/IO/StringStream.hpp)

source_group("io" FILES ${SRC_IO})

########################################################################################################################
# Core/Pattern files                                                                                                   #
########################################################################################################################

set(SRC_PATTERN ${INC_ROOT}/Pattern/NonCopyable.hpp
                ${INC_ROOT}/Pattern/Singleton.hpp)

source_group("pattern" FILES ${SRC_PATTERN})

########################################################################################################################
# Core/System files                                                                                                    #
########################################################################################################################

set(SRC_SYSTEM ${INC_ROOT}/System/Config.hpp
               ${INC_ROOT}/System/Export.hpp
               ${SRC_ROOT}/System/Library.cpp
               ${INC_ROOT}/System/Library.hpp
               ${SRC_ROOT}/System/LibraryImpl.cpp
               ${SRC_ROOT}/System/LibraryImpl.hpp)

if(BULL_OS_WINDOWS)
    list(APPEND SRC_SYSTEM ${SRC_ROOT}/System/Win32/LibraryImplWin32.cpp)
    list(APPEND SRC_SYSTEM ${SRC_ROOT}/System/Win32/LibraryImplWin32.hpp)
else()
    list(APPEND SRC_SYSTEM ${SRC_ROOT}/System/Unix/LibraryImplUnix.cpp)
    list(APPEND SRC_SYSTEM ${SRC_ROOT}/System/Unix/LibraryImplUnix.hpp)
endif()

source_group("system" FILES ${SRC_SYSTEM})

########################################################################################################################
# Core/Thread files                                                                                                    #
########################################################################################################################

set(SRC_THREAD ${SRC_ROOT}/Thread/ConditionVariable.cpp
               ${INC_ROOT}/Thread/ConditionVariable.hpp
               ${SRC_ROOT}/Thread/ConditionVariableImpl.cpp
               ${SRC_ROOT}/Thread/ConditionVariableImpl.hpp
               ${SRC_ROOT}/Thread/Lock.cpp
               ${INC_ROOT}/Thread/Lock.hpp
               ${SRC_ROOT}/Thread/Mutex.cpp
               ${INC_ROOT}/Thread/Mutex.hpp
               ${SRC_ROOT}/Thread/MutexImpl.cpp
               ${SRC_ROOT}/Thread/MutexImpl.hpp
               ${SRC_ROOT}/Thread/Semaphore.cpp
               ${INC_ROOT}/Thread/Semaphore.hpp
               ${SRC_ROOT}/Thread/SemaphoreImpl.cpp
               ${SRC_ROOT}/Thread/SemaphoreImpl.hpp
               ${SRC_ROOT}/Thread/Thread.cpp
               ${INC_ROOT}/Thread/Thread.hpp
               ${SRC_ROOT}/Thread/ThreadImpl.cpp
               ${SRC_ROOT}/Thread/ThreadImpl.hpp)

if(BULL_OS_WINDOWS)
    list(APPEND SRC_THREAD ${SRC_ROOT}/Thread/Win32/ConditionVariableImplWin32.cpp)
    list(APPEND SRC_THREAD ${SRC_ROOT}/Thread/Win32/ConditionVariableImplWin32.hpp)
    list(APPEND SRC_THREAD ${SRC_ROOT}/Thread/Win32/MutexImplWin32.cpp)
    list(APPEND SRC_THREAD ${SRC_ROOT}/Thread/Win32/MutexImplWin32.hpp)
    list(APPEND SRC_THREAD ${SRC_ROOT}/Thread/Win32/SemaphoreImplWin32.cpp)
    list(APPEND SRC_THREAD ${SRC_ROOT}/Thread/Win32/SemaphoreImplWin32.hpp)
    list(APPEND SRC_THREAD ${SRC_ROOT}/Thread/Win32/ThreadImplWin32.cpp)
    list(APPEND SRC_THREAD ${SRC_ROOT}/Thread/Win32/ThreadImplWin32.hpp)
else()
    list(APPEND SRC_THREAD ${SRC_ROOT}/Thread/Unix/ConditionVariableImplUnix.cpp)
    list(APPEND SRC_THREAD ${SRC_ROOT}/Thread/Unix/ConditionVariableImplUnix.cpp)
    list(APPEND SRC_THREAD ${SRC_ROOT}/Thread/Unix/MutexImplUnix.cpp)
    list(APPEND SRC_THREAD ${SRC_ROOT}/Thread/Unix/MutexImplUnix.cpp)
    list(APPEND SRC_THREAD ${SRC_ROOT}/Thread/Unix/SemaphoreImplUnix.cpp)
    list(APPEND SRC_THREAD ${SRC_ROOT}/Thread/Unix/SemaphoreImplUnix.cpp)
    list(APPEND SRC_THREAD ${SRC_ROOT}/Thread/Unix/ThreadImplUnix.cpp)
    list(APPEND SRC_THREAD ${SRC_ROOT}/Thread/Unix/ThreadImplUnix.hpp)
endif()

########################################################################################################################
# Core/Time files                                                                                                      #
########################################################################################################################

set(SRC_TIME ${SRC_ROOT}/Time/Clock.cpp
             ${INC_ROOT}/Time/Clock.hpp
             ${SRC_ROOT}/Time/ClockImpl.hpp
             ${SRC_ROOT}/Time/Date.cpp
             ${INC_ROOT}/Time/Date.hpp
             ${SRC_ROOT}/Time/DateImpl.hpp
             ${SRC_ROOT}/Time/Time.cpp
             ${INC_ROOT}/Time/Time.hpp)

if(BULL_OS_WINDOWS)
    list(APPEND SRC_TIME ${SRC_ROOT}/Time/Win32/ClockImpl.cpp)
    list(APPEND SRC_TIME ${SRC_ROOT}/Time/Win32/ClockImpl.hpp)
    list(APPEND SRC_TIME ${SRC_ROOT}/Time/Win32/DateImpl.cpp)
    list(APPEND SRC_TIME ${SRC_ROOT}/Time/Win32/DateImpl.hpp)
else()
    list(APPEND SRC_TIME ${SRC_ROOT}/Time/Unix/ClockImpl.cpp)
    list(APPEND SRC_TIME ${SRC_ROOT}/Time/Unix/ClockImpl.hpp)
    list(APPEND SRC_TIME ${SRC_ROOT}/Time/Unix/DateImpl.cpp)
    list(APPEND SRC_TIME ${SRC_ROOT}/Time/Unix/DateImpl.hpp)
endif()

set(EXTERNAL_LIBS)

if(BULL_OS_LINUX)
    list(APPEND EXTERNAL_LIBS pthread)
endif()

bull_add_library(bull-core SOURCES ${SRC} ${SRC_FILESYSTEM} ${SRC_IO} ${SRC_PATTERN} ${SRC_SYSTEM} ${SRC_THREAD} ${SRC_TIME}
                           EXTERNALS ${EXTERNAL_LIBS})