set(UTILITY_INC ${BULL_INCLUDE}/Utility)
set(UTILITY_SRC ${BULL_SRC}/Utility)

#Headers
file(GLOB_RECURSE UTILITY_INCLUDE_FILES ${UTILITY_INC}/*.hpp)

#Source
file(GLOB UTILITY_SOURCE_FILES ${UTILITY_SRC}/*.*)

list(APPEND UTILITY_EXT_LIBS stb)
list(APPEND UTILITY_EXT_LIBS freetype)

add_library(bull-utility SHARED ${UTILITY_INCLUDE_FILES} ${UTILITY_SOURCE_FILES})

target_link_libraries(bull-utility bull-core)
target_link_libraries(bull-utility bull-hardware)
target_link_libraries(bull-utility ${UTILITY_EXT_LIBS})