namespace Bull
{
    template <typename T>
    Camera<T>::Camera() :
        Camera(Vector3<T>::Zero, Vector3<T>::Zero)
    {
        /// Nothing
    }

    template <typename T>
    Camera<T>::Camera(const Vector3<T>& position, const Vector3<T>& target, const Vector3<T> up) :
        m_up(up),
        m_target(target),
        m_position(position)
    {
        recomputeMatrix();
    }

    template <typename T>
    Camera<T>& Camera<T>::setPosition(const Vector3<T>& position)
    {
        m_position = position;

        recomputeMatrix();

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

        recomputeMatrix();

        return (*this);
    }

    template <typename T>
    const Vector3<T>& Camera<T>::getTarget() const
    {
        return m_target;
    }

    template <typename T>
    Camera<T>& Camera<T>::setUp(const Vector3<T>& up)
    {
        m_up = up;

        recomputeMatrix();

        return (*this);
    }

    template <typename T>
    const Vector3<T>& Camera<T>::getUp() const
    {
        return m_up;
    }

    template <typename T>
    const Matrix4<T>& Camera<T>::getMatrix() const
    {
        return m_view;
    }

    template <typename T>
    void Camera<T>::recomputeMatrix()
    {
        Vector3<T> u = Vector3<T>::normalize(m_up);
        Vector3<T> f = Vector3<T>::normalize(m_target - m_position);
        Vector3<T> s = Vector3<T>::crossProduct(f, u).normalize();
        u            = Vector3<T>::crossProduct(s, f);

        m_view.setColumn(Vector4<T>( s, -s.dotProduct(m_position)), 0);
        m_view.setColumn(Vector4<T>( u, -u.dotProduct(m_position)), 1);
        m_view.setColumn(Vector4<T>(-f,  f.dotProduct(m_position)), 2);
        m_view.setColumn(Vector4<T>(0.f, 0.f, 0.f, 1.f),            3);
    }
}