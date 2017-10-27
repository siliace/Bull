#include <memory>

#include <Bull/Core/IO/StringStream.hpp>
#include <Bull/Core/Log/Log.hpp>

namespace Bull
{
    template <typename T>
    template <typename... Args>
    ObjectRef<T> RefCounted<T>::make(Args&&... args)
    {
        std::unique_ptr<T> pointer = std::make_unique<T>(std::forward<Args>(args)...);
        pointer->setPersistent(false);

        return ObjectRef<T>(pointer.get());
    }

    template <typename T>
    RefCounted<T>::RefCounted(bool persistent) :
        m_isPersistent(persistent),
        m_referenceCounter(0)
    {
        /// Nothing
    }

    template <typename T>
    RefCounted<T>::~RefCounted()
    {
        if(m_referenceCounter > 0)
        {
            StringStream ss;

            ss << "Deleting object with " << String::number(static_cast<unsigned int>(m_referenceCounter)) << " references";

            Log::get()->write(ss.toString(), LogLevel::LogLevel_Warning);
        }
    }

    template <typename T>
    void RefCounted<T>::addReference()
    {
        m_referenceCounter++;
    }

    template <typename T>
    bool RefCounted<T>::removeReference()
    {
        if(m_referenceCounter > 0)
        {
            if(--m_referenceCounter == 0 && !m_isPersistent)
            {
                delete this;

                return true;
            }
        }

        return false;
    }

    template <typename T>
    bool RefCounted<T>::setPersistent(bool persistent, bool checkReference)
    {
        m_isPersistent = persistent;

        if(m_referenceCounter == 0 && !m_isPersistent && checkReference)
        {
            delete this;

            return true;
        }

        return false;
    }

    template <typename T>
    bool RefCounted<T>::isPersistent() const
    {
        return m_isPersistent;
    }

    template <typename T>
    unsigned int RefCounted<T>::getReferenceCount() const
    {
        return m_referenceCounter;
    }
}
