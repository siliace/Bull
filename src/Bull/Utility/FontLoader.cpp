#include <Bull/Utility/FontLoader.hpp>

namespace Bull
{
    namespace prv
    {
        FontLoader::FontLoader() :
            m_library(nullptr)
        {
            if(FT_Init_FreeType(&m_library) != FT_Err_Ok)
            {
                throw std::runtime_error("Failed to load FreeType library");
            }
        }

        FontLoader::~FontLoader()
        {
            FT_Done_FreeType(static_cast<FT_Library>(m_library));
        }

        bool FontLoader::loadFromPath(const Path& path, std::unordered_map<unsigned char, Glyph>& characterSet) const
        {
            FT_Face face;

            if(FT_New_Face(static_cast<FT_Library>(m_library), path, 0, &face) == FT_Err_Ok)
            {
                characterSet.clear();

                for(unsigned char c = 0; c < 128; c++)
                {
                    if(FT_Load_Char(face, c, FT_LOAD_RENDER) == FT_Err_Ok)
                    {
                        Glyph glyph;
                        Vector2UI size;

                        size.x = face->glyph->bitmap.width;
                        size.y = face->glyph->bitmap.rows;

                        glyph.image   = Image(face->glyph->bitmap.buffer, size);
                        glyph.bounds  = RectangleUI(Vector2UI(face->glyph->bitmap_left, face->glyph->bitmap_top), size);
                        glyph.advance = face->glyph->advance.x;

                        characterSet.insert(std::pair<unsigned char, Glyph>(c, glyph));
                    }
                }

                FT_Done_Face(face);

                return true;
            }

            return false;
        }
    }
}
