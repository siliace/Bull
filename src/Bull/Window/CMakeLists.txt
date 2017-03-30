set(WINDOW_INC ${BULL_INCLUDE}/Window)
set(WINDOW_SRC ${BULL_SRC}/Window)

#Headers
file(GLOB_RECURSE WINDOW_INCLUDE_FILES ${WINDOW_INC}/*.hpp)

#Source
file(GLOB WINDOW_SOURCE_FILES ${WINDOW_SRC}/*.*)
if(BULL_OS_WINDOWS)
    file(GLOB WINDOW_IMPL_SOURCE_FILES ${WINDOW_SRC}/Win32/*)
else()
    file(GLOB WINDOW_IMPL_SOURCE_FILES ${WINDOW_SRC}/X11/*)
endif()
list(APPEND WINDOW_SOURCE_FILES ${WINDOW_IMPL_SOURCE_FILES})

if(BULL_OS_GNU_LINUX)
    list(APPEND UTILITY_EXT_LIBS GL)
    list(APPEND UTILITY_EXT_LIBS X11)
    list(APPEND UTILITY_EXT_LIBS Xrandr)
endif()

add_library(bull-window SHARED ${WINDOW_INCLUDE_FILES} ${WINDOW_SOURCE_FILES})
target_link_libraries(bull-window bull-core)
target_link_libraries(bull-window bull-hardware)
target_link_libraries(bull-window ${UTILITY_EXT_LIBS})