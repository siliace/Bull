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
    Matrix<T, 4, 4> createTranslation(T x, T y, T z)
    {

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
    Matrix<T, 4, 4> createScale(T x, T y, T z)
    {

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
