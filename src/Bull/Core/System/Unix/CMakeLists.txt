target_sources(bull-core
        PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}/LibraryImplUnix.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/LibraryImplUnix.hpp
        )

add_definitions(-ldl)