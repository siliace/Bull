#ifndef BULL_REGULARPOLYGON_HPP
#define BULL_REGULARPOLYGON_HPP

#include <array>

#include <Bull/Math/Angle.hpp>
#include <Bull/Math/Polygon/Polygon.hpp>

namespace Bull
{
    template<typename T, Index S>
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
        RegularPolygon(const Vector2<T>& center, T radius = 0.0, const Angle<T>& rotation = Angle<T>::Zero);

        /*! \brief Get a vertex form the polygon
         *
         * \param index The index of the vertex to get
         *
         * \return The vertex
         */
        Vector2<T> getVertex(Index index) const override;

        /*! \brief Get the number of vertex in the polygon
         *
         * \return The number of vertex
         *
         */
        Index getVertexCount() const override;

        /*! \brief Set the center of the polygon
         *
         * \param center The new center
         *
         * \return This
         *
         */
        RegularPolygon<T, S>& setCenter(const Vector2<T>& center);

        /*! \brief Get the center of the polygon
         *
         * \return The center
         *
         */
        Vector2<T> getCenter() const;

        /*! \brief Set the rotation of the polygon
         * 
         * \param rotation The new rotation
         * 
         * \return This
         */
        RegularPolygon<T, S>& setRotation(const Angle<T>& rotation);
        
        /*! \brief Get the rotation of the polygon
         * 
         * \return The rotation
         * 
         */
        const Angle<T>& getRotation() const;

        /*! \brief Set the radius of the polygon
         *
         * \param radius The new radius
         *
         * \return This
         *
         */
        RegularPolygon<T, S>& setRadius(T radius);

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
