#ifndef BULL_GRAPHICS_MODEL_SUBMESH_HPP
#define BULL_GRAPHICS_MODEL_SUBMESH_HPP

#include <Bull/Graphics/Export.hpp>

#include <Bull/Render/Buffer/ArrayBuffer.hpp>
#include <Bull/Render/Buffer/IndexBuffer.hpp>
#include <Bull/Render/Buffer/VertexArrayObject.hpp>
#include <Bull/Render/Draw/RenderPrimitive.hpp>

namespace Bull
{
    class BULL_GRAPHICS_API SubMesh : public NonCopyable
    {
    public:

        /*! \brief Default constructor
         *
         */
        SubMesh() = default;

        /*! \brief Constructor
         *
         * \param vertices
         * \param indices
         *
         */
        SubMesh(const std::vector<Vertex>& vertices, const std::vector<unsigned int>& indices);

        /*! \brief Constructor by movement semantic
         *
         * \param right The SubMesh to move
         *
         */
        SubMesh(SubMesh&& right) noexcept = default;

        /*! \brief Basic assignment operator by movement semantic
         *
         * \param right The SubMesh to move
         *
         * \return This
         *
         */
        SubMesh& operator=(SubMesh&& right) noexcept = default;

        /*! \brief Create the SubMesh
         *
         * \param vertices
         * \param indices
         *
         */
        void create(const std::vector<Vertex>& vertices, const std::vector<unsigned int>& indices);

        /*! \brief Render the SubMesh
         *
         * \param primitive The RenderPrimitive to use to render the SubMesh
         *
         */
        void render(RenderPrimitive primitive) const;

    private:

        VertexArrayObject m_vao;
        IndexBuffer       m_indices;
        ArrayBuffer       m_vertices;
    };
}

#endif // BULL_GRAPHICS_MODEL_SUBMESH_HPP
