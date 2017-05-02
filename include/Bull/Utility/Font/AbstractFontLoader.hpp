#ifndef BULL_ABSTRACTFONTLOADER_HPP
#define BULL_ABSTRACTFONTLOADER_HPP

#include <unordered_map>

#include <Bull/Core/FileSystem/Path.hpp>

#include <Bull/Utility/Font/Glyph.hpp>

namespace Bull
{
    struct BULL_API AbstractFontLoader
    {
        /*! \brief Load glyphs from a font
         *
         * \param path         The path of the font file
         * \param characterSet The character set to fill
         *
         * \return True if glyphs were loaded successfully
         *
         */
        virtual bool loadFromPath(const Path& path, std::unordered_map<unsigned char, Glyph>& characterSet) const = 0;
    };
}

#endif // BULL_ABSTRACTFONTLOADER_HPP
