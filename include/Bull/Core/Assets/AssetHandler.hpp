#ifndef BULL_CORE_ASSETS_ASSETHANDLER_HPP
#define BULL_CORE_ASSETS_ASSETHANDLER_HPP

#include <Bull/Core/Assets/AssetManager.hpp>

namespace Bull
{
    template <typename T>
    class BULL_CORE_API AssetHandler
    {
    public:

        /*! \brief Default constructor
         *
         */
        AssetHandler() :
            m_asset(nullptr)
        {
            /// Nothing
        }

        /*! \brief Constructor
         *
         * \param name The name of the Asset to handle
         *
         */
        explicit AssetHandler(const String& name) :
            m_name(name),
            m_asset(AssetManager<T>::getInstance()->findOrCreate(name))
        {
            /// Nothing
        }

        /*! \brief Tell whether the handled Asset exists
         *
         * \return True if the Asset exists
         *
         */
        bool isValid() const
        {
            return m_asset != nullptr;
        }

        /*! \brief Get the name of the Asset
         *
         * \return The name
         *
         */
        const String& getName()
        {
            return m_name;
        }

        /*! \brief Tell whether the handled Asset exists
         *
         * \return True if the Asset exists
         *
         */
        operator bool() const
        {
            return isValid();
        }

        /*! \brief Access to the Asset
         *
         * \return The asset
         *
         */
        T* operator->()
        {
            return m_asset;
        }

        /*! \brief Cast operator to raw pointer
         *
         * \return The pointer
         *
         */
        operator T*()
        {
            return m_asset;
        }

    private:

        String m_name;
        T*     m_asset;
    };
}

#endif // BULL_CORE_ASSETS_ASSETHANDLER_HPP
