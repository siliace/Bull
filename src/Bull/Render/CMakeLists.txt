set(RENDER_INC ${BULL_INCLUDE}/Render)
set(RENDER_SRC ${BULL_SRC}/Render)

#Headers
file(GLOB_RECURSE RENDER_INCLUDE_FILES ${RENDER_INC}/*.hpp)

#Source
file(GLOB RENDER_SOURCE_FILES ${RENDER_SRC}/*.*)

#File System
file(GLOB RENDER_WINDOW_SOURCE_FILES ${RENDER_SRC}/Context/*.*)
if(BULL_OS_WINDOWS)
    file(GLOB RENDER_WINDOW_IMPL_SOURCE_FILES ${RENDER_SRC}/Context/Wgl/*)
else()
    file(GLOB RENDER_WINDOW_IMPL_SOURCE_FILES ${RENDER_SRC}/Context/Glx/*)
endif()
list(APPEND RENDER_WINDOW_SOURCE_FILES ${RENDER_WINDOW_IMPL_SOURCE_FILES})

list(APPEND RENDER_SOURCE_FILES ${RENDER_WINDOW_SOURCE_FILES})

if(BULL_OS_WINDOWS)
    list(APPEND RENDER_EXT_LIBS gdi32)
elseif(BULL_OS_GNU_LINUX)
    list(APPEND RENDER_EXT_LIBS X11)
    list(APPEND RENDER_EXT_LIBS Xrandr)
    list(APPEND RENDER_EXT_LIBS GL)
endif()

add_library(bull-render SHARED ${RENDER_INCLUDE_FILES} ${RENDER_SOURCE_FILES})
target_link_libraries(bull-render bull-core)
target_link_libraries(bull-render bull-utility)
target_link_libraries(bull-render ${RENDER_EXT_LIBS})