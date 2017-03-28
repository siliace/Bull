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
         * @param size
         *
         */
        VertexArray(std::size_t size);

        /*! \brief Constructor
         *
         * @param vertices
         *
         */
        VertexArray(const std::vector<Vertex>& vertices);

        /*! \brief Add a Vertex in the array
         *
         * @param vertex The vertex to add
         *
         */
        void addVertex(const Vertex& vertex);

        /*! \brief Remove a Vertex from the array
         *
         * @param index The index of the Vertex to remove
         *
         * @return The removed Vertex
         *
         */
        Vertex removeVertex(std::size_t index);

        /*! \brief Get the size of the array
         *
         * @return The size
         */
        std::size_t getSize() const;

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
