#ifndef BULL_GRAPHICS_MESH_HPP
#define BULL_GRAPHICS_MESH_HPP

#include <Bull/Render/HardwareBuffer.hpp>
#include <Bull/Render/OpenGL.hpp>

#include <Bull/Utility/VertexArray.hpp>

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
        Mesh();

        /*! \brief Constructor
         *
         * \param vertices
         * \param indices
         *
         */
        Mesh(const VertexArray& vertices, const std::vector<unsigned int>& indices);

        /*! \brief Destructor
         *
         */
        ~Mesh();

        /*! \brief Set the Mesh
         *
         * \param vertices
         * \param indices
         *
         */
        void create(const VertexArray& vertices, const std::vector<unsigned int>& indices);

        /*! \brief Render the Mesh
         *
         * \param primitive The primitive to use to render the Mesh
         *
         */
        void render(Primitive primitive) const;

    private:

        unsigned int   m_vao;
        HardwareBuffer m_vbo, m_ebo;
    };
}

#endif // BULL_GRAPHICS_MESH_HPP
