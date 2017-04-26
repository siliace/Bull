#ifndef Bull_Viewport_hpp
#define Bull_Viewport_hpp

#include <Bull/Math/Vector/Vector2.hpp>

namespace Bull
{
    struct Viewport
    {
        /*! \brief Default constructor
         *
         */
        Viewport();

        /*! \brief Constructor
         *
         * \param x
         * \param y
         * \param width
         * \param height
         *
         */
        Viewport(int x, int y, int width, int height);

        /*! \brief Constructor
         *
         * \param position
         * \param size
         *
         */
        Viewport(const Vector2I& position, const Vector2I& size);

        /*! \brief Compare two viewports
         *
         * \param right The viewport to compare to this one
         *
         * \return Return true if this and right are equal, false otherwise
         *
         */
        bool operator==(const Viewport& right) const;

        /*! \brief Compare two viewports
         *
         * \param right The viewport to compare to this one
         *
         * \return Return true if this and right not are equal, false otherwise
         *
         */
        bool operator!=(const Viewport& right) const;

        /*! \brief Move the viewport
         *
         * \param offset The offset to move the viewport
         *
         */
        void move(const Vector2I& offset);

        /*! \brief Move the viewport
         *
         * \param x The offset on x-axis
         * \param y The offset on y-axis
         *
         */
        void move(int x, int y);

        int x, y;
        int width, height;
    };
}

#endif // Bull_Viewport_hpp