#ifndef BULL_QUATERNION_HPP
#define BULL_QUATERNION_HPP

#include <cmath>

namespace Bull
{
    template <typename T>
    class EulerAngles;

    /*! \class Quaternion
     * \brief Implement 3D rotations with Quaternion
     *
     * @tparam T
     */
    template <typename T>
    struct Quaternion
    {
        /*! \brief Compute the conjugate of the Quaternions
         *
         * @param left  The left Quaternion
         * @param right The right Quaternion
         *
         * @return The conjugate
         *
         */
        static Quaternion<T> conjugate(const Quaternion<T>& left, const Quaternion<T>& right);

        /*! \brief Default constructor
         *
         */
        Quaternion();

        /*! \brief Constructor
         *
         * @param angles Angles to compute as the Quaternion
         *
         */
        Quaternion(const EulerAngles<T>& angles);

        /*! \brief Constructor
         *
         * @param w The w value of the Quaternion
         * @param x The x value of the Quaternion
         * @param y The y value of the Quaternion
         * @param z The z value of the Quaternion
         */
        Quaternion(T w, T x, T y, T z);

        /*! \brief Set the Quaternion
         *
         * @param angles Angles to compute as the Quaternion
         *
         * @return This
         *
         */
        Quaternion& set(const EulerAngles<T>& angles);

        /*! \brief Set the Quaternion
         *
         * @param w The w value of the Quaternion
         * @param x The x value of the Quaternion
         * @param y The y value of the Quaternion
         * @param z The z value of the Quaternion
         *
         * @return This
         *
         */
        Quaternion& set(T w, T x, T y, T z);

        /*! \brief Set the Quaternion
         *
         * @param quaternion The Quaternion to copy
         *
         * @return This
         *
         */
        Quaternion<T>& set(const Quaternion& quaternion);

        /*! \brief Get the length of the Quaternion
         *
         * @return The length
         *
         */
        float getLength() const;

        /*! \brief Get the square root of the length
         *
         * @return The square root of the length
         *
         */
        float getSquareRootLength() const;

        /*! \brief Normalize the Quaternion
         *
         * @return This
         *
         */
        Quaternion<T>& normalize();

        /*! \brief Get the conjugate of a Quaternion with another one
         *
         * \param quaternion The quaternion to conjugate to this
         *
         * @return The conjugate of quaternion with this
         *
         */
        Quaternion<T>& conjugate(const Quaternion<T>& quaternion);

        /*! \brief Convert the Quaternion as an EulerAngle
         *
         * @return The EulerAngles
         *
         */
        EulerAngles<T> toEulerAngles() const;

        /*! \brief Compare two Quaternions
         *
         * @param right The Quaternion to compare to this
         *
         * @return True if right and this are equal
         *
         */
        bool operator==(const Quaternion<T>& right) const;

        /*! \brief Compare two Quaternions
         *
         * @param right The Quaternion to compare to this
         *
         * @return True if right and this are not equal
         *
         */
        bool operator!=(const Quaternion<T>& right) const;

        T w, x, y, z;
    };

    typedef Quaternion<int> QuaternionI;
    typedef Quaternion<float> QuaternionF;
    typedef Quaternion<double> QuaternionD;
    typedef Quaternion<unsigned int> QuaternionUI;
}

#include <Bull/Math/Quaternion.inl>

#endif // BULL_QUATERNION_HPP
