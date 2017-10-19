#ifndef BULL_CORE_RESOURCE_REGISTRAR_HPP
#define BULL_CORE_RESOURCE_REGISTRAR_HPP

#include <Bull/Core/Export.hpp>

namespace Bull
{
    template <typename S, typename RS>
    struct BULL_CORE_API SaverRegistrar
    {
        SaverRegistrar()
        {
            RS::get()->template registerSaver<S>();
        }
    };

    template <typename L, typename LS>
    struct BULL_CORE_API LoaderRegistrar
    {
        LoaderRegistrar()
        {
            LS::get()->template registerLoader<L>();
        }
    };
}

#endif // BULL_CORE_RESOURCE_REGISTRAR_HPP
