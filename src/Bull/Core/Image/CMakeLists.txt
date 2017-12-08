set(BULL_INC_CORE_IMAGE ${BULL_INC_CORE}/Image)
set(BULL_SRC_CORE_IMAGE ${BULL_SRC_CORE}/Image)

target_sources(bull-core
        PUBLIC
            ${BULL_INC_CORE_IMAGE}/AbstractImage.hpp
            ${BULL_INC_CORE_IMAGE}/Image.hpp
            ${BULL_SRC_CORE_IMAGE}/Image.cpp
            ${BULL_INC_CORE_IMAGE}/ImageFormat.hpp
            ${BULL_INC_CORE_IMAGE}/ImageLoader.hpp
            ${BULL_SRC_CORE_IMAGE}/ImageLoader.cpp
            ${BULL_INC_CORE_IMAGE}/PixelDataType.hpp
            ${BULL_INC_CORE_IMAGE}/PixelFormat.hpp
            ${BULL_SRC_CORE_IMAGE}/PixelFormat.cpp
            ${BULL_INC_CORE_IMAGE}/PixelFormatType.hpp
        )