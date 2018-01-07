#ifndef BULL_CORE_ASSETS_ASSET_HPP
#define BULL_CORE_ASSETS_ASSET_HPP

#include <Bull/Core/Export.hpp>

namespace Bull
{
    struct BULL_CORE_API Asset
    {
        /*! \brief Tell whether an Asset is loaded
         *
         * \return True if the Asset is loaded
         *
         */
        virtual bool isLoaded() const = 0;
    };
}

#endif // BULL_CORE_ASSETS_ASSET_HPP
