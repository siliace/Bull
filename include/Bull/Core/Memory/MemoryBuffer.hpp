#ifndef BULL_MEMORYBUFFER_HPP
#define BULL_MEMORYBUFFER_HPP

#include <memory>

#include <Bull/Core/Memory/Buffer.hpp>
#include <Bull/Core/Memory/BufferHandler.hpp>

#include <Bull/Core/System/Integer.hpp>

namespace Bull
{
    class BULL_API MemoryBuffer : public Buffer
    {
    public:

        using HandlerType = BufferHandler<Uint8>;

    private:

        using SharedHandlerType = std::shared_ptr<BufferHandler<Uint8>>;

        /*! @brief Get the empty handler shared by all empty buffers
         *
         * @return The empty handler
         *
         */
        static SharedHandlerType& getEmptyHandler();

    public:

        /*! @brief Default constructor
         *
         */
        MemoryBuffer() = default;

        /*! @brief Constructor
         *
         * @param capacity The buffer capacity
         *
         */
        MemoryBuffer(std::size_t capacity);

        /*! @brief Constructor
         *
         * @param capacity The capacity of the buffer
         * @param byte     The value to use to fill the buffer
         *
         */
        MemoryBuffer(std::size_t capacity, Uint8 byte);

        /*! @brief Create the Buffer
         *
         * @param capacity The capacity of the Buffer to create
         *
         * @return True if the Buffer was created successfully
         *
         */
        bool create(std::size_t capacity) override;

        /*! @brief Fill the buffer
         *
         * @param data    Data to insert in the Buffer
         * @param size    The length of data
         * @param offset  The offset of the data in the Buffer
         * @param discard True to flush the Buffer before fill it
         *
         * @return True if the buffer was filled successfully
         *
         */
        bool fill(const void* data, std::size_t size, std::size_t offset = 0, bool discard = false) override;

        /*! @brief Get the value from the buffer
         *
         * @param index The index of the value to get
         *
         * @return A reference to the indexth value of the buffer
         *
         */
        Uint8& at(std::size_t index);

        /*! @brief Get the value from the buffer
         *
         * @param index The index of the value to get
         *
         * @return The indexth value of the buffer
         *
         */
        const Uint8& at(std::size_t index) const;

        /*! @brief Get the value from the buffer
         *
         * @param index The index of the value to get
         *
         * @return The indexth value of the buffer
         *
         */
        Uint8& operator[](std::size_t index);

        /*! @brief Get the value from the buffer
         *
         * @param index The index of the value to get
         *
         * @return The indexth value of the buffer
         *
         */
        const Uint8& operator[](std::size_t index) const;

        /*! @brief Flush the Buffer
         *
         */
        void flush() override;

        /*! @brief Destroy the Buffer
         *
         */
        void destroy() override;

        /*! @brief Get the capacity of the Buffer
         *
         * @return The size
         *
         */
        std::size_t getCapacity() const override;

    private:

        SharedHandlerType m_buffer;
    };
}

#endif //BULL_MEMORYBUFFER_HPP
