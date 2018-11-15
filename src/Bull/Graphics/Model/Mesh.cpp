#include <Bull/Graphics/Model/Mesh.hpp>

namespace Bull
{
    Mesh::Mesh(const Mesh* parent, const Matrix4F& localModelMatrix) :
        m_parent(parent),
        m_localModelMatrix(localModelMatrix)
    {
        /// Nothing
    }

    void Mesh::addChild(const Mesh& mesh)
    {
        m_children.push_back(mesh);
    }

    void Mesh::addSubMesh(const std::shared_ptr<SubMesh>& subMesh)
    {
        m_subMeshes.push_back(subMesh);
    }

    bool Mesh::isValid() const
    {
        return !m_children.empty() || !m_subMeshes.empty();
    }

    void Mesh::render(const Shader& shader, const Matrix4F& modelMatrix) const
    {
        Matrix4F meshModelMatrix = modelMatrix * m_localModelMatrix;

        for(const Mesh& child : m_children)
        {
            child.render(shader, meshModelMatrix);
        }

        shader.setUniformMatrix("model", meshModelMatrix);

        for(const std::shared_ptr<SubMesh>& subMesh : m_subMeshes)
        {
            subMesh->render();
        }
    }
}
