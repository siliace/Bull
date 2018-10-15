#ifndef BULL_CORE_ASSETS_ASSET_HPP
#define BULL_CORE_ASSETS_ASSET_HPP

#include <memory>

#include <Bull/Core/Memory/String.hpp>

namespace Bull
{
    template <typename T>
    class AssetManager;

    template <typename T>
    class BULL_CORE_API Asset
    {
    public:

        /*! \brief Default constructor
         *
         */
        Asset() :
            m_manager(nullptr)
        {
            /// Nothing
        }

        /*! \brief Constructor
         *
         * \param instance The asset instance to handle
         *
         */
        explicit Asset(std::shared_ptr<T> instance) :
            m_instance(instance),
            m_manager(nullptr)
        {
            /// Nothing
        }

        /*! \brief Get a pointer to the handled asset
         *
         * \return A pointer to the instance
         *
         */
        T* get()
        {
            return m_instance.get();
        }

        /*! \brief Get a pointer to the handled asset
         *
         * \return A pointer to the instance
         *
         */
        const T* get() const
        {
            return m_instance.get();
        }

        /*! \brief Get the name of the handled asset
         *
         * \return The name
         *
         */
        inline const String& getName() const
        {
            return m_name;
        }

        /*! \brief Dereference operator
         *
         * \return A pointer to the asset
         *
         */
        T* operator->()
        {
            return get();
        }

        /*! \brief Indirection operator
         *
         * \return A reference to the asset
         *
         */
        T& operator*()
        {
            return *m_instance;
        }

        /*! \brief Indirection operator
         *
         * \return A reference to the asset
         *
         */
        const T& operator*() const
        {
            return *m_instance;
        }

    private:

        friend class AssetManager<T>;

        /*! \brief Constructor
         *
         * \param instance The asset instance to handle
         * \param name     The name of the instance in its manager
         * \param manager  The manager where the asset is stored
         *
         */
        Asset(std::shared_ptr<T> instance, const String& name, AssetManager<T>* manager) :
            m_name(name),
            m_instance(instance),
            m_manager(manager)
        {
            /// Nothing
        }

    private:

        String             m_name;
        std::shared_ptr<T> m_instance;
        AssetManager<T>*   m_manager;
    };
}

#endif // BULL_CORE_ASSETS_ASSET_HPP
