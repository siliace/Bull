#ifndef BULL_CORE_UTILITY_COLOR_HPP
#define BULL_CORE_UTILITY_COLOR_HPP

#include <Bull/Core/Export.hpp>

namespace Bull
{
    struct BULL_CORE_API Color
    {
        static Color Red;
        static Color Green;
        static Color Blue;
        static Color Yellow;
        static Color Magenta;
        static Color Cyan;
        static Color Black;
        static Color White;
        static Color Transparent;

        /** \brief Default constructor
         *
         */
        Color();

        /** \brief Constructor
         *
         * \param red   The red component of the color
         * \param green The green component of the color
         * \param blue  The blue component of the color
         * \param alpha The alpha (opacity) component of the color
         *
         */
        Color(Uint8 red, Uint8 blue, Uint8 green, Uint8 alpha = 255);

        /** \brief Constructor
         *
         * \param hexa The hexadecimal representation of the color
         *
         */
        explicit Color(Uint32 hexa);

        /** \brief Compare two colors
         *
         * \param right The color to compare to this one
         *
         * \return Return true if right and this are the same, false otherwise
         *
         */
        bool operator==(const Color& right);

        /** \brief Compare two colors
         *
         * \param right The color to compare to this one
         *
         * \return Return true if right and this are not the same, false otherwise
         *
         */
        bool operator!=(const Color& right);

        /** \brief Convert the color to an hexadecimal value
         *
         * \return Return the representation of the color as an hexadecimal value
         *
         */
        Uint32 toHexa() const;

        /** \brief Combine two colors
         *
         * \param right The color to compare to this
         *
         * \return Return the sum of right and this
         *
         */
        Color& operator+=(const Color& right);

        /** \brief Combine two colors
         *
         * \param right The color to compare to this
         *
         * \return Return the sum of right and this
         *
         */
        Color operator+(const Color& right);

        /** \brief Combine two colors
         *
         * \param right The color to compare to this
         *
         * \return Return the subtract of right and this
         *
         */
        Color& operator-=(const Color& right);

        /** \brief Combine two colors
         *
         * \param right The color to compare to this
         *
         * \return Return the subtract of right and this
         *
         */
        Color operator-(const Color& right);

        Uint8 red;
        Uint8 green;
        Uint8 blue;
        Uint8 alpha;
    };
}

#endif // BULL_CORE_UTILITY_COLOR_HPP
