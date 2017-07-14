namespace Bull
{
    template <typename T>
    OrthographicProjection<T>::OrthographicProjection(const Rectangle<T>& plan, const Vector2<T>& zBounds) :
        m_plan(plan),
        m_zBounds(zBounds)
    {
        /// Nothing
    }

    template <typename T>
    OrthographicProjection<T>& OrthographicProjection<T>::setPlan(const Rectangle<T>& plan)
    {
        m_plan = plan;

        updateProjection();

        return (*this);
    }

    template <typename T>
    const Rectangle<T>& OrthographicProjection<T>::getPlan() const
    {
        return m_plan;
    }

    template <typename T>
    OrthographicProjection<T>& OrthographicProjection<T>::setZBounds(const Vector2<T>& zBounds)
    {
        m_zBounds = zBounds;

        updateProjection();

        return (*this);
    }

    template <typename T>
    const Rectangle<T>& OrthographicProjection<T>::getZBounds() const
    {
        return m_zBounds;
    }

    template <typename T>
    const Matrix4<T>& OrthographicProjection<T>::getMatrix() const
    {
        return m_projection;
    }

    template <typename T>
    void OrthographicProjection<T>::updateProjection() const
    {
        T top    = m_plan.y;
        T left   = m_plan.x;
        T right  = m_plan.x + m_plan.width;
        T bottom = m_plan.y + m_plan.height;

        m_projection(0, 0) = 2 / (right - left);

        m_projection(1, 1) = 2 / (top - bottom);

        m_projection(2, 2) = 1 / (m_zBounds.x - m_zBounds.y);

        m_projection(3, 0) = (left + right) / (left - right);
        m_projection(3, 1) = (top + bottom) / (bottom - top);
        m_projection(3, 2) = m_zBounds.x / (m_zBounds.x - m_zBounds.y);
        m_projection(3, 3) = 1;
    }
}