#ifndef BULL_QUATERNION_HPP
#define BULL_QUATERNION_HPP

#include <cmath>

#include <Bull/Math/Vector/Vector3.hpp>

namespace Bull
{
    template <typename T>
    class EulerAngles;

    template <typename T>
    class Angle;

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
        static Quaternion<T> conjugate(const Quaternion<T>& quaternion)
        {
            return Quaternion<T>(quaternion).conjugate();
        }

        /*! \brief Normalize a Quaternion
         *
         * \param quaternion The Quaternion to normalize
         *
         * \return The normalized Quaternion
         *
         */
        static Quaternion<T> normalize(const Quaternion<T>& quaternion)
        {
            return Quaternion<T>(quaternion).normalize();
        }

        /*! \brief Create a quaternion from three angles
         *
         * \param roll  The roll Angle
         * \param pitch The pitch Angle
         * \param yaw   The yaw Angle
         *
         * \return The created Quaternion
         *
         */
        static Quaternion<T> fromEulerAngles(const Angle<T>& roll, const Angle<T>& pitch, const Angle<T>& yaw)
        {
            return Quaternion<T>(EulerAngles<T>(roll, pitch, yaw));
        }

        /*! \brief Default constructor
         *
         */
        Quaternion() :
            Quaternion<T>(0, 0, 0, 0)
        {
            /// Nothing
        }

        /*! \brief Constructor
         *
         * \param w The w value of the Quaternion
         * \param x The x value of the Quaternion
         * \param y The y value of the Quaternion
         * \param z The z value of the Quaternion
         */
        Quaternion(T w, T x, T y, T z) :
            w(w),
            x(x),
            y(y),
            z(z)
        {
            /// Nothing
        }

        /*! \brief Constructor
         *
         * \param angles Angles to compute as the Quaternion
         *
         */
        explicit Quaternion(const EulerAngles<T>& angles)
        {
            T cy = std::cos(angles.yaw   * static_cast<T>(0.5));
            T sy = std::sin(angles.yaw   * static_cast<T>(0.5));
            T cr = std::cos(angles.roll  * static_cast<T>(0.5));
            T sr = std::sin(angles.roll  * static_cast<T>(0.5));
            T cp = std::cos(angles.pitch * static_cast<T>(0.5));
            T sp = std::sin(angles.pitch * static_cast<T>(0.5));

            w = cy * cr * cp + sy * sr * sp;
            x = cy * sr * cp - sy * cr * sp;
            y = cy * cr * sp + sy * sr * cp;
            z = sy * cr * cp - cy * sr * sp;
        }

        /*! \brief Get the length of the Quaternion
         *
         * \return The length
         *
         */
        float getLength() const
        {
            return std::pow(w, 2) + std::pow(x, 2) + std::pow(y, 2) + std::pow(z, 2);
        }

        /*! \brief Get the square root of the length
         *
         * \return The square root of the length
         *
         */
        float getSquareRootLength() const
        {
            return std::sqrt(getLength());
        }

        /*! \brief Normalize the Quaternion
         *
         * \return This
         *
         */
        Quaternion<T>& normalize()
        {
            T n = Quaternion<T>::getSquareRootLength();

            w /= n;
            x /= n;
            y /= n;
            z /= n;

            return (*this);
        }

        /*! \brief Get the conjugate of the Quaternion
         *
         * \return The conjugate
         *
         */
        Quaternion<T>& conjugate()
        {
            x = -x;
            y = -y;
            z = -z;

            return (*this);
        }

        /*! \brief Compare two Quaternions
         *
         * \param right The Quaternion to compare to this
         *
         * \return True if right and this are equal
         *
         */
        bool operator==(const Quaternion<T>& right) const
        {
            return w == right.w &&
                   x == right.x &&
                   y == right.y &&
                   z == right.z;
        }

        /*! \brief Compare two Quaternions
         *
         * \param right The Quaternion to compare to this
         *
         * \return True if right and this are not equal
         *
         */
        bool operator!=(const Quaternion<T>& right) const
        {
            return !((*this) == right);
        }

        /*! \brief Multiply the Quaternion with a scalar. Scale the Quaternion by the scalar
         *
         * \param scale The scalar to multiply to this
         *
         * \return The scaled Quaternion
         */
        Quaternion<T> operator*(T scale)
        {
            return Quaternion<T>(w * scale,
                                 x * scale,
                                 y * scale,
                                 z * scale);
        }

        /*! \brief Multiply the Quaternion with a Vector3
         *
         * \param right The Vector3 to multiply to this
         *
         * \return The product of this and right
         *
         */
        Vector3<T> operator*(const Vector3<T>& right)
        {
            Vector3<T> quaternionVector(x, y, z);
            Vector3<T> uv  = Vector3<T>::crossProduct(quaternionVector, right);
            Vector3<T> uuv = Vector3<T>::crossProduct(quaternionVector, uv);

            uv  *= 2 * w;
            uuv *= 2;

            return right + uv + uuv;
        }

        T w, x, y, z;
    };

    typedef Quaternion<int> QuaternionI;
    typedef Quaternion<float> QuaternionF;
    typedef Quaternion<double> QuaternionD;
    typedef Quaternion<unsigned int> QuaternionUI;
}

#endif // BULL_QUATERNION_HPP
