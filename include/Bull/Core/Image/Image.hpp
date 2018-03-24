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
        bool create(const Size& size) override;

        /*! \brief Create the Image
         *
         * \param pixels Pixels of the Image
         * \param size   The size of the Image
         *
         * \return True if the Image was created successfully
         *
         */
        bool create(const ByteArray& pixels, const Size& size) override;

        /*! \brief Tell whether an Image is loaded
         *
         * \return True if the Image is loaded
         *
         */
        bool isLoaded() const override;

        /*! \brief Fill the Image with a Color
         *
         * \param color The Color
         *
         * \return This
         *
         */
        Image& fill(const Color& color);

        /*! \brief Get pixels of the Image
         *
         * \return The pixels
         *
         */
        const ByteArray& getPixels() const;

        /*! \brief Get the size of the Image
         *
         * \return The size
         *
         */
        const Size& getSize() const override;

    private:

        Size       m_size;
        ByteArray m_pixels;
    };
}

#endif // BULL_CORE_IMAGE_IMAGE_HPP
