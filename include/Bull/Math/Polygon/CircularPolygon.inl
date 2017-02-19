namespace Bull
{
    template<typename T, std::size_t S>
    CircularPolygon<T, S>::CircularPolygon() :
        m_radius(static_cast<T>(0.0))
    {
        /// Nothing
    }

    template<typename T, std::size_t S>
    template<typename U, typename V, typename W>
    CircularPolygon<T, S>::CircularPolygon(const Vector2<U>& center, V radius, const Angle<W>& rotation) :
        m_radius(static_cast<T>(radius)),
        m_rotation(static_cast<T>(rotation)),
        m_center(center)
    {
        update();
    }

    template<typename T, std::size_t S>    Vector2<T> CircularPolygon<T, S>::getVertex(std::size_t index) const
    {
        return m_vertices[index];
    }

    template<typename T, std::size_t S>
    std::size_t CircularPolygon<T, S>::getVertexCount() const
    {
        return m_vertices.size();
    }

    template<typename T, std::size_t S>
    template<typename U>
    CircularPolygon<T, S>& CircularPolygon<T, S>::setCenter(const Vector2<U>& center)
    {
        m_center = static_cast<T>(center);

        update();

        return (*this);
    }

    template<typename T, std::size_t S>
    Vector2<T> CircularPolygon<T, S>::getCenter() const
    {
        return m_center;
    }

    template<typename T, std::size_t S>
    template<typename U>
    CircularPolygon<T, S>& CircularPolygon<T, S>::setRadius(U radius)
    {
        m_radius = static_cast<T>(radius);

        update();

        return (*this);
    }

    template<typename T, std::size_t S>
    T CircularPolygon<T, S>::getRadius() const
    {
        return m_radius;
    }

    template<typename T, std::size_t S>
    void CircularPolygon<T, S>::update()
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
