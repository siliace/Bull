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

    bool Mesh::isRoot() const
    {
        return m_parent == nullptr;
    }

#if defined BULL_MESH_HAS_NAME
    void Mesh::setName(const std::string& name)
    {
        m_name = name;
    }

    const std::string& Mesh::getName() const
    {
        return m_name;
    }
#endif

    const Mesh* Mesh::getParent() const
    {
        return m_parent;
    }

    void Mesh::setLocalModelMatrix(const Matrix4F& localModelMatrix)
    {
        m_localModelMatrix = localModelMatrix;
    }

    const Matrix4F& Mesh::getLocalModelMatrix() const
    {
        return m_localModelMatrix;
    }
}
