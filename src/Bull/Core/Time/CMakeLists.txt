target_sources(bull-core
        PUBLIC
            ${CMAKE_CURRENT_SOURCE_DIR}/Clock.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/Date.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/Time.cpp
        PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}/ClockImpl.hpp
            ${CMAKE_CURRENT_SOURCE_DIR}/DateImpl.hpp
        )

if(BULL_OS_WINDOWS)
    add_subdirectory(Win32)
else()
    add_subdirectory(Unix)
endif()