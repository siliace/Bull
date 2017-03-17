#ifndef BULL_EULERANGLES_HPP
#define BULL_EULERANGLES_HPP

#include <Bull/Math/Angle.hpp>

namespace Bull
{
    template <typename T>
    struct BULL_API EulerAngles
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
        template <typename U>
        EulerAngles(const EulerAngles<U>& copy);

        /*! \brief Constructor
         *
         * @param roll  The roll of the angle
         * @param pitch the pitch of the angle
         * @param yaw   the yaw of the angle
         *
         */
        template <typename U, typename V, typename W>
        EulerAngles(const Angle<U>& roll, const Angle<V>& pitch, const Angle<W>& yaw);

        /*! \brief Basic assignment operator
         *
         * @param copy The EulerAngles to copy
         *
         * @return This
         *
         */
        template <typename U>
        EulerAngles<T>& operator=(const EulerAngles<U>& copy);

        /*! \brief Set the angle
         *
         * @param copy The EulerAngles to copy
         *
         * @return This
         *
         */
        template <typename U>
        EulerAngles<T>& set(const EulerAngles<U>& copy);

        /*! \brief Set the angle
         *
         * @param roll  The roll of the angle
         * @param pitch the pitch of the angle
         * @param yaw   the yaw of the angle
         *
         * @return This
         *
         */
        template <typename U, typename V, typename W>
        EulerAngles<T>& set(const Angle<U>& roll, const Angle<V>& pitch, const Angle<W>& yaw);

        /*! \brief Compare two EulerAngles
         *
         * @param right The EulerAngles to compare
         *
         * @return True if right and this are equal
         *
         */
        template <typename U>
        bool operator==(const EulerAngles<U>& right);

        /*! \brief Compare two EulerAngles
         *
         * @param right The EulerAngles to compare
         *
         * @return True if right and this are not equal
         *
         */
        template <typename U>
        bool operator!=(const EulerAngles<U>& right);

        Angle<T> roll, pitch, yaw;
    };

    typedef EulerAngles<int> EulerAnglesI;
    typedef EulerAngles<float> EulerAnglesF;
    typedef EulerAngles<double> EulerAnglesF;
    typedef EulerAngles<unsigned int> EulerAnglesUI;
}

#include <Bull/Math/EulerAngles.inl>

#endif //BULL_EULERANGLES_HPP
