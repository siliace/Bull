#ifndef BULL_TEXT_HPP
#define BULL_TEXT_HPP

#include <Bull/Core/String.hpp>

#include <Bull/Render/Font.hpp>
#include <Bull/Render/Texture.hpp>

namespace Bull
{
    class BULL_API Text : public NonCopyable
    {
    public:

        /*! \brief Default constructor
         *
         */
        Text();

        /*! \brief Constructor
         *
         * \param text
         * \param font
         * \param fontSize
         *
         */
        Text(const String& text, const Font& font, unsigned int fontSize);

        /*! \brief
         *
         * \return
         *
         */
        const Texture& getTexture() const;

    private:

        Font         m_font;
        String       m_text;
        Texture      m_texture;
        unsigned int m_fontSize;
    };
}

#endif // BULL_TEXT_HPP
