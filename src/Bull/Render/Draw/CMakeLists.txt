set(BULL_INC_RENDER_DRAW ${BULL_INC_RENDER}/Draw)
set(BULL_SRC_RENDER_DRAW ${BULL_SRC_RENDER}/Draw)

target_sources(bull-render
        PUBLIC
            ${BULL_INC_RENDER_DRAW}/Drawer.hpp
            ${BULL_SRC_RENDER_DRAW}/Drawer.cpp
            ${BULL_INC_RENDER_DRAW}/RenderPrimitive.hpp
        )