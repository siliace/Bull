#include <Bull/Graphics/Model/SubMesh.hpp>

#include <Bull/Render/Draw/Drawer.hpp>

namespace Bull
{
    SubMesh::SubMesh(RenderPrimitive primitive) :
            m_primitive(primitive)
    {
        /// Nothing
    }

    void SubMesh::create(const VertexArray& vertices, const std::vector<unsigned int>& indices)
    {
        m_vao.runBound([this, vertices, indices]()
                       {
                           m_indices.create(indices);
                           m_vertices.create(vertices);

                           m_vertices.setAttribPointer(0, 3, sizeof(Vertex));
                           m_vertices.setAttribPointer(1, 4, sizeof(Vertex), sizeof(Vector3F));
                           m_vertices.setAttribPointer(2, 2, sizeof(Vertex), sizeof(Vector3F) + sizeof(Vector4F));
                           m_vertices.setAttribPointer(3, 3, sizeof(Vertex), sizeof(Vector3F) + sizeof(Vector4F) + sizeof(Vector2F));
                       });
    }

    void SubMesh::render() const
    {
        m_vao.runBound([this]()
                       {
                           Drawer::drawElements(m_primitive, m_indices.getCapacity(), m_indices.getDataType());
                       });
    }
}
