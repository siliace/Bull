#ifndef BULL_RENDER_TARGET_VIEWPORT_HPP
#define BULL_RENDER_TARGET_VIEWPORT_HPP

#include <Bull/Core/Utility/Size.hpp>

#include <Bull/Render/Export.hpp>

namespace Bull
{
    struct BULL_RENDER_API Viewport
    {
        /** \brief Default constructor
         *
         */
        Viewport() = default;

        /** \brief Constructor
         *
         * \param position
         * \param size
         *
         */
        Viewport(const Size<int>& position, const Size<unsigned int>& size);

        /** \brief Compare two viewports
         *
         * \param right The viewport to compare to this one
         *
         * \return Return true if this and right are equal, false otherwise
         *
         */
        bool operator==(const Viewport& right) const;

        /** \brief Compare two viewports
         *
         * \param right The viewport to compare to this one
         *
         * \return Return true if this and right not are equal, false otherwise
         *
         */
        bool operator!=(const Viewport& right) const;

        /** \brief Move the viewport
         *
         * \param offset The offset to move the viewport
         *
         */
        void move(const Size<int>& offset);

        Size<int> position;
        Size<unsigned int> size;
    };
}

#endif // BULL_RENDER_TARGET_VIEWPORT_HPP
