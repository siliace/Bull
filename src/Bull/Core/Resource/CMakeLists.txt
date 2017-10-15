set(BULL_INC_CORE_RESOURCE ${BULL_INC_CORE}/Resource)
set(BULL_SRC_CORE_RESOURCE ${BULL_SRC_CORE}/Resource)

target_sources(bull-core
        PUBLIC
            ${BULL_INC_CORE_RESOURCE}/AbstractResourceLoader.hpp
            ${BULL_INC_CORE_RESOURCE}/AbstractResourceSaver.hpp
            ${BULL_SRC_CORE_RESOURCE}/Parameter.cpp
            ${BULL_INC_CORE_RESOURCE}/ParameterBag.hpp
            ${BULL_SRC_CORE_RESOURCE}/ParameterBag.cpp
            ${BULL_INC_CORE_RESOURCE}/Registrar.hpp
            ${BULL_INC_CORE_RESOURCE}/Resource.hpp
            ${BULL_INC_CORE_RESOURCE}/ResourceLoader.hpp
            ${BULL_INC_CORE_RESOURCE}/ResourceLoader.inl
            ${BULL_INC_CORE_RESOURCE}/ResourceSaver.hpp
            ${BULL_INC_CORE_RESOURCE}/ResourceSaver.inl
        )