#ifndef BULL_CORE_UTILITY_SIZE_HPP
#define BULL_CORE_UTILITY_SIZE_HPP

#include <Bull/Core/Export.hpp>

namespace Bull
{
    struct BULL_CORE_API Size
    {
        /*! \brief Default constructor
         *
         */
        Size();

        /*! \brief Constructor
         *
         * \param width  The width of the Size
         * \param height The height of the Size
         *
         */
        Size(int width, int height);

        /*! \brief Compare two Size
         *
         * \param right The Size to compare to this
         *
         * \return True if this and right are equal
         *
         */
        bool operator==(const Size& right) const;

        /*! \brief Compare two Size
         *
         * \param right The Size to compare to this
         *
         * \return True if this and right are not equal
         *
         */
        bool operator!=(const Size& right) const;

        /*! \brief Get the ratio of the Size
         *
         * Get the result of width / height
         *
         * \return The ratio
         *
         */
        float getRatio() const;

        Size& operator+=(const Size& right);
        Size& operator-=(const Size& right);
        Size& operator*=(int right);
        Size& operator/=(int right);

        Size operator+(const Size& right) const;
        Size operator-(const Size& right) const;
        Size operator*(int right) const;
        Size operator/(int right) const;

        int width, height;
    };
}

#endif // BULL_CORE_UTILITY_SIZE_HPP
