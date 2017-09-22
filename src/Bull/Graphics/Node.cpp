#include <Bull/Graphics/Node.hpp>

namespace Bull
{
    Node::Node() :
        m_scale(Vector3F::Unit),
        m_parent(nullptr)
    {
        /// Nothing
    }

    Node::Node(const Node* parent) :
        m_scale(Vector3F::Unit),
        m_parent(parent)
    {
        /// Nothing
    }

    bool Node::isRoot() const
    {
        return getParent() == nullptr;
    }

    Node& Node::scale(const Vector3F& scale)
    {
        m_scale += scale;

        return (*this);
    }

    Node& Node::rotate(const EulerAnglesF& rotation)
    {
        m_rotation += rotation;

        return (*this);
    }

    Node& Node::move(const Vector3F& translation)
    {
        m_translation += translation;

        return (*this);
    }

    const Vector3F& Node::getInitialScale() const
    {
        if(m_parent)
        {
            return m_parent->getInitialScale();
        }

        return m_scale;
    }

    const EulerAnglesF& Node::getInitialRotation() const
    {
        if(m_parent)
        {
            return m_parent->getInitialRotation();
        }

        return m_rotation;
    }

    const Vector3F& Node::getInitialTranslation() const
    {
        if(m_parent)
        {
            return m_parent->getInitialTranslation();
        }

        return m_translation;
    }

    Node& Node::addChild(const NodeRef& child)
    {
        child->m_parent = this;
        m_children.emplace_back(child);

        return (*this);
    }

    const Node* Node::getParent() const
    {
        return m_parent;
    }

    Matrix4F Node::getModelMatrix() const
    {
        QuaternionF rotationQuaternion(EulerAnglesF::normalize(getInitialRotation() + m_rotation));

        Matrix4F rotation = Matrix4F::makeRotation(rotationQuaternion);
        Matrix4F scaling = Matrix4F::makeScale(getInitialScale() + m_scale);
        Matrix4F translation = Matrix4F::makeTranslation(getInitialTranslation() + m_translation);

        return translation * rotation * scaling;
    }
}
