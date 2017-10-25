set(BULL_INC_GRAPHICS ${BULL_INC}/Graphics)
set(BULL_SRC_GRAPHICS ${BULL_SRC}/Graphics)

bull_add_library(bull-graphics)

target_sources(bull-graphics
        PUBLIC
            ${BULL_INC_GRAPHICS}/AbstractViewer.hpp
            ${BULL_INC_GRAPHICS}/Export.hpp
            ${BULL_INC_GRAPHICS}/Material.hpp
            ${BULL_SRC_GRAPHICS}/Material.cpp
            ${BULL_INC_GRAPHICS}/MaterialTextureType.hpp
            ${BULL_INC_GRAPHICS}/Node.hpp
            ${BULL_SRC_GRAPHICS}/Node.cpp
        )

target_link_libraries(bull-graphics bull-core)
target_link_libraries(bull-graphics bull-render)