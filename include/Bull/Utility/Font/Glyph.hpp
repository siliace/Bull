#ifndef BULL_GLYPH_HPP
#define BULL_GLYPH_HPP

#include <Bull/Math/Polygon/Rectangle.hpp>

#include <Bull/Utility/Image/Image.hpp>

namespace Bull
{
    struct BULL_UTILITY_API Glyph
    {
        Image        image;
        RectangleUI  bounds;
        int          advance;
    };
}

#endif // BULL_GLYPH_hpP
