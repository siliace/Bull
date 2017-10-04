set(BULL_INC_CORE_IMAGE ${BULL_INC_CORE}/Image)
set(BULL_SRC_CORE_IMAGE ${BULL_SRC_CORE}/Image)

target_sources(bull-core
        PUBLIC
            ${BULL_INC_CORE_IMAGE}/AbstractImageLoader.hpp
            ${BULL_INC_CORE_IMAGE}/AbstractImageSaver.hpp
            ${BULL_INC_CORE_IMAGE}/Image.hpp
            ${BULL_SRC_CORE_IMAGE}/Image.cpp
            ${BULL_INC_CORE_IMAGE}/ImageFormat.hpp
            ${BULL_INC_CORE_IMAGE}/ImageParameterBag.hpp
            ${BULL_SRC_CORE_IMAGE}/ImageParameterBag.cpp
        PRIVATE
            ${BULL_SRC_CORE_IMAGE}/STBLoader.cpp
            ${BULL_SRC_CORE_IMAGE}/STBLoader.cpp
            ${BULL_SRC_CORE_IMAGE}/STBSaver.cpp
            ${BULL_SRC_CORE_IMAGE}/STBSaver.cpp
        )