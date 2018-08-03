set(BULL_INC_CORE_ASSETS ${BULL_INC_CORE}/Assets)
set(BULL_SRC_CORE_ASSETS ${BULL_SRC_CORE}/Assets)

target_sources(bull-core
        PUBLIC
            ${BULL_INC_CORE_ASSETS}/Asset.hpp
            ${BULL_INC_CORE_ASSETS}/AssetHandler.hpp
            ${BULL_INC_CORE_ASSETS}/AssetIOScheduler.hpp
            ${BULL_INC_CORE_ASSETS}/AssetManager.hpp
        )