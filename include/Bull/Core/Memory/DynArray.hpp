#ifndef BULL_CORE_MEMORY_DYNARRAY_HPP
#define BULL_CORE_MEMORY_DYNARRAY_HPP

#include <memory>

#include <Bull/Core/Memory/AbstractBuffer.hpp>

namespace Bull
{
    template <typename T>
    class BULL_CORE_API DynArray : public AbstractBuffer
    {
    public:

        /*! \brief Default constructor
         *
         */
        DynArray();

        /*! \brief Constructor
         *
         * \param capacity The capacity of the DynArray
         * 
         */
        explicit DynArray(std::size_t capacity);

        /*! \brief Create the DynArray
         *
         * \param capacity The capacity of the DynArray to create
         *
         * \return True if the DynArray was created successfully
         *
         */
        bool create(std::size_t capacity) override;

        /*! \brief Tell whether the DynArray has been allocated
         *
         * \return True if the DynArray has been allocated
         *
         */
        bool isAllocated() const;

        /*! \brief Fill the dynArray
         *
         * \param data   Data to insert in the DynArray
         * \param size   The length of data
         * \param offset The offset of the data in the DynArray
         *
         * \return True if the dynArray was filled successfully
         *
         */
        bool fill(const void* data, std::size_t size, std::size_t offset = 0) override;

        /*! \brief Clear the DynArray
         *
         */
        void clear() override;

        /*! \brief Get the capacity of the DynArray
         *
         * \return The capacity
         *
         */
        std::size_t getCapacity() const override;
        
    private:

        std::shared_ptr<T[]> m_array;
        std::size_t          m_capacity;
    };
}

#include <Bull/Core/Memory/DynArray.inl>

#endif // BULL_CORE_MEMORY_DYNARRAY_HPP
