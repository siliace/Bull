#ifndef BULL_CORE_IMAGE_IMAGE_HPP
#define BULL_CORE_IMAGE_IMAGE_HPP

#include <Bull/Core/Assets/Asset.hpp>
#include <Bull/Core/Image/AbstractImage.hpp>
#include <Bull/Core/Utility/Color.hpp>

namespace Bull
{
    class BULL_CORE_API Image : public AbstractImage, public Asset
    {
    public:

        /*! \brief Default constructor
         *
         */
        Image() = default;

        /*! \brief Constructor
         *
         * \param size The size of the Image
         *
         */
        explicit Image(const Size& size);

        /*! \brief Constructor
         *
         * \param pixels Pixels of the Image
         * \param size   The size of the Image
         *
         */
        Image(const ByteArray& pixels, const Size& size);

        /*! \brief Create the Image
         *
         * \param size The size of the Image
         *
         */
        void create(const Size& size) override;

        /*! \brief Create the Image
         *
         * \param pixels Pixels of the Image
         * \param size   The size of the Image
         *
         */
        void create(const ByteArray& pixels, const Size& size) override;

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
         */
        void fill(const Color& color);

        /*! \brief Get the size of the Image
         *
         * \return The size
         *
         */
        Size getSize() const override;

        /*! \brief Get pixels of the Image
         *
         * \return The pixels
         *
         */
        ByteArray getPixels() const override;

    private:

        Size m_size;
        ByteArray m_pixels;
    };
}

#endif // BULL_CORE_IMAGE_IMAGE_HPP
