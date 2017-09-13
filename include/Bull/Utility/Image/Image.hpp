#ifndef BULL_UTILITY_IMAGE_IMAGE_HPP
#define BULL_UTILITY_IMAGE_IMAGE_HPP

#include <Bull/Core/Loader/Resource.hpp>
#include <Bull/Core/Memory/ByteArray.hpp>

#include <Bull/Math/Vector/Vector2.hpp>

#include <Bull/Utility/Export.hpp>

namespace Bull
{
    class BULL_UTILITY_API Image : public Resource
    {
    public:

        /*! \brief Default constructor
         *
         */
        Image() = default;

        /*! \brief Create the Image
         *
         * \param size The size of the Image
         *
         * \return True if the Image was created successfully
         *
         */
        bool create(const Vector2UI& size);

        /*! \brief Create the Image
         *
         * \param pixels Pixels of the Image
         * \param size   The size of the Image
         *
         * \return True if the Image was created successfully
         *
         */
        bool create(const ByteArray& pixels, const Vector2UI& size);

        /*! \brief Get the size of the Image
         *
         * \return The size
         *
         */
        const Vector2UI& getSize() const;

        /*! \brief Get pixels of the Image
         *
         * \return The pixels
         *
         */
        const ByteArray& getPixels() const;

    private:

        Vector2UI m_size;
        ByteArray m_pixels;
    };
}

#endif // BULL_UTILITY_IMAGE_IMAGE_HPP
