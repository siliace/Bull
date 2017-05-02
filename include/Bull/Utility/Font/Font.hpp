#ifndef BULL_FONT_HPP
#define BULL_FONT_HPP

#include <unordered_map>

#include <Bull/Core/FileSystem/Path.hpp>

#include <Bull/Utility/Font/Glyph.hpp>

namespace Bull
{
    class AbstractFontLoader;

    class BULL_API Font
    {
    private:

        static std::unique_ptr<AbstractFontLoader> s_loader;

    public:

        /*! \brief Default constructor
         *
         */
        Font() = default;

        /*! \brief Constructor
         *
         * \param path The path of the font file
         *
         */
        Font(const Path& path);

        /*! \brief Load a font from a file
         *
         * \param path The path of the font file
         *
         * \return True if the font was loaded successfully
         *
         */
        bool loadFromPath(const Path& path);

        /*! \brief Check whether a font is ready to use
         *
         * \return True if the font is loaded
         *
         */
        bool isValid() const;

        /*! \brief Get a glyph from the font
         *
         * \param character The character wanted
         *
         * \return The glyph
         *
         */
        const Glyph& getGlyph(unsigned char character) const;

    private:

        std::unordered_map<unsigned char, Glyph> m_characterSet;
    };
}

#endif // BULL_FONT_HPP
