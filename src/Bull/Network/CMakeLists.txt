add_library(bull-network SHARED "")

target_sources(bull-network
        PUBLIC
            ${CMAKE_CURRENT_SOURCE_DIR}/IpAddress.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/Socket.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/TcpListenner.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/TcpSocket.cpp
        PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}/IpAddressImpl.hpp
            ${CMAKE_CURRENT_SOURCE_DIR}/SocketImpl.hpp
        )

if(BULL_OS_WINDOWS)
    add_subdirectory(Win32)
else()
    add_subdirectory(Unix)
endif()