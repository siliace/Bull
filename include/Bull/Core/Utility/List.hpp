#ifndef BULL_CORE_UTILITY_LIST_HPP
#define BULL_CORE_UTILITY_LIST_HPP

#include <utility>

#include <Bull/Core/Export.hpp>

namespace Bull
{
    template <typename T>
    struct BULL_CORE_API List
    {
        /*! \brief Add an element at the end of the List
         *
         * \param element The element to add
         *
         */
        virtual void add(const T& element) = 0;

        /*! \brief Add an element in a precise index of the List
         *
         * \param index   The index where insert the element
         * \param element The element to add
         *
         * \throw InvalidParameter
         *
         */
        virtual void add(std::size_t index, const T& element) = 0;

        /*! \brief Get a reference to an element
         *
         *  Get an element from the List by its index.
         *  If the index is superior to the list size, an InvalidParameter exception is thrown
         *
         * \param index The index to the element to get
         *
         * \return The element
         *
         * \throw InvalidParameter
         *
         */
        virtual T& at(std::size_t index) = 0;

        /*! \brief Get a reference to an element
         *
         *  Get an element from the List by its index.
         *  If the index is superior to the list size, an InvalidParameter exception is thrown
         *
         * \param index The index to the element to get
         *
         * \return The element
         *
         * \throw InvalidParameter
         *
         */
        virtual const T& at(std::size_t index) const = 0;

        /*! \brief Remove an element from the List
         *
         * \param index The index of the element to remove
         *
         * \throw InvalidParameter
         *
         */
        virtual void remove(std::size_t index) = 0;

        /*! \brief Remove each occurrence of an element in the List
         *
         * \param element The element to remove
         *
         * \return True if one or more elements where removed
         *
         */
        virtual bool remove(const T& element) = 0;

        /*! \brief Tell whether the List is empty
         *
         * A List is empty if its size is 0
         *
         * \return True if the List is empty
         *
         */
        virtual bool isEmpty() const = 0;

        /*! \brief Remove every elements into the List
         *
         */
        virtual void clear() = 0;

        /*! \brief Get the size of the List
         *
         * \return The size
         *
         */
        virtual std::size_t getSize() const = 0;

        /*! \brief Access operator
         *
         * \param index The value to get from the Array
         *
         * \return The value
         *
         */
        T& operator[](std::size_t index)
        {
            return at(index);
        }

        /*! \brief Access operator
         *
         * \param index The value to get from the Array
         *
         * \return The value
         *
         */
        const T& operator[](std::size_t index) const
        {
            return at(index);
        }
    };
}

#endif // BULL_CORE_UTILITY_LIST_HPP
