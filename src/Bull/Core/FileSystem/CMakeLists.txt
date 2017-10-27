set(BULL_INC_CORE_FILESYSTEM ${BULL_INC_CORE}/FileSystem)
set(BULL_SRC_CORE_FILESYSTEM ${BULL_SRC_CORE}/FileSystem)

target_sources(bull-core
        PUBLIC
            ${BULL_INC_CORE_FILESYSTEM}/Directory.hpp
            ${BULL_SRC_CORE_FILESYSTEM}/Directory.cpp
            ${BULL_INC_CORE_FILESYSTEM}/DirectorySearchFlag.hpp
            ${BULL_INC_CORE_FILESYSTEM}/File.hpp
            ${BULL_SRC_CORE_FILESYSTEM}/File.cpp
            ${BULL_INC_CORE_FILESYSTEM}/FileOpeningMode.hpp
            ${BULL_INC_CORE_FILESYSTEM}/FileSystem.hpp
            ${BULL_SRC_CORE_FILESYSTEM}/FileSystem.cpp
            ${BULL_INC_CORE_FILESYSTEM}/FileSystemInfo.hpp
            ${BULL_INC_CORE_FILESYSTEM}/InvalidPathException.hpp
            ${BULL_SRC_CORE_FILESYSTEM}/InvalidPathException.cpp
            ${BULL_INC_CORE_FILESYSTEM}/Path.hpp
            ${BULL_SRC_CORE_FILESYSTEM}/Path.cpp
        PRIVATE
            ${BULL_SRC_CORE_FILESYSTEM}/DirectoryImpl.hpp
            ${BULL_SRC_CORE_FILESYSTEM}/DirectoryImpl.cpp
            ${BULL_SRC_CORE_FILESYSTEM}/FileImpl.hpp
            ${BULL_SRC_CORE_FILESYSTEM}/FileImpl.cpp
            ${BULL_SRC_CORE_FILESYSTEM}/FileSystemImpl.hpp
            ${BULL_SRC_CORE_FILESYSTEM}/PathImpl.hpp
        )

if(BULL_OS_WINDOWS)
    add_subdirectory(Win32)
else()
    add_subdirectory(Unix)
endif()