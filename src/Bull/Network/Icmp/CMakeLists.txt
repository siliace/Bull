set(BULL_INC_NETWORK_ICMP ${BULL_INC_NETWORK}/Icmp)
set(BULL_SRC_NETWORK_ICMP ${BULL_SRC_NETWORK}/Icmp)

target_sources(bull-network
        PUBLIC
            ${BULL_INC_NETWORK_ICMP}/Icmp.hpp
            ${BULL_SRC_NETWORK_ICMP}/Icmp.cpp
        PUBLIC
            ${BULL_SRC_NETWORK_ICMP}/IcmpImpl.hpp
        )

if(BULL_OS_WINDOWS)
    add_subdirectory(Win32)
else()
    add_subdirectory(Unix)
endif()