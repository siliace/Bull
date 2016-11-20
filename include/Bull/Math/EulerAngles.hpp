#ifndef Bull_EulerAngles_hpp
#define Bull_EulerAngles_hpp

#include <functional>

namespace Bull
{
    template<typename T>
    struct EulerAngles
    {
        static constexpr EulerAngles<T> Zero = EulerAngles<T>(0.0);

        /*! \brief Default constructor
         *
         */
        EulerAngles();

        /*! \brief Constructor
         *
         * \param value The value of the angle on every axes
         *
         */
        template<typename U>
        EulerAngles(U value);

        /*! \brief Constructor
         *
         * \param roll  The roll of the angle to create
         * \param pitch The pitch of the angle to create
         * \param yaw   The yaw of the angle to create
         *
         */
        template<typename U>
        EulerAngles(U roll, U pitch, U yaw);

        /*! \brief Copy constructor
         *
         * \param copy The EulerAngles to copy
         *
         */
        template<typename U>
        EulerAngles(const EulerAngles<U>& copy);

        /*! \brief Basic assignment operator
         *
         * \param copy The EulerAngles to copy
         *
         * \return Return this
         *
         */
        template<typename U>
        EulerAngles<T> operator=(const EulerAngles<U>& copy);

        /*! \brief Set the value of the EulerAngles
         *
         * \param value The value of the angle on every axes
         *
         * \return Return this
         *
         */
        template<typename U>
        EulerAngles<T>& set(U value);

        /*! \brief Set the value of the EulerAngles
         *
         * \param roll  The roll of the angle to create
         * \param pitch The pitch of the angle to create
         * \param yaw   The yaw of the angle to create
         *
         * \return Return this
         *
         */
        template<typename U>
        EulerAngles<T>& set(U roll, U pitch, U yaw);

        /*! \brief Set the value of the EulerAngles
         *
         * \param copy The EulerAngles to copy
         *
         * \return Return this
         *
         */
        template<typename U>
        EulerAngles<T>& set(const EulerAngles<U>& copy);

        /*! \brief Compare two EulerAngles
         *
         * \param right The EulerAngles to compare to this
         *
         * \return Return true if this and right are equal, false otherwise
         *
         */
        template<typename U>
        bool operator==(const EulerAngles<U>& right);

        /*! \brief Compare two EulerAngles
         *
         * \param right The EulerAngles to compare to this
         *
         * \return Return true if this and right are not equal, false otherwise
         *
         */
        template<typename U>
        bool operator!=(const EulerAngles<U>& right);

        T roll, pitch, yaw;
    };
}

#include <Bull/Math/EulerAngles.inl>

#endif // Bull_EulerAngles_hpp
