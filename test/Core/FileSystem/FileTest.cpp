#include <catch/catch.hpp>

#include <Bull/Core/Exception/InternalError.hpp>
#include <Bull/Core/FileSystem/File.hpp>
#include <Bull/Core/FileSystem/Directory.hpp>

using namespace Bull;

SCENARIO("File::create", "[FILE]")
{
    GIVEN("A valid path")
    {
        const Path path("foo.txt");

        WHEN("The file does not exists")
        {
            REQUIRE_NOTHROW(File::create(path));

            THEN("The file should exists")
            {
                REQUIRE(File::exists(path));
            }

            File::remove(path);
        }

        WHEN("The file already exists")
        {
            File::create(path);

            THEN("Throw a FileAlreadyExists exception")
            {
                REQUIRE_THROWS_AS(File::create(path), FileAlreadyExists);
            }

            File::remove(path);
        }
    }

    GIVEN("A directory path")
    {
        const Path path("foo");
        Directory::create(path);

        THEN("Throw an InternalError exception")
        {
            REQUIRE_THROWS_AS(File::create(path), Exception);
        }

        Directory::remove(path);
    }
}

SCENARIO("File::exists", "[FILE]")
{
    GIVEN("A valid path")
    {
        const Path path("foo.txt");

        WHEN("The file does not exists")
        {
            THEN("Return false")
            {
                REQUIRE_FALSE(File::exists(path));
            }
        }

        WHEN("The file exists")
        {
            File::create(path);

            THEN("Return true")
            {
                REQUIRE(File::exists(path));
            }

            File::remove(path);
        }
    }
}

SCENARIO("FIle::remove", "[File]")
{
    GIVEN("A valid path")
    {
        const Path path("foo.txt");

        WHEN("The file does not exists")
        {
            THEN("Throw a FileNotFound exception")
            {
                REQUIRE_THROWS_AS(File::remove(path), FileNotFound);
            }
        }

        WHEN("The file exists")
        {
            File::create(path);

            File::remove(path);

            THEN("The file should not exists anymore")
            {
                REQUIRE_FALSE(File::exists(path));
            }
        }
    }
}