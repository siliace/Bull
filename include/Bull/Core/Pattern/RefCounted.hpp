#ifndef BULL_CORE_PATTERN_REFCOUNTED_HPP
#define BULL_CORE_PATTERN_REFCOUNTED_HPP

#include <atomic>

#include <Bull/Core/Pattern/NonCopyable.hpp>
#include <Bull/Core/Pattern/ObjectRef.hpp>

namespace Bull
{
    template <typename T>
    class BULL_CORE_API RefCounted : public NonCopyable
    {
    public:

        using Ref = ObjectRef<T>;
        using ConstRef = ObjectRef<const T>;

        /*! \brief Create an object
         *
         * \param args Arguments to create the object
         *
         * \return
         */
        template <typename... Args>
        static ObjectRef<T> make(Args&&... args);

    public:

        /*! \brief Constructor
         *
         * \param persistent The persistence
         *
         */
        explicit RefCounted(bool persistent = true);

        /*! \brief Destructor
         *
         */
        virtual ~RefCounted();

        /*! \brief Add a reference to the object
         *
         */
        void addReference();

        /*! \brief Remove a reference to the object
         *
         * \return True if the object have been deleted
         *
         */
        bool removeReference();

        /*! \brief Set the persistence of the object
         *
         * \param persistent    The persistence
         * \param checkReference Delete the object if it is no more persistent and don't have references
         *
         * \return True if the object have been deleted
         *
         */
        bool setPersistent(bool persistent = true, bool checkReference = false);

        /*! \brief Tell whether the reference is persistent
         *
         * \return True if the object is persistent
         *
         */
        bool isPersistent() const;

        /*! \brief Get the reference counter of the object
         *
         * \return The counter
         *
         */
        unsigned int getReferenceCount() const;

    private:

        std::atomic_bool         m_isPersistent;
        mutable std::atomic_uint m_referenceCounter;
    };
}

#include <Bull/Core/Pattern/RefCounted.inl>

#endif // BULL_CORE_PATTERN_REFCOUNTED_HPP
