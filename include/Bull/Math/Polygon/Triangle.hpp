#ifndef BULL_TRIANGLE_HPP
#define BULL_TRIANGLE_HPP

#include <Bull/Math/Angle.hpp>
#include <Bull/Math/Polygon/RegularPolygon.hpp>

namespace Bull
{
    template<typename T>
    struct Triangle : public RegularPolygon<T, 3>
    {
        /*! \brief Default constructor
         *
         */
        Triangle() = default;

        /*! \brief Constructor
         *
         * \param center   The center of the polygon
         * \param radius   The radius of the polygon
         * \param rotation The rotation of the polygon
         *
         */
        Triangle(const Vector2<T>& center, T radius = 0, const Angle<T>& rotation = Angle<T>::Zero);
    };

    typedef Triangle<int> TriangleI;
    typedef Triangle<float> TriangleF;
    typedef Triangle<double> TriangleD;
    typedef Triangle<unsigned int> TriangleUI;
}

#include <Bull/Math/Polygon/Triangle.inl>

#endif // BULL_TRIANGLE_HPP
