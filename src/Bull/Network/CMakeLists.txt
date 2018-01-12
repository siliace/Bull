set(BULL_INC_NETWORK ${BULL_INC}/Network)
set(BULL_SRC_NETWORK ${BULL_SRC}/Network)

bull_add_library(bull-network)

target_sources(bull-network
        PUBLIC
            ${BULL_INC_NETWORK}/Export.hpp
        )

add_subdirectory(Address)
add_subdirectory(Icmp)
add_subdirectory(Socket)

if(BULL_OS_WINDOWS)
    target_link_libraries(bull-network ws2_32)
    target_link_libraries(bull-network iphlpapi)
endif()

target_link_libraries(bull-network bull-core)