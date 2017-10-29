set(BULL_INC_GRAPHICS_LIGHT ${BULL_INC_GRAPHICS}/Light)
set(BULL_SRC_GRAPHICS_LIGHT ${BULL_SRC_GRAPHICS}/Light)

target_sources(bull-graphics
        PUBLIC
            ${BULL_INC_GRAPHICS_LIGHT}/DirectionalLight.hpp
            ${BULL_SRC_GRAPHICS_LIGHT}/DirectionaLLight.cpp
            ${BULL_INC_GRAPHICS_LIGHT}/Light.hpp
            ${BULL_SRC_GRAPHICS_LIGHT}/Light.cpp
            ${BULL_INC_GRAPHICS_LIGHT}/LightType.hpp
            ${BULL_INC_GRAPHICS_LIGHT}/PointLight.hpp
            ${BULL_SRC_GRAPHICS_LIGHT}/PointLight.cpp
            ${BULL_INC_GRAPHICS_LIGHT}/SpotLight.hpp
            ${BULL_SRC_GRAPHICS_LIGHT}/SpotLight.cpp
        )