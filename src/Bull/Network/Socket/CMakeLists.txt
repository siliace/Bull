set(BULL_INC_NETWORK_SOCKET ${BULL_INC_NETWORK}/Socket)
set(BULL_SRC_NETWORK_SOCKET ${BULL_SRC_NETWORK}/Socket)

target_sources(bull-network
        PUBLIC
            ${BULL_INC_NETWORK_SOCKET}/Socket.hpp
            ${BULL_SRC_NETWORK_SOCKET}/Socket.cpp
            ${BULL_INC_NETWORK_SOCKET}/SocketHandler.hpp
            ${BULL_INC_NETWORK_SOCKET}/SocketType.hpp
            ${BULL_INC_NETWORK_SOCKET}/TcpClient.hpp
            ${BULL_SRC_NETWORK_SOCKET}/TcpClient.cpp
            ${BULL_INC_NETWORK_SOCKET}/TcpServer.hpp
            ${BULL_SRC_NETWORK_SOCKET}/TcpServer.cpp
            ${BULL_INC_NETWORK_SOCKET}/UdpSocket.hpp
        PRIVATE
            ${BULL_SRC_NETWORK_SOCKET}/SocketHeader.hpp
            ${BULL_SRC_NETWORK_SOCKET}/SocketImpl.hpp
            ${BULL_SRC_NETWORK_SOCKET}/SocketImpl.cpp
            ${BULL_SRC_NETWORK_SOCKET}/TcpClientImpl.hpp
            ${BULL_SRC_NETWORK_SOCKET}/TcpClientImpl.cpp
            ${BULL_SRC_NETWORK_SOCKET}/TcpServerImpl.hpp
            ${BULL_SRC_NETWORK_SOCKET}/TcpServerImpl.cpp
        )

if(BULL_OS_WINDOWS)
    add_subdirectory(Win32)
endif()