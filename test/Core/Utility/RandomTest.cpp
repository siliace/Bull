#include <Catch/catch.hpp>

#include <Bull/Core/Utility/Random.hpp>

using namespace Bull;

TEST_CASE("Random::number", "[Core][Random]")
{
    RandomGenerator generator;

    SECTION("A random integer")
    {
        const int n(generator.number<int>(0, 10));

        REQUIRE(n >= 0);
        REQUIRE(n <= 10);
    }

    SECTION("A random float number")
    {
        const double n(generator.number<double>(0.0, 10.0));

        REQUIRE(n >= 0.0);
        REQUIRE(n <= 10.0);
    }
}