#ifndef BULL_CORE_IMAGE_IMAGEPARAMETERBAG_HPP
#define BULL_CORE_IMAGE_IMAGEPARAMETERBAG_HPP

#include <Bull/Core/Export.hpp>
#include <Bull/Core/Image/ImageFormat.hpp>
#include <Bull/Core/Loader/ParameterBag.hpp>

namespace Bull
{
    struct BULL_CORE_API ImageParameterBag : public ParameterBag
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

#endif // BULL_CORE_IMAGE_IMAGEPARAMETERBAG_HPP
