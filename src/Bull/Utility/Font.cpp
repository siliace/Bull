#include <Bull/Utility/Font.hpp>
#include <Bull/Utility/FontLoader.hpp>

namespace Bull
{
    Font::Font(const Path& path)
    {
        loadFromPath(path);
    }

    bool Font::loadFromPath(const Path& path)
    {
        return prv::FontLoader::get()->loadFromPath(path, m_characterSet);
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
