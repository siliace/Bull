#ifndef BULL_CORE_IMAGE_IMAGE_HPP
#define BULL_CORE_IMAGE_IMAGE_HPP

#include <Bull/Core/Image/AbstractImage.hpp>
#include <Bull/Core/Utility/Color.hpp>

namespace Bull
{
    class BULL_CORE_API Image : public AbstractImage
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
        bool create(const Vector2UI& size) override;

        /*! \brief Create the Image
         *
         * \param pixels Pixels of the Image
         * \param size   The size of the Image
         *
         * \return True if the Image was created successfully
         *
         */
        bool create(const ByteVector& pixels, const Vector2UI& size) override;

        /*! \brief Fill the Image with a Color
         *
         * \param color The Color
         *
         * \return This
         *
         */
        Image& fill(const Color& color);

        /*! \brief Flip the Image vertically
         *
         * \return This
         *
         */
        Image& flipVertically();

        /*! \brief Flip the Image horizontally
         *
         * \return This
         *
         */
        Image& flipHorizontally();

        /*! \brief Get pixels of the Image
         *
         * \return The pixels
         *
         */
        const ByteVector& getPixels() const;

        /*! \brief Get the size of the Image
         *
         * \return The size
         *
         */
        const Vector2UI& getSize() const override;

    private:

        Vector2UI m_size;
        ByteVector m_pixels;
    };
}

#endif // BULL_CORE_IMAGE_IMAGE_HPP
