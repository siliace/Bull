#ifndef BULL_FONT_HPP
#define BULL_FONT_HPP

#include <Bull/Core/FileSystem/Path.hpp>

namespace Bull
{
    class BULL_API Font
    {
    public:

        /*! \brief Default constructor
         *
         */
        Font() = default;

        /*! \brief Load a font from a file
         *
         * \param path The path of the font file
         *
         * \return True if the font was loaded successfully
         *
         */
        bool loadFromPath(const Path& path);
    };
}

#endif // BULL_FONT_HPP
