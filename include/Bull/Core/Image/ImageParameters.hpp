#ifndef BULL_CORE_LOADER_IMAGEPARAMETERS_HPP
#define BULL_CORE_LOADER_IMAGEPARAMETERS_HPP

#include <Bull/Core/Export.hpp>
#include <Bull/Core/Image/ImageFormat.hpp>
#include <Bull/Core/Resource/ParameterBag.hpp>

namespace Bull
{
    struct BULL_CORE_API ImageParameters : public ParameterBag
    {
        int         stride  = 0;
        int         quality = 100;
        ImageFormat format  = ImageFormat::Png;
    };
}

#endif // BULL_CORE_LOADER_IMAGEPARAMETERS_HPP
