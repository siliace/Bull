#include <Bull/Render/Mesh.hpp>

namespace Bull
{
    Mesh::Mesh(const std::vector<Vertex>& vertices, const std::vector<unsigned int>& indices)
    {
        create(vertices, indices);
    }

    void Mesh::create(const std::vector<Vertex>& vertices, const std::vector<unsigned int>& indices)
    {
        m_vao.runBound([this, vertices, indices](){
            m_vbo.create(vertices);
            m_vbo.setAttribPointer(0, 3, sizeof(Vertex));
            m_vbo.setAttribPointer(1, 4, sizeof(Vertex), sizeof(Vector3F));
            m_vbo.setAttribPointer(2, 2, sizeof(Vertex), sizeof(Vector3F) + sizeof(Vector4F));
            m_vbo.setAttribPointer(3, 3, sizeof(Vertex), sizeof(Vector3F) + sizeof(Vector4F) + sizeof(Vector2F));

            m_ebo.create(indices);
        });
    }

    void Mesh::render(Primitive primitive) const
    {
        m_vao.runBound([this, primitive](){
            gl::drawElements(primitive, static_cast<GLsizei>(m_ebo.getCapacity()), GL_UNSIGNED_INT, nullptr);
        });
    }
}
