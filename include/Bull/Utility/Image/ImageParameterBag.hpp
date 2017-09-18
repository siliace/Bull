#ifndef BULL_UTILITY_IMAGE_IMAGEPARAMETERBAG_HPP
#define BULL_UTILITY_IMAGE_IMAGEPARAMETERBAG_HPP

#include <Bull/Core/Loader/ParameterBag.hpp>

#include <Bull/Utility/Export.hpp>
#include <Bull/Utility/Image/ImageFormat.hpp>

namespace Bull
{
    struct BULL_UTILITY_API ImageParameterBag : public ParameterBag
    {
        /*! \brief Default constructor
         *
         */
        ImageParameterBag() = default;

        /*! \brief Constructor
         *
         * \param format The ImageFormat to use
         *
         */
        ImageParameterBag(ImageFormat format);

        /*! \brief Set the ImageFormat
         *
         * \param format The ImaeFormat to use
         *
         * \return This
         *
         */
        ImageParameterBag& setImageFormat(ImageFormat format);

        /*! \brief Get the ImageFormat used
         *
         * \return The ImageFormat
         *
         */
        ImageFormat getImageFormat() const;
    };
}

#endif // BULL_UTILITY_IMAGE_IMAGEPARAMETERBAG_HPP
