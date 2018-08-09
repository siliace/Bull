set(BULL_INC_MATH ${BULL_INC}/Math)
set(BULL_SRC_MATH ${BULL_SRC}/Math)

add_library(bull-math INTERFACE)

target_sources(bull-math
        INTERFACE
            ${BULL_INC_MATH}/Angle.hpp
            ${BULL_INC_MATH}/Clamp.hpp
            ${BULL_INC_MATH}/Constants.hpp
            ${BULL_INC_MATH}/EulerAngles.hpp
            ${BULL_INC_MATH}/Normalize.hpp
            ${BULL_INC_MATH}/Quaternion.hpp
        )

add_subdirectory(Matrix)
add_subdirectory(Polygon)
add_subdirectory(Vector)