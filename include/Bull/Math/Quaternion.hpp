#ifndef BULL_QUATERNION_HPP
#define BULL_QUATERNION_HPP

#include <cmath>

#include <Bull/Math/Vector/Vector3.hpp>

namespace Bull
{
    template <typename T>
    class EulerAngles;

    /*! \class Quaternion
     * \brief Implement 3D rotations with Quaternion
     *
     * \tparam T
     */
    template <typename T>
    struct Quaternion
    {
        /*! \brief Compute the conjugate of the Quaternion
         *
         * \param quaternion The Quaternion to get the conjugate
         *
         * \return The conjugate Quaternion
         *
         */
        static Quaternion<T> conjugate(const Quaternion<T>& quaternion);

        /*! \brief Create a quaternion from three angles
         *
         * \param roll  The roll Angle
         * \param pitch The pitch Angle
         * \param yaw   The yaw Angle
         *
         * \return The created Quaternion
         *
         */
        static Quaternion<T> fromEulerAngles(const Angle<T>& roll, const Angle<T>& pitch, const Angle<T>& yaw);

        /*! \brief Default constructor
         *
         */
        Quaternion();

        /*! \brief Constructor
         *
         * \param w The w value of the Quaternion
         * \param x The x value of the Quaternion
         * \param y The y value of the Quaternion
         * \param z The z value of the Quaternion
         */
        Quaternion(T w, T x, T y, T z);

        /*! \brief Constructor
         *
         * \param angles Angles to compute as the Quaternion
         *
         */
        Quaternion(const EulerAngles<T>& angles);

        /*! \brief Get the length of the Quaternion
         *
         * \return The length
         *
         */
        float getLength() const;

        /*! \brief Get the square root of the length
         *
         * \return The square root of the length
         *
         */
        float getSquareRootLength() const;

        /*! \brief Normalize the Quaternion
         *
         * \return This
         *
         */
        Quaternion<T>& normalize();

        /*! \brief Get the conjugate of the Quaternion
         *
         * \return The conjugate
         *
         */
        Quaternion<T>& conjugate();

        /*! \brief Compare two Quaternions
         *
         * \param right The Quaternion to compare to this
         *
         * \return True if right and this are equal
         *
         */
        bool operator==(const Quaternion<T>& right) const;

        /*! \brief Compare two Quaternions
         *
         * \param right The Quaternion to compare to this
         *
         * \return True if right and this are not equal
         *
         */
        bool operator!=(const Quaternion<T>& right) const;

        /*! \brief Multiply the Quaternion with a scalar. Scale the Quaternion by the scalar
         *
         * \param scale The scalar to multiply to this
         *
         * \return The scaled Quaternion
         */
        Quaternion<T> operator*(T scale);

        /*! \brief Multiply the Quaternion with a Vector3
         *
         * \param right The Vector3 to multiply to this
         *
         * \return The product of this and right
         *
         */
        Vector3<T> operator*(const Vector3<T>& vector);

        T w, x, y, z;
    };

    typedef Quaternion<int> QuaternionI;
    typedef Quaternion<float> QuaternionF;
    typedef Quaternion<double> QuaternionD;
    typedef Quaternion<unsigned int> QuaternionUI;
}

#include <Bull/Math/Quaternion.inl>

#endif // BULL_QUATERNION_HPP
