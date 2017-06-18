namespace Bull
{
    template <typename T>
    PerspectiveProjection<T>::PerspectiveProjection() :
        PerspectiveProjection(Angle<T>::Zero, 0, Vector2<T>::Zero)
    {
        /// Nothing
    }

    template <typename T>
    PerspectiveProjection<T>::PerspectiveProjection(const Angle<T>& angle, float ratio, const Vector2<T>& zBounds)
    {
        setAngle(angle).setRatio(ratio).setZBounds(zBounds);
    }

    template <typename T>
    PerspectiveProjection<T>& PerspectiveProjection<T>::setAngle(const Angle<T>& angle)
    {
        m_angle   = angle;
        m_isValid = false;

        return (*this);
    }

    template <typename T>
    const Angle<T>& PerspectiveProjection<T>::getAngle() const
    {
        return m_angle;
    }

    template <typename T>
    PerspectiveProjection<T>& PerspectiveProjection<T>::setRatio(float ratio)
    {
        m_ratio   = ratio;
        m_isValid = false;

        return (*this);
    }

    template <typename T>
    float PerspectiveProjection<T>::getRatio() const
    {
        return m_ratio;
    }

    template <typename T>
    PerspectiveProjection<T>& PerspectiveProjection<T>::setZBounds(const Vector2<T>& zBounds)
    {
        m_isValid = false;
        m_zBounds = zBounds;

        return (*this);
    }

    template <typename T>
    const Vector2<T>& PerspectiveProjection<T>::getZBounds() const
    {
        return m_zBounds;
    }

    template <typename T>
    const Matrix4<T>& PerspectiveProjection<T>::getMatrix() const
    {
        if(!m_isValid)
        {
            updateProjection();
        }

        return m_projection;
    }

    template <typename T>
    void PerspectiveProjection<T>::updateProjection() const
    {
        Angle<T> fov = Angle<T>::toRadian(m_angle) / static_cast<T>(2);
        float yScale = std::tan(Pi2 - fov);

        m_projection(0, 0) = yScale / m_ratio;
        m_projection(1, 1) = yScale;
        m_projection(2, 2) = -(m_zBounds.y + m_zBounds.x) / (m_zBounds.y - m_zBounds.x);
        m_projection(2, 3) = -1;
        m_projection(3, 2) = -2 * (m_zBounds.x * m_zBounds.y) / (m_zBounds.y - m_zBounds.x);
    }
}
