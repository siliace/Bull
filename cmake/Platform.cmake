if(${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
    set(BULL_OS_WINDOWS 1)

    include(CheckTypeSize)
    check_type_size(void* SIZEOF_VOID_PTR)
    if(${SIZEOF_VOID_PTR} STREQUAL "4")
        set(ARCH_32BITS 1)
    elseif(${SIZEOF_VOID_PTR} STREQUAL "8")
        set(ARCH_64BITS 1)
    else()
        message(FATAL_ERROR "Unsupported architecture")
        return()
    endif()
elseif(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
    set(BULL_OS_UNIX 1)
    set(BULL_OS_GNU_LINUX 1)
else()
    message(FATAL_ERROR "Unsupported operating system or environment")
    return()
endif()