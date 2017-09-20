#ifndef BULL_GRAPHICS_MESH_HPP
#define BULL_GRAPHICS_MESH_HPP

#include <Bull/Render/Buffer/ArrayBuffer.hpp>
#include <Bull/Render/Buffer/ElementBuffer.hpp>
#include <Bull/Render/Buffer/VertexArrayObject.hpp>

namespace Bull
{
    class BULL_RENDER_API Mesh
    {
    public:

        enum Primitive
        {
            Points,
            Lines,
            LineLoop,
            LineStrip,
            Triangles,
            TriangleFan ,
            TriangleStrip,
            LinesAdjacency,
            LineStripAdjacency,
            TrianglesAdjacency,
            TriangleStripAdjacency,
        };

    public:

        /*! \brief Default constructor
         *
         */
        Mesh() = default;

        /*! \brief Constructor
         *
         * \param vertices
         * \param indices
         *
         */
        Mesh(const std::vector<Vertex>& vertices, const std::vector<unsigned int>& indices);

        /*! \brief Create the Mesh
         *
         * \param vertices
         *
         */
        void create(const std::vector<Vertex>& vertices);

        /*! \brief Create the Mesh
         *
         * \param vertices
         * \param indices
         *
         */
        void create(const std::vector<Vertex>& vertices, const std::vector<unsigned int>& indices);

        /*! \brief Render the Mesh
         *
         * \param primitive The primitive to use to render the Mesh
         *
         */
        void render(Primitive primitive) const;

    private:

        VertexArrayObject m_vao;
        ArrayBuffer       m_vbo;
        ElementBuffer     m_ebo;
        bool              m_hasIndex;
    };
}

#endif // BULL_GRAPHICS_MESH_HPP
