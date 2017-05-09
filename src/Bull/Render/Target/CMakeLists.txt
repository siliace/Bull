target_sources(bull-render
        PUBLIC
            ${CMAKE_CURRENT_SOURCE_DIR}/RenderTarget.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/RenderTexture.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/RenderWindow.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/Viewport.cpp
        PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}/RenderTextureImpl.hpp
            ${CMAKE_CURRENT_SOURCE_DIR}/RenderTextureImplDefault.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/RenderTextureImplDefault.hpp
            ${CMAKE_CURRENT_SOURCE_DIR}/RenderWindowImpl.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/RenderWindowImpl.hpp
        )

if(BULL_OS_WINDOWS)
    add_subdirectory(Win32)
else()
    if(WINDOW_LIBRARY STREQUAL "BULL_BUILD_XLIB")
        add_subdirectory(Xlib)
    elseif(WINDOW_LIBRARY STREQUAL "BULL_BUILD_XCB")
        add_subdirectory(XCB)
    elseif(WINDOW_LIBRARY STREQUAL "BULL_BUILD_WEYLAND")
        add_subdirectory(Weyland)
    endif()
endif()