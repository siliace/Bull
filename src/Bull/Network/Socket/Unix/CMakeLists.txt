target_sources(bull-network
        PUBLIC
            ${CMAKE_CURRENT_SOURCE_DIR}/SocketHeader.hpp
            ${CMAKE_CURRENT_SOURCE_DIR}/SocketImplUnix.hpp
            ${CMAKE_CURRENT_SOURCE_DIR}/SocketImplUnix.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/SocketPollerImplUnix.hpp
            ${CMAKE_CURRENT_SOURCE_DIR}/SocketPollerImplUnix.cpp
        )