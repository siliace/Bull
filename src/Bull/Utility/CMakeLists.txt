bull_add_library(bull-utility)

target_sources(bull-utility
        PUBLIC
            ${CMAKE_CURRENT_SOURCE_DIR}/CallOnExit.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/Color.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/Random.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/Vertex.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/VertexArray.cpp
        )

add_subdirectory(Image)
add_subdirectory(Logger)
add_subdirectory(TransformationPipeline)

target_link_libraries(bull-utility stb)

target_link_libraries(bull-utility bull-core)