#include <Bull/Render/TextSprite.hpp>

namespace Bull
{
    TextSprite::TextSprite(const String& text, const Font& font) :
        m_font(font),
        m_text(text)
    {
        create(text, font);
    }

    bool TextSprite::create(const String& text, const Font& font)
    {
        return true;
    }

    const String& TextSprite::getText() const
    {
        return m_text;
    }

    const Texture& TextSprite::getTexture() const
    {
        return m_texture;
    }
}
