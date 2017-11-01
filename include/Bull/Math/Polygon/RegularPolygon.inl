namespace Bull
{
    template<typename T, std::size_t S>
    RegularPolygon<T, S>::RegularPolygon() :
        m_radius(0)
    {
        /// Nothing
    }

    template<typename T, std::size_t S>
    RegularPolygon<T, S>::RegularPolygon(const Vector2<T>& center, T radius, const Angle<T>& rotation) :
        m_radius(static_cast<T>(radius)),
        m_rotation(static_cast<T>(rotation)),
        m_center(center)
    {
        update();
    }

    template<typename T, std::size_t S>
    Vector2<T> RegularPolygon<T, S>::getVertex(std::size_t index) const
    {
        return m_vertices.at(index);
    }

    template<typename T, std::size_t S>
    std::size_t RegularPolygon<T, S>::getVertexCount() const
    {
        return m_vertices.size();
    }

    template<typename T, std::size_t S>
    RegularPolygon<T, S>& RegularPolygon<T, S>::setCenter(const Vector2<T>& center)
    {
        m_center = center;

        update();

        return (*this);
    }

    template<typename T, std::size_t S>
    Vector2<T> RegularPolygon<T, S>::getCenter() const
    {
        return m_center;
    }

    template<typename T, std::size_t S>
    RegularPolygon<T, S>& RegularPolygon<T, S>::setRotation(const Angle<T>& rotation)
    {
        m_rotation = rotation;

        update();

        return (*this);
    }

    template<typename T, std::size_t S>
    const Angle<T>& RegularPolygon<T, S>::getRotation() const
    {
        return m_rotation;
    }

    template<typename T, std::size_t S>
    RegularPolygon<T, S>& RegularPolygon<T, S>::setRadius(T radius)
    {
        m_radius = static_cast<T>(radius);

        update();

        return (*this);
    }

    template<typename T, std::size_t S>
    T RegularPolygon<T, S>::getRadius() const
    {
        return m_radius;
    }

    template<typename T, std::size_t S>
    void RegularPolygon<T, S>::update()
    {
        Angle<T> angle = m_rotation, step = Angle<T>::degree(360 / getVertexCount());

        if(getVertexCount() % 2 == 0)
        {
            angle += step / 2;
        }

        for(Vector2<T>& vertex : m_vertices)
        {
            vertex.x = std::cos(angle) * m_radius;
            vertex.y = std::sin(angle) * m_radius;

            angle += step;
        }
    }
}
