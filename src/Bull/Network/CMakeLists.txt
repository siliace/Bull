set(NETWORK_INC ${BULL_INCLUDE}/Network)
set(NETWORK_SRC ${BULL_SRC}/Network)

#Headers
file(GLOB_RECURSE NETWORK_INCLUDE_FILES ${NETWORK_INC}/*.hpp)

#Source
file(GLOB NETWORK_SOURCE_FILES ${NETWORK_SRC}/*.*)
if(BULL_OS_WINDOWS)
    file(GLOB NETWORK_IMPL_SOURCE_FILES ${NETWORK_SRC}/Win32/*)
else()
    file(GLOB NETWORK_IMPL_SOURCE_FILES ${NETWORK_SRC}/Unix/*)
endif()
list(APPEND NETWORK_SOURCE_FILES ${NETWORK_IMPL_SOURCE_FILES})

if(BULL_OS_WINDOW)
    list(APPED NETWORK_EXT_LIBS ws2_32)
endif()

add_library(bull-network SHARED ${NETWORK_INCLUDE_FILES} ${NETWORK_SOURCE_FILES})
target_link_libraries(bull-network bull-core)
target_link_libraries(bull-network ${NETWORK_EXT_LIBS})