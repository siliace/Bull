#include <Bull/Graphics/Model/Transformable.hpp>

namespace Bull
{
    Transformable::Transformable() :
        m_scale(Vector3F::Unit)
    {
        /// Nothing
    }

    Transformable& Transformable::scale(const Vector3F& scale)
    {
        m_scale += scale;

        return *this;
    }

    Transformable& Transformable::rotate(const EulerAnglesF& rotation)
    {
        m_rotation += rotation;

        return *this;
    }

    Transformable& Transformable::move(const Vector3F& translation)
    {
        m_translation += translation;

        return *this;
    }

    Matrix4F Transformable::getModelMatrix() const
    {
        Matrix4F rotation = Matrix4F::makeRotation(QuaternionF(EulerAnglesF::normalize(m_rotation)));
        Matrix4F scaling = Matrix4F::makeScale(m_scale);
        Matrix4F translation = Matrix4F::makeTranslation(m_translation);

        return translation * rotation * scaling;
    }
}
