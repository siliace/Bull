#ifndef BULL_FONTLOADER_HPP
#define BULL_FONTLOADER_HPP

#include <ft2build.h>
#include FT_FREETYPE_H

#include <Bull/Core/Pattern/Singleton.hpp>

#include <Bull/Utility/Glyph.hpp>

namespace Bull
{
    namespace prv
    {
        class FontLoader : public Singleton<FontLoader>
        {
        public:

            bool loadFromPath(const Path& path, std::unsorted_map<char, Glyph>& glyphs);
        };
    }
}

#endif // BULL_FONTLOADER_HPP
