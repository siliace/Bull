#ifndef Bull_Angle_hpp
#define Bull_Angle_hpp

#include <Bull/Core/System/Export.hpp>

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
        static float radToDeg(float rad);

        /*! \brief Convert an angle from degree to radian
         *
         * \param deg The angle in degree
         *
         * \return The angle converted in radian
         *
         */
        static float degToRad(float deg);
    };
}

#endif // Bull_Angle_hpp
