#ifndef BULL_CURSORIMPLXCB_HPP
#define BULL_CURSORIMPLXCB_HPP

#include <xcb/xproto.h>

#include <Bull/Window/CursorImpl.hpp>

namespace Bull
{
    namespace prv
    {
        class CursorImplXCB : public CursorImpl
        {
        public:

            /*! \brief Default constructor
             *
             */
            CursorImplXCB();

            /*! \brief Destructor
             *
             */
            ~CursorImplXCB();

            /*! \brief Create a Cursor from the system
             *
             * \param cursor The type of cursor to create
             *
             * \return True if the cursor was created successfully
             *
             */
            bool loadFromSystem(Cursor::Type cursor) override;

            /*! \brief Create a Cursor from an image
             *
             * \param cursor  The image of the Cursor
             * \param hotSpot The hotspot of the Cursor
             *
             * \return True if the cursor was created successfully
             *
             */
            bool loadFromImage(const Image& cursor, const Vector2UI& hotSpot) override;

            /*! \brief Get the native system handler of the cursor
             *
             * \return The system handler
             *
             */
            CursorHandler getSystemHandler() const override;

        private:

            xcb_cursor_t m_handler;
        };
    }
}

#endif //BULL_CURSORIMPLXCB_HPP
