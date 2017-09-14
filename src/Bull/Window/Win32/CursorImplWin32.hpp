#ifndef BULL_WINDOW_WIN32_CURSORIMPLWIN32_HPP
#define BULL_WINDOW_WIN32_CURSORIMPLWIN32_HPP

#include <windows.h>

#include <Bull/Window/CursorImpl.hpp>

namespace Bull
{
    namespace prv
    {
        class CursorImplWin32 : public CursorImpl
        {
        public:

            /*! \brief Default constructor
             *
             */
            CursorImplWin32();

            /*! \brief Destructor
             *
             */
            ~CursorImplWin32();

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

            /*! \brief Destroy the cursor
             *
             */
            void destroy();

            HCURSOR m_handler;
        };
    }
}

#endif // BULL_WINDOW_WIN32_CURSORIMPLWIN32_HPP
