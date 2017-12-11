#ifndef BULL_CORE_CURSOR_CURSOR_HPP
#define BULL_CORE_CURSOR_CURSOR_HPP

#include <memory>

#include <Bull/Core/Image/Image.hpp>
#include <Bull/Core/Pattern/NonCopyable.hpp>
#include <Bull/Core/Window/CursorType.hpp>

namespace Bull
{
    class Window;

    namespace prv
    {
        class CursorImpl;
    }

    class BULL_CORE_API Cursor : public NonCopyable
    {
    public:

        /*! \brief Default constructor
         *
         */
        Cursor();

        /*! \brief Constructor by movement
         *
         * \param cursor The Cursor to move
         *
         */
        Cursor(Cursor&& cursor) noexcept = default;

        /*! \brief Destructor
         *
         */
        ~Cursor();

        /*! \brief Basic assignment operator by movement
         *
         * \param cursor The Cursor to move
         *
         * \return This
         *
         */
        Cursor& operator=(Cursor&& cursor) noexcept = default;

        /*! \brief Create a Cursor from the system
         *
         * \param cursor The type of cursor to create
         *
         * \return True if the cursor was created successfully
         *
         */
        bool create(CursorType cursor);

        /*! \brief Create a Cursor from an image
         *
         * \param image   The image of the Cursor
         * \param hotSpot The hotspot of the Cursor
         *
         * \return True if the cursor was created successfully
         *
         */
        bool create(const Image& image, const Vector2UI& hotSpot);

    private:

        friend class Window;

        /*! \brief Get the implementation of the cursor
         *
         * \return The implementation
         *
         */
        const std::unique_ptr<prv::CursorImpl>& getImpl() const;

    private:

        std::unique_ptr<prv::CursorImpl> m_impl;
    };
}

#endif // BULL_CORE_CURSOR_CURSOR_HPP
