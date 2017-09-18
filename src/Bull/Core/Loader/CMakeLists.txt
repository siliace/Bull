set(BULL_INC_CORE_LOADER ${BULL_INC_CORE}/Loader)
set(BULL_SRC_CORE_LOADER ${BULL_SRC_CORE}/Loader)

target_sources(bull-core
            PUBLIC
                ${BULL_INC_CORE_LOADER}/AbstractResourceLoader.hpp
                ${BULL_INC_CORE_LOADER}/AbstractResourceSaver.hpp
                ${BULL_INC_CORE_LOADER}/ParameterBag.hpp
                ${BULL_SRC_CORE_LOADER}/ParameterBag.cpp
                ${BULL_INC_CORE_LOADER}/ParameterNotFound.hpp
                ${BULL_SRC_CORE_LOADER}/ParameterNotFound.cpp
                ${BULL_INC_CORE_LOADER}/Resource.hpp
                ${BULL_INC_CORE_LOADER}/Resource.inl
        )