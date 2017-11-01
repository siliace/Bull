#ifndef BULL_MATH_MATRIX_SQUAREMATRIX_HPP
#define BULL_MATH_MATRIX_SQUAREMATRIX_HPP

#include <Bull/Math/Matrix/Matrix.hpp>

namespace Bull
{
    template <typename T, std::size_t S>
    struct SquareMatrix : public Matrix<T, S, S>
    {
        static SquareMatrix<T, S> Zero;

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
        template <typename U, std::size_t WU, std::size_t HU>
        SquareMatrix(const Matrix<U, WU, HU>& copy);
    };

    template <typename T, std::size_t S>
    SquareMatrix<T, S> SquareMatrix<T, S>::Zero = SquareMatrix<T, S>();

    /*! \brief Multiply two Matrix
     *
     * \param left  The left Matrix
     * \param right The right Matrix
     *
     * \return The product of left and right
     *
     */
    template <typename T, std::size_t S>
    SquareMatrix<T, S> operator*(const SquareMatrix<T, S>& left, const SquareMatrix<T, S>& right);
}

#include <Bull/Math/Matrix/SquareMatrix.inl>

#endif // BULL_MATH_MATRIX_SQUAREMATRIX_HPP
