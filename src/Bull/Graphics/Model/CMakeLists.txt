set(BULL_INC_GRAPHICS_MODEL ${BULL_INC_GRAPHICS}/Model)
set(BULL_SRC_GRAPHICS_MODEL ${BULL_SRC_GRAPHICS}/Model)

target_sources(bull-graphics
        PUBLIC
        ${BULL_INC_GRAPHICS_MODEL}/Material.hpp
        ${BULL_SRC_GRAPHICS_MODEL}/Material.cpp
        ${BULL_INC_GRAPHICS_MODEL}/Mesh.hpp
        ${BULL_SRC_GRAPHICS_MODEL}/Mesh.cpp
        ${BULL_INC_GRAPHICS_MODEL}/Model.hpp
        ${BULL_SRC_GRAPHICS_MODEL}/Model.cpp
        ${BULL_INC_GRAPHICS_MODEL}/SubMesh.hpp
        ${BULL_SRC_GRAPHICS_MODEL}/SubMesh.cpp
        ${BULL_INC_GRAPHICS_MODEL}/TextureType.hpp
        )