#ifndef BULL_TEXTSPRITE_HPP
#define BULL_TEXTSPRITE_HPP

#include <Bull/Core/Memory/String.hpp>
#include <Bull/Core/Pattern/NonCopyable.hpp>

#include <Bull/Render/Texture.hpp>

#include <Bull/Utility/Font.hpp>

namespace Bull
{
    class BULL_API TextSprite : public NonCopyable
    {
    public:

        /*! \brief Default constructor
         *
         */
        TextSprite() = default;

        /*! \brief Constructor
         *
         * \param text The text to render
         * \param font The font to use to render the text
         *
         */
        TextSprite(const String& text, const Font& font);

        /*! \brief Create the TextSprite
         *
         * \param text The text to render
         * \param font The font to use to render the text
         *
         * \return True if the texture was created successfully
         *
         */
        bool create(const String& text, const Font& font);

        /*! \brief Get the text rendered on the texture
         *
         * \return The text
         *
         */
        const String& getText() const;

        /*! \brief Get the texture with the rendered text
         *
         * \return The texture
         *
         */
        const Texture& getTexture() const;

    private:

        Font    m_font;
        String  m_text;
        Texture m_texture;
    };
}

#endif // BULL_TEXTSPRITE_HPP
