#ifndef BULL_CORE_PATTERN_OBJECTREF_HPP
#define BULL_CORE_PATTERN_OBJECTREF_HPP

#include <utility>

#include <Bull/Core/Export.hpp>
#include <Bull/Core/Pattern/RefCounted.hpp>

namespace Bull
{
    template <typename T>
    class BULL_CORE_API ObjectRef
    {
    public:

        /*! \brief Default constructor
         *
         */
        ObjectRef();

        /*! \brief Constructor
         *
         * \param object The object to reference
         *
         */
        ObjectRef(T* object);

        /*! \brief Copy constructor
         *
         * \param copy The ObjectRef to copy
         *
         */
        ObjectRef(const ObjectRef& copy);

        /*! \brief Move constructor
         *
         * \param copy The ObjectRef to move
         *
         */
        ObjectRef(ObjectRef&& move) noexcept;

        /*! \brief Destructor
         *
         */
        ~ObjectRef();

        /*! \brief Basic assignment operator
         *
         * \param object The object to reference
         *
         * \return This
         *
         */
        ObjectRef& operator=(T* object);

        /*! \brief Basic assignment operator
         *
         * \param copy The ObjectRef to copy
         *
         * \return This
         *
         */
        ObjectRef& operator=(const ObjectRef<T>& copy);

        /*! \brief Basic assignment operator
         *
         * \param move The ObjectRef to move
         *
         * \return This
         *
         */
        ObjectRef& operator=(ObjectRef<T>&& move) noexcept;

        /*! \brief Tell whether the referenced object is valid
         *
         * \return True if the object is valid
         *
         */
        bool isValid() const;

        /*! \brief Reset the referenced object
         *
         * \param object The new object to reference
         *
         * \return True if the old object has been destroyed
         *
         */
        bool reset(T* object = nullptr);

        /*! \brief Swap two ObjectRef
         *
         * \param objectRef The ObjectRef to swap with this
         *
         * \return This
         *
         */
        ObjectRef<T>& swap(ObjectRef<T>& objectRef);

        /*! \brief Get a pointer to the referenced object
         *
         * \return The pointer
         *
         */
        T* get() const;

        /*! \brief Release the reference on the object
         *
         * \return A pointer to the object
         *
         */
        T* release();

        /*! \brief Get the object referenced to apply a const method
         *
         * \return The object
         *
         */
        T* operator->() const;

        /*! \brief Convert the ObjectRef to a boolean
         *
         * \return True if the object is not null
         *
         */
        explicit operator bool() const;

    private:

        T* m_object;
    };
}

#include <Bull/Core/Pattern/ObjectRef.inl>

#endif // BULL_CORE_PATTERN_OBJECTREF_HPP
