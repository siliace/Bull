#ifndef BULL_CORE_PATTERN_REFCOUNTED_HPP
#define BULL_CORE_PATTERN_REFCOUNTED_HPP

#include <atomic>

#include <Bull/Core/Export.hpp>
#include <Bull/Core/Pattern/NonCopyable.hpp>

namespace Bull
{
    class BULL_CORE_API RefCounted : public NonCopyable
    {
    public:

        /*! \brief Constructor
         *
         * \param persistents
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
         * \param persistence    The persistence
         * \param checkReference Delete the object if it is no more persistent and don't have references
         *
         * \return True if the object have been deleted
         *
         */
        bool setPersistent(bool persistence = true, bool checkReference = false);

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

        std::atomic_bool m_isPersistent;
        mutable std::atomic_uint m_referenceCounter;
    };
}

#endif // BULL_CORE_PATTERN_REFCOUNTED_HPP
