#ifndef Bull_Vector3_hpp
#define Bull_Vector3_hpp

#include <cmath>

#include <Bull/Core/System/Export.hpp>

#include <Bull/Math/Vector/Vector2.hpp>

namespace Bull
{
    template<typename T>
    struct BULL_API Vector3
    {
        static constexpr Vector3<T> Zero = {0.0, 0.0, 0.0};

        static constexpr Vector3<T> Unit  = {1.0, 1.0, 1.0};
        static constexpr Vector3<T> UnitX = {1.0, 0.0, 0.0};
        static constexpr Vector3<T> UnitY = {0.0, 1.0, 0.0};
        static constexpr Vector3<T> UnitZ = {0.0, 0.0, 1.0};

        static constexpr Vector3<T> Left  = {1.0, 0.0, 0.0};
        static constexpr Vector3<T> Right = {-1.0, 0.0, 0.0};

        static constexpr Vector3<T> Up    = {0.0, 1.0, 0.0};
        static constexpr Vector3<T> Down  = {0.0, -1.0, 0.0};

        static constexpr Vector3<T> Forward  = {0.0, 0.0, 1.0};
        static constexpr Vector3<T> Backward = {0.0, 0.0, -1.0};

        /*! \brief Get a normalized Vector3
         *
         * \param vector The Vector3 to normalize
         *
         * \return The normalized Vector3
         *
         */
        static Vector3<T> normalize(const Vector3<T>& vector);

        /*! \brief Calculate the dot(scalar) product of two Vector3
         *
         * \param left  The left Vector3 of the product
         * \param right The right Vector3 of the product
         *
         * \return The value of the dot product of left and right
         *
         */
        static T dotProduct(const Vector3& left, const Vector3& right);

        /*! \brief Default constructor
         *
         */
        Vector3();

        /*! \brief Constructor
         *
         * \param value The value of all components
         *
         */
        Vector3(T value);

        /*! \brief Constructor
         *
         * \param x The x component
         * \param y The y component
         * \param z The z component
         *
         */
        Vector3(T x, T y, T z);

        /*! \brief Constructor
         *
         * \param copy The vector to copy
         * \param z The z component
         *
         */
        Vector3(const Vector2<T>& copy, T z = 0);

        /*! \brief Compute the length
         *
         * \return Return the length of the vector
         *
         */
        float getLength() const;

        /*! \brief Normalize the Vector3
         *
         * \return This
         *
         */
        Vector3<T>& normalize();

        /*! \brief Calculate the dot(scalar) product of two vectors
         *
         * \param right The other to calculate the dot product with
         *
         * \return The value of the dot product
         *
         */
        T dotProduct(const Vector3& right);

        /*! \brief == operator override
         *
         * \param right The vector to compare
         *
         * \return Return true if this and right are equal, else return false
         *
         */
        bool operator==(const Vector3& right) const;

        /*! \brief != operator override
         *
         * \param right The vector to compare
         *
         * \return Return true if this and right are not equal, else return false
         *
         */
        bool operator!=(const Vector3& right) const;

        /*! \brief += operator override
         *
         * \param right The vector to add
         *
         * \return Return this after addition
         *
         */
        Vector3& operator+=(const Vector3& right);

        /*! \brief Negation operator
         *
         * \return Return the opposite of this Vector
         *
         */
        Vector3 operator-() const;

        /*! \brief -= operator override
         *
         * \param right The vector to subtract
         *
         * \return Return this after subtraction
         *
         */
        Vector3& operator-=(const Vector3& right);

        T x, y, z;
    };

    /*! \brief Addition two Vector3
     *
     * \param left  The vector to add to right
     * \param right The vector to add to left
     *
     * \return Return a vector resulting of an addition of this and right
     *
     */
    template<typename T>
    Vector3<T> operator+(const Vector3<T>& left, const Vector3<T>& right);

    /*! \brief Addition two Vector3
     *
     * \param left  The number to add to right
     * \param right The vector to add to left
     *
     * \return Return a vector resulting of an addition of this and right
     *
     */
    template<typename T>
    Vector3<T> operator+(float left, const Vector3<T>& right);

    /*! \brief Addition two Vector3
     *
     * \param left  The vector to add to right
     * \param right The number to add to left
     *
     * \return Return a vector resulting of an addition of this and right
     *
     */
    template<typename T>
    Vector3<T> operator+(const Vector3<T>& left, float right);

    /*! \brief Subtract two Vector3
     *
     * \param left  The vector to subtract to right
     * \param right The vector to subtract to left
     *
     * \return Return a vector resulting of a subtraction of this and right
     *
     */
    template<typename T>
    Vector3<T> operator-(const Vector3<T>& left, const Vector3<T>& right);

    /*! \brief Subtract two Vector3
     *
     * \param left  The number to subtract to right
     * \param right The vector to subtract to left
     *
     * \return Return a vector resulting of an addition of this and right
     *
     */
    template<typename T>
    Vector3<T> operator-(float left, const Vector3<T>& right);

    /*! \brief Subtract two Vector3
     *
     * \param left  The vector to subtract to right
     * \param right The number to subtract to left
     *
     * \return Return a vector resulting of an addition of this and right
     *
     */
    template<typename T>
    Vector3<T> operator-(const Vector3<T>& left, float right);

    typedef Vector3<int> Vector3I;
    typedef Vector3<float> Vector3F;
    typedef Vector3<double> Vector3D;
    typedef Vector3<unsigned int> Vector3UI;
}

#include <Bull/Math/Vector/Vector3.inl>

#endif // Bull_Vector3_hpp
