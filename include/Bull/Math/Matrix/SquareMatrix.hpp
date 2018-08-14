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

        for(std::size_t y = 0; y < S; y++)
        {
            for(std::size_t x = 0; x < S; x++)
            {
                T sum = 0;

                Vector<T, S> row = left.getRow(x);
                Vector<T, S> column = right.getColumn(y);

                for(std::size_t i = 0; i < S; i++)
                {
                    sum += row.at(i) * column.at(i);
                }

                product.at(x, y) = sum;
            }
        }

        return product;
    }
}

#endif // BULL_MATH_MATRIX_SQUAREMATRIX_HPP
