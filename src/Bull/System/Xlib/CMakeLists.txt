target_sources(bull-system
        PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}/CursorImplXlib.hpp
            ${CMAKE_CURRENT_SOURCE_DIR}/CursorImplXlib.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/KeyboardImpl.hpp
            ${CMAKE_CURRENT_SOURCE_DIR}/KeyboardImpl.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/MouseImpl.hpp
            ${CMAKE_CURRENT_SOURCE_DIR}/MouseImpl.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/VideoModeImpl.hpp
            ${CMAKE_CURRENT_SOURCE_DIR}/VideoModeImpl.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/WindowImplXlib.hpp
            ${CMAKE_CURRENT_SOURCE_DIR}/WindowImplXlib.cpp
        )

