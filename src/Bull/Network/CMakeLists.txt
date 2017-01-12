set (INCROOT ${PROJECT_SOURCE_DIR}/include/Bull/Network)
set (SRCROOT ${PROJECT_SOURCE_DIR}/src/Bull/Network)

set(SRC ${SRCROOT}/IpAddress.cpp
        ${INCROOT}/IpAddress.hpp
        ${SRCROOT}/IpAddressImpl.hpp
        ${SRCROOT}/Socket.cpp
        ${INCROOT}/Socket.hpp
        ${SRCROOT}/SocketImpl.hpp
        ${SRCROOT}/TcpListenner.cpp
        ${INCROOT}/TcpListenner.hpp
        ${SRCROOT}/TcpSocket.cpp
        ${INCROOT}/TcpSocket.hpp)

if(BULL_OS_WINDOWS)
    list(APPEND SRC ${SRCROOT}/Win32/SocketImpl.cpp)
    list(APPEND SRC ${SRCROOT}/Win32/SocketImpl.hpp)
    list(APPEND SRC ${SRCROOT}/Win32/IpAddressImpl.cpp)
    list(APPEND SRC ${SRCROOT}/Win32/IpAddressImpl.hpp)
    list(APPEND SRC ${SRCROOT}/Win32/SystemSocket.hpp)
else()
    list(APPEND SRC ${SRCROOT}/Unix/SocketImpl.cpp)
    list(APPEND SRC ${SRCROOT}/Unix/SocketImpl.hpp)
    list(APPEND SRC ${SRCROOT}/Unix/IpAddressImpl.cpp)
    list(APPEND SRC ${SRCROOT}/Unix/IpAddressImpl.hpp)
    list(APPEND SRC ${SRCROOT}/Unix/SystemSocket.hpp)
endif()

add_library(bull-network ${LIB_TYPE} ${SRC})

if(BULL_OS_WINDOWS)
    target_link_libraries(bull-network ws2_32)
endif()

target_link_libraries(bull-network bull-core)