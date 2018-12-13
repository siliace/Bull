#include <Catch.hpp>

#include <Bull/Core/Utility/StringUtils.hpp>

using namespace Bull;

TEST_CASE("StringUtils::boolean", "[Core::StringUtils]")
{
    SECTION("Create a \"true\" string")
    {
        REQUIRE(StringUtils::boolean(true) == "true");
    }

    SECTION("Create a \"false\" string")
    {
        REQUIRE(StringUtils::boolean(false) == "false");
    }
}

TEST_CASE("StringUtils::repeat", "[Core::StringUtils]")
{
    SECTION("Repeat a String once")
    {
        REQUIRE(StringUtils::repeat("foo", 1) == "foo");
    }

    SECTION("Repeat a String 3 times")
    {
        REQUIRE(StringUtils::repeat("foo", 3) == "foofoofoo");
    }

    SECTION("Repeat an empty String")
    {
        REQUIRE_THROWS_AS(StringUtils::repeat("", 3), InvalidParameter);
    }

    SECTION("Repeat a String zero time")
    {
        REQUIRE_THROWS_AS(StringUtils::repeat("foo", 0), InvalidParameter);
    }
}

TEST_CASE("StringUtils::ofSize", "[Core::StringUtils]")
{
    SECTION("Create a String of size 0")
    {
        REQUIRE(StringUtils::ofSize(0).getSize() == 0);
    }

    SECTION("Create a String of size 5")
    {
        REQUIRE(StringUtils::ofSize(5).getSize() == 5);
    }
}