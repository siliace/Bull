#ifndef Bull_Vector3_hpp
#define Bull_Vector3_hpp

#include <cmath>

#include <Bull/Core/System/Export.hpp>

#include <Bull/Math/Vector/Vector2.hpp>

namespace Bull
{
    template<typename TComponent>
    struct BULL_API Vector3
    {
        /*! \brief Calculate the dot(scalar) product of two Vector3
         *
         * \param left  The left Vector3 of the product
         * \param right The right Vector3 of the product
         *
         * \return The value of the dot product of left and right
         *
         */
        static TComponent dotProduct(const Vector3& left, const Vector3& right);

        /*! \brief Default constructor
         *
         */
        Vector3();

        /*! \brief Constructor
         *
         * \param value The value of all components
         *
         */
        Vector3(TComponent value);

        /*! \brief Constructor
         *
         * \param x The x component
         * \param y The y component
         * \param z The z component
         *
         */
        Vector3(TComponent x, TComponent y, TComponent z);

        /*! \brief Constructor
         *
         * \param copy The vector to copy
         * \param z The z component
         *
         */
        Vector3(const Vector2<TComponent>& copy, TComponent z = 0);

        /*! \brief Compute the length
         *
         * \return Return the length of the vector
         *
         */
        float getLength() const;

        /*! \brief Calculate the dot(scalar) product of two vectors
         *
         * \param right The other to calculate the dot product with
         *
         * \return The value of the dot product
         *
         */
        TComponent dotProduct(const Vector3& right);

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

        TComponent x, y, z;
    };

    /*! \brief Addition two Vector3
     *
     * \param left  The vector to add to right
     * \param right The vector to add to left
     *
     * \return Return a vector resulting of an addition of this and right
     *
     */
    template<typename TComponent>
    Vector3<TComponent> operator+(const Vector3<TComponent>& left, const Vector3<TComponent>& right);

    /*! \brief Addition two Vector3
     *
     * \param left  The number to add to right
     * \param right The vector to add to left
     *
     * \return Return a vector resulting of an addition of this and right
     *
     */
    template<typename TComponent>
    Vector3<TComponent> operator+(float left, const Vector3<TComponent>& right);

    /*! \brief Addition two Vector3
     *
     * \param left  The vector to add to right
     * \param right The number to add to left
     *
     * \return Return a vector resulting of an addition of this and right
     *
     */
    template<typename TComponent>
    Vector3<TComponent> operator+(const Vector3<TComponent>& left, float right);

    /*! \brief Subtract two Vector3
     *
     * \param left  The vector to subtract to right
     * \param right The vector to subtract to left
     *
     * \return Return a vector resulting of a subtraction of this and right
     *
     */
    template<typename TComponent>
    Vector3<TComponent> operator-(const Vector3<TComponent>& left, const Vector3<TComponent>& right);

    /*! \brief Subtract two Vector3
     *
     * \param left  The number to subtract to right
     * \param right The vector to subtract to left
     *
     * \return Return a vector resulting of an addition of this and right
     *
     */
    template<typename TComponent>
    Vector3<TComponent> operator-(float left, const Vector3<TComponent>& right);

    /*! \brief Subtract two Vector3
     *
     * \param left  The vector to subtract to right
     * \param right The number to subtract to left
     *
     * \return Return a vector resulting of an addition of this and right
     *
     */
    template<typename TComponent>
    Vector3<TComponent> operator-(const Vector3<TComponent>& left, float right);

    typedef Vector3<float> Vector3F;
    typedef Vector3<int> Vector3I;
    typedef Vector3<unsigned int> Vector3UI;
}

#include <Bull/Math/Vector/Vector3.inl>

#endif // Bull_Vector3_hpp
