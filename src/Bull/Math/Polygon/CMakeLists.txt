set(BULL_INC_MATH_POLYGON ${BULL_INC_MATH}/Polygon)
set(BULL_SRC_MATH_POLYGON ${BULL_SRC_MATH}/Polygon)

target_sources(bull-math
        INTERFACE
            ${BULL_INC_MATH_POLYGON}/Polygon.hpp
            ${BULL_INC_MATH_POLYGON}/Polygon.inl
            ${BULL_INC_MATH_POLYGON}/Polygon.inl
            ${BULL_INC_MATH_POLYGON}/Rectangle.hpp
            ${BULL_INC_MATH_POLYGON}/Rectangle.inl
            ${BULL_INC_MATH_POLYGON}/RegularPolygon.hpp
            ${BULL_INC_MATH_POLYGON}/RegularPolygon.inl
            ${BULL_INC_MATH_POLYGON}/Triangle.hpp
            ${BULL_INC_MATH_POLYGON}/Triangle.inl
        )