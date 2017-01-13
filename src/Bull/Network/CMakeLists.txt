set (INC_ROOT ${PROJECT_SOURCE_DIR}/include/Bull/Network)
set (SRC_ROOT ${PROJECT_SOURCE_DIR}/src/Bull/Network)

########################################################################################################################
# Network files                                                                                                        #
########################################################################################################################

set(SRC ${SRC_ROOT}/IpAddress.cpp
        ${INC_ROOT}/IpAddress.hpp
        ${SRC_ROOT}/IpAddressImpl.hpp
        ${SRC_ROOT}/Socket.cpp
        ${INC_ROOT}/Socket.hpp
        ${SRC_ROOT}/SocketImpl.hpp
        ${SRC_ROOT}/TcpListenner.cpp
        ${INC_ROOT}/TcpListenner.hpp
        ${SRC_ROOT}/TcpSocket.cpp
        ${INC_ROOT}/TcpSocket.hpp)

if(BULL_OS_WINDOWS)
    list(APPEND SRC ${SRC_ROOT}/Win32/SocketImpl.cpp)
    list(APPEND SRC ${SRC_ROOT}/Win32/SocketImpl.hpp)
    list(APPEND SRC ${SRC_ROOT}/Win32/IpAddressImpl.cpp)
    list(APPEND SRC ${SRC_ROOT}/Win32/IpAddressImpl.hpp)
    list(APPEND SRC ${SRC_ROOT}/Win32/SystemSocket.hpp)
else()
    list(APPEND SRC ${SRC_ROOT}/Unix/SocketImpl.cpp)
    list(APPEND SRC ${SRC_ROOT}/Unix/SocketImpl.hpp)
    list(APPEND SRC ${SRC_ROOT}/Unix/IpAddressImpl.cpp)
    list(APPEND SRC ${SRC_ROOT}/Unix/IpAddressImpl.hpp)
    list(APPEND SRC ${SRC_ROOT}/Unix/SystemSocket.hpp)
endif()

source_group("" FILES ${SRC})

set(EXTERNAL_LIBS)

if(BULL_OS_WINDOWS)
    list(APPEND EXTERNAL_LIBS ws2_32)
endif()

bull_add_library(bull-network SOURCES ${SRC}
                              DEPENDS bull-core
                              EXTERNALS ${EXTERNAL_LIBS})