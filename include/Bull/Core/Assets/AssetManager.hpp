#ifndef BULL_CORE_ASSETS_ASSETMANAGER_HPP
#define BULL_CORE_ASSETS_ASSETMANAGER_HPP

#include <map>

#include <Bull/Core/Exception/InvalidParameter.hpp>

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
        T& create(const String& name, Args&&... args)
        {
            typename AssetMap::iterator it = m_assets.find(name);

            if(it == m_assets.end())
            {
                it = m_assets.insert(
                        std::make_pair(name, T(std::forward<Args>(args)...))
                ).first;
            }
            else
            {
                it->second = T(std::forward<Args>(args)...);
            }

            it->second.setName(name);

            return it->second;
        }

        /*! \brief Register an Asset in the AssetManager
         *
         * \param asset The Asset to register
         * \param name  The name of the Asset to register
         *
         * \return A handler to the added Asset
         *
         */
        T& add(T&& asset, const String& name)
        {
            typename AssetMap::iterator it = m_assets.find(name);

            if(it == m_assets.end())
            {
                it = m_assets.insert(
                        std::make_pair(name, std::forward<T>(asset))
                ).first;
            }
            else
            {
                it->second = std::forward<T>(asset);
            }

            it->second.setName(name);

            return it->second;
        }

        /*! \brief Remove an Asset from the AssetManager
         *
         * \param name The name of the Asset to remove
         *
         * \return The removed
         *
         */
        T remove(const String& name)
        {
            typename AssetMap::iterator it = m_assets.find(name);

            Expect(it != m_assets.end(), Throw(InvalidParameter, "AssetManager::find", "The manager does not contains any asset " + name));

            return std::move(m_assets.erase(it)->second);
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
        T& find(const String& name)
        {
            typename AssetMap::iterator it = m_assets.find(name);

            Expect(it != m_assets.end(), Throw(InvalidParameter, "AssetManager::find", "The manager does not contains any asset " + name));

            return it->second;
        }

        /*! \brief Find an Asset by its name or create a new one and return it
         *
         * \param name The name of the Asset to find
         *
         * \return The Asset
         *
         */
        template <typename... Args>
        T& findOrCreate(const String& name, Args&&... args)
        {
            return findOrCreateWithFactory(name, [&args...]() -> T {
                return T(std::forward<Args>(args)...);
            });
        }

        /*! \brief Find or create an Asset by its name or create a new one using a factory and return it
         *
         * \param name    The name of the Asset to create
         * \param factory The factory to use to create the Asset
         *
         * \return The created Asset
         *
         */
        T& findOrCreateWithFactory(const String& name, const std::function<T()>& factory)
        {
            typename AssetMap::iterator it = m_assets.find(name);

            if(it == m_assets.end())
            {
                it = m_assets.insert(std::make_pair(name, factory())).first;

                it->second.setName(name);
            }

            return it->second;
        }

        /*! \brief Delete every Asset
         *
         */
        void clear()
        {
            m_assets.clear();
        }

    private:

        using AssetMap = std::map<String, T>;

        AssetMap m_assets;
    };
}

#endif // BULL_CORE_ASSETS_ASSETMANAGER_HPP
