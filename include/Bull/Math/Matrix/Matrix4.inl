namespace Bull
{
    /*! \brief Create an identity matrix
     *
     * \return Return the matrix
     *
     */
    template<typename T>
    Matrix4<T> Matrix4<T>::createIdentity()
    {
        Matrix4<T> identity;

        for(std::size_t i = 0; i < 4; i++)
        {
            identity.set(1, i, i);
        }

        return identity;
    }

    /*! \brief Create a translation matrix
     *
     * \param x The translation value on x axis
     * \param y The translation value on y axis
     * \param z The translation value on z axis
     *
     * \return Return the matrix
     *
     */
    template<typename T>
    Matrix4<T> Matrix4<T>::createTranslation(T x, T y, T z)
    {
        Matrix4<T> translation = Matrix4<T>::createIdentity();

        translation.set(x, 3, 0);
        translation.set(y, 3, 1);
        translation.set(z, 3, 2);

        return translation;
    }

    /*! \brief Create a scale matrix
     *
     * \param x The scale value on x axis
     * \param y The scale value on y axis
     * \param z The scale value on z axis
     *
     * \return Return the matrix
     *
     */
    template<typename T>
    Matrix4<T> Matrix4<T>::createScale(T x, T y, T z)
    {
        Matrix4<T> scale;

        scale.set(x, 0, 0);
        scale.set(y, 1, 1);
        scale.set(z, 2, 2);
        scale.set(1, 3, 3);

        return scale;
    }

    /*! \brief Default Constructor
     *
     */
    template<typename T>
    Matrix4<T>::Matrix4()
    {
        static_assert(std::is_arithmetic<T>::value, "T must be a numeric type");

        set(0);
    }

    /*! \brief Constructor
     *
     * \param value The value of every matrix cell
     *
     */
    template<typename T>
    Matrix4<T>::Matrix4(T value)
    {
        static_assert(std::is_arithmetic<T>::value, "T must be a numeric type");

        set(value);
    }

    /*! \brief Constructor
     *
     * \param data The matrix content
     *
     */
    template<typename T>    Matrix4<T>::Matrix4(const std::array<T, 16>& data)
    {
        static_assert(std::is_arithmetic<T>::value, "T must be a numeric type");

        set(data);
    }

    /*! \brief Set the matrix content
     *
     * \param value The value of every matrix cell
     *
     */
    template<typename T>    void Matrix4<T>::set(T value)
    {
        m_data.fill(value);
    }

    /*! \brief The value of a cell of the matrix
     *
     * \param value The value to set
     * \param x     The abscissa of the cell in the matrix
     * \param y     The ordinate of the cell in the matrix
     *
     */
    template<typename T>
    void Matrix4<T>::set(T value, std::size_t x, std::size_t y)
    {
        m_data[y * 4 + x] = value;
    }

    /*! \brief Set the matrix content
     *
     * \param data The matrix content
     *
     */
    template<typename T>
    void Matrix4<T>::set(const std::array<T, 16>& data)
    {
        m_data = data;
    }

    /*! \brief Get the value of a cell of the matrix
     *
     * \param x The abscissa of the cell to get in the matrix
     * \param y The ordinate of the cell to get in the matrix
     *
     * \return Return the value
     *
     */
    template<typename T>
    T Matrix4<T>::get(std::size_t x, std::size_t y) const
    {
        return m_data[y * 4 + x];
    }

    /*! \brief Get a column a the matrix
     *
     * \param column The column to get
     *
     * \return Return the column
     *
     */
    template<typename T>
    std::array<T, 4> Matrix4<T>::getColumn(std::size_t column) const
    {
        std::array<T, 4> col;

        for(std::size_t i = 0; i < 4; i++)
        {
            col[i] = get(column, i);
        }

        return col;
    }

    /*! \brief Get a row a the matrix
     *
     * \param row The row to get
     *
     * \return Return the row
     *
     */
    template<typename T>    std::array<T, 4> Matrix4<T>::getRow(std::size_t row) const
    {
        std::array<T, 4> r;

        for(std::size_t i = 0; i < 4; i++)
        {
            r[i] = get(i, row);
        }

        return r;
    }

    /*! \brief Compare two matrices
     *
     * \param right The matrix to compare to this
     *
     * \return Return true if the two matrices are equal, false otherwise
     *
     */
    template<typename T>
    bool Matrix4<T>::operator==(const Matrix4<T>& right)
    {
        return m_data == right.m_data;
    }

    /*! \brief Compare two matrices
     *
     * \param right The matrix to compare to this
     *
     * \return Return true if the two matrices are not equal, false otherwise
     *
     */
    template<typename T>
    bool Matrix4<T>::operator!=(const Matrix4<T>& right)
    {
        return m_data != right.m_data;
    }

    /*! \brief Addition two matrices
     *
     * \param right
     *
     * \return Return the sum the addition of right and this
     *
     */
    template<typename T>
    Matrix4<T>& Matrix4<T>::operator+=(const Matrix4<T>& right)
    {
        for(std::size_t i = 0; i < 16; i++)
        {
            m_data[i] += right.m_data[i];
        }

        return (*this);
    }

    /*! \brief Addition two matrices
     *
     * \param right
     *
     * \return Return the sum the addition of right and this
     *
     */
    template<typename T>
    Matrix4<T>& Matrix4<T>::operator+=(T right)
    {
        return (*this) += Matrix4<T>(right);
    }

    /*! \brief Subtract two matrices
     *
     * \param right
     *
     * \return Return the difference the subtraction of right and this
     *
     */
    template<typename T>
    Matrix4<T>& Matrix4<T>::operator-=(const Matrix4<T>& right)
    {
        for(std::size_t i = 0; i < 16; i++)
        {
            m_data[i] -= right.m_data[i];
        }

        return (*this);
    }

    /*! \brief Subtract two matrices
     *
     * \param right
     *
     * \return Return the difference the subtraction of right and this
     *
     */
    template<typename T>
    Matrix4<T>& Matrix4<T>::operator-=(T right)
    {
        return (*this) -= Matrix4<T>(right);
    }

    /*! \brief Multiply two matrices
     *
     * \param left
     *
     * \return Return the product of the multiplication between right and this
     *
     */
    template<typename T>
    Matrix4<T> Matrix4<T>::operator*=(const Matrix4<T>& right)
    {
        std::array<T, 16> product;

        for(std::size_t i = 0; i < 16; i++)
        {
            std::array<T, 4> row, col;
            T sum = 0;

            row = getRow(i / 4);
            col = right.getColumn(i % 4);

            for(std::size_t j = 0; j < 4; j++)
            {
                sum += row[j] * col[j];
            }

            product[i] = sum;
        }

        m_data = std::move(product);

        return (*this);
    }

    /*! \brief Get a pointer to the internal data
     *
     * \return Return the pointer
     *
     */
    template<typename T>
    Matrix4<T>::operator const T*() const
    {
        return &m_data[0];
    }

    /*! \brief Addition two matrices
     *
     * \param right
     * \param left
     *
     * \return Return the sum the addition of right and left
     *
     */
    template<typename T>
    Matrix4<T> operator+(const Matrix4<T>& left, const Matrix4<T>& right)
    {
        Matrix4<T> sum(left);

        sum += right;

        return sum;
    }

    /*! \brief Addition two matrices
     *
     * \param right
     * \param left
     *
     * \return Return the sum the addition of right and left
     *
     */
    template<typename T>
    Matrix4<T> operator+(T left, const Matrix4<T>& right)
    {
        Matrix4<T> sum(left);

        sum += right;

        return sum;
    }

    /*! \brief Addition two matrices
     *
     * \param right
     * \param left
     *
     * \return Return the sum the addition of right and left
     *
     */
    template<typename T>
    Matrix4<T> operator+(const Matrix4<T>& left, T right)
    {
        Matrix4<T> sum(left);

        sum += right;

        return sum;
    }

    /*! \brief Subtract two matrices
     *
     * \param right
     * \param left
     *
     * \return Return the sum the subtraction of right and left
     *
     */
    template<typename T>
    Matrix4<T> operator-(const Matrix4<T>& left, const Matrix4<T>& right)
    {
        Matrix4<T> difference(left);

        difference -= right;

        return difference;
    }

    /*! \brief Subtract two matrices
     *
     * \param right
     * \param left
     *
     * \return Return the sum the subtraction of right and left
     *
     */
    template<typename T>
    Matrix4<T> operator-(T left, const Matrix4<T>& right)
    {
        Matrix4<T> difference(left);

        difference -= right;

        return difference;
    }

    /*! \brief Subtract two matrices
     *
     * \param right
     * \param left
     *
     * \return Return the difference the subtraction of right and left
     *
     */
    template<typename T>
    Matrix4<T> operator-(const Matrix4<T>& left, T right)
    {
        Matrix4<T> difference(left);

        difference -= right;

        return difference;
    }

    /*! \brief Multiply two matrices
     *
     * \param right
     * \param left
     *
     * \return Return the product of the multiplication between right and left
     *
     */
    template<typename T>
    Matrix4<T> operator*(const Matrix4<T>& left, const Matrix4<T>& right)
    {
        Matrix4<T> product(left);

        product *= right;

        return product;
    }
}
