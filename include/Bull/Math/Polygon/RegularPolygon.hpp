#ifndef BULL_REGULARPOLYGON_HPP
#define BULL_REGULARPOLYGON_HPP

#include <array>

#include <Bull/Math/Angle.hpp>
#include <Bull/Math/Polygon/Polygon.hpp>

namespace Bull
{
    template<typename T, std::size_t S>
    class RegularPolygon : public Polygon<T>
    {
    public:

        /*! \brief Default constructor
         *
         */
        RegularPolygon() :
            m_radius(0)
        {
            /// Nothing
        }

        /*! \brief Constructor
         *
         * \param center   The center of the polygon
         * \param radius   The radius of the polygon
         * \param rotation The rotation of the polygon
         *
         */
        explicit RegularPolygon(const Vector2<T>& center, T radius = 0.0, const Angle<T>& rotation = Angle<T>::Zero) :
            m_radius(radius),
            m_rotation(rotation),
            m_center(center)
        {
            update();
        }

        /*! \brief Get a vertex form the polygon
         *
         * \param index The index of the vertex to get
         *
         * \return The vertex
         */
        Vector2<T> getVertex(std::size_t index) const override
        {
            return m_vertices.at(index);
        }

        /*! \brief Get the number of vertex in the polygon
         *
         * \return The number of vertex
         *
         */
        std::size_t getVertexCount() const override
        {
            return m_vertices.size();
        }

        /*! \brief Set the center of the polygon
         *
         * \param center The new center
         *
         * \return This
         *
         */
        RegularPolygon<T, S>& setCenter(const Vector2<T>& center)
        {
            m_center = center;

            update();

            return (*this);
        }

        /*! \brief Get the center of the polygon
         *
         * \return The center
         *
         */
        Vector2<T> getCenter() const
        {
            return m_center;
        }

        /*! \brief Set the rotation of the polygon
         * 
         * \param rotation The new rotation
         * 
         * \return This
         */
        RegularPolygon<T, S>& setRotation(const Angle<T>& rotation)
        {
            m_rotation = rotation;

            update();

            return (*this);
        }
        
        /*! \brief Get the rotation of the polygon
         * 
         * \return The rotation
         * 
         */
        const Angle<T>& getRotation() const
        {
            return m_rotation;
        }

        /*! \brief Set the radius of the polygon
         *
         * \param radius The new radius
         *
         * \return This
         *
         */
        RegularPolygon<T, S>& setRadius(T radius)
        {
            m_radius = radius;

            update();

            return (*this);
        }

        /*! \brief Get the radius of the polygon
         *
         * \return The radius
         *
         */
        T getRadius() const
        {
            return m_radius;
        }

    private:

        /*! \brief Update vertices
         *
         */
        void update()
        {
            Angle<T> angle = m_rotation, step = Angle<T>::degree(360 / getVertexCount());

            if(getVertexCount() % 2 == 0)
            {
                angle += step / 2;
            }

            for(Vector2<T>& vertex : m_vertices)
            {
                vertex.x() = std::cos(angle) * m_radius;
                vertex.y() = std::sin(angle) * m_radius;

                angle += step;
            }
        }

    private:

        T                         m_radius;
        Angle<T>                  m_rotation;
        Vector2<T>                m_center;
        std::array<Vector2<T>, S> m_vertices;
    };
}

#endif // BULL_REGULARPOLYGON_HPP
