#include <Bull/Render/Context/GlFunctions.hpp>
#include <Bull/Render/Mesh.hpp>

namespace Bull
{
    namespace
    {
        constexpr unsigned int Primitives[] = {
            GL_POINTS,
            GL_LINES,
            GL_LINE_LOOP,
            GL_LINE_STRIP,
            GL_TRIANGLES,
            GL_TRIANGLE_FAN,
            GL_TRIANGLE_STRIP,
            GL_LINES_ADJACENCY,
            GL_LINE_STRIP_ADJACENCY,
            GL_TRIANGLES_ADJACENCY,
            GL_TRIANGLE_STRIP_ADJACENCY,
        };
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

    void Mesh::render(Primitive primitive) const
    {
        m_vao.runBound([this, primitive](){
            if(m_hasIndex)
            {
                gl::drawElements(Primitives[primitive], static_cast<GLsizei>(m_ebo.getCapacity()), GL_UNSIGNED_INT, nullptr);
            }
            else
            {
                gl::drawArrays(Primitives[primitive], 0, static_cast<GLsizei>(m_vbo.getCapacity()));
            }
        });
    }
}
