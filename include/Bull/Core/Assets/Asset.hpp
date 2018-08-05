#ifndef BULL_CORE_ASSETS_ASSET_HPP
#define BULL_CORE_ASSETS_ASSET_HPP

#include <Bull/Core/Memory/String.hpp>

namespace Bull
{
    template <typename T>
    class AssetManager;

    class BULL_CORE_API Asset
    {
    public:

        /*! \brief Destructor
         *
         */
        virtual ~Asset() = default;

        /*! \brief Tell whether an Asset is loaded
         *
         * \return True if the Asset is loaded
         *
         */
        virtual bool isLoaded() const = 0;

        /*! \brief Get the name of the Asset in the manager
         *
         * \return The name
         *
         */
        inline const String& getName()
        {
            return m_name;
        }

    private:

        template <typename T>
        friend class AssetManager;

        /*! \brief Set the name of the Asset in the manager
         *
         * \param name The name
         *
         */
        inline void setName(const String& name)
        {
            m_name = name;
        }

    private:

        String m_name;
    };
}

#endif // BULL_CORE_ASSETS_ASSET_HPP
