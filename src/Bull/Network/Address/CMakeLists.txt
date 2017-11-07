set(BULL_INC_NETWORK_ADDRESS ${BULL_INC_NETWORK}/Address)
set(BULL_SRC_NETWORK_ADDRESS ${BULL_SRC_NETWORK}/Address)

target_sources(bull-network
        PUBLIC
            ${BULL_INC_NETWORK_ADDRESS}/IpAddress.hpp
            ${BULL_INC_NETWORK_ADDRESS}/IpAddressV4.hpp
            ${BULL_SRC_NETWORK_ADDRESS}/IpAddressV4.cpp
            ${BULL_INC_NETWORK_ADDRESS}/IpAddressV6.hpp
            ${BULL_SRC_NETWORK_ADDRESS}/IpAddressV6.cpp
            ${BULL_INC_NETWORK_ADDRESS}/IpAddressWrapper.hpp
            ${BULL_SRC_NETWORK_ADDRESS}/IpAddressWrapper.cpp
            ${BULL_INC_NETWORK_ADDRESS}/NetPort.hpp
            ${BULL_INC_NETWORK_ADDRESS}/NetProtocol.hpp
        PRIVATE
            ${BULL_SRC_NETWORK_ADDRESS}/IpAddressImpl.hpp
            ${BULL_SRC_NETWORK_ADDRESS}/SockAddrBuffer.hpp
            ${BULL_SRC_NETWORK_ADDRESS}/SockAddrBuffer.cpp
        )

if(BULL_OS_WINDOWS)
    add_subdirectory(Win32)
endif()