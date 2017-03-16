#include <Bull/Utility/Font.hpp>
#include <Bull/Utility/FontLoader.hpp>

namespace Bull
{
    std::unique_ptr<AbstractFontLoader> Font::loader = std::make_unique<prv::FontLoader>();

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
