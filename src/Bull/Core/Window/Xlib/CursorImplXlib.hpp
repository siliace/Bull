#ifndef BULL_CURSORIMPLXLIB_HPP
#define BULL_CURSORIMPLXLIB_HPP

#include <Bull/Core/Support/Xlib/Display.hpp>

#include <Bull/Core/Window/CursorImpl.hpp>

namespace Bull
{
    namespace prv
    {
        class CursorImplXlib : public CursorImpl
        {
        public:

            /*! \brief Default constructor
             *
             */
            CursorImplXlib();

            /*! \brief Destructor
             *
             */
            ~CursorImplXlib();

            /*! \brief Create a Cursor from the system
             *
             * \param cursor The type of cursor to create
             *
             * \return True if the cursor was created successfully
             *
             */
            bool create(Cursor::Type cursor) override;

            /*! \brief Create a Cursor from an image
             *
             * \param cursor  The image of the Cursor
             * \param hotSpot The hotspot of the Cursor
             *
             * \return True if the cursor was created successfully
             *
             */
            bool create(const Image& cursor, const Vector2UI& hotSpot) override;

            /*! \brief Get the native system handler of the cursor
             *
             * \return The system handler
             *
             */
            CursorHandler getSystemHandler() const override;

        private:

            /*! \brief Destructor the cursor
             *
             */
            void destroy();

            XCursor            m_cursor;
            Display::Instance  m_display;
        };
    }
}

#endif //BULL_CURSORIMPLXLIB_HPP