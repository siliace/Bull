namespace Bull
{
    /*! \brief Create an identity matrix
     *
     * \return Return the matrix
     *
     */
    template<typename T, std::size_t W, std::size_t H>
    Matrix<T, W, H> Matrix<T, W, H>::createIdentity()
    {
        static_assert(Matrix<T, W, H>::Width == Matrix<T, W, H>::Height, "Identity matrix can be used only with squares matrices");

        Matrix<T, W, H> identity;

        for(std::size_t i = 0; i < Matrix<T, W, H>::Width; i++)
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
    template<typename T, std::size_t W, std::size_t H>
    Matrix<T, 4, 4> Matrix<T, W, H>::createTranslation(T x, T y, T z)
    {
        Matrix<T, 4, 4> translation = Matrix<T, 4, 4>::createIdentity();

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
    template<typename T, std::size_t W, std::size_t H>
    Matrix<T, 4, 4> Matrix<T, W, H>::createScale(T x, T y, T z)
    {
        Matrix<T, 4, 4> scale;

        scale.set(x, 0, 0);
        scale.set(y, 1, 1);
        scale.set(z, 2, 2);
        scale.set(1, 3, 3);

        return scale;
    }

    /*! \brief Default Constructor
     *
     */
    template<typename T, std::size_t W, std::size_t H>
    Matrix<T, W, H>::Matrix()
    {
        static_assert(std::is_arithmetic<T>::value, "T must be a numeric type");

        set(0);
    }

    /*! \brief Constructor
     *
     * \param value The value of every matrix cell
     *
     */
    template<typename T, std::size_t W, std::size_t H>
    Matrix<T, W, H>::Matrix(T value)
    {
        static_assert(std::is_arithmetic<T>::value, "T must be a numeric type");

        set(value);
    }

    /*! \brief Constructor
     *
     * \param data The matrix content
     *
     */
    template<typename T, std::size_t W, std::size_t H>    Matrix<T, W, H>::Matrix(const std::array<T, W * H>& data)
    {
        static_assert(std::is_arithmetic<T>::value, "T must be a numeric type");

        set(data);
    }

    /*! \brief Set the matrix content
     *
     * \param value The value of every matrix cell
     *
     */
    template<typename T, std::size_t W, std::size_t H>    void Matrix<T, W, H>::set(T value)
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
    template<typename T, std::size_t W, std::size_t H>
    void Matrix<T, W, H>::set(T value, std::size_t x, std::size_t y)
    {
        m_data[y * Matrix<T, W, H>::Width + x] = value;
    }

    /*! \brief Set the matrix content
     *
     * \param data The matrix content
     *
     */
    template<typename T, std::size_t W, std::size_t H>
    void Matrix<T, W, H>::set(const std::array<T, W * H>& data)
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
    template<typename T, std::size_t W, std::size_t H>
    T Matrix<T, W, H>::get(std::size_t x, std::size_t y) const
    {
        return m_data[y * Matrix<T, W, H>::Width + x];
    }

    /*! \brief Get the width of the matrix
     *
     * \return Return the width
     *
     */
    template<typename T, std::size_t W, std::size_t H>
    std::size_t Matrix<T, W, H>::getWidth() const
    {
        return Matrix<T, W, H>::Width;
    }

    /*! \brief Get the height of the matrix
     *
     * \return Return the height
     *
     */
    template<typename T, std::size_t W, std::size_t H>    std::size_t Matrix<T, W, H>::getHeight() const
    {
        return Matrix<T, W, H>::Height;
    }

    /*! \brief Get the length of the matrix
     *
     * \return Return the length
     *
     */
    template<typename T, std::size_t W, std::size_t H>
    std::size_t Matrix<T, W, H>::getLength() const
    {
        return m_data.size();
    }

    /*! \brief Get a column a the matrix
     *
     * \param column The column to get
     *
     * \return Return the column
     *
     */
    template<typename T, std::size_t W, std::size_t H>
    std::array<T, H> Matrix<T, W, H>::getColumn(std::size_t column) const
    {
        std::array<T, H> col;

        for(std::size_t i = 0; i < getHeight(); i++)
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
    template<typename T, std::size_t W, std::size_t H>    std::array<T, W> Matrix<T, W, H>::getRow(std::size_t row) const
    {
        std::array<T, W> r;

        for(std::size_t i = 0; i < getWidth(); i++)
        {
            r[i] = get(row, i);
        }

        return r;
    }

    /*! \brief Get a pointer to the internal data
     *
     * \return Return the pointer
     *
     */
    template<typename T, std::size_t W, std::size_t H>
    Matrix<T, W, H>::operator const T*() const
    {
        return &m_data[0];
    }
}
