#include <Bull/Utility/TransformationPipeline/Transformation3D.hpp>

namespace Bull
{
    Transformation3D Transformation3D::makeScale(const Vector3F& scale)
    {
        return Transformation3D().setScale(scale);
    }

    Transformation3D Transformation3D::makeRotation(const EulerAnglesF& angles)
    {
        return Transformation3D().setRotation(angles);
    }

    Transformation3D Transformation3D::makeTranslation(const Vector3F& translation)
    {
        return Transformation3D().setTranslation(translation);
    }

    Transformation3D Transformation3D::make(const EulerAnglesF& angles, const Vector3F& scale)
    {
        return Transformation3D::makeRotation(angles).applyScale(scale);
    }

    Transformation3D Transformation3D::make(const Vector3F& translation, const Vector3F& scale)
    {
        return Transformation3D::makeTranslation(translation).applyScale(scale);
    }

    Transformation3D Transformation3D::make(const Vector3F& translation, const EulerAnglesF& angles)
    {
        return Transformation3D::makeTranslation(translation).setRotation(angles);
    }

    Transformation3D Transformation3D::make(const Vector3F& translation, const EulerAnglesF& angles, const Vector3F& scale)
    {
        return Transformation3D::make(translation, angles).applyScale(scale);
    }

    Transformation3D::Transformation3D() :
        m_matrix(Matrix4F::Identity)
    {
        /// Nothing
    }

    Transformation3D& Transformation3D::setScale(const Vector3F& scale)
    {
        m_matrix(0, 0) = scale.x;
        m_matrix(1, 1) = scale.y;
        m_matrix(2, 2) = scale.z;

        return (*this);
    }

    Vector3F Transformation3D::getScale() const
    {
        return Vector3F(m_matrix(0, 0), m_matrix(1, 1), m_matrix(2, 2));
    }

    Transformation3D& Transformation3D::setRotation(const EulerAnglesF& angles)
    {
        QuaternionF rotation(angles);

        float tx  = rotation.x + rotation.x;
        float ty  = rotation.y + rotation.y;
        float tz  = rotation.z + rotation.z;
        float twx = tx * rotation.w;
        float twy = ty * rotation.w;
        float twz = tz * rotation.w;
        float txx = tx * rotation.x;
        float txy = ty * rotation.x;
        float txz = tz * rotation.x;
        float tyy = ty * rotation.y;
        float tyz = tz * rotation.y;
        float tzz = tz * rotation.z;

        m_matrix(0, 0) = 1.f - (tyy + tzz);
        m_matrix(0, 1) = txy + twz;
        m_matrix(0, 2) = txz - twy;

        m_matrix(1, 0) = txy - twz;
        m_matrix(1, 1) = 1.f - (txx + tzz);
        m_matrix(1, 2) = tyz + twx;

        m_matrix(2, 0) = txz + twy;
        m_matrix(2, 1) = tyz - twx;
        m_matrix(2, 2) = 1.f - (txx + tyy);

        return (*this);
    }

    EulerAnglesF Transformation3D::getRotation() const
    {
        /// Todo : Needs to be implemented

        return EulerAnglesF();
    }

    Transformation3D& Transformation3D::setTranslation(const Vector3F& translation)
    {
        m_matrix(3, 0) = translation.x;
        m_matrix(3, 1) = translation.y;
        m_matrix(3, 2) = translation.z;

        return (*this);
    }

    Vector3F Transformation3D::getTranslation() const
    {
        return Vector3F(m_matrix(0, 3), m_matrix(1, 3), m_matrix(2, 3));
    }

    Transformation3D& Transformation3D::applyScale(const Vector3F& scale)
    {
        m_matrix(0, 0) *= scale.x;
        m_matrix(1, 0) *= scale.x;
        m_matrix(1, 0) *= scale.x;

        m_matrix(0, 1) *= scale.y;
        m_matrix(1, 1) *= scale.y;
        m_matrix(2, 1) *= scale.y;

        m_matrix(0, 2) *= scale.z;
        m_matrix(1, 2) *= scale.z;
        m_matrix(2, 2) *= scale.z;

        return (*this);
    }

    Transformation3D& Transformation3D::applyRotation(const EulerAnglesF& angles)
    {
        /// Todo : Needs to be implemented

        return (*this);
    }

    Transformation3D& Transformation3D::applyTranslation(const Vector3F& translation)
    {
        m_matrix(0, 3) += translation.x;
        m_matrix(1, 3) += translation.y;
        m_matrix(2, 3) += translation.z;

        return (*this);
    }

    Matrix4F Transformation3D::toMatrix() const
    {
        return m_matrix;
    }
}