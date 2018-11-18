#ifndef BULL_MEMORYACCUMULATOR_HPP
#define BULL_MEMORYACCUMULATOR_HPP

#include <Bull/Core/IO/OutStream.hpp>
#include <Bull/Core/Memory/ByteArray.hpp>

namespace Bull
{
    class BULL_CORE_API MemoryAccumulator : public OutStream
    {
    public:

        /*! \brief Write a ByteArray into the MemoryAccumulator
         *
         * \param bytes Bytes to write
         *
         * \return The number of bytes written
         *
         */
        std::size_t write(const ByteArray& bytes) override;

        /*! \brief Write the content of a memory area into the MemoryAccumulator
         *
         * \param data   The memory area to write
         * \param length The length of the memory area
         *
         * \return The number of bytes written
         *
         */
        std::size_t write(const void* data, std::size_t length);

        /*! \brief Flush the MemoryAccumulator
         *
         * Writing operations are immediate so flushing doesn't have any effect
         *
         */
        void flush() override;

        /*! \brief Get bytes written so far
         *
         * \return Bytes written
         *
         */
        const ByteArray& getBytes() const;

    private:

        ByteArray m_bytes;
    };
}

#endif //BULL_MEMORYACCUMULATOR_HPP
