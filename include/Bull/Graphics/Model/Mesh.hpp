#ifndef BULL_GRAPHICS_MODEL_MESH_HPP
#define BULL_GRAPHICS_MODEL_MESH_HPP

#include <Bull/Graphics/Model/SubMesh.hpp>

#include <Bull/Render/Shader/Shader.hpp>

namespace Bull
{
    class BULL_GRAPHICS_API Mesh : public NonCopyable
    {
    public:

        /*! \brief Constructor
         *
         * \param parent           The parent Mesh
         * \param localModelMatrix The model matrix of the mesh relatively to the parent
         *
         */
        explicit Mesh(const Mesh* parent = nullptr, const Matrix4F& localModelMatrix = Matrix4F::Identity);

        /*! \brief Constructor by movement semantic
         *
         * \param mesh The Mesh to move
         *
         */
        Mesh(Mesh&& mesh) noexcept = default;

        /*! \param Assignment operator by movement semantic
         *
         * \param mesh The Mesh to move
         *
         * \return This
         *
         */
        Mesh& operator=(Mesh&& mesh) noexcept = default;

        /*! \brief Add a child Mesh to the Mesh
         *
         * \param mesh The child Mesh
         *
         */
        void addChild(Mesh&& mesh);

        /*! \brief Add a SubMesh to the Mesh
         *
         * \param subMesh The SubMesh
         *
         */
        void addSubMesh(SubMesh&& subMesh);

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
         * \param shader          The Shader
         * \param modelMatrix     The model matrix of the parent Mesh
         * \param renderPrimitive The RenderPrimitive to use to render the mesh
         *
         */
        void render(const Shader& shader, const Matrix4F& modelMatrix, RenderPrimitive renderPrimitive) const;

        /*! \brief Tell whether the Mesh is a root
         *
         * A Mesh is a root if it does not have a parent (i.e getParent() == nullptr)
         *
         * \return True if root
         *
         */
        inline bool isRoot() const
        {
            return m_parent == nullptr;
        }

        /*! \brief
         *
         * \param name
         *
         */
        inline void setName(const String& name)
        {
            m_name = name;
        }

        /*! \brief
         *
         * \return
         *
         */
        inline const String& getName() const
        {
            return m_name;
        }

        /*! \brief
         *
         * \return
         *
         */
        inline const Mesh* getParent() const
        {
            return m_parent;
        }

        /*! \brief
         *
         * \param localModelMatrix
         *
         */
        inline void setLocalModelMatrix(const Matrix4F& localModelMatrix)
        {
            m_localModelMatrix = localModelMatrix;
        }

        /*! \brief
         *
         * \return
         *
         */
        inline const Matrix4F& getLocalModelMatrix() const
        {
            return m_localModelMatrix;
        }

    private:

        String               m_name;
        const Mesh*          m_parent;
        std::vector<Mesh>    m_children;
        std::vector<SubMesh> m_subMeshes;
        Matrix4F             m_localModelMatrix;
    };
}

#endif // BULL_GRAPHICS_MODEL_MESH_HPP
