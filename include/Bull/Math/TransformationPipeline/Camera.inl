namespace Bull
{
    template <typename T>
    Camera<T>::Camera() :
        Camera(Vector3<T>::Zero, Vector3<T>::Zero)
    {
        /// Nothing
    }

    template <typename T>
    Camera<T>::Camera(const Vector3<T>& eye, const Vector3<T>& target, const Vector3<T>& up) :
        m_up(up),
        m_eye(eye),
        m_target(target)
    {
        recomputeMatrix();
    }

    template <typename T>
    Camera<T>& Camera<T>::setEye(const Vector3<T>& eye)
    {
        m_eye = eye;

        recomputeMatrix();

        return (*this);
    }

    template <typename T>
    const Vector3<T>& Camera<T>::getEye() const
    {
        return m_eye;
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
        Vector3<T> forward = Vector3<T>::normalize(m_target - m_eye);
        Vector3<T> right   = Vector3<T>::crossProduct(forward, m_up).normalize();
        m_up               = Vector3<T>::crossProduct(right, forward);

        m_view.setColumn(Vector4<T>(right,   -right.dotProduct(m_eye)),   0);
        m_view.setColumn(Vector4<T>(m_up,    -m_up.dotProduct(m_eye)),    1);
        m_view.setColumn(Vector4<T>(-forward, forward.dotProduct(m_eye)), 2);
        m_view.setColumn(Vector4<T>(0.f, 0.f, 0.f, 1.f),                  3);
    }
}