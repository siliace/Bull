#ifndef BULL_CORE_RESOURCE_REGISTRAR_HPP
#define BULL_CORE_RESOURCE_REGISTRAR_HPP

#include <Bull/Core/Export.hpp>

namespace Bull
{
    template <typename Saver, typename Type, typename Parameters>
    struct BULL_CORE_API SaverRegistrar
    {
        SaverRegistrar()
        {
            ResourceSaver<Type, Parameters>::get()->createSaver();
        }
    };

    template <typename Loader, typename Type, typename Parameters>
    struct BULL_CORE_API LoaderRegistrar
    {
        LoaderRegistrar()
        {
            ResourceLoader<Type, Parameters>::get()->createLoader();
        }
    };

    namespace
    {
        template <typename Saver, typename Type, typename Parameters>
        SaverRegistrar<Saver, Type, Parameters> saverRegistrar;

        template <typename Loader, typename Type, typename Parameters>
        SaverRegistrar<Loader, Type, Parameters> loaderRegistrar;
    }
}

#endif // BULL_CORE_RESOURCE_REGISTRAR_HPP
