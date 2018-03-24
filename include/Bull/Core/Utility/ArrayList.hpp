#ifndef BULL_CORE_UTILITY_ARRAYLIST_HPP
#define BULL_CORE_UTILITY_ARRAYLIST_HPP

#include <algorithm>
#include <cstring>
#include <vector>

#include <Bull/Core/Memory/AbstractBuffer.hpp>
#include <Bull/Core/Memory/RangeCheck.hpp>
#include <Bull/Core/Utility/List.hpp>

namespace Bull
{
    template <typename T>
    class BULL_CORE_API ArrayList : public List<T>, public AbstractBuffer
    {
    public:

        /*! \brief Default constructor
        *
        */
        ArrayList() = default;

        /*! \brief Constructor
         *
         * \param size The size of the ArrayList
         *
         */
        explicit ArrayList(std::size_t size) :
            ArrayList<T>(size, T())
        {
            /// nothing
        }

        /*! \brief Constructor
         *
         * \param size  The size of the ArrayList 
         * \param value The value to the ArrayList 
         *
         */
        ArrayList(std::size_t size, const T& value) :
            m_array(size, value)
        {
            /// nothing
        }

        /*! \brief Create the ArrayList 
         *
         * \param capacity The capacity of the ArrayList to create
         *
         * \return True if the ArrayList was created successfully
         *
         */
        bool create(std::size_t capacity) override
        {
            if(isEmpty())
            {
                resize(capacity);

                return true;
            }

            return false;
        }

        /*! \brief Fill the buffer
         *
         * \param data   Data to insert in the ArrayList 
         * \param size   The length of data
         * \param offset The offset of the data in the ArrayList 
         *
         * \return True if the buffer was filled successfully
         *
         */
        bool fill(const void* data, std::size_t size, std::size_t offset = 0) override
        {
            if(data && size)
            {
                if(getCapacity() < size + offset)
                {
                    resize(size + offset);
                }

                std::memcpy(&m_array[offset], data, size);

                return true;
            }

            return false;
        }

        /*! \brief Add an element at the end of the ArrayList
         *
         * \param element The element to add
         *
         */
        void add(const T& element) override
        {
            m_array.push_back(element);
        }

        /*! \brief Access operator
         *
         * \param index The value to get from the ArrayList 
         *
         * \return The value
         *
         */
        T& at(std::size_t index) override
        {
            RangeCheck(index, getCapacity());

            return m_array[index];
        }

        /*! \brief Access operator
         *
         * \param index The value to get from the ArrayList 
         *
         * \return The value
         *
         */
        const T& at(std::size_t index) const override
        {
            RangeCheck(index, getCapacity());

            return m_array[index];
        }

        /*! \brief Resize the ArrayList
         *
         * \param size The size
         *
         */
        void resize(std::size_t size)
        {
            m_array.resize(size);
        }

        /*! \brief Remove an element from the ArrayList
         *
         * \param index The index of the element to remove
         *
         * \throw InvalidParameter
         *
         */
        void remove(std::size_t index) override
        {
            RangeCheck(index, getSize());

            m_array.erase(m_array.begin() + index);
        }

        /*! \brief Remove each occurrence of an element in the ArrayList
         *
         * \param element The element to remove
         *
         * \return True if one or more elements where removed
         *
         */
        bool remove(const T& element) override
        {
            if(std::find(m_array.begin(), m_array.end(), element) != m_array.end())
            {
                m_array.erase(std::remove(m_array.begin(), m_array.end(), element), m_array.end());

                return true;
            }

            return false;
        }

        /*! \brief Tell whether the List is empty
         *
         * A List is empty if its size is 0
         *
         * \return True if the List is empty
         *
         */
        bool isEmpty() const override
        {
            return m_array.empty();
        }

        /*! \brief Clear the ArrayList
         *
         */
        void clear() override
        {
            m_array.clear();
        }

        /*! \brief Get the size of the ArrayList
         *
         * \return The size
         *
         */
        std::size_t getSize() const override
        {
            return m_array.size();
        }

        /*! \brief Get a pointer to the ArrayList 
         *
         * \return The pointer
         *
         */
        const T* getBuffer() const
        {
            return m_array.data();
        }

        /*! \brief Get the capacity of the ArrayList 
         *
         * \return The capacity
         *
         */
        std::size_t getCapacity() const override
        {
            return m_array.size();
        }

    private:

        std::vector<T> m_array;
    };
}

#endif // BULL_CORE_UTILITY_ARRAYLIST_HPP
