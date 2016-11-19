#ifndef Bull_Matrix_hpp
#define Bull_Matrix_hpp

#include <array>
#include <functional>

namespace Bull
{
    template<typename T, std::size_t W, std::size_t H>
    class Matrix
    {
    public:

        static constexpr std::size_t Width = W;

        static constexpr std::size_t Height = H;

        /*! \brief Create an identity matrix
         *
         * \return Return the matrix
         *
         */
        static Matrix<T, W, H> createIdentity();

        /*! \brief Create a translation matrix
         *
         * \param x The translation value on x axis
         * \param y The translation value on y axis
         * \param z The translation value on z axis
         *
         * \return Return the matrix
         *
         */
        static Matrix<T, 4, 4> createTranslation(T x, T y, T z);

        /*! \brief Create a scale matrix
         *
         * \param x The scale value on x axis
         * \param y The scale value on y axis
         * \param z The scale value on z axis
         *
         * \return Return the matrix
         *
         */
        static Matrix<T, 4, 4> createScale(T x, T y, T z);

    public:

        /*! \brief Default Constructor
         *
         */
        Matrix();

        /*! \brief Constructor
         *
         * \param value The value of every matrix cell
         *
         */
        Matrix(T value);

        /*! \brief Constructor
         *
         * \param data The matrix content
         *
         */
        Matrix(const std::array<T, W * H>& data);

        /*! \brief Set the matrix content
         *
         * \param value The value of every matrix cell
         *
         */
        void set(T value);

        /*! \brief The value of a cell of the matrix
         *
         * \param value The value to set
         * \param x     The abscissa of the cell in the matrix
         * \param y     The ordinate of the cell in the matrix
         *
         */
        void set(T value, std::size_t x, std::size_t y);

        /*! \brief Set the matrix content
         *
         * \param data The matrix content
         *
         */
        void set(const std::array<T, W * H>& data);

        /*! \brief Get the value of a cell of the matrix
         *
         * \param x The abscissa of the cell to get in the matrix
         * \param y The ordinate of the cell to get in the matrix
         *
         * \return Return the value
         *
         */
        T get(std::size_t x, std::size_t y) const;

        /*! \brief Get the width of the matrix
         *
         * \return Return the width
         *
         */
        std::size_t getWidth() const;

        /*! \brief Get the height of the matrix
         *
         * \return Return the height
         *
         */
        std::size_t getHeight() const;

        /*! \brief Get the length of the matrix
         *
         * \return Return the length
         *
         */
        std::size_t getLength() const;

        /*! \brief Get a pointer to the internal data
         *
         * \return Return the pointer
         *
         */
        operator const T*() const;

    private:

        std::array<T, W * H> m_data;
    };

    typedef Matrix<int, 1, 2> Matrix12I;
    typedef Matrix<float, 1, 2> Matrix12F;
    typedef Matrix<unsigned int, 1, 2> Matrix12UI;

    typedef Matrix<int, 1, 3> Matrix13I;
    typedef Matrix<float, 1, 3> Matrix13F;
    typedef Matrix<unsigned int, 1, 3> Matrix13UI;

    typedef Matrix<int, 1, 4> Matrix14I;
    typedef Matrix<float, 1, 4> Matrix14F;
    typedef Matrix<unsigned int, 1, 4> Matrix14UI;

    typedef Matrix<int, 2, 2> Matrix2I;
    typedef Matrix<float, 2, 2> Matrix2F;
    typedef Matrix<unsigned int, 2, 2> Matrix2UI;

    typedef Matrix<int, 3, 3> Matrix3I;
    typedef Matrix<float, 3, 3> Matrix3F;
    typedef Matrix<unsigned int, 3, 3> Matrix3UI;

    typedef Matrix<int, 4, 4> Matrix4I;
    typedef Matrix<float, 4, 4> Matrix4F;
    typedef Matrix<unsigned int, 4, 4> Matrix4UI;
}

#include <Bull/Math/Matrix.inl>

#endif // Bull_Matrix_hpp
