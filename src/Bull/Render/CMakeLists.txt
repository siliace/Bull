set(BULL_INC_RENDER ${BULL_INC}/Render)
set(BULL_SRC_RENDER ${BULL_SRC}/Render)

bull_add_library(bull-render)

target_sources(bull-render
        PUBLIC
            ${BULL_INC_RENDER}/Export.hpp
        )

add_subdirectory(Buffer)
add_subdirectory(Context)
add_subdirectory(Draw)
add_subdirectory(Shader)
add_subdirectory(Target)
add_subdirectory(Texture)
add_subdirectory(Vertex)

if(BULL_OS_WINDOWS)
    target_link_libraries(bull-render opengl32 gdi32)
else()
    target_link_libraries(bull-render GL)
endif()

target_link_libraries(bull-render bull-core)