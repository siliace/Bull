namespace Bull
{
    Transformation3D Transformation3D::makeScale(const Vector3<T>& scale)
    {
        return Transformation3D().setScale(scale);
    }

    Transformation3D Transformation3D::makeRotation(const EulerAnglesF& angles)
    {
        return Transformation3D().setRotation(angles);
    }

    Transformation3D Transformation3D::makeTranslation(const Vector3<T>& translation)
    {
        return Transformation3D().setTranslation(translation);
    }

    Transformation3D Transformation3D::make(const EulerAnglesF& angles, const Vector3<T>& scale)
    {
        return Transformation3D::makeRotation(angles).applyScale(scale);
    }

    Transformation3D Transformation3D::make(const Vector3<T>& translation, const Vector3<T>& scale)
    {
        return Transformation3D::makeTranslation(translation).applyScale(scale);
    }

    Transformation3D Transformation3D::make(const Vector3<T>& translation, const EulerAnglesF& angles)
    {
        return Transformation3D::makeTranslation(translation).setRotation(angles);
    }

    Transformation3D Transformation3D::make(const Vector3<T>& translation, const EulerAnglesF& angles, const Vector3<T>& scale)
    {
        return Transformation3D::make(translation, angles).applyScale(scale);
    }

    Transformation3D::Transformation3D() :
        m_matrix(Matrix4<T>::Identity)
    {
        /// Nothing
    }

    Transformation3D& Transformation3D::setScale(const Vector3<T>& scale)
    {
        m_matrix(0, 0) = scale.x;
        m_matrix(1, 1) = scale.y;
        m_matrix(2, 2) = scale.z;

        return (*this);
    }

    Vector3<T> Transformation3D::getScale() const
    {
        return Vector3<T>(m_matrix(0, 0), m_matrix(1, 1), m_matrix(2, 2));
    }

    Transformation3D& Transformation3D::setRotation(const EulerAnglesF& angles)
    {
        QuaternionF rotation(angles);

        T tx  = rotation.x + rotation.x;
        T ty  = rotation.y + rotation.y;
        T tz  = rotation.z + rotation.z;
        T twx = tx * rotation.w;
        T twy = ty * rotation.w;
        T twz = tz * rotation.w;
        T txx = tx * rotation.x;
        T txy = ty * rotation.x;
        T txz = tz * rotation.x;
        T tyy = ty * rotation.y;
        T tyz = tz * rotation.y;
        T tzz = tz * rotation.z;

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

    Transformation3D& Transformation3D::setTranslation(const Vector3<T>& translation)
    {
        m_matrix(3, 0) = translation.x;
        m_matrix(3, 1) = translation.y;
        m_matrix(3, 2) = translation.z;

        return (*this);
    }

    Vector3<T> Transformation3D::getTranslation() const
    {
        return Vector3<T>(m_matrix(0, 3), m_matrix(1, 3), m_matrix(2, 3));
    }

    Transformation3D& Transformation3D::applyScale(const Vector3<T>& scale)
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

    Transformation3D& Transformation3D::applyTranslation(const Vector3<T>& translation)
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