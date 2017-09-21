namespace Bull
{
    template<typename T>
    Matrix4<T>::Matrix4()
    {
        set(0.0);
    }

    template<typename T>
    Matrix4<T>::Matrix4(T value)
    {
        set(value);
    }

    template<typename T>
    Matrix4<T>::Matrix4(const std::array<T, 16>& data)
    {
        set(data);
    }

    template<typename T>
    void Matrix4<T>::set(T value)
    {
        m_data.fill(value);
    }

    template<typename T>
    void Matrix4<T>::set(const std::array<T, 16>& data)
    {
        m_data = data;
    }

    template<typename T>
    void Matrix4<T>::set(T value, Index x, Index y)
    {
        if(x >= 4 || y >= 4)
        {
            throw OutOfRange("Requested value out of range");
        }

        m_data[y * 4 + x] = value;
    }

    template<typename T>
    T Matrix4<T>::get(Index x, Index y) const
    {
        if(x >= 4 || y >= 4)
        {
            throw OutOfRange("Requested value out of range");
        }

        return m_data[y * 4 + x];
    }

    template<typename T>
    T& Matrix4<T>::operator()(Index x, Index y)
    {
        if(x >= 4 || y >= 4)
        {
            throw OutOfRange("Requested value out of range");
        }

        return m_data[y * 4 + x];
    }

    template<typename T>
    const T& Matrix4<T>::operator()(Index x, Index y) const
    {
        if(x >= 4 || y >= 4)
        {
            throw OutOfRange("Requested value out of range");
        }

        return m_data[y * 4 + x];
    }

    template<typename T>
    Matrix4<T>& Matrix4<T>::setColumn(const Vector4<T>& column, Index position)
    {
        if(position >= 4)
        {
            throw OutOfRange("Requested column out of range");
        }

        set(column.x(), 0, position);
        set(column.y(), 1, position);
        set(column.z(), 2, position);
        set(column.w(), 3, position);

        return (*this);
    }

    template<typename T>
    std::array<T, 4> Matrix4<T>::getColumn(Index column) const
    {
        if(column >= 4)
        {
            throw OutOfRange("Requested column out of range");
        }

        std::array<T, 4> col;

        for(Index i = 0; i < 4; i++)
        {
            col[i] = get(column, i);
        }

        return col;
    }

    template<typename T>
    Matrix4<T>& Matrix4<T>::setRow(const Vector4<T>& row, Index position)
    {
        if(position >= 4)
        {
            throw OutOfRange("Requested column out of range");
        }

        set(row.w(), position, 0);
        set(row.x(), position, 1);
        set(row.y(), position, 2);
        set(row.z(), position, 3);

        return (*this);
    }

    template<typename T>
    std::array<T, 4> Matrix4<T>::getRow(Index row) const
    {
        if(row >= 4)
        {
            throw OutOfRange("Requested row out of range");
        }

        std::array<T, 4> r;

        for(Index i = 0; i < 4; i++)
        {
            r[i] = get(i, row);
        }

        return r;
    }

    template<typename T>
    bool Matrix4<T>::operator==(const Matrix4<T>& right)
    {
        return m_data == right.m_data;
    }

    template<typename T>
    bool Matrix4<T>::operator!=(const Matrix4<T>& right)
    {
        return m_data != right.m_data;
    }

    template<typename T>
    Matrix4<T>& Matrix4<T>::operator+=(const Matrix4<T>& right)
    {
        for(Index i = 0; i < 16; i++)
        {
            m_data[i] += static_cast<T>(right.m_data[i]);
        }

        return (*this);
    }

    template<typename T>
    Matrix4<T>& Matrix4<T>::operator+=(T right)
    {
        return (*this) += Matrix4<T>(right);
    }

    template<typename T>
    Matrix4<T>& Matrix4<T>::operator-=(const Matrix4<T>& right)
    {
        for(Index i = 0; i < 16; i++)
        {
            m_data[i] -= static_cast<T>(right.m_data[i]);
        }

        return (*this);
    }

    template<typename T>
    Matrix4<T>& Matrix4<T>::operator-=(T right)
    {
        return (*this) -= Matrix4<T>(right);
    }

    template<typename T>
    Matrix4<T> Matrix4<T>::operator*=(const Matrix4<T>& right)
    {
        std::array<T, 16> product;

        for(Index i = 0; i < 16; i++)
        {
            T sum = 0;
            std::array<T, 4> row, col;

            row = getRow(i / 4);
            col = right.getColumn(i % 4);

            for(Index j = 0; j < 4; j++)
            {
                sum += row[j] * col[j];
            }

            product[i] = sum;
        }

        m_data = std::move(product);

        return (*this);
    }

    template<typename T>
    Matrix4<T>::operator const T*() const
    {
        return &m_data[0];
    }

    template<typename T>
    Matrix4<T> operator+(const Matrix4<T>& left, const Matrix4<T>& right)
    {
        Matrix4<T> sum(left);

        sum += right;

        return sum;
    }

    template<typename T>
    Matrix4<T> operator+(T left, const Matrix4<T>& right)
    {
        Matrix4<T> sum(left);

        sum += right;

        return sum;
    }

    template<typename T>
    Matrix4<T> operator+(const Matrix4<T>& left, T right)
    {
        Matrix4<T> sum(left);

        sum += right;

        return sum;
    }

    template<typename T>
    Matrix4<T> operator-(const Matrix4<T>& left, const Matrix4<T>& right)
    {
        Matrix4<T> difference(left);

        difference -= right;

        return difference;
    }

    template<typename T>
    Matrix4<T> operator-(T left, const Matrix4<T>& right)
    {
        Matrix4<T> difference(left);

        difference -= right;

        return difference;
    }

    template<typename T>
    Matrix4<T> operator-(const Matrix4<T>& left, T right)
    {
        Matrix4<T> difference(left);

        difference -= right;

        return difference;
    }

    template<typename T>
    Matrix4<T> operator*(const Matrix4<T>& left, const Matrix4<T>& right)
    {
        Matrix4<T> product(left);

        product *= right;

        return product;
    }

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
