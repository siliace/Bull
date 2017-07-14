#include <Bull/Core/Exception/RuntimeError.hpp>

#include <Bull/Render/Mesh.hpp>

namespace Bull
{
    Mesh::Mesh() :
        m_vao(0),
        m_vbo(HardwareBuffer::Array),
        m_ebo(HardwareBuffer::Element)
    {
        gl::genVertexArrays(1, &m_vao);

        if(m_vao == 0)
        {
            throw RuntimeError("Failed to create VAO");
        }
    }

    Mesh::Mesh(const VertexArray& vertices, const std::vector<unsigned int>& indices) :
        Mesh()
    {
        create(vertices, indices);
    }

    Mesh::~Mesh()
    {
        gl::deleteVertexArrays(1, &m_vao);
    }

    void Mesh::create(const VertexArray& vertices, const std::vector<unsigned int>& indices)
    {
        gl::bindVertexArray(m_vao);

        m_vbo.create(vertices.getSize() * sizeof(Vertex));
        m_vbo.fill(&vertices[0], vertices.getSize() * sizeof(Vertex));

        m_ebo.create(indices.size() * sizeof(unsigned int));
        m_ebo.fill(&indices[0], indices.size() * sizeof(unsigned int));

        gl::enableVertexAttribArray(0);
        gl::vertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(0));

        gl::enableVertexAttribArray(1);
        gl::vertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(sizeof(Vector3F)));

        gl::enableVertexAttribArray(2);
        gl::vertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(sizeof(Vector3F) + sizeof(Vector4F)));

        gl::bindVertexArray(0);
    }

    void Mesh::render(Primitive primitive) const
    {
        gl::bindVertexArray(m_vao);
        gl::drawElements(primitive, m_ebo.getCapacity(), GL_UNSIGNED_INT, nullptr);
        gl::bindVertexArray(0);
    }
}
