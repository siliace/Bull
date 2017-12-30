#ifndef BULL_CORE_ASSETS_ASSETMANAGER_HPP
#define BULL_CORE_ASSETS_ASSETMANAGER_HPP

#include <map>

#include <Bull/Core/Memory/String.hpp>
#include <Bull/Core/Pattern/Singleton.hpp>

namespace Bull
{
    template <typename T>
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
        T* createAsset(const String& name, Args&&... args)
        {
            AssetMap::iterator it = m_assets.find(name);

            if(it == m_assets.end())
            {
                it = m_assets.insert(
                        std::make_pair(name, new T(std::forward<Args>(args)...))
                ).first;
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
        bool registerAsset(T* asset, const String& name, bool override = true)
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
        void unregisterAsset(const String& name)
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

        /*! \brief Get an Asset
         *
         * \param name The name of the Asset to get
         *
         * \return The Asset
         *
         */
        T* getAsset(const String& name)
        {
            if(!has(name))
            {
                return createAsset(name);
            }

            return m_assets[name].get();
        }

        /*! \brief Delete every Asset
         *
         */
        void clear()
        {
            m_assets.clear();
        }

    private:

        using AssetMap = std::map<String, std::unique_ptr<T>>;

        AssetMap m_assets;
    };
}

#endif // BULL_CORE_ASSETS_ASSETMANAGER_HPP
