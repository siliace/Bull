#ifndef BULL_MATH_MATRIX_MATRIX_HPP
#define BULL_MATH_MATRIX_MATRIX_HPP

#include <array>

#include <Bull/Math/Vector/Vector3.hpp>

namespace Bull
{
    template <typename T, std::size_t W, std::size_t H>
    class Matrix
    {
    public:

        /** \brief Default constructor
         *
         */
        Matrix() :
                Matrix<T, W, H>(0)
        {
            /// Nothing
        }

        /** \brief Constructor
         *
         * \param value The value to use to fill the Matrix
         *
         */
        explicit Matrix(T value)
        {
            set(value);
        }

        /** \brief Copy constructor
         *
         * \param copy The Matrix to copy
         *
         */
        template <typename U, std::size_t WU, std::size_t HU>
        Matrix(const Matrix<U, WU, HU>& copy) :
                Matrix<T, W, H>(0)
        {
            for(std::size_t j = 0; j < std::min(H, HU); j++)
            {
                for(std::size_t i = 0; i < std::min(W, WU); i++)
                {
                    at(i, j) = static_cast<T>(copy.at(i, j));
                }
            }
        }

        /** \brief Basic assignment operator
         *
         * \param copy The Matrix to copy
         *
         * \return This
         *
         */
        template <typename U, std::size_t WU, std::size_t HU>
        Matrix<T, W, H>& operator=(const Matrix<U, WU, HU>& copy)
        {
            set(0);

            for(std::size_t j = 0; j < std::min(H, HU); j++)
            {
                for(std::size_t i = 0; i < std::min(W, WU); i++)
                {
                    at(i, j) = static_cast<T>(copy.at(i, j));
                }
            }

            return (*this);
        }

        /** \brief Set the Matrix
         *
         * \param value The value to use to fill the Matrix
         *
         * \return This
         *
         */
        Matrix<T, W, H>& set(T value)
        {
            m_matrix.fill(value);

            return *this;
        }

        /** \brief Compare two Matrix
         *
         * \param right The Matrix to compare to this
         *
         * \return True if this and right are equal
         *
         */
        bool operator==(const Matrix<T, W, H>& right) const
        {
            return m_matrix == right.m_matrix;
        }

        /** \brief Compare two Matrix
         *
         * \param right The Matrix to compare to this
         *
         * \return True if this and right are not equal
         *
         */
        bool operator!=(const Matrix<T, W, H>& right) const
        {
            return m_matrix != right.m_matrix;
        }

        /** \brief Get the transpose Matrix
         *
         * \return The transpose
         *
         */
        Matrix<T, H, W> transpose() const
        {
            Matrix<T, H, W> transpose;

            for(std::size_t i = 0; i < H; i++)
            {
                for(std::size_t j = 0; j < W; j++)
                {
                    transpose.at(i, j) = at(j, i);
                }
            }

            return transpose;
        }

        /** \brief Access to a Matrix cell
         *
         * \param x The abscissa of the cell
         * \param y The ordinate of the cell
         *
         * \return The cell
         *
         */
        T& at(std::size_t x, std::size_t y)
        {
            RangeCheck(x, W);
            RangeCheck(y, H);

            return m_matrix.at(y * W + x);
        }

        /** \brief Access to a Matrix cell
         *
         * \param x The abscissa of the cell
         * \param y The ordinate of the cell
         *
         * \return The cell
         *
         */
        const T& at(std::size_t x, std::size_t y) const
        {
            RangeCheck(x, W);
            RangeCheck(y, H);

            return m_matrix.at(y * W + x);
        }

        /** \brief Set a row of the Matrix
         *
         * \param row   The row
         * \param index The index of the row
         *
         * \return This
         *
         */
        Matrix<T, W, H>& setRow(const Vector<T, H>& row, std::size_t index)
        {
            for(std::size_t i = 0; i < W; i++)
            {
                at(index, i) = row.at(i);
            }

            return (*this);
        }

        /** \brief Get a row of the Matrix
         *
         * \param row The row to get
         *
         * \return The row
         *
         */
        Vector<T, W> getRow(std::size_t row) const
        {
            Vector<T, W> rowVec;

            for(std::size_t i = 0; i < W; i++)
            {
                rowVec.at(i) = at(row, i);
            }

            return rowVec;
        }

        /** \brief Set a column of the Matrix
         *
         * \param column The column
         * \param index  The index of the column
         *
         * \return This
         *
         */
        Matrix<T, W, H>& setColumn(const Vector<T, H>& column, std::size_t index)
        {
            for(std::size_t i = 0; i < W; i++)
            {
                at(i, index) = column.at(i);
            }

            return (*this);
        }

        /** \brief Get a column of the Matrix
         *
         * \param column The column to get
         *
         * \return The column
         *
         */
        Vector<T, H> getColumn(std::size_t column) const
        {
            Vector<T, W> columnVec;

            for(std::size_t i = 0; i < W; i++)
            {
                columnVec.at(i) = at(i, column);
            }

            return columnVec;
        }

        /** \brief Negation operator
         *
         * \return The opposite Matrix of this
         *
         */
        Matrix<T, W, H> operator-() const
        {
            Matrix<T, W, H> negation;

            for(std::size_t i = 0; i < W * H; i++)
            {
                negation.at(i) = -at(i);
            }

            return negation;
        }

        /** \brief Get a pointer to the matrix
         *
         * \return The pointer
         *
         */
        const T* getPtr() const
        {
            return m_matrix.data();
        }

    private:

        std::array<T, W * H> m_matrix;
    };

    /** \brief Addition two Matrix
     *
     * \param left  The left Matrix
     * \param right The right Matrix
     *
     * \return The sum of left and right
     *
     */
    template <typename T, std::size_t W, std::size_t H>
    Matrix<T, W, H> operator+(const Matrix<T, W, H>& left, const Matrix<T, W, H>& right)
    {
        Matrix<T, W, H> sum;

        for(std::size_t j = 0; j < H; j++)
        {
            for(std::size_t i = 0; i < W; i++)
            {
                sum.at(i, j) = left.at(i, j) + right.at(i, j);
            }
        }

        return sum;
    }

    /** \brief Subtract two Matrix
     *
     * \param left  The left Matrix
     * \param right The right Matrix
     *
     * \return The difference of left and right
     *
     */
    template <typename T, std::size_t W, std::size_t H>
    Matrix<T, W, H> operator-(const Matrix<T, W, H>& left, const Matrix<T, W, H>& right)
    {
        return left + -right;
    }
}

#endif // BULL_MATH_MATRIX_MATRIX_HPP
