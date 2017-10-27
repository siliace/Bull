set(BULL_INC_MATH_VECTOR ${BULL_INC_MATH}/Vector)
set(BULL_SRC_MATH_VECTOR ${BULL_SRC_MATH}/Vector)

target_sources(bull-math
        INTERFACE
            ${BULL_INC_MATH_VECTOR}/Vector.hpp
            ${BULL_INC_MATH_VECTOR}/Vector.inl
            ${BULL_INC_MATH_VECTOR}/Vector2.hpp
            ${BULL_INC_MATH_VECTOR}/Vector2.inl
            ${BULL_INC_MATH_VECTOR}/Vector3.hpp
            ${BULL_INC_MATH_VECTOR}/Vector3.inl
            ${BULL_INC_MATH_VECTOR}/Vector4.hpp
            ${BULL_INC_MATH_VECTOR}/Vector4.inl
        )