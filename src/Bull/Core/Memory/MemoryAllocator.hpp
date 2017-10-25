#ifndef BULL_CORE_MEMORY_MEMORYALLOCATOR_HPP
#define BULL_CORE_MEMORY_MEMORYALLOCATOR_HPP

#include <map>

#include <Bull/Core/Log/Log.hpp>
#include <Bull/Core/Memory/String.hpp>
#include <Bull/Core/Pattern/Singleton.hpp>

namespace Bull
{
    namespace prv
    {
        class MemoryAllocator : public Singleton<MemoryAllocator>
        {
        public:

            /*! \brief Default constructor
             *
             */
            MemoryAllocator();

            /*! \brief Destructor
             *
             */
            virtual ~MemoryAllocator();

            /*! \brief Allocate a memory area on the heap
             *
             * \param size  The size of the memory area to allocate
             * \param array True to allocate an array
             *
             * \return A pointer to the allocated memory area
             *
             */
            void* allocate(const Index& size, bool array);

            /*! \brief Free allocated memory
             *
             * \param ptr   The pointer to free
             * \param array True if the pointer is an array
             *
             */
            void free(void* ptr, bool array);

            /*! \brief Report potential memory leaks
             *
             */
            void reportLeaks() const;

        private:

            struct Block
            {
                Index size;
                bool  array;
            };

            using BlockMap = std::map<void*, Block>;

            Log::Instance m_log;
            BlockMap      m_blocks;
        };
    }
}

#endif // BULL_CORE_MEMORY_MEMORYALLOCATOR_HPP
