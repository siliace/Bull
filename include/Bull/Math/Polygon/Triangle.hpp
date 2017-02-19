#ifndef BULL_TRIANGLE_HPP
#define BULL_TRIANGLE_HPP

#include <Bull/Math/Angle.hpp>
#include <Bull/Math/Polygon/CircularPolygon.hpp>

namespace Bull
{
    template<typename T>
    struct Triangle : public CircularPolygon<T, 3>
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
        template<typename U, typename V, typename W = T>
        Triangle(const Vector2<U>& center, V radius = 0.0, const Angle<W>& rotation = Angle<W>::Zero);
    };

    typedef Triangle<int> TriangleI;
    typedef Triangle<float> TriangleF;
    typedef Triangle<double> TriangleD;
    typedef Triangle<unsigned int> TriangleUI;
}

#include <Bull/Math/Polygon/Triangle.inl>

#endif // BULL_TRIANGLE_HPP
