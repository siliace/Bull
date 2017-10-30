#include <Bull/Graphics/Model/Node.hpp>

namespace Bull
{
    Node::Node() :
        m_scale(Vector3F::Unit)
    {
        /// Nothing
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

    Matrix4F Node::getModelMatrix() const
    {
        QuaternionF rotationQuaternion(EulerAnglesF::normalize(m_rotation));

        Matrix4F rotation = Matrix4F::makeRotation(rotationQuaternion);
        Matrix4F scaling = Matrix4F::makeScale(m_scale);
        Matrix4F translation = Matrix4F::makeTranslation(m_translation);

        return translation * rotation * scaling;
    }
}
