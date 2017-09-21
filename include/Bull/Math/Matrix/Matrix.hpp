#ifndef BULL_MATH_MATRIX_MATRIX_HPP
#define BULL_MATH_MATRIX_MATRIX_HPP

#include <array>

#include <Bull/Core/Configuration/Integer.hpp>

#include <Bull/Math/Vector/Vector3.hpp>

namespace Bull
{
    template <typename T, Index W, Index H>
    class Matrix
    {
    public:

        /*! \brief Default constructor
         *
         */
        Matrix();

        /*! \brief Constructor
         *
         * \param value The value to use to fill the Matrix
         *
         */
        explicit Matrix(T value);

        /*! \brief Copy constructor
         *
         * \param copy The Matrix to copy
         *
         */
        template <typename U, Index WU, Index HU>
        Matrix(const Matrix<U, WU, HU>& copy);

        /*! \brief Basic assignment operator
         *
         * \param copy The Matrix to copy
         *
         * \return This
         *
         */
        template <typename U, Index WU, Index HU>
        Matrix<T, W, H>& operator=(const Matrix<U, WU, HU>& copy);

        /*! \brief Set the Matrix
         *
         * \param value The value to use to fill the Matrix
         *
         * \return This
         *
         */
        Matrix<T, W, H>& set(T value);

        /*! \brief Compare two Matrix
         *
         * \param right The Matrix to compare to this
         *
         * \return True if this and right are equal
         *
         */
        bool operator==(const Matrix<T, W, H>& right) const;

        /*! \brief Compare two Matrix
         *
         * \param right The Matrix to compare to this
         *
         * \return True if this and right are not equal
         *
         */
        bool operator!=(const Matrix<T, W, H>& right) const;

        /*! \brief Access to a Matrix cell
         *
         * \param x The abscissa of the cell
         * \param y The ordinate of the cell
         *
         * \return The cell
         *
         */
        T& at(Index x, Index y);

        /*! \brief Access to a Matrix cell
         *
         * \param x The abscissa of the cell
         * \param y The ordinate of the cell
         *
         * \return The cell
         *
         */
        const T& at(Index x, Index y) const;

        /*! \brief Set a row of the Matrix
         *
         * \param row   The row
         * \param index The index of the row
         *
         * \return This
         *
         */
        Matrix<T, W, H>& setRow(const Vector<T, H>& row, Index index);

        /*! \brief Get a row of the Matrix
         *
         * \param row The row to get
         *
         * \return The row
         *
         */
        Vector<T, W> getRow(Index row) const;

        /*! \brief Set a column of the Matrix
         *
         * \param column The column
         * \param index  The index of the column
         *
         * \return This
         *
         */
        Matrix<T, W, H>& setColumn(const Vector<T, H>& column, Index index);

        /*! \brief Get a column of the Matrix
         *
         * \param column The column to get
         *
         * \return The column
         *
         */
        Vector<T, H> getColumn(Index column) const;

        /*! \brief Negation operator
         *
         * \return The opposite Matrix of this
         *
         */
        Matrix<T, W, H> operator-() const;

        /*! \brief Get a pointer to the matrix
         *
         * \return The pointer
         *
         */
        const T* getPtr() const;

    private:

        std::array<T, W * H> m_matrix;
    };

    /*! \brief Addition two Matrix
     *
     * \param left  The left Matrix
     * \param right The right Matrix
     *
     * \return The sum of left and right
     *
     */
    template <typename T, Index W, Index H>
    Matrix<T, W, H> operator+(const Matrix<T, W, H>& left, const Matrix<T, W, H>& right);

    /*! \brief Subtract two Matrix
     *
     * \param left  The left Matrix
     * \param right The right Matrix
     *
     * \return The difference of left and right
     *
     */
    template <typename T, Index W, Index H>
    Matrix<T, W, H> operator-(const Matrix<T, W, H>& left, const Matrix<T, W, H>& right);
}

#include <Bull/Math/Matrix/Matrix.inl>

#endif // BULL_MATH_MATRIX_MATRIX_HPP
