#include <Bull/Core/System/Config.hpp>

#include <Bull/Utility/Font/Font.hpp>
#include <Bull/Utility/Font/FontLoader.hpp>

std::unique_ptr<Bull::AbstractFontLoader> Bull::Font::s_loader = std::make_unique<FONT_LOADER>();

namespace Bull
{
    Font::Font(const Path& path)
    {
        loadFromPath(path);
    }

    bool Font::loadFromPath(const Path& path)
    {
        return false;
    }

    bool Font::isValid() const
    {
        return m_characterSet.size() > 0;
    }

    const Glyph& Font::getGlyph(unsigned char character) const
    {
        return m_characterSet.at(character);
    }
}
