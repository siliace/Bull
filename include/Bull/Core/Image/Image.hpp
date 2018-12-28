#ifndef BULL_CORE_IMAGE_IMAGE_HPP
#define BULL_CORE_IMAGE_IMAGE_HPP

#include <Bull/Core/Image/AbstractImage.hpp>
#include <Bull/Core/Utility/Color.hpp>

namespace Bull
{
    class BULL_CORE_API Image : public AbstractImage
    {
    public:

        /*! \brief Constructor
         *
         * \param pixelFormat
         *
         */
        explicit Image(PixelFormat pixelFormat = PixelFormat_Rgb8Alpha8);

        /*! \brief Constructor
         *
         * \param size The size of the Image
         *
         */
        explicit Image(const Size<std::size_t>& size, PixelFormat pixelFormat = PixelFormat_Rgb8Alpha8);

        /*! \brief Constructor
         *
         * \param pixels Pixels of the Image
         * \param size   The size of the Image
         *
         */
        Image(const ByteArray& pixels, const Size<std::size_t>& size, PixelFormat pixelFormat = PixelFormat_Rgb8Alpha8);

        /*! \brief Create the Image
         *
         * \param size The size of the Image
         *
         */
        void create(const Size<std::size_t>& size) override;

        /*! \brief Create the Image
         *
         * \param pixels Pixels of the Image
         * \param size   The size of the Image
         *
         */
        void create(const ByteArray& pixels, const Size<std::size_t>& size) override;

        /*! \brief Get the size of the Image
         *
         * \return The size
         *
         */
        Size<std::size_t> getSize() const override;

        /*! \brief Get pixels of the Image
         *
         * \return The pixels
         *
         */
        ByteArray getPixels() const override;

        /*! \brief Get the PixelFormat used by the Image
         *
         * \return The PixelFormat
         *
         */
        PixelFormat getPixelFormat() const override;

    private:

        Size<std::size_t> m_size;
        ByteArray         m_pixels;
        PixelFormat       m_pixelFormat;
    };
}

#endif // BULL_CORE_IMAGE_IMAGE_HPP
