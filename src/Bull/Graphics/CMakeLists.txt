set(BULL_INC_GRAPHICS ${BULL_INC}/Graphics)
set(BULL_SRC_GRAPHICS ${BULL_SRC}/Graphics)

bull_add_library(bull-graphics)

target_sources(bull-graphics
        PUBLIC
        ${BULL_INC_GRAPHICS}/Export.hpp
        )

add_subdirectory(Light)
add_subdirectory(Model)
add_subdirectory(Rendering)

target_link_libraries(bull-graphics bull-core)
target_link_libraries(bull-graphics bull-render)