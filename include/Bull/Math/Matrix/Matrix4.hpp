#ifndef BULL_MATRIX4_HPP
#define BULL_MATRIX4_HPP

#include <array>

#include <Bull/Math/Vector/Vector4.hpp>

namespace Bull
{
    template<typename T>
    class Matrix4
    {
    public:

        static Matrix4<T> Identity;

    public:

        /*! \brief Default Constructor
         *
         */
        Matrix4();

        /*! \brief Constructor
         *
         * \param value The value of every cell of the Matrix4
         *
         */
        Matrix4(T value);

        /*! \brief Constructor
         *
         * \param data The matrix content
         *
         */
        Matrix4(const std::array<T, 16>& data);

        /*! \brief Set the matrix content
         *
         * \param value The value of every matrix cell
         *
         */
        void set(T value);

        /*! \brief Set the matrix content
         *
         * \param data The matrix content
         *
         */
        void set(const std::array<T, 16>& data);

        void set(T value, std::size_t x, std::size_t y);

        T get(std::size_t x, std::size_t y) const;

        /*! \brief Set a column of the Matrix4
         *
         * \param column   The column
         * \param position The position of the column to set
         *
         * \return This
         *
         */
        Matrix4<T>& setColumn(const Vector4<T>& column, std::size_t position);

        /*! \brief Get a column a the Matrix4
         *
         * \param column The column to get
         *
         * \return Return the column
         *
         */
        std::array<T, 4> getColumn(std::size_t column) const;

        Matrix4<T>& setRow(const Vector4<T>& row, std::size_t position);

        /*! \brief Get a row a the matrix
         *
         * \param row The row to get
         *
         * \return Return the row
         *
         */
        std::array<T, 4> getRow(std::size_t row) const;

        /*! \brief
         *
         * \param
         * \param
         *
         * \return
         *
         */
        T& operator()(std::size_t x, std::size_t y);

        /*! \brief
         *
         * \param
         * \param
         *
         * \return
         *
         */
        const T& operator()(std::size_t x, std::size_t y) const;

        /*! \brief Compare two matrices
         *
         * \param right The matrix to compare to this
         *
         * \return Return true if the two matrices are equal, false otherwise
         *
         */
        bool operator==(const Matrix4<T>& right);

        /*! \brief Compare two matrices
         *
         * \param right The matrix to compare to this
         *
         * \return Return true if the two matrices are not equal, false otherwise
         *
         */
        bool operator!=(const Matrix4<T>& right);

        /*! \brief Addition two matrices
         *
         * \param right
         *
         * \return Return the sum the addition of right and this
         *
         */
        Matrix4<T>& operator+=(const Matrix4<T>& right);

        /*! \brief Addition two matrices
         *
         * \param right
         *
         * \return Return the sum of the addition between right and this
         *
         */
        Matrix4<T>& operator+=(T right);

        /*! \brief Subtract two matrices
         *
         * \param right
         *
         * \return Return the difference of the subtraction between right and this
         *
         */
        Matrix4<T>& operator-=(const Matrix4<T>& right);

        /*! \brief Subtract a matrix with a scalar
         *
         * \param right
         *
         * \return Return the difference the subtraction between right and this
         *
         */
        Matrix4<T>& operator-=(T right);

        /*! \brief Multiply two matrices
         *
         * \param right
         *
         * \return Return the product of the multiplication between right and this
         *
         */
        Matrix4<T> operator*=(const Matrix4<T>& right);

        /*! \brief Get a pointer to the internal data
         *
         * \return Return the pointer
         *
         */
        operator const T*() const;

    private:

        std::array<T, 16> m_data;
    };

    template<typename T>
    Matrix4<T> Matrix4<T>::Identity({1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0});

    /*! \brief Addition two matrices
     *
     * \param right
     * \param left
     *
     * \return Return the sum of the addition between right and left
     *
     */
    template<typename T>
    Matrix4<T> operator+(const Matrix4<T>& left, const Matrix4<T>& right);

    /*! \brief Addition two matrices
     *
     * \param right
     * \param left
     *
     * \return Return the sum of the addition between right and left
     *
     */
    template<typename T>
    Matrix4<T> operator+(T left, const Matrix4<T>& right);

    /*! \brief Addition two matrices
     *
     * \param right
     * \param left
     *
     * \return Return the sum of the addition between right and left
     *
     */
    template<typename T>
    Matrix4<T> operator+(const Matrix4<T>& left, T right);

    /*! \brief Subtract two matrices
     *
     * \param right
     * \param left
     *
     * \return Return the difference of the subtraction between right and left
     *
     */
    template<typename T>
    Matrix4<T> operator-(const Matrix4<T>& left, const Matrix4<T>& right);

    /*! \brief Subtract two matrices
     *
     * \param right
     * \param left
     *
     * \return Return the difference of the subtraction between right and left
     *
     */
    template<typename T>
    Matrix4<T> operator-(T left, const Matrix4<T>& right);

    /*! \brief Subtract two matrices
     *
     * \param right
     * \param left
     *
     * \return Return the difference of the subtraction between right and left
     *
     */
    template<typename T>
    Matrix4<T> operator-(const Matrix4<T>& left, T right);

    /*! \brief Multiply two matrices
     *
     * \param right
     * \param left
     *
     * \return Return the product of the multiplication between right and left
     *
     */
    template<typename T>
    Matrix4<T> operator*(const Matrix4<T>& left, const Matrix4<T>& right);

    /*! \brief Multiply a matrix with a vector
     *
     * \param right
     * \param left
     *
     * \return Return the product of the multiplication between right and left
     *
     */
    template<typename T>
    Vector4<T> operator*(const Matrix4<T>& left, const Vector4<T>& right);

    typedef Matrix4<int> Matrix4I;
    typedef Matrix4<float> Matrix4F;
    typedef Matrix4<double> Matrix4D;
    typedef Matrix4<unsigned int> Matrix4UI;
}

#include <Bull/Math/Matrix/Matrix4.inl>

#endif // BULL_MATRIX4_HPP
