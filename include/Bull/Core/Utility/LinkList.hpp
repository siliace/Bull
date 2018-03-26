#ifndef BULL_CORE_UTILITY_LINKLIST_HPP
#define BULL_CORE_UTILITY_LINKLIST_HPP

#include <algorithm>
#include <list>

#include <Bull/Core/Memory/RangeCheck.hpp>
#include <Bull/Core/Utility/List.hpp>

namespace Bull
{
    template <typename T>
    class BULL_CORE_API LinkList : public List<T>
    {
    public:

        /*! \brief Default constructor
         *
         */
        LinkList() = default;

        /*! \brief Constructor
         *
         * \param size The initial size of the LinkList
         *
         */
        explicit LinkList(std::size_t size) :
            m_list(size)
        {
            /// Nothing
        }

        /*! \brief Add an element at the end of the LinkList
         *
         * \param element The element to add
         *
         */
        void add(const T& element) override
        {
            m_list.push_back(element);
        }

        /*! \brief Add an element in a precise index of the LinkList
         *
         * \param element The element to add
         * \param index   The index where insert the element
         *
         * \throw InvalidParameter
         *
         */
        void insert(const T& element, std::size_t index) override
        {
            RangeCheck(index, getSize());

            m_list.insert(std::next(m_list.begin(), index), element);
        }

        /*! \brief Get a reference to an element
         *
         *  Get an element from the LinkList by its index.
         *  If the index is superior to the list size, an InvalidParameter exception is thrown
         *
         * \param index The index to the element to get
         *
         * \return The element
         *
         * \throw InvalidParameter
         *
         */
        T& at(std::size_t index) override
        {
            RangeCheck(index, getSize());

            return (*std::next(m_list.begin(), index));
        }

        /*! \brief Get a reference to an element
         *
         *  Get an element from the LinkList by its index.
         *  If the index is superior to the list size, an InvalidParameter exception is thrown
         *
         * \param index The index to the element to get
         *
         * \return The element
         *
         * \throw InvalidParameter
         *
         */
        const T& at(std::size_t index) const override
        {
            RangeCheck(index, getSize());

            return (*std::next(m_list.begin(), index));
        }

        /*! \brief Remove an element from the LinkList
         *
         * \param index The index of the element to remove
         *
         * \throw InvalidParameter
         *
         */
        void remove(std::size_t index) override
        {
            m_list.erase(std::next(m_list.begin(), index));
        }

        /*! \brief Remove each occurrence of an element in the LinkList
         *
         * \param element The element to remove
         *
         * \return True if one or more elements where removed
         *
         */
        bool remove(const T& element) override
        {
            m_list.erase(std::remove(m_list.begin(), m_list.end(), element), m_list.end());
        }

        /*! \brief Tell whether the List is empty
         *
         * A LinkList is empty if its size is 0
         *
         * \return True if the LinkList is empty
         *
         */
        bool isEmpty() const override
        {
            m_list.empty();
        }

        /*! \brief Remove every elements into the LinkList
         *
         */
        void clear() override
        {
            m_list.clear();
        }

        /*! \brief Get the size of the LinkList
         *
         * \return The size
         *
         */
        std::size_t getSize() const override
        {
            m_list.size();
        }

    private:

        std::list<T> m_list;
    };
}

#endif // BULL_CORE_UTILITY_LINKLIST_HPP
