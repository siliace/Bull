#ifndef BULL_FONTLOADER_HPP
#define BULL_FONTLOADER_HPP

#include <ft2build.h>
#include FT_FREETYPE_H

#include <Bull/Utility/AbstractFontLoader.hpp>

namespace Bull
{
    namespace prv
    {
        class FontLoader : public AbstractFontLoader
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
            bool loadFromPath(const Path& path, std::unordered_map<unsigned char, Glyph>& characterSet) const override;

        private:

            FT_Library m_library;
        };
    }
}


#endif // BULL_FONTLOADER_HPP
