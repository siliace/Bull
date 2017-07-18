namespace Bull
{
    template <typename T>
    Transformation3D<T> Transformation3D<T>::makeScale(const Vector3<T>& scale)
    {
        return Transformation3D().setScale(scale);
    }

    template <typename T>
    Transformation3D<T> Transformation3D<T>::makeRotation(const EulerAnglesF& angles)
    {
        return Transformation3D().setRotation(angles);
    }

    template <typename T>
    Transformation3D<T> Transformation3D<T>::makeTranslation(const Vector3<T>& translation)
    {
        return Transformation3D().setTranslation(translation);
    }

    template <typename T>
    Transformation3D<T> Transformation3D<T>::make(const EulerAngles<T>& angles, const Vector3<T>& scale)
    {
        return Transformation3D<T>::makeRotation(angles).applyScale(scale);
    }

    template <typename T>
    Transformation3D<T> Transformation3D<T>::make(const Vector3<T>& translation, const Vector3<T>& scale)
    {
        return Transformation3D<T>::makeTranslation(translation).applyScale(scale);
    }

    template <typename T>
    Transformation3D<T> Transformation3D<T>::make(const Vector3<T>& translation, const EulerAngles<T>& angles)
    {
        return Transformation3D<T>::makeTranslation(translation).setRotation(angles);
    }

    template <typename T>
    Transformation3D<T> Transformation3D<T>::make(const Vector3<T>& translation, const EulerAngles<T>& angles, const Vector3<T>& scale)
    {
        return Transformation3D<T>::make(translation, angles).applyScale(scale);
    }

    template <typename T>
    Transformation3D<T>::Transformation3D() :
        m_matrix(Matrix4<T>::Identity)
    {
        /// Nothing
    }

    template <typename T>
    Transformation3D<T>& Transformation3D<T>::setScale(const Vector3<T>& scale)
    {
        m_matrix(0, 0) = scale.x;
        m_matrix(1, 1) = scale.y;
        m_matrix(2, 2) = scale.z;

        return (*this);
    }

    template <typename T>
    Vector3<T> Transformation3D<T>::getScale() const
    {
        return Vector3<T>(m_matrix(0, 0), m_matrix(1, 1), m_matrix(2, 2));
    }

    template <typename T>
    Transformation3D<T>& Transformation3D<T>::setRotation(const EulerAngles<T>& angles)
    {
        Quaternion<T> rotation(angles);

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

    template <typename T>
    EulerAnglesF Transformation3D<T>::getRotation() const
    {
        /// Todo : Needs to be implemented

        return EulerAnglesF();
    }

    template <typename T>
    Transformation3D<T>& Transformation3D<T>::setTranslation(const Vector3<T>& translation)
    {
        m_matrix(3, 0) = translation.x;
        m_matrix(3, 1) = translation.y;
        m_matrix(3, 2) = translation.z;

        return (*this);
    }

    template <typename T>
    Vector3<T> Transformation3D<T>::getTranslation() const
    {
        return Vector3<T>(m_matrix(0, 3), m_matrix(1, 3), m_matrix(2, 3));
    }

    template <typename T>
    Transformation3D<T>& Transformation3D<T>::applyScale(const Vector3<T>& scale)
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

    template <typename T>
    Transformation3D<T>& Transformation3D<T>::applyRotation(const EulerAngles<T>& angles)
    {
        /// Todo : Needs to be implemented

        return (*this);
    }

    template <typename T>
    Transformation3D<T>& Transformation3D<T>::applyTranslation(const Vector3<T>& translation)
    {
        m_matrix(0, 3) += translation.x;
        m_matrix(1, 3) += translation.y;
        m_matrix(2, 3) += translation.z;

        return (*this);
    }

    template <typename T>
    const Matrix4<T>& Transformation3D<T>::getMatrix() const
    {
        return m_matrix;
    }
}