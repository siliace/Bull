set(BULL_INC_NETWORK ${BULL_INC}/Network)
set(BULL_SRC_NETWORK ${BULL_SRC}/Network)

bull_add_library(bull-network)

target_sources(bull-network
        PUBLIC
            ${BULL_INC_NETWORK}/Export.hpp
            ${BULL_INC_NETWORK}/Icmp.hpp
            ${BULL_SRC_NETWORK}/Icmp.cpp
            ${BULL_INC_NETWORK}/IpAddress.hpp
            ${BULL_SRC_NETWORK}/IpAddress.cpp
            ${BULL_INC_NETWORK}/Socket.hpp
            ${BULL_SRC_NETWORK}/Socket.cpp
            ${BULL_INC_NETWORK}/SocketHandler.hpp
            ${BULL_INC_NETWORK}/TcpListener.hpp
            ${BULL_SRC_NETWORK}/TcpListener.cpp
            ${BULL_INC_NETWORK}/TcpSocket.hpp
            ${BULL_SRC_NETWORK}/TcpSocket.cpp
            ${BULL_INC_NETWORK}/UdpSocket.hpp
            ${BULL_SRC_NETWORK}/UdpSocket.cpp
        PRIVATE
            ${BULL_SRC_NETWORK}/IcmpImpl.hpp
            ${BULL_SRC_NETWORK}/IpAddressImpl.hpp
            ${BULL_SRC_NETWORK}/SocketImpl.hpp
        )

if(BULL_OS_WINDOWS)
    add_subdirectory(Win32)
    target_link_libraries(bull-network icmp)
    target_link_libraries(bull-network ws2_32)
    target_link_libraries(bull-network iphlpapi)
else()
    add_subdirectory(Unix)
endif()

target_link_libraries(bull-network bull-core)
target_link_libraries(bull-network bull-utility)
