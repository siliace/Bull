#ifndef BULL_GRAPHICS_MESH_HPP
#define BULL_GRAPHICS_MESH_HPP

#include <Bull/Render/Buffer/VertexBuffer.hpp>
#include <Bull/Render/Buffer/IndexBuffer.hpp>
#include <Bull/Render/Buffer/VertexArrayObject.hpp>
#include <Bull/Render/Draw/RenderPrimitive.hpp>

namespace Bull
{
    class BULL_RENDER_API Mesh
    {
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
        Mesh(const VertexArray& vertices, const ArrayList<unsigned int>& indices);

        /*! \brief Create the Mesh
         *
         * \param vertices
         *
         */
        void create(const VertexArray& vertices);

        /*! \brief Create the Mesh
         *
         * \param vertices
         * \param indices
         *
         */
        void create(const VertexArray& vertices, const ArrayList<unsigned int>& indices);

        /*! \brief Render the Mesh
         *
         * \param primitive The primitive to use to render the Mesh
         *
         */
        void render(RenderPrimitive primitive) const;

    private:

        VertexArrayObject m_vao;
        VertexBuffer      m_vbo;
        IndexBuffer       m_ebo;
        bool              m_hasIndex;
    };
}

#endif // BULL_GRAPHICS_MESH_HPP
