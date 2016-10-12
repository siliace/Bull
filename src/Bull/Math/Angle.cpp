#include <cmath>

#include <Bull/Math/Angle.hpp>
#include <Bull/Math/Constants.hpp>

namespace Bull
{
    /*! \brief Convert an angle from radian to degree
     *
     * \param rad The angle in radian
     *
     * \return The angle converted in degree
     *
     */
    float Angle::radToDeg(float rad)
    {
        return rad * (180.f / Pi);
    }

    /*! \brief Convert an angle from degree to radian
     *
     * \param deg The angle in degree
     *
     * \return The angle converted in radian
     *
     */
    float Angle::degToRad(float deg)
    {
        return deg * (Pi / 180.f);
    }
}
