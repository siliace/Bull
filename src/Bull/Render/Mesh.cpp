#include <Bull/Core/Exception/RuntimeError.hpp>

#include <Bull/Render/Mesh.hpp>

namespace Bull
{
    Mesh::Mesh() :
        m_vao(0)
    {
        gl::genVertexArrays(1, &m_vao);

        if(m_vao == 0)
        {
            throw RuntimeError("Failed to create VAO");
        }
    }

    Mesh::Mesh(const std::vector<Vertex>& vertices, const std::vector<unsigned int>& indices) :
        Mesh()
    {
        create(vertices, indices);
    }

    Mesh::~Mesh()
    {
        gl::deleteVertexArrays(1, &m_vao);
    }

    void Mesh::create(const std::vector<Vertex>& vertices, const std::vector<unsigned int>& indices)
    {
        gl::bindVertexArray(m_vao);

        m_ebo.create(indices);

        m_vbo.create(vertices);
        m_vbo.setAttribPointer(0, 3, sizeof(Vertex));
        m_vbo.setAttribPointer(1, 4, sizeof(Vertex), sizeof(Vector3F));
        m_vbo.setAttribPointer(2, 2, sizeof(Vertex), sizeof(Vector3F) + sizeof(Vector4F));

        gl::bindVertexArray(0);
    }

    void Mesh::render(Primitive primitive) const
    {
        gl::bindVertexArray(m_vao);
        gl::drawElements(primitive, m_ebo.getCapacity(), GL_UNSIGNED_INT, nullptr);
        gl::bindVertexArray(0);
    }
}
