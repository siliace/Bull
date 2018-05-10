#ifndef BULL_CORE_ASSETS_ASSETMANAGER_HPP
#define BULL_CORE_ASSETS_ASSETMANAGER_HPP

#include <map>

#include <Bull/Core/Assets/Asset.hpp>
#include <Bull/Core/Memory/String.hpp>
#include <Bull/Core/Pattern/Singleton.hpp>

namespace Bull
{
    template <typename T, typename = std::enable_if<std::is_base_of<Asset, T>::value>>
    class BULL_CORE_API AssetManager : public Singleton<AssetManager<T>>
    {
    public:

        /*! \brief Create an Asset and register it the AssetManager
         *
         * \param name The name of the Asset to create
         * \param args Arguments to create the Asset
         *
         * \return The Asset
         *
         */
        template <typename... Args>
        T* create(const String& name, Args&&... args)
        {
            typename AssetMap::iterator it = m_assets.find(name);

            if(it == m_assets.end())
            {
                it = m_assets.insert(
                        std::make_pair(name, new T(std::forward<Args>(args)...))
                ).first;
            }
            else
            {
                it->second = std::make_unique<T>(std::forward<Args>(args)...);
            }

            return it->second.get();
        }

        /*! \brief Register an Asset in the AssetManager
         *
         * \param asset    The Asset to register
         * \param name     The name of the Asset to register
         * \param override True to override the existing Asset
         *
         */
        bool add(T* asset, const String& name, bool override = true)
        {
            if(!has(name) || override)
            {
                return m_assets.insert(std::make_pair(name, asset)).second;
            }

            return false;
        }

        /*! \brief Remove an Asset from the AssetManager
         *
         * \param name The name of the Asset to remove
         *
         */
        void remove(const String& name)
        {
            m_assets.erase(m_assets.find(name));
        }

        /*! \brief Tell whether an Asset exists in the AssetManager
         *
         * \param name The name of the Asset to get
         *
         * \return True if the Asset exists
         *
         */
        bool has(const String& name) const
        {
            return m_assets.find(name) != m_assets.end();
        }

        /*! \brief Find an Asset by its name a new one and return it
         *
         * \param name The name of the Asset to find
         *
         * \return The Asset
         *
         */
        T* find(const String& name)
        {
            typename AssetMap::iterator it = m_assets.find(name);

            if(it != m_assets.end())
            {
                return it->second.get();
            }

            return nullptr;
        }

        /*! \brief Find an Asset by its name or create a new one and return it
         *
         * \param name The name of the Asset to find
         *
         * \return The Asset
         *
         */
        T* findOrCreate(const String& name)
        {
            return find(name) ?: create(name);
        }

        /*! \brief Delete every Asset
         *
         */
        void clear()
        {
            m_assets.clear();
        }

    private:

        friend class Singleton<AssetManager<T>>;

        /*! \brief Default constructor
         *
         */
        AssetManager() = default;

    private:

        using AssetMap = std::map<String, std::unique_ptr<T>>;

        AssetMap m_assets;
    };
}

#endif // BULL_CORE_ASSETS_ASSETMANAGER_HPP
