#ifndef BULL_GRAPHICS_MODEL_MESH_HPP
#define BULL_GRAPHICS_MODEL_MESH_HPP

#include <memory>

#include <Bull/Graphics/Model/SubMesh.hpp>

#include <Bull/Render/Shader/Shader.hpp>

namespace Bull
{
    class BULL_GRAPHICS_API Mesh
    {
    public:

        /*! \brief Constructor
         *
         * \param parent           The parent Mesh
         * \param localModelMatrix The model matrix of the mesh relatively to the parent
         *
         */
        explicit Mesh(const Mesh* parent = nullptr, const Matrix4F& localModelMatrix = Matrix4F::Identity);

        /*! \brief Add a child Mesh to the Mesh
         *
         * \param mesh The child Mesh
         *
         */
        void addChild(const Mesh& mesh);

        /*! \brief Add a SubMesh to the Mesh
         *
         * \param subMesh The SubMesh
         *
         */
        void addSubMesh(const std::shared_ptr<SubMesh>& subMesh);

        /*! \brief Tell whether the Mesh is valid
         *
         * A Mesh is valid if it has at least one child Mesh or has at least one SubMesh
         *
         * \return True if valid
         *
         */
        bool isValid() const;

        /*! \brief Render the Mesh thought a Shader
         *
         * \param shader      The Shader
         * \param modelMatrix The model matrix of the parent Mesh
         *
         */
        void render(const Shader& shader, const Matrix4F& modelMatrix) const;

        /*! \brief Tell whether the Mesh is a root
         *
         * A Mesh is a root if it does not have a parent (i.e getParent() == nullptr)
         *
         * \return True if root
         *
         */
        bool isRoot() const;

    #if defined BULL_MESH_HAS_NAME
        /*! \brief Set the name of the Mesh
         *
         * \param name The name
         *
         */
        void setName(const String& name);

        /*! \brief Get the name of the Mesh
         *
         * \return The name
         *
         */
        const String& getName() const;
    #endif

        /*! \brief Get the parent Mesh
         *
         * \return The parent
         *
         */
        const Mesh* getParent() const;

        /*! \brief Set the local model matrix of the Mesh
         *
         * \param localModelMatrix The matrix
         *
         */
        void setLocalModelMatrix(const Matrix4F& localModelMatrix);

        /*! \brief Get the local model matrix of the Mesh
         *
         * \return The matrix
         *
         */
        const Matrix4F& getLocalModelMatrix() const;

    private:

    #if defined BULL_MESH_HAS_NAME
        String                                m_name;
    #endif
        const Mesh*                           m_parent;
        std::vector<Mesh>                     m_children;
        std::vector<std::shared_ptr<SubMesh>> m_subMeshes;
        Matrix4F                              m_localModelMatrix;
    };
}

#endif // BULL_GRAPHICS_MODEL_MESH_HPP
