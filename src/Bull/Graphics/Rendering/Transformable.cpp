#include <Bull/Graphics/Rendering/Transformable.hpp>

namespace Bull
{
    Transformable::Transformable() :
        m_scale(Vector3F::Unit)
    {
        /// Nothing
    }

    void Transformable::scale(const Vector3F& scale)
    {
        m_scale *= scale;
    }

    void Transformable::rotate(const EulerAnglesF& rotation)
    {
        m_rotation = EulerAnglesF::normalize(m_rotation += rotation);
    }

    void Transformable::move(const Vector3F& translation)
    {
        m_translation += translation;
    }

    Matrix4F Transformable::getModelMatrix() const
    {
        Matrix4F scaling = Matrix4F::makeScale(m_scale);
        Matrix4F translation = Matrix4F::makeTranslation(m_translation);
        Matrix4F rotation = Matrix4F::makeRotation(QuaternionF(EulerAnglesF::normalize(m_rotation)));

        return translation * rotation * scaling;
    }
}
