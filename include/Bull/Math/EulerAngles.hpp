#ifndef BULL_EULERANGLES_HPP
#define BULL_EULERANGLES_HPP

#include <Bull/Math/Angle.hpp>

namespace Bull
{
    template <typename T>
    class Quaternion;

    /*! \class EulerAngles
     * \brief Implement 3D rotation with EulerAngles
     *
     * @tparam T The type of angles values
     */
    template <typename T>
    struct EulerAngles
    {
        /*! \brief Default constructor
         *
         */
        EulerAngles();

        /*! \brief Constructor
         *
         * @param quaternion The Quaternion to compute as an EulerAngles
         *
         */
        EulerAngles(const Quaternion<T>& quaternion);

        /*! \brief Constructor
         *
         * @param roll  The roll of the EulerAngles
         * @param pitch the pitch of the EulerAngles
         * @param yaw   the yaw of the EulerAngles
         *
         */
        EulerAngles(const Angle<T>& roll, const Angle<T>& pitch, const Angle<T>& yaw);

        /*! \brief Set the EulerAngles
         *
         * @param copy The EulerAngles to copy
         *
         * @return This
         *
         */
        EulerAngles<T>& set(const EulerAngles<T>& copy);

        /*! \brief Set the EulerAngles
         *
         * @param quaternion The Quaternion to compute as an EulerAngles
         *
         * @return This
         *
         */
        EulerAngles<T>& set(const Quaternion<T>& quaternion);

        /*! \brief Set the EulerAngles
         *
         * @param roll  The roll of the angle
         * @param pitch the pitch of the angle
         * @param yaw   the yaw of the angle
         *
         * @return This
         *
         */
        EulerAngles<T>& set(const Angle<T>& roll, const Angle<T>& pitch, const Angle<T>& yaw);

        /*! \brief Normalize the angle of each rotation
         *
         * @return This
         *
         */
        EulerAngles<T>& normalize();

        /*! \brief Convert the EulerAngles as a Quaternion
         *
         * @return The Quaternion
         *
         */
        Quaternion<T> toQuaternion() const;

        /*! \brief Compare two EulerAngles
         *
         * @param right The EulerAngles to compare
         *
         * @return True if right and this are equal
         *
         */
        bool operator==(const EulerAngles<T>& right);

        /*! \brief Compare two EulerAngles
         *
         * @param right The EulerAngles to compare
         *
         * @return True if right and this are not equal
         *
         */
        bool operator!=(const EulerAngles<T>& right);

        Angle<T> roll;  /*!< The rotation around the X axis */
        Angle<T> pitch; /*!< The rotation around the Y axis */
        Angle<T> yaw;   /*!< The rotation around the Z axis */
    };

    typedef EulerAngles<int> EulerAnglesI;
    typedef EulerAngles<float> EulerAnglesF;
    typedef EulerAngles<double> EulerAnglesD;
    typedef EulerAngles<unsigned int> EulerAnglesUI;
}

#include <Bull/Math/EulerAngles.inl>

#endif //BULL_EULERANGLES_HPP
