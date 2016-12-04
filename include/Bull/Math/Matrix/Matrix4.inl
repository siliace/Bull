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
    template<typename U>
    Matrix4<T> Matrix4<T>::createTranslation(U x, U y, U z)
    {
        Matrix4<T> translation = Matrix4<T>::createIdentity();

        translation(3, 0) = static_cast<T>(x);
        translation(3, 1) = static_cast<T>(y);
        translation(3, 2) = static_cast<T>(z);

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
    template<typename U>
    Matrix4<T> Matrix4<T>::createScale(U x, U y, U z)
    {
        Matrix4<T> scale;

        scale(0, 0) = static_cast<T>(x);
        scale(1, 1) = static_cast<T>(y);
        scale(2, 2) = static_cast<T>(z);
        scale(3, 3) = static_cast<T>(1.0);

        return scale;
    }

    /*! \brief Create a rotation matrix
     *
     * \param x The rotation on the x axis
     * \param y The rotation on the y axis
     * \param z The rotation on the z axis
     *
     * \return Return the matrix
     *
     */
    template<typename T>
    template<typename U>
    Matrix4<T> Matrix4<T>::createRotation(U x, U y, U z)
    {
        return createRotation(EulerAngles<U>(Angle<U>::radian(x), Angle<U>::radian(y), Angle<U>::radian(z)));
    }

    /*! \brief Create a rotation matrix
     *
     * \param angles Angles of rotations
     *
     * \return Return the matrix
     *
     */
    template<typename T>
    template<typename U>
    Matrix4<T> Matrix4<T>::createRotation(const EulerAngles<U>& angles)
    {
        return createRotation(Quaternion<U>(angles));
    }

    /*! \brief Create a rotation matrix
     *
     * \param quaternion The quaternion representing a rotation
     *
     * \return Return the matrix
     *
     */
    template<typename T>
    template<typename U>
    Matrix4<T> Matrix4<T>::createRotation(const Quaternion<U>& quaternion)
    {
        Matrix4<T> left, right;

        left.set( quaternion.w, 0, 0);   left.set( quaternion.z, 1, 0);   left.set(-quaternion.y, 2, 0);   left.set(quaternion.x, 3, 0);
        left.set(-quaternion.z, 0, 1);   left.set( quaternion.w, 1, 1);   left.set( quaternion.x, 2, 1);   left.set(quaternion.y, 3, 1);
        left.set( quaternion.y, 0, 2);   left.set(-quaternion.x, 1, 2);   left.set( quaternion.w, 2, 2);   left.set(quaternion.z, 3, 2);
        left.set(-quaternion.x, 0, 3);   left.set(-quaternion.y, 1, 3);   left.set(-quaternion.z, 2, 3);   left.set(quaternion.w, 3, 3);

        right.set( quaternion.w, 0, 0);  right.set( quaternion.z, 1, 0);  right.set(-quaternion.y, 2, 0);  right.set(-quaternion.x, 3, 0);
        right.set(-quaternion.z, 0, 1);  right.set( quaternion.w, 1, 1);  right.set( quaternion.x, 2, 1);  right.set(-quaternion.y, 3, 1);
        right.set( quaternion.y, 0, 2);  right.set(-quaternion.x, 1, 2);  right.set( quaternion.w, 2, 2);  right.set(-quaternion.z, 3, 2);
        right.set( quaternion.x, 0, 3);  right.set( quaternion.y, 1, 3);  right.set( quaternion.z, 2, 3);  right.set( quaternion.w, 3, 3);

        return left * right;
    }

    /*! \brief Default Constructor
     *
     */
    template<typename T>
    Matrix4<T>::Matrix4()
    {
        static_assert(std::is_arithmetic<T>::value, "T must be a numeric type");

        set(0.0);
    }

    /*! \brief Constructor
     *
     * \param value The value of every matrix cell
     *
     */
    template<typename T>
    template<typename U>
    Matrix4<T>::Matrix4(U value)
    {
        static_assert(std::is_arithmetic<T>::value, "T must be a numeric type");

        set(value);
    }

    /*! \brief Constructor
     *
     * \param data The matrix content
     *
     */
    template<typename T>    template<typename U>
    Matrix4<T>::Matrix4(const std::array<U, 16>& data)
    {
        static_assert(std::is_arithmetic<T>::value, "T must be a numeric type");

        set(data);
    }

    /*! \brief Set the matrix content
     *
     * \param value The value of every matrix cell
     *
     */
    template<typename T>    template<typename U>
    void Matrix4<T>::set(U value)
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
    template<typename U>
    void Matrix4<T>::set(U value, std::size_t x, std::size_t y)
    {
        m_data[y * 4 + x] = static_cast<T>(value);
    }

    /*! \brief Set the matrix content
     *
     * \param data The matrix content
     *
     */
    template<typename T>
    template<typename U>
    void Matrix4<T>::set(const std::array<U, 16>& data)
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

    /*! \brief
     *
     * \param
     * \param
     *
     * \return
     *
     */
    template<typename T>
    T& Matrix4<T>::operator()(std::size_t x, std::size_t y)
    {
        return m_data[y * 4 + x];
    }

    /*! \brief
     *
     * \param
     * \param
     *
     * \return
     *
     */
    template<typename T>
    const T& Matrix4<T>::operator()(std::size_t x, std::size_t y) const
    {
        return m_data[y * 4 + x];
    }

    /*! \brief Compare two matrices
     *
     * \param right The matrix to compare to this
     *
     * \return Return true if the two matrices are equal, false otherwise
     *
     */
    template<typename T>
    template<typename U>
    bool Matrix4<T>::operator==(const Matrix4<U>& right)
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
    template<typename U>
    bool Matrix4<T>::operator!=(const Matrix4<U>& right)
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
    template<typename U>
    Matrix4<T>& Matrix4<T>::operator+=(const Matrix4<U>& right)
    {
        for(std::size_t i = 0; i < 16; i++)
        {
            m_data[i] += static_cast<U>(right.m_data[i]);
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
    template<typename U>
    Matrix4<T>& Matrix4<T>::operator+=(U right)
    {
        return (*this) += Matrix4<U>(right);
    }

    /*! \brief Subtract two matrices
     *
     * \param right
     *
     * \return Return the difference the subtraction of right and this
     *
     */
    template<typename T>
    template<typename U>
    Matrix4<T>& Matrix4<T>::operator-=(const Matrix4<U>& right)
    {
        for(std::size_t i = 0; i < 16; i++)
        {
            m_data[i] -= static_cast<T>(right.m_data[i]);
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
    template<typename U>
    Matrix4<T>& Matrix4<T>::operator-=(U right)
    {
        return (*this) -= Matrix4<U>(right);
    }

    /*! \brief Multiply two matrices
     *
     * \param right
     *
     * \return Return the product of the multiplication between right and this
     *
     */
    template<typename T>
    template<typename U>
    Matrix4<T> Matrix4<T>::operator*=(const Matrix4<U>& right)
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

    /*! \brief Multiply a matrix with a vector
     *
     * \param right
     * \param left
     *
     * \return Return the product of the multiplication between right and left
     *
     */
    template<typename T>
    Vector4<T> operator*(const Matrix4<T>& left, const Vector4<T>& right)
    {
        Vector4<T> product;

        product.x = (right.x * left.get(0, 0)) + (right.y * left.get(1, 0)) + (right.z * left.get(2, 0)) + (right.w * left.get(3, 0));
        product.y = (right.x * left.get(0, 1)) + (right.y * left.get(1, 1)) + (right.z * left.get(2, 1)) + (right.w * left.get(3, 1));
        product.z = (right.x * left.get(0, 2)) + (right.y * left.get(1, 2)) + (right.z * left.get(2, 2)) + (right.w * left.get(3, 2));
        product.w = (right.x * left.get(0, 3)) + (right.y * left.get(1, 3)) + (right.z * left.get(2, 3)) + (right.w * left.get(3, 3));

        return product;
    }
}
