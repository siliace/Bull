#ifndef BULL_VERTEXARRAY_HPP
#define BULL_VERTEXARRAY_HPP

#include <vector>

#include <Bull/Render/Vertex.hpp>

namespace Bull
{
    class BULL_API VertexArray
    {
    public:

        /*! \brief Default constructor
         *
         */
        VertexArray() = default;

        /*! \brief Constructor
         *
         * @param vertices
         *
         */
        VertexArray(const std::vector<Vertex>& vertices);

        /*! \brief
         *
         * @param index
         *
         * @return
         *
         */
        Vertex& operator[](std::size_t index);

        /*! \brief
         *
         * @param index
         *
         * @return
         *
         */
        const Vertex& operator[](std::size_t index) const;

    private:

        std::vector<Vertex> m_vertices;
    };
}

#endif // BULL_VERTEXARRAY_HPP
