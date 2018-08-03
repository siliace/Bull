#ifndef BULL_CORE_ASSETS_ASSETHANDLER_HPP
#define BULL_CORE_ASSETS_ASSETHANDLER_HPP

#include <Bull/Core/Memory/String.hpp>

namespace Bull
{
    template <typename T>
    class BULL_CORE_API AssetHandler
    {
    public:

        /*! \brief Constructor
         *
         * \param asset
         * \param name
         *
         */
        AssetHandler(T& asset, const String& name) :
            m_asset(asset),
            m_name(name)
        {
            /// Nothing
        }

        /*! \brief Access to the handled Asset
         *
         * \return The Asset
         *
         */
        T* operator->()
        {
            return &m_asset;
        }

        /*! \brief Access to the handled Asset
         *
         * \return The Asset
         *
         */
        const T* operator->() const
        {
            return &m_asset;
        }

        /*! \brief Get the name of the handled Asset
         *
         * \return The name
         *
         */
        const String& getName()
        {
            return m_name;
        }

    private:

        T& m_asset;
        const String& m_name;
    };
}

#endif // BULL_CORE_ASSETS_ASSETHANDLER_HPP
