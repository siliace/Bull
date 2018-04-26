#ifndef BULL_CORE_WINDOW_CURSORIMPL_HPP
#define BULL_CORE_WINDOW_CURSORIMPL_HPP

#include <memory>

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
            static std::unique_ptr<CursorImpl> createInstance();

        public:

            /*! \brief Destructor
             *
             */
            virtual ~CursorImpl();

            /*! \brief Create a Cursor from the system
             *
             * \param cursor The type of cursor to create
             *
             */
            virtual void create(CursorType cursor) = 0;

            /*! \brief Create a Cursor from an image
             *
             * \param cursor  The image of the Cursor
             * \param hotSpot The hotspot of the Cursor
             *
             */
            virtual void create(const Image& cursor, const Size& hotSpot) = 0;

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

#endif // BULL_CORE_WINDOW_CURSORIMPL_HPP
