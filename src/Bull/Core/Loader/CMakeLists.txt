set(BULL_INC_CORE_LOADER ${BULL_INC_CORE}/Loader)
set(BULL_SRC_CORE_LOADER ${BULL_SRC_CORE}/Loader)

target_sources(bull-core
            PUBLIC
                ${BULL_INC_CORE_LOADER}/AbstractResourceLoader.hpp
                ${BULL_INC_CORE_LOADER}/AbstractResourceSaver.hpp
                ${BULL_INC_CORE_LOADER}/FailedToLoad.hpp
                ${BULL_INC_CORE_LOADER}/FailedToLoad.inl
                ${BULL_INC_CORE_LOADER}/ResourceManager.hpp
                ${BULL_INC_CORE_LOADER}/ResourceManager.inl
        )