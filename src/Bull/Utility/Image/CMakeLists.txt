set(BULL_INC_UTILITY_IMAGE ${BULL_INC_UTILITY}/Image)
set(BULL_SRC_UTILITY_IMAGE ${BULL_SRC_UTILITY}/Image)

target_sources(bull-utility
        PUBLIC
            ${BULL_INC_UTILITY_IMAGE}/AbstractImageLoader.hpp
            ${BULL_INC_UTILITY_IMAGE}/Image.hpp
            ${BULL_SRC_UTILITY_IMAGE}/Image.cpp
            ${BULL_INC_UTILITY_IMAGE}/ImageFormat.hpp
        PRIVATE
            ${BULL_SRC_UTILITY_IMAGE}/ImageLoader.cpp
            ${BULL_SRC_UTILITY_IMAGE}/ImageLoader.hpp
        )
