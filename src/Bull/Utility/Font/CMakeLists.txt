target_sources(bull-utility
        PUBLIC
            ${CMAKE_CURRENT_SOURCE_DIR}/Font.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/Glyph.cpp
        PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}/FontLoader.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/FontLoader.hpp
        )