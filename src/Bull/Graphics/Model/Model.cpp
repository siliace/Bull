#include <Bull/Graphics/Model/Model.hpp>

namespace Bull
{
    Model::Model(const std::shared_ptr<Mesh>& mesh) :
        m_mesh(mesh)
    {
        /// Nothing
    }

    void Model::render(const Shader& shader) const
    {
        shader.bind();

        m_mesh->render(shader, getModelMatrix(), RenderPrimitive_Triangles);
    }
}