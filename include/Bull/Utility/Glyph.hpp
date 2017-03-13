#ifndef BULL_GLYPH_HPP
#define BULL_GLYPH_HPP

#include <Bull/Math/Polygon/Rectangle.hpp>

#include <Bull/Utility/Image.hpp>

namespace Bull
{
    struct BULL_API Glyph
    {
        Image        image;
        Rectangle2UI bounds;
        int          advance;
    };
}

#endif // BULL_GLYPH_hpP
