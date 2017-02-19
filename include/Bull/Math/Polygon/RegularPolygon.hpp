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
        RegularPolygon();

        /*! \brief Constructor
         *
         * \param center   The center of the polygon
         * \param radius   The radius of the polygon
         * \param rotation The rotation of the polygon
         *
         */
        template<typename U, typename V, typename W = T>
        RegularPolygon(const Vector2<U>& center, V radius = 0.0, const Angle<W>& rotation = Angle<W>::Zero);

        /*! \brief Get a vertex form the polygon
         *
         * \param index The index of the vertex to get
         *
         * \return The vertex
         */
        Vector2<T> getVertex(std::size_t index) const override;

        /*! \brief Get the number of vertex in the polygon
         *
         * \return The number of vertex
         *
         */
        std::size_t getVertexCount() const override;

        /*! \brief Set the center of the polygon
         *
         * \param center The new center
         *
         * \return This
         *
         */
        template<typename U>
        RegularPolygon<T, S>& setCenter(const Vector2<U>& center);

        /*! \brief Get the center of the polygon
         *
         * \return The center
         *
         */
        Vector2<T> getCenter() const;

        template<typename U>
        RegularPolygon<T, S>& setRotation(const Angle<U>& rotation);

        const Angle<T>& getAngle() const;

        /*! \brief Set the radius of the polygon
         *
         * \param radius The new radius
         *
         * \return This
         *
         */
        template<typename U>
        RegularPolygon<T, S>& setRadius(U radius);

        /*! \brief Get the radius of the polygon
         *
         * \return The radius
         *
         */
        T getRadius() const;

    protected:

        /*! \brief Update vertices
         *
         */
        void update();

        T                         m_radius;
        Angle<T>                  m_rotation;
        Vector2<T>                m_center;
        std::array<Vector2<T>, S> m_vertices;
    };
}

#include <Bull/Math/Polygon/RegularPolygon.inl>

#endif // BULL_REGULARPOLYGON_HPP
