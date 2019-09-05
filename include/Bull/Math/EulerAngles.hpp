#ifndef BULL_EULERANGLES_HPP
#define BULL_EULERANGLES_HPP

#include <Bull/Math/Angle.hpp>
#include <Bull/Math/Quaternion.hpp>

namespace Bull
{
    /** \class EulerAngles
     *
     * \brief Implement 3D rotation with EulerAngles
     *
     * \tparam T The type of angles values
     *
     */
    template <typename T>
    class EulerAngles
    {
    public:

        static EulerAngles<T> Zero;

        /** \brief Normalize an EulerAngles
         *
         * \param angles EulerAngles to normalize
         *
         * \return The normalized EulerAngles
         *
         */
        static EulerAngles<T> normalize(const EulerAngles<T>& angles)
        {
            return EulerAngles<T>(angles).normalize();
        }

        /** \brief Create an EulerAngles with a rotation on the X axis
         *
         * \param angle The rotation
         *
         * \return The created EulerAngles
         *
         */
        static EulerAngles<T> onX(const Bull::Angle<T>& angle)
        {
            return EulerAngles<T>(angle);
        }

        /** \brief Create an EulerAngles with a rotation on the Y axis
         *
         * \param angle The rotation
         *
         * \return The created EulerAngles
         *
         */
        static EulerAngles<T> onY(const Bull::Angle<T>& angle)
        {
            return EulerAngles<T>(Angle<T>::Zero, angle);
        }

        /** \brief Create an EulerAngles with a rotation on the Z axis
         *
         * \param angle The rotation
         *
         * \return The created EulerAngles
         *
         */
        static EulerAngles<T> onZ(const Bull::Angle<T>& angle)
        {
            return EulerAngles<T>(Angle<T>::Zero, Angle<T>::Zero, angle);
        }

    public:

        /** \brief Constructor
         *
         * \param quaternion The Quaternion to compute as an EulerAngles
         *
         */
        explicit EulerAngles(const Quaternion<T>& quaternion)
        {
            set(quaternion);
        }

        /** \brief Constructor
         *
         * \param roll  The roll of the EulerAngles
         * \param pitch the pitch of the EulerAngles
         * \param yaw   the yaw of the EulerAngles
         *
         */
        explicit EulerAngles(const Angle<T>& roll = Angle<T>::Zero, const Angle<T>& pitch = Angle<T>::Zero, const Angle<T>& yaw = Angle<T>::Zero)
        {
            set(roll, pitch, yaw);
        }

        /** \brief Set the EulerAngles
         *
         * \param copy The EulerAngles to copy
         *
         * \return This
         *
         */
        EulerAngles<T>& set(const EulerAngles<T>& copy)
        {
            roll = copy.roll;
            pitch = copy.pitch;
            yaw = copy.yaw;

            return (*this);
        }

        /** \brief Set the EulerAngles
         *
         * \param quaternion The Quaternion to compute as an EulerAngles
         *
         * \return This
         *
         */
        EulerAngles<T>& set(const Quaternion<T>& quaternion)
        {
            EulerAngles<T> representation = quaternion.toEulerAngles();

            roll = representation.roll;
            pitch = representation.pitch;
            yaw = representation.yaw;

            return (*this);
        }

        /** \brief Set the EulerAngles
         *
         * \param roll  The roll of the angle
         * \param pitch the pitch of the angle
         * \param yaw   the yaw of the angle
         *
         * \return This
         *
         */
        EulerAngles<T>& set(const Angle<T>& roll, const Angle<T>& pitch, const Angle<T>& yaw)
        {
            this->roll = roll;
            this->pitch = pitch;
            this->yaw = yaw;

            return (*this);
        }

        /** \brief Normalize the angle of each rotation
         *
         * \return This
         *
         */
        EulerAngles<T>& normalize()
        {
            roll.normalize();
            pitch.normalize();
            yaw.normalize();

            return (*this);
        }

        /** \brief Convert the EulerAngles as a Quaternion
         *
         * \return The Quaternion
         *
         */
        Quaternion<T> toQuaternion() const
        {
            return Quaternion<T>((*this));
        }

        /** \brief Compare two EulerAngles
         *
         * \param right The EulerAngles to compare
         *
         * \return True if right and this are equal
         *
         */
        bool operator==(const EulerAngles<T>& right)
        {
            return (roll == right.roll) &&
                   (pitch == right.pitch) &&
                   (yaw == right.yaw);
        }

        /** \brief Compare two EulerAngles
         *
         * \param right The EulerAngles to compare
         *
         * \return True if right and this are not equal
         *
         */
        bool operator!=(const EulerAngles<T>& right)
        {
            return !((*this) == right);
        }

        /** \brief Addition two EulerAngles
         *
         * \param right The EulerAngles to addition to this
         *
         * \return This
         *
         */
        EulerAngles<T> operator+(const EulerAngles<T>& right) const
        {
            return EulerAngles<T>(*this) += right;
        }

        /** \brief Addition two EulerAngles
         *
         * \param right The EulerAngles to addition to this
         *
         * \return The sum of this and right
         *
         */
        EulerAngles<T>& operator+=(const EulerAngles<T>& right)
        {
            roll += right.roll;
            pitch += right.pitch;
            yaw += right.yaw;

            return (*this);
        }

        /** \brief Subtract two EulerAngles
         *
         * \param right The EulerAngles to subtract to this
         *
         * \return This
         *
         */
        EulerAngles<T> operator-(const EulerAngles<T>& right) const
        {
            return EulerAngles<T>((*this)) -= right;
        }

        /** \brief Addition two EulerAngles
         *
         * \param right The EulerAngles to subtract to this
         *
         * \return The difference of this and right
         *
         */
        EulerAngles<T>& operator-=(const EulerAngles<T>& right)
        {
            roll -= right.roll;
            pitch -= right.pitch;
            yaw -= right.yaw;

            return (*this);
        }

        Angle<T> roll;  /**< The rotation around the X axis */
        Angle<T> pitch; /**< The rotation around the Y axis */
        Angle<T> yaw;   /**< The rotation around the Z axis */
    };

    typedef EulerAngles<int> EulerAnglesI;
    typedef EulerAngles<float> EulerAnglesF;
    typedef EulerAngles<double> EulerAnglesD;
    typedef EulerAngles<unsigned int> EulerAnglesUI;

    template <typename T>
    EulerAngles<T> EulerAngles<T>::Zero = EulerAngles<T>();
}

#endif //BULL_EULERANGLES_HPP
