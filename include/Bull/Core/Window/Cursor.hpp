#ifndef BULL_CORE_WINDOW_CURSOR_HPP
#define BULL_CORE_WINDOW_CURSOR_HPP

#include <memory>

#include <Bull/Core/Export.hpp>
#include <Bull/Core/Image/Image.hpp>
#include <Bull/Core/Pattern/NonCopyable.hpp>

#include <Bull/Math/Vector/Vector2.hpp>

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

        enum Type
        {
            Crosshair,
            Default,
            Hand,
            Help,
            Move,
            None,
            Pointer,
            Progress,
            ResizeE,
            ResizeN,
            ResizeNE,
            ResizeNW,
            ResizeS,
            ResizeSE,
            ResizeSW,
            ResizeW,
            Text,
            Wait,
            NotAllowed,
        };

    public:

        /*! \brief Default constructor
         *
         */
        Cursor();

        /*! \brief Destructor
         *
         */
        ~Cursor();

        /*! \brief Create a Cursor from the system
         *
         * \param cursor The type of cursor to create
         *
         * \return True if the cursor was created successfully
         *
         */
        bool create(Type cursor);

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

#endif // BULL_CORE_WINDOW_CURSOR_HPP