#include <Bull/Core/Memory/BadFree.hpp>
#include <Bull/Core/Memory/MemoryAllocator.hpp>

namespace Bull
{
    namespace prv
    {
        MemoryAllocator::MemoryAllocator() :
            m_log(Log::get())
        {
            /// Nothing
        }

        MemoryAllocator::~MemoryAllocator()
        {
            if(!m_blocks.empty())
            {
                reportLeaks();
            }
        }

        void* MemoryAllocator::allocate(const std::size_t& size, bool array)
        {
            Block block;
            void* pointer = std::malloc(size);

            block.size  = size;
            block.array = array;

            m_blocks[pointer] = block;

            return pointer;
        }

        void MemoryAllocator::free(void* ptr, bool array)
        {
            BlockMap::iterator iterator = m_blocks.find(ptr);

            if(iterator != m_blocks.end())
            {
                if(iterator->second.array != array)
                {
                    throw BadFree(ptr, array);
                }

                std::free(ptr);
            }

            throw BadFree(ptr, array);
        }

        void MemoryAllocator::reportLeaks() const
        {

        }
    }
}