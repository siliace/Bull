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
        static SquareMatrix<T, S> makeIdentity()
        {
            SquareMatrix<T, S> identity;

            for(std::size_t i = 0; i < S; i++)
            {
                identity.at(i, i) = 1;
            }

            return identity;
        }

        /*! \brief Default constructor
         *
         */
        SquareMatrix() = default;

        /*! \brief Constructor
         *
         * \param value The value to use to fill the Matrix
         *
         */
        explicit SquareMatrix(T value) :
            Matrix<T, S, S>(value)
        {
            /// Nothing
        }

        /*! \brief Copy constructor
         *
         * \param copy The Matrix to copy
         *
         */
        template <typename U, std::size_t WU, std::size_t HU>
        SquareMatrix(const Matrix<U, WU, HU>& copy) :
            Matrix<T, S, S>(copy)
        {
            /// Nothing
        }
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
    SquareMatrix<T, S> operator*(const SquareMatrix<T, S>& left, const SquareMatrix<T, S>& right)
    {
        SquareMatrix<T, S> product;

        for(std::size_t j = 0; j < S; j++)
        {
            for(std::size_t i = 0; i < S; i++)
            {
                T sum = 0;
                Vector<T, S> row = left.getRow(j);
                Vector<T, S> column = right.getColumn(i);

                for(std::size_t k = 0; k < S; k++)
                {
                    sum += row.at(k) * column.at(k);
                }

                product.at(i, j) = sum;
            }
        }

        return product;
    }
}

#endif // BULL_MATH_MATRIX_SQUAREMATRIX_HPP
