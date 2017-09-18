#include <Bull/Core/Loader/ParameterNotFound.hpp>

#include <Bull/Utility/Image/ImageParameterBag.hpp>

namespace Bull
{
    ImageParameterBag::ImageParameterBag(ImageFormat format)
    {
        setImageFormat(format);
    }

    ImageParameterBag& ImageParameterBag::setImageFormat(ImageFormat format)
    {
        setParameter("image_format", format);
    }

    ImageFormat ImageParameterBag::getImageFormat() const
    {
        unsigned int type;

        if(getParameter("image_format", type))
        {
            return ImageFormat(type);
        }

        throw ParameterNotFound("image_format");
    }
}