#ifndef BULL_EULERANGLES_HPP
#define BULL_EULERANGLES_HPP

#include <Bull/Math/Angle.hpp>

namespace Bull
{
    template <typename T>
    struct EulerAngles
    {
        /*! \brief Default constructor
         *
         */
        EulerAngles();

        /*! \brief Copy constructor
         *
         * @param copy The EulerAngles to copy
         *
         */
        EulerAngles(const EulerAngles<T>& copy);

        /*! \brief Constructor
         *
         * @param roll  The roll of the angle
         * @param pitch the pitch of the angle
         * @param yaw   the yaw of the angle
         *
         */
        EulerAngles(const Angle<T>& roll, const Angle<T>& pitch, const Angle<T>& yaw);

        /*! \brief Basic assignment operator
         *
         * @param copy The EulerAngles to copy
         *
         * @return This
         *
         */
        EulerAngles<T>& operator=(const EulerAngles<T>& copy);

        /*! \brief Set the angle
         *
         * @param copy The EulerAngles to copy
         *
         * @return This
         *
         */
        EulerAngles<T>& set(const EulerAngles<T>& copy);

        /*! \brief Set the angle
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

        Angle<T> roll, pitch, yaw;
    };

    typedef EulerAngles<int> EulerAnglesI;
    typedef EulerAngles<float> EulerAnglesF;
    typedef EulerAngles<double> EulerAnglesD;
    typedef EulerAngles<unsigned int> EulerAnglesUI;
}

#include <Bull/Math/EulerAngles.inl>

#endif //BULL_EULERANGLES_HPP
