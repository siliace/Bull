set(BULL_INC_RENDER_TARGET ${BULL_INC_RENDER}/Target)
set(BULL_SRC_RENDER_TARGET ${BULL_SRC_RENDER}/Target)

target_sources(bull-render
        PUBLIC
            ${BULL_INC_RENDER_TARGET}/RenderTarget.hpp
            ${BULL_SRC_RENDER_TARGET}/RenderTarget.cpp
            ${BULL_INC_RENDER_TARGET}/RenderWindow.hpp
            ${BULL_SRC_RENDER_TARGET}/RenderWindow.cpp
            ${BULL_INC_RENDER_TARGET}/Viewport.hpp
            ${BULL_SRC_RENDER_TARGET}/Viewport.cpp
        PRIVATE
            ${BULL_SRC_RENDER_TARGET}/RenderWindowImpl.cpp
            ${BULL_SRC_RENDER_TARGET}/RenderWindowImpl.hpp
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