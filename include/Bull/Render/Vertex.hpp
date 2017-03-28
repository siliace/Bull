#ifndef BULL_VERTEX_HPP
#define BULL_VERTEX_HPP

#include <Bull/Math/Vector/Vector2.hpp>
#include <Bull/Math/Vector/Vector3.hpp>
#include <Bull/Math/Vector/Vector4.hpp>

#include <Bull/Utility/Color.hpp>

namespace Bull
{
    class BULL_API Vertex
    {
        /*! \brief Default constructor
         *
         */
        Vertex() = default;

        /*! \brief Constructor
         *
         * @param position
         * @param color
         * @param texCoord
         */
        Vertex(const Vertex3F& position, const Vertex4F& color, const Vector2F& texCoord);

        /*! \brief Constructor
         *
         * @param position
         * @param color
         * @param texCoord
         */
        Vertex(const Vertex3F& position, const Color& color, const Vector2F& texCoord);

        /*! \brief Compare two Vertex
         *
         * @param right The Vertex to compare to this
         *
         * @return True is right and this are equal
         *
         */
        bool operator==(const Vertex& right);

        /*! \brief Compare two Vertex
         *
         * @param right The Vertex to compare to this
         *
         * @return True is right and this are not equal
         *
         */
        bool operator!=(const Vertex& right);

        Vector3F position; /*!< The position of the vertex */
        Vector4F color;    /*!< The color of the vertex */
        Vector2F texCoord; /*!< The texture coordinates of the vertex */
    };
}

#endif // BULL_VERTEX_HPP
