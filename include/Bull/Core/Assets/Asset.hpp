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

        Asset() :
            m_manager(nullptr)
        {
            /// Nothing
        }

        explicit Asset(std::shared_ptr<T> instance) :
            m_instance(instance),
            m_manager(nullptr)
        {
            /// Nothing
        }

        T* get()
        {
            return m_instance.get();
        }

        const T* get() const
        {
            return m_instance.get();
        }

        T* operator->()
        {
            return get();
        }

        T& operator*()
        {
            return *m_instance;
        }

        const T& operator*() const
        {
            return *m_instance;
        }

    private:

        friend class AssetManager<T>;

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
