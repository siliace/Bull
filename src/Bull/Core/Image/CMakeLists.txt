set(BULL_INC_CORE_IMAGE ${BULL_INC_CORE}/Image)
set(BULL_SRC_CORE_IMAGE ${BULL_SRC_CORE}/Image)

target_sources(bull-core
        PUBLIC
        ${BULL_INC_CORE_IMAGE}/AbstractImage.hpp
        ${BULL_INC_CORE_IMAGE}/AbstractImageLoader.hpp
        ${BULL_SRC_CORE_IMAGE}/AbstractImageLoader.cpp
        ${BULL_INC_CORE_IMAGE}/AbstractImageSaver.hpp
        ${BULL_SRC_CORE_IMAGE}/AbstractImageSaver.cpp
        ${BULL_INC_CORE_IMAGE}/Image.hpp
        ${BULL_SRC_CORE_IMAGE}/Image.cpp
        ${BULL_INC_CORE_IMAGE}/ImageFormat.hpp
        ${BULL_INC_CORE_IMAGE}/ImageLoader.hpp
        ${BULL_INC_CORE_IMAGE}/PixelFormat.hpp
        ${BULL_INC_CORE_IMAGE}/PixelFormatUtils.hpp
        ${BULL_SRC_CORE_IMAGE}/PixelFormatUtils.cpp
        )