target_sources(bull-window
        PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}/Display.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/Display.hpp
            ${CMAKE_CURRENT_SOURCE_DIR}/ErrorHandler.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/ErrorHandler.hpp
            ${CMAKE_CURRENT_SOURCE_DIR}/VideoModeImpl.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/VideoModeImpl.hpp
            ${CMAKE_CURRENT_SOURCE_DIR}/WindowImplX11.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/WindowImplX11.hpp
        )

