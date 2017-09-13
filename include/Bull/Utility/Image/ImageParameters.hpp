#ifndef BULL_UTILITY_IMAGE_IMAGEPARAMETERS_HPP
#define BULL_UTILITY_IMAGE_IMAGEPARAMETERS_HPP

#include <Bull/Core/Loader/ParameterBag.hpp>

#include <Bull/Utility/Export.hpp>
#include <Bull/Utility/Image/ImageFormat.hpp>

namespace Bull
{
    struct BULL_UTILITY_API ImageParameters : public ParameterBag
    {
        /*! \brief Default constructor
         *
         */
        ImageParameters() = default;

        /*! \brief Constructor
         *
         * \param format The ImageFormat
         *
         */
        explicit ImageParameters(ImageFormat format);

        /*! \brief Set the ImageFormat of the parameter bag
         *
         * \param format The format
         *
         * \return This
         *
         */
        ImageParameters& setFormat(ImageFormat format);

        /*! \brief Get the ImageFormat of the parameter bag
         *
         * \return The ImageFormat
         */
        ImageFormat getFormat() const;
    };
}

#endif //BULL_IMAGEPARAMETERS_HPP
