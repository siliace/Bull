#ifndef BULL_CORE_UTILITY_SIZE_HPP
#define BULL_CORE_UTILITY_SIZE_HPP

#include <limits>

#include <Bull/Core/Export.hpp>

namespace Bull
{
    template <typename T>
    class BULL_CORE_API Size
    {
    public:

        static Size Zero;
        static Size Infinite;

    public:

        /*! \brief Default constructor
         *
         */
        Size() :
            width(0),
            height(0)
        {
            /// Nothing
        }

        /*! \brief Constructor
         *
         * \param width  The width of the Size
         * \param height The height of the Size
         *
         */
        Size(T width, T height) :
            width(width),
            height(height)
        {
            /// Nothing
        }

        template <typename U>
        Size(const Size<U>& size) :
            width(size.width),
            height(size.height)
        {
            /// Nothing
        }

        template <typename U>
        Size operator=(const Size<U>& size)
        {
            width = size.width;
            height = size.height;

            return *this;
        }

        /*! \brief Get the ratio of the Size
         *
         * Get the result of width / height
         *
         * \return The ratio
         *
         */
        template <typename U>
        U getRatio() const
        {
            return static_cast<U>(width) / static_cast<U>(height);
        }

        template <typename U>
        Size operator+=(const Size<U>& right)
        {
            width += static_cast<T>(right.width);
            height += static_cast<T>(right.height);

            return *this;
        }

    public:

        T width, height;
    };

    template <typename L, typename R>
    bool operator==(const Size<L>& left, const Size<R>& right)
    {
        return left.width == right.width &&
               left.height == right.height;
    }

    template <typename L, typename R>
    bool operator!=(const Size<L>& left, const Size<R>& right)
    {
        return !(left == right);
    }

    template <typename L, typename R>
    Size<R> operator+(const Size<L>& left, const Size<R>& right)
    {
        return { left.width + right.width, right.height + left.height };
    }

    template <typename L, typename R>
    Size<R> operator/(const Size<L>& left, R right)
    {
        return {static_cast<R>(left.width) / right, static_cast<R>(left.height) / right };
    }

    template <typename T>
    Size<T> Size<T>::Zero(0, 0);

    template <typename T>
    Size<T> Size<T>::Infinite(std::numeric_limits<T>::max(), std::numeric_limits<T>::max());

    typedef Size<int>          SizeI;
    typedef Size<unsigned int> SizeUI;
}

#endif // BULL_CORE_UTILITY_SIZE_HPP
