target_sources(bull-core
        PUBLIC
            ${CMAKE_CURRENT_SOURCE_DIR}/Exception.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/InvalidArgument.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/LogicError.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/OutOfRange.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/RuntimeError.cpp
        )