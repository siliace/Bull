#ifndef BULL_CORE_ASSETS_ASSETMANAGER_HPP
#define BULL_CORE_ASSETS_ASSETMANAGER_HPP

#include <map>
#include <memory>

#include <Bull/Core/Assets/AssetHandler.hpp>
#include <Bull/Core/Exception/Expect.hpp>
#include <Bull/Core/Exception/InvalidParameter.hpp>
#include <Bull/Core/Exception/Throw.hpp>

namespace Bull
{
    template <typename T>
    class BULL_CORE_API AssetManager
    {
    public:

        /*! \brief Create an Asset and register it the AssetManager
         *
         * \param name The name of the Asset to create
         * \param args Arguments to create the Asset
         *
         * \return A handler to the created Asset
         *
         */
        template <typename... Args>
        AssetHandler<T> create(const String& name, Args&&... args)
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

            return AssetHandler<T>(*it->second.get(), it->first);
        }

        /*! \brief Register an Asset in the AssetManager
         *
         * \param asset The Asset to register
         * \param name  The name of the Asset to register
         *
         * \return A handler to the added Asset
         *
         */
        AssetHandler<T> add(std::unique_ptr<T>&& asset, const String& name)
        {
            typename AssetMap::iterator it = m_assets.find(name);

            if(it == m_assets.end())
            {
                it = m_assets.insert(
                        std::make_pair(name, std::move(asset))
                ).first;
            }
            else
            {
                it->second = std::move(asset);
            }

            return AssetHandler<T>(*it->second.get(), it->first);
        }

        /*! \brief Remove an Asset from the AssetManager
         *
         * \param name The name of the Asset to remove
         *
         */
        std::unique_ptr<T> remove(const String& name)
        {
            return m_assets.erase(m_assets.find(name))->second;
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
         * \return A handler to the Asset
         *
         */
        AssetHandler<T> find(const String& name)
        {
            typename AssetMap::iterator it = m_assets.find(name);

            Expect(it != m_assets.end(), Throw(InvalidParameter, "AssetManager::find", "The manager does not contains any asset " + name));

            return AssetHandler<T>(*it->second.get(), it->first);
        }

        /*! \brief Find an Asset by its name or create a new one and return it
         *
         * \param name The name of the Asset to find
         *
         * \return The Asset
         *
         */
        AssetHandler<T> findOrCreate(const String& name)
        {
            typename AssetMap::iterator it = m_assets.find(name);

            if(it == m_assets.end())
            {
                it = m_assets.insert(std::make_pair(name, std::make_unique<T>())).first;
            }

            return AssetHandler<T>(*it->second.get(), it->first);
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
