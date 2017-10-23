#ifndef BULL_GRAPHICS_NODE_HPP
#define BULL_GRAPHICS_NODE_HPP

#include <Bull/Core/Pattern/ObjectRef.hpp>
#include <Bull/Core/Pattern/NonCopyable.hpp>

#include <Bull/Graphics/Export.hpp>

#include <Bull/Math/EulerAngles.hpp>
#include <Bull/Math/Matrix/Matrix4.hpp>
#include <Bull/Math/Vector/Vector3.hpp>

namespace Bull
{
    class Node;

    using NodeRef = ObjectRef<Node>;
    using NodeConstRef = ObjectRef<const Node>;

    class BULL_GRAPHICS_API Node : public NonCopyable
    {
    public:

        /*! \brief Default constructor
         *
         */
        Node();

        /*! \brief Constructor
         *
         * \param parent The parent Node
         *
         */
        explicit Node(const Node* parent);

        /*! \brief Tell whether the Node is a root Node
         *
         * \return True if the Node is a root Node
         *
         */
        bool isRoot() const;

        /*! \brief Scale the Node
         *
         * \param scale The scaling factor
         *
         * \return This
         *
         */
        Node& scale(const Vector3F& scale);

        /*! \brief Rotate the Node
         *
         * \param rotation The rotation
         *
         * \return This
         *
         */
        Node& rotate(const EulerAnglesF& rotation);

        /*! \brief Move the Node
         *
         * \param translation The translation
         *
         * \return This
         *
         */
        Node& move(const Vector3F& translation);

        /*! \brief Get the initial scale
         *
         * \return The scale
         *
         */
        const Vector3F& getInitialScale() const;

        /*! \brief Get the initial rotation
         *
         * \return The rotation
         *
         */
        const EulerAnglesF& getInitialRotation() const;

        /*! \brief Get the initial translation
         *
         * \return The translation
         *
         */
        const Vector3F& getInitialTranslation() const;

        /*! \brief Add a child to this Node
         *
         * \param child The Node to add
         *
         * \return This
         *
         */
        Node& addChild(const NodeRef& child);

        /*! \brief Get the parent Node
         *
         * \return The parent
         *
         */
        const Node* getParent() const;

        /*! \brief Get the model Matrix of the Node
         *
         * \return The model Matrix
         *
         */
        Matrix4F getModelMatrix() const;

    private:

        Vector3F             m_scale; /*!< The scale of the Node */
        const Node*          m_parent; /*!< The parent Node */
        std::vector<NodeRef> m_children; /*!< Children of the Node */
        EulerAnglesF         m_rotation; /*!< The rotation of the Node */
        Vector3F             m_translation; /*!< The translation of the Node */
    };
}

#endif // BULL_GRAPHICS_NODE_HPP
