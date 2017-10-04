#include <Bull/Core/Image/ImageFormat.hpp>
#include <Bull/Core/Image/ImageParameterBag.hpp>
#include <Bull/Core/Loader/ParameterNotFound.hpp>

namespace Bull
{
    ImageParameterBag::ImageParameterBag(ImageFormat format)
    {
        setImageFormat(format);
    }

    ImageParameterBag& ImageParameterBag::setImageFormat(ImageFormat format)
    {
        setParameter("image_format", format);

		return (*this);
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