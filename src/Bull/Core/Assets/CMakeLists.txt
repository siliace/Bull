set(BULL_INC_CORE_ASSETS ${BULL_INC_CORE}/Assets)
set(BULL_SRC_CORE_ASSETS ${BULL_SRC_CORE}/Assets)

target_sources(bull-core
        PUBLIC
        ${BULL_INC_CORE_ASSETS}/AssetLoader.hpp
        ${BULL_INC_CORE_ASSETS}/AssetManager.hpp
        )