namespace Bull
{
    template <typename T>
    BufferHandler<T>::BufferHandler() :
        m_capacity(0)
    {
        /// Nothing
    }

    template <typename T>
    BufferHandler<T>::BufferHandler(std::size_t capacity) :
        m_capacity(capacity)
    {
        realloc(capacity);
    }

    template <typename T>
    void BufferHandler<T>::memset(T value)
    {
        std::memset(m_data.get(), value, m_capacity * sizeof(T));
    }

    template <typename T>
    void BufferHandler<T>::memcpy(const T* data, std::size_t size, std::size_t offset)
    {
        if(size + offset > m_capacity)
        {
            realloc(size + offset);
        }

        std::memcpy(&m_data[offset], data, m_capacity);
    }

    template <typename T>
    T& BufferHandler<T>::at(std::size_t index)
    {
        if(index >= m_capacity)
        {
            throw std::out_of_range("Index in BufferHandler::at is out of range");
        }

        return m_data[index];
    }

    template <typename T>
    const T& BufferHandler<T>::at(std::size_t index) const
    {
        if(index >= m_capacity)
        {
            throw std::out_of_range("Index in BufferHandler::at is out of range");
        }

        return m_data[index];
    }

    template <typename T>
    std::size_t BufferHandler<T>::getCapacity()
    {
        return m_capacity;
    }

    template <typename T>
    void BufferHandler<T>::realloc(std::size_t capacity)
    {
        std::unique_ptr<T[]> buffer = std::make_unique<T[]>(capacity);

        if(capacity > m_capacity)
        {
            std::memset(buffer.get(), 0, capacity * sizeof(T));
        }

        if(m_data)
        {
            std::memcpy(buffer.get(), m_data.get(), std::min(m_capacity, capacity) * sizeof(T));
        }

        m_capacity = capacity;
        m_data     = std::move(buffer);
    }
}