#ifndef BULL_GRAPHICS_MESH_HPP
#define BULL_GRAPHICS_MESH_HPP

#include <Bull/Render/Buffer/ArrayBuffer.hpp>
#include <Bull/Render/Buffer/ElementBuffer.hpp>
#include <Bull/Render/Buffer/VertexArrayObject.hpp>
#include <Bull/Render/OpenGL.hpp>

namespace Bull
{
    class BULL_RENDER_API Mesh
    {
    public:

        enum Primitive
        {
            Points                 = GL_POINTS,
            Lines                  = GL_LINES,
            LineLoop               = GL_LINE_LOOP,
            LineStrip              = GL_LINE_STRIP,
            Triangles              = GL_TRIANGLES,
            TriangleFan            = GL_TRIANGLE_FAN,
            TriangleStrip          = GL_TRIANGLE_STRIP,
            LinesAdjacency         = GL_LINES_ADJACENCY,
            LineStripAdjacency     = GL_LINE_STRIP_ADJACENCY,
            TrianglesAdjacency     = GL_TRIANGLES_ADJACENCY,
            TriangleStripAdjacency = GL_TRIANGLE_STRIP_ADJACENCY,
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

        /*! \brief Set the Mesh
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
    };
}

#endif // BULL_GRAPHICS_MESH_HPP
