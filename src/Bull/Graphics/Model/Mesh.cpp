#include <Bull/Graphics/Model/Mesh.hpp>

namespace Bull
{
    Mesh::Mesh(const Mesh* parent, const Matrix4F& localModelMatrix) :
        m_parent(parent),
        m_localModelMatrix(localModelMatrix)
    {
        /// Nothing
    }

    void Mesh::addChild(Mesh&& mesh)
    {
        m_children.emplace_back(std::move(mesh));
    }

    void Mesh::addSubMesh(SubMesh&& subMesh)
    {
        m_subMeshes.emplace_back(std::move(subMesh));
    }

    bool Mesh::isValid() const
    {
        return !m_children.empty() || !m_subMeshes.empty();
    }

    void Mesh::render(const Shader& shader, const Matrix4F& modelMatrix, RenderPrimitive renderPrimitive) const
    {
        Matrix4F meshModelMatrix = modelMatrix * m_localModelMatrix;

        for(const Mesh& child : m_children)
        {
            child.render(shader, meshModelMatrix, renderPrimitive);
        }

        shader.setUniformMatrix("model", meshModelMatrix);

        for(const SubMesh& subMesh : m_subMeshes)
        {
            subMesh.render(renderPrimitive);
        }
    }
}
