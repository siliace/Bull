#ifndef BULL_MATH_POLYGON_RECTANGLE_HPP
#define BULL_MATH_POLYGON_RECTANGLE_HPP

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
        Rectangle()
        {
            set(0, 0, 0, 0);
        }

        /*! \brief Constructor
         *
         * \param x      The x coordinate of the top-left corner
         * \param y      The y coordinate of the top-left corner
         * \param width  The width of the rectangle
         * \param height The height of the rectangle
         *
         */
        Rectangle(T x, T y, T width, T height)
        {
            set(x, y, width, height);
        }

        /*! \brief Constructor
         *
         * \param size The size of the rectangle
         *
         */
        explicit Rectangle(const Vector2<T>& size)
        {
            set(size);
        }

        /*! \brief Constructor
         *
         * \param topLeft Coordinates of the top left corner of rectangle
         * \param width   The width of the rectangle
         * \param height  The height of the rectangle
         *
         */
        Rectangle(const Vector2<T>& topLeft, T width, T height)
        {
            set(topLeft, width, height);
        }

        /*! \brief Constructor
         *
         * \param topLeft     Coordinates of the top left corner of rectangle
         * \param bottomRight Coordinates of the top bottom right of rectangle
         *
         */
        Rectangle(const Vector2<T>& topLeft, const Vector2<T>& bottomRight)
        {
            set(topLeft, bottomRight);
        }

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
        Rectangle& set(T x, T y, T width, T height)
        {
            this->x      = x;
            this->y      = y;
            this->width  = width;
            this->height = height;

            return (*this);
        }

        /*! \brief Set the rectangle
         *
         * \param size The size of the rectangle
         *
         * \return Return this
         *
         */
        Rectangle& set(const Vector2<T>& size)
        {
            x      = 0;
            y      = 0;
            width  = size.x();
            height = size.y();

            return (*this);
        }

        /*! \brief Set the rectangle
         *
         * \param topLeft Coordinates of the top left corner of rectangle
         * \param width   The width of the rectangle
         * \param height  The height of the rectangle
         *
         * \return Return this
         *
         */
        Rectangle& set(const Vector2<T>& topLeft, T width, T height)
        {
            return set(topLeft.x, topLeft.y, width, height);
        }

        /*! \brief Set the rectangle
         *
         * \param topLeft     Coordinates of the top left corner of rectangle
         * \param bottomRight Coordinates of the top bottom right of rectangle
         *
         * \return Return this
         *
         */
        Rectangle& set(const Vector2<T>& topLeft, const Vector2<T>& bottomRight)
        {
            return set(topLeft, bottomRight.x() - topLeft.x(), bottomRight.y() - topLeft.y());
        }

        /*! \brief Get a vertex form the polygon
         *
         * \param index The index of the vertex to get
         *
         * \return The vertex
         */
        Vector2<T> getVertex(std::size_t index) const override
        {
            RangeCheck(index, 4);

            switch(index)
            {
                case 0: return Vector2<T>(x, y);
                case 1: return Vector2<T>(x + width, y);
                case 2: return Vector2<T>(x + width, y + height);
                case 3: return Vector2<T>(x, y + height);
            }
        }

        /*! \brief Get the number of vertex in the polygon
         *
         * \return The number of vertex
         *
         */
        std::size_t getVertexCount() const override
        {
            return 4;
        }

        T x, y, width, height;
    };

    typedef Rectangle<int> RectangleI;
    typedef Rectangle<float> RectangleF;
    typedef Rectangle<double> RectangleD;
    typedef Rectangle<unsigned int> RectangleUI;
}

#endif // BULL_MATH_POLYGON_RECTANGLE_HPP
