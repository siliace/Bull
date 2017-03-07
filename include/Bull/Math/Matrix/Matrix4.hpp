#ifndef Bull_Matrix4_hpp
#define Bull_Matrix4_hpp

#include <array>

#include <Bull/Core/System/Export.hpp>

#include <Bull/Math/Angle.hpp>
#include <Bull/Math/EulerAngles.hpp>
#include <Bull/Math/Quaternion.hpp>
#include <Bull/Math/Vector/Vector4.hpp>

namespace Bull
{
    template<typename T>
    class BULL_API Matrix4
    {
    public:

        /*! \brief Create an identity matrix
         *
         * \return Return the matrix
         *
         */
        static Matrix4<T> createIdentity();

        /*! \brief Create a translation matrix
         *
         * \param x The translation value on x axis
         * \param y The translation value on y axis
         * \param z The translation value on z axis
         *
         * \return Return the matrix
         *
         */
        template<typename U>
        static Matrix4<T> createTranslation(U x, U y, U z);

        /*! \brief Create a scale matrix
         *
         * \param x The scale value on x axis
         * \param y The scale value on y axis
         * \param z The scale value on z axis
         *
         * \return Return the matrix
         *
         */
        template<typename U>
        static Matrix4<T> createScale(U x, U y, U z);

        /*! \brief Create a rotation matrix
         *
         * \param x The rotation on the x axis
         * \param y The rotation on the y axis
         * \param z The rotation on the z axis
         *
         * \return Return the matrix
         *
         */
        template<typename U>
        static Matrix4<T> createRotation(U x, U y, U z);

        /*! \brief Create a rotation matrix
         *
         * \param angles Angles of rotations
         *
         * \return Return the matrix
         *
         */
        template<typename U>
        static Matrix4<T> createRotation(const EulerAngles<U>& angles);

        /*! \brief Create a rotation matrix
         *
         * \param quaternion The quaternion representing a rotation
         *
         * \return Return the matrix
         *
         */
        template<typename U>
        static Matrix4<T> createRotation(const Quaternion<U>& quaternion);

        /*! \brief Create an orthographic matrix
         *
         * \param left   The distance between center and left
         * \param right  The distance between center and right
         * \param top    The distance between center and top
         * \param bottom The distance between center and bottom
         * \param zNear  The distance where vision begins
         * \param zFar   The distance where vision ends
         *
         * \return Return the created matrix
         *
         */
        template<typename U>
        static Matrix4<T> createOrtho(U left, U right, U top, U bottom, U zNear, U zfar);

        /*! \brief Create a perspective matrix
         *
         * \param angle The angle of the perspective
         * \param ratio The rendering ratio (16/9, 4/3, 16/10...)
         * \param zNear The distance where vision begins
         * \param zFar  The distance where vision ends
         *
         * \return Return the created matrix
         *
         */
        template<typename U>
        static Matrix4<T> createPersperctive(const Angle<U>& angle, U ratio, U zNear, U zFar);

    public:

        /*! \brief Default Constructor
         *
         */
        Matrix4();

        /*! \brief Constructor
         *
         * \param value The value of every matrix cell
         *
         */
        template<typename U>
        Matrix4(U value);

        /*! \brief Constructor
         *
         * \param data The matrix content
         *
         */
        template<typename U>
        Matrix4(const std::array<U, 16>& data);

        /*! \brief Set the matrix content
         *
         * \param value The value of every matrix cell
         *
         */
        template<typename U>
        void set(U value);

        /*! \brief The value of a cell of the matrix
         *
         * \param value The value to set
         * \param x     The abscissa of the cell in the matrix
         * \param y     The ordinate of the cell in the matrix
         *
         */
        template<typename U>
        void set(U value, std::size_t x, std::size_t y);

        /*! \brief Set the matrix content
         *
         * \param data The matrix content
         *
         */
        template<typename U>
        void set(const std::array<U, 16>& data);

        /*! \brief Get the value of a cell of the matrix
         *
         * \param x The abscissa of the cell to get in the matrix
         * \param y The ordinate of the cell to get in the matrix
         *
         * \return Return the value
         *
         */
        T get(std::size_t x, std::size_t y) const;

        /*! \brief Get a column a the matrix
         *
         * \param column The column to get
         *
         * \return Return the column
         *
         */
        std::array<T, 4> getColumn(std::size_t column) const;

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
        template<typename U>
        bool operator==(const Matrix4<U>& right);

        /*! \brief Compare two matrices
         *
         * \param right The matrix to compare to this
         *
         * \return Return true if the two matrices are not equal, false otherwise
         *
         */
        template<typename U>
        bool operator!=(const Matrix4<U>& right);

        /*! \brief Addition two matrices
         *
         * \param right
         *
         * \return Return the sum the addition of right and this
         *
         */
        template<typename U>
        Matrix4<T>& operator+=(const Matrix4<U>& right);

        /*! \brief Addition two matrices
         *
         * \param right
         *
         * \return Return the sum of the addition between right and this
         *
         */
        template<typename U>
        Matrix4<T>& operator+=(U right);

        /*! \brief Subtract two matrices
         *
         * \param right
         *
         * \return Return the difference of the subtraction between right and this
         *
         */
        template<typename U>
        Matrix4<T>& operator-=(const Matrix4<U>& right);

        /*! \brief Subtract a matrix with a scalar
         *
         * \param right
         *
         * \return Return the difference the subtraction between right and this
         *
         */
        template<typename U>
        Matrix4<T>& operator-=(U right);

        /*! \brief Multiply two matrices
         *
         * \param right
         *
         * \return Return the product of the multiplication between right and this
         *
         */
        template<typename U>
        Matrix4<T> operator*=(const Matrix4<U>& right);

        /*! \brief Get a pointer to the internal data
         *
         * \return Return the pointer
         *
         */
        operator const T*() const;

    private:

        std::array<T, 16> m_data;
    };

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

#endif // Bull_Matrix4_hpp
