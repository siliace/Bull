#ifndef BULL_POLYGON_HPP
#define BULL_POLYGON_HPP

#include <Bull/Core/System/Export.hpp>

#include <Bull/Math/Vector/Vector2.hpp>

namespace Bull
{
    template<typename T>
    struct BULL_API Polygon
    {
        /*! \brief Get a vertex form the polygon
         *
         * \param index The index of the vertex to get
         *
         * \return The vertex
         */
        virtual Vector2<T> getVertex(unsigned int index) const = 0;

        /*! \brief Get the number of vertex in the polygon
         *
         * \return The number of vertex
         *
         */
        virtual unsigned int getVertexCount() const = 0;
    };
}

#endif // BULL_POLYGON_HPP
