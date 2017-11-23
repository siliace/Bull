#ifndef BULL_CORECURSORIMPL_HPP
#define BULL_CORECURSORIMPL_HPP

#include <Bull/Core/Image/Image.hpp>
#include <Bull/Core/Pattern/NonCopyable.hpp>
#include <Bull/Core/Window/CursorType.hpp>
#include <Bull/Core/Window/CursorHandler.hpp>

namespace Bull
{
    namespace prv
    {
        class CursorImpl : public NonCopyable
        {
        public:

            /*! \brief Create a OS specific CursorImpl instance
             *
             * \return The instance
             *
             */
            static ImplPtr<CursorImpl> createInstance();

        public:

            /*! \brief Destructor
             *
             */
            virtual ~CursorImpl();

            /*! \brief Create a Cursor from the system
             *
             * \param cursor The type of cursor to create
             *
             * \return True if the cursor was created successfully
             *
             */
            virtual bool create(CursorType cursor) = 0;

            /*! \brief Create a Cursor from an image
             *
             * \param cursor  The image of the Cursor
             * \param hotSpot The hotspot of the Cursor
             *
             * \return True if the cursor was created successfully
             *
             */
            virtual bool create(const Image& cursor, const Vector2UI& hotSpot) = 0;

            /*! \brief Get the native system handler of the cursor
             *
             * \return The system handler
             *
             */
            virtual CursorHandler getSystemHandler() const = 0;

        protected:

            /*! \brief Default constructor
             *
             */
            CursorImpl() = default;
        };
    }
}

#endif // BULL_CORECURSORIMPL_HPP
