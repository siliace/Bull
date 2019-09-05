set(BULL_INC_GRAPHICS_RENDERING ${BULL_INC_GRAPHICS}/Rendering)
set(BULL_SRC_GRAPHICS_RENDERING ${BULL_SRC_GRAPHICS}/Rendering)

target_sources(bull-graphics
        PUBLIC
        ${BULL_INC_GRAPHICS_RENDERING}/AbstractViewer.hpp
        ${BULL_INC_GRAPHICS_RENDERING}/Renderable.hpp
        ${BULL_INC_GRAPHICS_RENDERING}/InstancedRenderable.hpp
        ${BULL_INC_GRAPHICS_RENDERING}/Transformable.hpp
        ${BULL_SRC_GRAPHICS_RENDERING}/Transformable.cpp
        )