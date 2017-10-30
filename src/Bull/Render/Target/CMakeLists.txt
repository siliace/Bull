set(BULL_INC_RENDER_TARGET ${BULL_INC_RENDER}/Target)
set(BULL_SRC_RENDER_TARGET ${BULL_SRC_RENDER}/Target)

target_sources(bull-render
        PUBLIC
            ${BULL_INC_RENDER_TARGET}/RenderTarget.hpp
            ${BULL_SRC_RENDER_TARGET}/RenderTarget.cpp
            ${BULL_INC_RENDER_TARGET}/RenderWindow.hpp
            ${BULL_SRC_RENDER_TARGET}/RenderWindow.cpp
            ${BULL_INC_RENDER_TARGET}/Viewport.hpp
            ${BULL_SRC_RENDER_TARGET}/Viewport.cpp
        )