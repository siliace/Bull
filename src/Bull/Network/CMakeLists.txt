bull_add_library(bull-network)

target_sources(bull-network
        PUBLIC
            ${CMAKE_CURRENT_SOURCE_DIR}/IpAddress.cpp
        )

if(BULL_OS_WINDOWS)
    add_subdirectory(Win32)
endif()

target_link_libraries(bull-network bull-core)
