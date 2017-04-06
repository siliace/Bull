#ifndef Bull_Rectangle_hpp
#define Bull_Rectangle_hpp

#include <Bull/Math/Polygon/Polygon.hpp>
#include <Bull/Math/Vector/Vector2.hpp>

namespace Bull
{
    template<typename T>
    struct Rectangle : public Polygon<T>
    {
        /*! \brief Default constructor
         *
         */
        Rectangle();

        /*! \brief Constructor
         *
         * \param x      The x coordinate of the top-left corner
         * \param y      The y coordinate of the top-left corner
         * \param width  The width of the rectangle
         * \param height The height of the rectangle
         *
         */
        Rectangle(T x, T y, T width, T height);

        /*! \brief Constructor
         *
         * \param size The size of the rectangle
         *
         */
        Rectangle(const Vector2<T>& size);

        /*! \brief Constructor
         *
         * \param topLeft Coordinates of the top left corner of rectangle
         * \param width   The width of the rectangle
         * \param height  The height of the rectangle
         *
         */
        Rectangle(const Vector2<T>& topLeft, T width, T height);

        /*! \brief Constructor
         *
         * \param topLeft     Coordinates of the top left corner of rectangle
         * \param bottomRight Coordinates of the top bottom right of rectangle
         *
         */
        Rectangle(const Vector2<T>& topLeft, const Vector2<T>& bottomRight);

        /*! \brief Set the rectangle
         *
         * \param x      The x coordinate of the top-left corner
         * \param y      The y coordinate of the top-left corner
         * \param width  The width of the rectangle
         * \param height The height of the rectangle
         *
         * \return Return this
         *
         */
        Rectangle& set(T x, T y, T width, T height);

        /*! \brief Set the rectangle
         *
         * \param size The size of the rectangle
         *
         * \return Return this
         *
         */
        Rectangle& set(const Vector2<T>& size);

        /*! \brief Set the rectangle
         *
         * \param topLeft Coordinates of the top left corner of rectangle
         * \param width   The width of the rectangle
         * \param height  The height of the rectangle
         *
         * \return Return this
         *
         */
        Rectangle& set(const Vector2<T>& topLeft, T width, T height);

        /*! \brief Set the rectangle
         *
         * \param topLeft     Coordinates of the top left corner of rectangle
         * \param bottomRight Coordinates of the top bottom right of rectangle
         *
         * \return Return this
         *
         */
        Rectangle& set(const Vector2<T>& topLeft, const Vector2<T>& bottomRight);

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

        T x, y, width, height;
    };

    typedef Rectangle<int> RectangleI;
    typedef Rectangle<float> RectangleF;
    typedef Rectangle<double> RectangleD;
    typedef Rectangle<unsigned int> RectangleUI;
}

#include <Bull/Math/Polygon/Rectangle.inl>

#endif // Bull_Rectangle_hpp
