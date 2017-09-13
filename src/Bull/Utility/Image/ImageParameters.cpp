#include <Bull/Utility/Image/ImageParameters.hpp>

namespace Bull
{
    ImageParameters::ImageParameters(ImageFormat format)
    {
        setFormat(format);
    }

    ImageParameters& ImageParameters::setFormat(ImageFormat format)
    {
        setParameter("format", format);

        return (*this);
    }

    ImageFormat ImageParameters::getFormat() const
    {
        unsigned int format = 0;

        getParameter("format", format);

        return ImageFormat(format);
    }
}
