#ifndef Bull_Rectangle_hpp
#define Bull_Rectangle_hpp

#include <functional>

#include <Bull/Core/System/Export.hpp>

#include <Bull/Math/Vector/Vector2.hpp>

namespace Bull
{
    template<typename T>
    struct BULL_API Rectangle
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
        template<typename U>
        Rectangle(U x, U y, U width, U height);

        /*! \brief Constructor
         *
         * \param size The size of the rectangle
         *
         */
        template<typename U>
        Rectangle(const Vector2<U>& size);

        /*! \brief Constructor
         *
         * \param topLeft Coordinates of the top left corner of rectangle
         * \param width   The width of the rectangle
         * \param height  The height of the rectangle
         *
         */
        template<typename U>
        Rectangle(const Vector2<U>& topLeft, U width, U height);

        /*! \brief Constructor
         *
         * \param topLeft     Coordinates of the top left corner of rectangle
         * \param bottomRight Coordinates of the top bottom right of rectangle
         *
         */
        template<typename U>
        Rectangle(const Vector2<U>& topLeft, const Vector2<U>& bottomRight);

        /*! \brief Copy constructor
         *
         * \param rectangle The rectangle to copy
         *
         */
        template<typename U>
        Rectangle(const Rectangle<U>& rectangle);

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
        template<typename U>
        Rectangle& set(U x, U y, U width, U height);

        /*! \brief Set the rectangle
         *
         * \param size The size of the rectangle
         *
         * \return Return this
         *
         */
        template<typename U>
        Rectangle& set(const Vector2<U>& size);

        /*! \brief Set the rectangle
         *
         * \param topLeft Coordinates of the top left corner of rectangle
         * \param width   The width of the rectangle
         * \param height  The height of the rectangle
         *
         * \return Return this
         *
         */
        template<typename U>
        Rectangle& set(const Vector2<U>& topLeft, U width, U height);

        /*! \brief Set the rectangle
         *
         * \param topLeft     Coordinates of the top left corner of rectangle
         * \param bottomRight Coordinates of the top bottom right of rectangle
         *
         * \return Return this
         *
         */
        template<typename U>
        Rectangle& set(const Vector2<U>& topLeft, const Vector2<U>& bottomRight);


        /*! \brief Set the rectangle
         *
         * \param rectangle The rectangle to copy
         *
         * \return Return this
         *
         */
        template<typename U>
        Rectangle& set(const Rectangle<U>& rectangle);

        T x, y, width, height;
    };

    typedef Rectangle<int> RectangleI;
    typedef Rectangle<float> RectangleF;
    typedef Rectangle<double> RectangleD;
    typedef Rectangle<unsigned int> RectangleUI;
}

#include <Bull/Math/Polygon/Rectangle.inl>

#endif // Bull_Rectangle_hpp
