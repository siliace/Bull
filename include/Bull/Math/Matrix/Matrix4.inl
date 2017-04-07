namespace Bull
{
    template<typename T>
    Matrix4<T> Matrix4<T>::makeIdentity()
    {
        Matrix4<T> identity;

        for(std::size_t i = 0; i < 4; i++)
        {
            identity(i, i) = 1;
        }

        return identity;
    }

    template<typename T>
    Matrix4<T> Matrix4<T>::makeScale(T x, T y, T z)
    {
        Matrix4<T> scale;

        scale(0, 0) = static_cast<T>(x);
        scale(1, 1) = static_cast<T>(y);
        scale(2, 2) = static_cast<T>(z);
        scale(3, 3) = static_cast<T>(1.0);

        return scale;
    }

    template<typename T>
    Matrix4<T> Matrix4<T>::makeTranslation(T x, T y, T z)
    {
        Matrix4<T> translation = Matrix4<T>::makeIdentity();

        translation(3, 0) = static_cast<T>(x);
        translation(3, 1) = static_cast<T>(y);
        translation(3, 2) = static_cast<T>(z);

        return translation;
    }

    template<typename T>
    Matrix4<T> Matrix4<T>::makeRotation(const Quaternion<T>& quaternion)
    {
        Matrix4<T> rotation;

        T tx  = quaternion.x + quaternion.x;
        T ty  = quaternion.y + quaternion.y;
        T tz  = quaternion.z + quaternion.z;
        T twx = tx * quaternion.w;
        T twy = ty * quaternion.w;
        T twz = tz * quaternion.w;
        T txx = tx * quaternion.x;
        T txy = ty * quaternion.x;
        T txz = tz * quaternion.x;
        T tyy = ty * quaternion.y;
        T tyz = tz * quaternion.y;
        T tzz = tz * quaternion.z;

        rotation.set(1.0 - (tyy + tzz), 0, 0);
        rotation.set(txy + twz,         0, 1);
        rotation.set(txz - twy,         0, 2);

        rotation.set(txy - twz,         1, 0);
        rotation.set(1.0 - (txx + tzz), 1, 1);
        rotation.set(tyz + twx,         1, 2);

        rotation.set(txz + twy,         2, 0);
        rotation.set(tyz - twx,         2, 1);
        rotation.set(1.0 - (txx + tyy), 2, 2);

        rotation.set(1.0, 3, 3);

        return rotation;
    }

    template<typename T>
    Matrix4<T> Matrix4<T>::makePerspective(const Angle<T>& angle, T ratio, T near, T far)
    {
        Matrix4<T> perspective;
        Angle<T> fov = angle.asRadian() / 2.0;
        T yScale = std::tan(static_cast<T>(Pi2) - static_cast<T>(angle));

        perspective.set(yScale / ratio,                     0, 0);
        perspective.set(yScale,                             1, 1);
        perspective.set(-(far + near) / (far - near),       2, 2);
        perspective.set(-1.0,                               2, 3);
        perspective.set(-2.0 * (near * far) / (far - near), 3, 2);

        return perspective;
    }

    template<typename T>
    Matrix4<T> Matrix4<T>::makeOrthographic(const Rectangle<T>& plan, T near, T far)
    {
        Matrix4<T> orthographic;

        orthographic.set(2.0 / plan.width  - plan.x,                      0, 0);
        orthographic.set(2.0 / plan.height - plan.y,                      1, 1);
        orthographic.set(1.0 / near - far,                                2, 2);
        orthographic.set((plan.x + plan.width) / (plan.x - plan.width),   0, 3);
        orthographic.set((plan.height + plan.y) / (plan.height - plan.y), 1, 3);
        orthographic.set(near / near - far,                               2, 3);
        orthographic.set(1.0,                                             3, 3);

        return orthographic;
    }

    template<typename T>
    Matrix4<T> Matrix4<T>::makeLookAt(const Vector3<T>& eye, const Vector3<T>& target, const Vector3<T> up)
    {
        Matrix4<T> lookAt;
        Vector3<T> f = Vector3<T>::normalize(target - eye);
        Vector3<T> s = Vector3<T>::normalize(f.crossProduct(up));
        Vector3<T> u = s.crossProduct(f);

        lookAt.setColumn(Vector4<T>(s, -s.dotProduct(eye)), 0);
        lookAt.setColumn(Vector4<T>(u, -u.dotProduct(eye)), 1);
        lookAt.setColumn(Vector4<T>(f, -f.dotProduct(eye)), 2);
        lookAt.setColumn(Vector4<T>(0, 0, 0, 1), 3);

        return lookAt;
    }

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
    void Matrix4<T>::set(T value, std::size_t x, std::size_t y)
    {
        if(x >= 4 || y >= 4)
        {
            throw std::out_of_range("Requested value out of range");
        }

        m_data[y * 4 + x] = static_cast<T>(value);
    }

    template<typename T>
    void Matrix4<T>::set(const std::array<T, 16>& data)
    {
        m_data = data;
    }

    template<typename T>
    T Matrix4<T>::get(std::size_t x, std::size_t y) const
    {
        return m_data[y * 4 + x];
    }

    template<typename T>
    Matrix4<T>& Matrix4<T>::setColumn(const Vector4<T>& column, std::size_t position)
    {
        if(position >= 4)
        {
            throw std::out_of_range("Requested column out of range");
        }

        set(column.x, position, 0);
        set(column.y, position, 1);
        set(column.z, position, 2);
        set(column.w, position, 3);

        return (*this);
    }

    template<typename T>
    std::array<T, 4> Matrix4<T>::getColumn(std::size_t column) const
    {
        if(column >= 4)
        {
            throw std::out_of_range("Requested column out of range");
        }

        std::array<T, 4> col;

        for(std::size_t i = 0; i < 4; i++)
        {
            col[i] = get(column, i);
        }

        return col;
    }

    template<typename T>
    std::array<T, 4> Matrix4<T>::getRow(std::size_t row) const
    {
        if(row >= 4)
        {
            throw std::out_of_range("Requested row out of range");
        }

        std::array<T, 4> r;

        for(std::size_t i = 0; i < 4; i++)
        {
            r[i] = get(i, row);
        }

        return r;
    }

    template<typename T>
    T& Matrix4<T>::operator()(std::size_t x, std::size_t y)
    {
        if(x >= 4 || y >= 4)
        {
            throw std::out_of_range("Requested value out of range");
        }

        return m_data[y * 4 + x];
    }

    template<typename T>
    const T& Matrix4<T>::operator()(std::size_t x, std::size_t y) const
    {
        if(x >= 4 || y >= 4)
        {
            throw std::out_of_range("Requested value out of range");
        }

        return m_data[y * 4 + x];
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
        for(std::size_t i = 0; i < 16; i++)
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
        for(std::size_t i = 0; i < 16; i++)
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

        for(std::size_t i = 0; i < 16; i++)
        {
            T sum = 0;
            std::array<T, 4> row, col;

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
