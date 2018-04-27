#ifndef BULL_CORE_IMAGE_IMAGETRANSFORMER_HPP
#define BULL_CORE_IMAGE_IMAGETRANSFORMER_HPP

#include <Bull/Core/Image/EdgeMode.hpp>
#include <Bull/Core/Image/Image.hpp>

namespace Bull
{
    class BULL_CORE_API ImageTransformer
    {
    public:

        /*! \brief Constructor
         *
         * \param image The image to transform
         *
         */
        explicit ImageTransformer(const Image& image);

        /*! \return Resize the Image
         *
         * \param size The new size of the Image
         * \param mode The EdgeMode to apply the the resized Image is bigger
         *
         * \return This
         *
         */
        ImageTransformer& resize(const Size& size, EdgeMode mode = EdgeMode_None);

        /*! \brief Get the processed Image
         *
         * \return The Image
         *
         */
        const Image& getImage() const;

    private:

        Image m_image;
    };
}

#endif // BULL_CORE_IMAGE_IMAGETRANSFORMER_HPP
