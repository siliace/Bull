#ifndef BULL_CORE_UTILITY_SIZE_HPP
#define BULL_CORE_UTILITY_SIZE_HPP

#include <limits>
#include <numeric>
#include <tuple>

namespace Bull
{
    template <typename T>
    class Size
    {
    public:

        static_assert(std::is_arithmetic<T>::value, "T type is not arithmetic");

        static Size Zero;
        static Size Infinite;

    public:

        /*! \brief Default constructor
         *
         */
        Size() :
            Size(0, 0)
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
                m_width(width),
                m_height(height)
        {
            /// Nothing
        }

        /*! \brief Get the ratio of the Size
         *
         * Get the result of width / height
         *
         * \return The ratio
         *
         */
        template <typename U>
        float getRatio() const
        {
            return static_cast<float>(m_width) / static_cast<float>(m_height);
        }

        /*! \brief
         *
         * \return
         *
         */
        T getWidth() const
        {
            return m_width;
        }

        /*! \brief
         *
         * \param width
         *
         */
        void setWidth(T width)
        {
            m_width = width;
        }

        /*! \brief
         *
         * \return
         *
         */
        T getHeight() const
        {
            return m_height;
        }

        /*! \brief
         *
         * \param height
         *
         */
        void setHeight(T height)
        {
            m_height = height;
        }

        bool operator==(const Size& rhs) const
        {
            return std::tie(m_width, m_height) == std::tie(rhs.m_width, rhs.m_height);
        }

        bool operator!=(const Size& rhs) const
        {
            return std::tie(m_width, m_height) != std::tie(rhs.m_width, rhs.m_height);
        }

        /*! \brief
         *
         * \param rhs
         *
         * \return
         *
         */
        Size<T> operator+(const Size<T>& rhs) const
        {
            return {m_width + rhs.m_width, m_height + rhs.m_height};
        }

        /*! \brief
         *
         * \param rhs
         *
         * \return
         *
         */
        Size<T>& operator+=(const Size<T>& rhs)
        {
            m_width += rhs.m_width;
            m_height += rhs.m_height;

            return *this;
        }

        /*! \brief
         *
         * \param rhs
         * \return
         */
        Size<T> operator/(T rhs) const
        {
            return {m_width / rhs, m_height / rhs};
        }

    private:

        T m_width;
        T m_height;
    };

    template <typename T>
    Size<T> Size<T>::Zero(0, 0);

    template <typename T>
    Size<T> Size<T>::Infinite(std::numeric_limits<T>::max(), std::numeric_limits<T>::max());
}

#endif // BULL_CORE_UTILITY_SIZE_HPP
