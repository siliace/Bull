#include <Catch.hpp>

#include <Bull/Core/Utility/MapUtils.hpp>

using namespace Bull;

SCENARIO("MapUtils::create")
{
    GIVEN("A none zero size")
    {
        const std::size_t size = 5;

        WHEN("Create a map")
        {
            std::map<int, int> map = MapUtils::create<int, int>(size, [](int index) {
                return std::make_pair(index, index);
            });

            THEN("The map should have a correct size")
            {
                REQUIRE(map.size() == size);
            }
            AND_THEN("The map should contains correct elements")
            {
                for(std::size_t i = 0; i < size; i++)
                {
                    REQUIRE(map[i] == i);
                }
            }
        }
    }

    GIVEN("A zero size")
    {
        const std::size_t size = 0;

        WHEN("Create a map")
        {
            std::map<int, int> map = MapUtils::create<int, int>(size, [](int index) {
                return std::make_pair(index, index);
            });

            THEN("The map should be empty")
            {
                REQUIRE(map.empty());
            }
        }
    }
}