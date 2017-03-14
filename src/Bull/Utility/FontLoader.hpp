#ifndef BULL_FONTLOADER_HPP
#define BULL_FONTLOADER_HPP

#include <ft2build.h>
#include FT_FREETYPE_H

#include <unordered_map>

#include <Bull/Core/FileSystem/Path.hpp>
#include <Bull/Core/Pattern/Singleton.hpp>

#include <Bull/Utility/Glyph.hpp>

namespace Bull
{
    namespace prv
    {
        class FontLoader : public Singleton<FontLoader>
        {
        public:

            /*! \brief Default constructor
             *
             */
            FontLoader();

            /*! \brief Destructor
             *
             */
            ~FontLoader();

            /*! \brief Load glyphs from a font
             *
             * \param path         The path of the font file
             * \param characterSet The character set to fill
             *
             * \return True if glyphs were loaded successfully
             *
             */
            bool loadFromPath(const Path& path, std::unordered_map<unsigned char, Glyph>& characterSet);

        private:

            FT_Library m_library;
        };
    }
}

#endif // BULL_FONTLOADER_HPP
