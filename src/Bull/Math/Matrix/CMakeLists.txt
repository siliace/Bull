set(BULL_INC_MATH_MATRIX ${BULL_INC_MATH}/Matrix)
set(BULL_SRC_MATH_MATRIX ${BULL_SRC_MATH}/Matrix)

target_sources(bull-math
        INTERFACE
        ${BULL_INC_MATH_MATRIX}/Matrix.hpp
        ${BULL_INC_MATH_MATRIX}/Matrix2.hpp
        ${BULL_INC_MATH_MATRIX}/Matrix3.hpp
        ${BULL_INC_MATH_MATRIX}/Matrix4.hpp
        ${BULL_INC_MATH_MATRIX}/SquareMatrix.hpp
        )