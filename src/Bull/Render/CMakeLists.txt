set(RENDER_INC ${BULL_INCLUDE}/Render)
set(RENDER_SRC ${BULL_SRC}/Render)

#Headers
file(GLOB_RECURSE RENDER_INCLUDE_FILES ${RENDER_INC}/*.hpp)

#Source
file(GLOB RENDER_SOURCE_FILES ${RENDER_SRC}/*.*)
file(GLOB RENDER_CONTEXT_SOURCE_FILES ${RENDER_SRC}/Context/*.*)

list(APPEND RENDER_SOURCE_FILES ${RENDER_CONTEXT_SOURCE_FILES})

add_library(bull-render SHARED ${RENDER_INCLUDE_FILES} ${RENDER_SOURCE_FILES})
target_link_libraries(bull-render bull-core)
target_link_libraries(bull-render bull-utility)
target_link_libraries(bull-render bull-window)
target_link_libraries(bull-render ${RENDER_EXT_LIBS})