namespace Bull
{
    template <typename T>
    ObjectRef<T>::ObjectRef() :
        m_object(nullptr)
    {
        /// Nothing
    }

    template <typename T>
    ObjectRef<T>::ObjectRef(T* object) :
        m_object(object)
    {
        if(m_object)
        {
            m_object->addReference();
        }
    }

    template <typename T>
    ObjectRef<T>::ObjectRef(const ObjectRef<T>& copy) :
        m_object(copy.get())
    {
        if(m_object)
        {
            m_object->addReference();
        }
    }

    template <typename T>
    ObjectRef<T>::ObjectRef(ObjectRef<T>&& move) noexcept :
        m_object(move.get())
    {
        move.reset();
    }

    template <typename T>
    ObjectRef<T>::~ObjectRef()
    {
        release();
    }

    template <typename T>
    ObjectRef<T>& ObjectRef<T>::operator=(T* object)
    {
        reset(object);

        return (*this);
    }

    template <typename T>
    ObjectRef<T>& ObjectRef<T>::operator=(const ObjectRef<T>& copy)
    {
        reset(copy.get());

        return (*this);
    }

    template <typename T>
    ObjectRef<T>& ObjectRef<T>::operator=(ObjectRef<T>&& move) noexcept
    {
        reset(move.get());
        move.reset();

        return (*this);
    }

    template <typename T>
    bool ObjectRef<T>::isValid() const
    {
        return m_object != nullptr;
    }

    template <typename T>
    bool ObjectRef<T>::reset(T* object)
    {
        if(m_object != object)
        {
            bool destroyed = false;

            if(m_object)
            {
                destroyed = m_object->removeReference();
            }

            m_object = object;

            if(m_object)
            {
                m_object->addReference();
            }

            return destroyed;
        }

        return false;
    }

    template <typename T>
    ObjectRef<T>& ObjectRef<T>::swap(ObjectRef<T>& objectRef)
    {
        std::swap(m_object, objectRef.get());

        return (*this);
    }

    template <typename T>
    T* ObjectRef<T>::get() const
    {
        return m_object;
    }

    template <typename T>
    T* ObjectRef<T>::release()
    {
        if(m_object)
        {
            m_object->removeReference();
        }

        T* object = get();
        m_object = nullptr;

        return object;
    }

    template <typename T>
    T* ObjectRef<T>::operator->() const
    {
        return get();
    }

    template <typename T>
    ObjectRef<T>::operator bool() const
    {
        return isValid();
    }
}