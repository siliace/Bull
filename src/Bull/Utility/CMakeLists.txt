add_library(bull-utility SHARED "")

target_sources(bull-utility
        PUBLIC
            ${CMAKE_CURRENT_SOURCE_DIR}/CallOnExit.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/Color.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/Font.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/Glyph.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/Image.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/Random.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/Vertex.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/VertexArray.cpp
        PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}/FontLoader.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/FontLoader.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/ImageLoader.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/ImageLoader.hpp
        )

add_subdirectory(Logger)
add_subdirectory(TransformationPipeline)

target_link_libraries(bull-utility freetype)
target_link_libraries(bull-utility stb)

target_link_libraries(bull-utility bull-core)