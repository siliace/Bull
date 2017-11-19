#include <Bull/Graphics/Model/Mesh.hpp>

#include <Bull/Render/Draw/Drawer.hpp>

namespace Bull
{
    Mesh::Mesh() :
        m_hasIndex(false)
    {
        /// Nothing
    }

    Mesh::Mesh(const std::vector<Vertex>& vertices, const std::vector<unsigned int>& indices)
    {
        create(vertices, indices);
    }

    void Mesh::create(const std::vector<Vertex>& vertices)
    {
        m_hasIndex = false;

        m_vao.runBound([this, vertices](){
            m_vbo.create(vertices);
            m_vbo.setAttribPointer(0, 3, sizeof(Vertex));
            m_vbo.setAttribPointer(1, 4, sizeof(Vertex), sizeof(Vector3F));
            m_vbo.setAttribPointer(2, 2, sizeof(Vertex), sizeof(Vector3F) + sizeof(Vector4F));
            m_vbo.setAttribPointer(3, 3, sizeof(Vertex), sizeof(Vector3F) + sizeof(Vector4F) + sizeof(Vector2F));
        });
    }

    void Mesh::create(const std::vector<Vertex>& vertices, const std::vector<unsigned int>& indices)
    {
        m_hasIndex = true;

        m_vao.runBound([this, vertices, indices](){
            m_ebo.create(indices);
            m_vbo.create(vertices);
            m_vbo.setAttribPointer(0, 3, sizeof(Vertex));
            m_vbo.setAttribPointer(1, 4, sizeof(Vertex), sizeof(Vector3F));
            m_vbo.setAttribPointer(2, 2, sizeof(Vertex), sizeof(Vector3F) + sizeof(Vector4F));
            m_vbo.setAttribPointer(3, 3, sizeof(Vertex), sizeof(Vector3F) + sizeof(Vector4F) + sizeof(Vector2F));
        });
    }

    void Mesh::render(RenderPrimitive primitive) const
    {
        m_vao.runBound([this, primitive](){
            if(m_hasIndex)
            {
                Drawer::drawElements(primitive, m_ebo.getCapacity(), m_ebo.getDataType());
            }
            else
            {
                Drawer::drawArrays(primitive, 0, m_vbo.getCapacity());
            }
        });
    }
}
