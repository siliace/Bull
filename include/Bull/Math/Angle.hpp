#ifndef Bull_Angle_hpp
#define Bull_Angle_hpp

#include <Bull/Core/System/Export.hpp>

#include <Bull/Math/Constants.hpp>

namespace Bull
{
    struct BULL_API Angle
    {
        /*! \brief Convert an angle from radian to degree
         *
         * \param rad The angle in radian
         *
         * \return The angle converted in degree
         *
         */
        template<typename T>
        static T radToDeg(T rad);

        /*! \brief Convert an angle from degree to radian
         *
         * \param deg The angle in degree
         *
         * \return The angle converted in radian
         *
         */
        template<typename T>
        static T degToRad(T deg);
    };
}

#include <Bull/Math/Angle.inl>

#endif // Bull_Angle_hpp
