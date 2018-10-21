#ifndef BULL_CORE_UTILITY_MAPUTILS_HPP
#define BULL_CORE_UTILITY_MAPUTILS_HPP

#include <functional>
#include <map>

#include <Bull/Core/Export.hpp>

namespace Bull
{
    class BULL_CORE_API MapUtils
    {
    public:

        template <typename K, typename V>
        static std::map<K, V> create(std::size_t count, const std::function<std::pair<K, V>(std::size_t index)>& factory)
        {
            std::map<K, V> map;

            for(std::size_t i = 0; i < count; i++)
            {
                map.insert(factory(i));
            }

            return map;
        }
    };
}

#endif // BULL_CORE_UTILITY_MAPUTILS_HPP
