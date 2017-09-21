#ifndef BULL_MATH_MATRIX_SQUAREMATRIX_HPP
#define BULL_MATH_MATRIX_SQUAREMATRIX_HPP

#include <Bull/Math/Matrix/Matrix.hpp>

namespace Bull
{
    template <typename T, Index S>
    struct SquareMatrix : public Matrix<T, S, S>
    {
        /*! \brief Create an identity SquareMatrix
         *
         * \return The identity SquareMatrix
         *
         */
        static SquareMatrix<T, S> makeIdentity();

        /*! \brief Default constructor
         *
         */
        SquareMatrix() = default;

        /*! \brief Constructor
         *
         * \param value The value to use to fill the Matrix
         *
         */
        SquareMatrix(T value);

        /*! \brief Copy constructor
         *
         * \param copy The Matrix to copy
         *
         */
        template <typename U, Index WU, Index HU>
        SquareMatrix(const Matrix<U, WU, HU>& copy);
    };
}

#include <Bull/Math/Matrix/SquareMatrix.inl>

#endif // BULL_MATH_MATRIX_SQUAREMATRIX_HPP
