namespace Bull
{
    template <typename T>
    Camera<T>::Camera(const Vector3<T>& position, const Vector3<T>& target, const Vector3<T>& up) :
        m_up(up)
    {
        setPosition(position).setTarget(target);
    }

    template <typename T>
    Camera<T>& Camera<T>::setPosition(const Vector3<T>& position)
    {
        m_position = position;

        return (*this);
    }

    template <typename T>
    const Vector3<T>& Camera<T>::getPosition() const
    {
        return m_position;
    }

    template <typename T>
    Camera<T>& Camera<T>::setTarget(const Vector3<T>& target)
    {
        m_target = target;

        updateVectors();

        return (*this);
    }

    template <typename T>
    const Vector3<T>& Camera<T>::getTarget() const
    {
        return m_target;
    }

    template <typename T>
    const Matrix4<T>& Camera<T>::getMatrix() const
    {
        if(!m_isValid)
        {
            recomputeMatrix();
        }

        return m_view;
    }

    template <typename T>
    void Camera<T>::updateVectors()
    {
        m_isValid = false;
        m_forward = Vector3F::normalize(m_target - m_position);
        m_right   = Vector3F::crossProduct(m_forward, m_up).normalize();
        m_up      = Vector3F::crossProduct(m_right, m_forward);
    }

    template <typename T>
    void Camera<T>::recomputeMatrix() const
    {
        m_view.setColumn(Vector4F(m_right, -m_right.dotProduct(m_position)),     0);
        m_view.setColumn(Vector4F(m_up, -m_up.dotProduct(m_position)),           1);
        m_view.setColumn(Vector4F(-m_forward, m_forward.dotProduct(m_position)), 2);
        m_view.setColumn(Vector4F(0.f, 0.f, 0.f, 1.f),                           3);
    }
}