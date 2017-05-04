bull_add_library(bull-render)

target_sources(bull-render
        PUBLIC
            ${CMAKE_CURRENT_SOURCE_DIR}/HardwareBuffer.cpp
        )

add_subdirectory(Context)
add_subdirectory(Shader)
add_subdirectory(Target)
add_subdirectory(Texture)

if(BULL_OS_WINDOWS)
    target_link_libraries(bull-render opengl32 gdi32)
else()
    target_link_libraries(bull-render GL)
endif()

target_link_libraries(bull-render bull-core)
target_link_libraries(bull-render bull-hardware)
target_link_libraries(bull-render bull-window)