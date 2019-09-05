#ifndef BULL_CORE_WINDOW_XLIB_CURSORIMPLXLIB_HPP
#define BULL_CORE_WINDOW_XLIB_CURSORIMPLXLIB_HPP

#include <Bull/Core/Support/Xlib/Display.hpp>

#include <Bull/Core/Window/CursorImpl.hpp>

namespace Bull
{
    namespace prv
    {
        class CursorImplXlib : public CursorImpl
        {
        public:

            /** \brief Default constructor
             *
             */
            CursorImplXlib();

            /** \brief Destructor
             *
             */
            ~CursorImplXlib();

            /** \brief Create a Cursor from the system
             *
             * \param cursor The type of cursor to create
             *
             */
            void create(CursorType cursor) override;

            /** \brief Create a Cursor from an Image
             *
             * \param cursor  The Image of the Cursor
             * \param hotSpot The hotspot of the Cursor
             *
             */
            void create(const Image& cursor, const Size<unsigned int>& hotSpot) override;

            /** \brief Get the native system handler of the cursor
             *
             * \return The system handler
             *
             */
            CursorHandler getSystemHandler() const override;

        private:

            /** \brief Destructor the cursor
             *
             */
            void destroy();

            XCursor m_handler;
            Display& m_display;
        };
    }
}

#endif //BULL_CORE_WINDOW_XLIB_CURSORIMPLXLIB_HPP
