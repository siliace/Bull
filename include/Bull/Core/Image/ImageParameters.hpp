#ifndef BULL_CORE_LOADER_IMAGEPARAMETERS_HPP
#define BULL_CORE_LOADER_IMAGEPARAMETERS_HPP

#include <Bull/Core/Export.hpp>
#include <Bull/Core/Image/ImageFormat.hpp>
#include <Bull/Core/Resource/ParameterBag.hpp>

namespace Bull
{
    struct BULL_CORE_API ImageParameters : public ParameterBag
    {
        enum Channels
        {
            Default   = 0,
            Grey      = 1,
            GreyAlpha = 2,
            RGB       = 3,
            RGBA      = 4,
        };

        int         stride   = 0;
        int         quality  = 100;
        Channels    channels = RGBA;
        ImageFormat format   = ImageFormat::Png;
    };
}

#endif // BULL_CORE_LOADER_IMAGEPARAMETERS_HPP
