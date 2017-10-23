#ifndef BULL_CORE_PATTERN_NONCOPYABLE_HPP
#define BULL_CORE_PATTERN_NONCOPYABLE_HPP

#include <atomic>

#include <Bull/Core/Export.hpp>

namespace Bull
{
    class BULL_CORE_API NonCopyable
    {
    public:

        /*! \brief Constructor
         *
         * \param persistent The persistence
         *
         */
        explicit NonCopyable(bool persistent = true);

        /*! \brief Copy constructor
         *
         */
        NonCopyable(const NonCopyable& copy) = delete;

        /*! \brief Basic assignment operator
         *
         */
        NonCopyable& operator=(const NonCopyable& copy) = delete;

        /*! \brief Destructor
         *
         */
        virtual ~NonCopyable();

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
         * \param persistent     The persistence
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

#endif // BULL_CORE_PATTERN_NONCOPYABLE_HPP
