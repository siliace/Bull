#include <Catch/catch.hpp>

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

SCENARIO("File::copy", "[FILE]")
{
    GIVEN("Two valid paths")
    {
        const Path path("foo.txt");
        const Path target("bar.txt");

        WHEN("The source file exists and the target path does not exists")
        {
            File::create(path);
            File::copy(path, target);

            THEN("The target should exists")
            {
                REQUIRE(File::exists(target));
            }
            AND_THEN("The original file should still exists")
            {
                REQUIRE(File::exists(path));
            }

            File::remove(path);
            File::remove(target);
        }

        WHEN("The source file does not exists and the target path does not exists")
        {
            THEN("Throw a FileNotFound exception")
            {
                REQUIRE_THROWS_AS(File::copy(path, target), FileNotFound);
            }
            AND_THEN("The target file should still not exists")
            {
                REQUIRE_FALSE(File::exists(target));
            }
        }

        WHEN("The source file does not exists and the target path does exists")
        {
            File::create(target);

            THEN("Throw a FileNotFound exception")
            {
                REQUIRE_THROWS_AS(File::copy(path, target), FileNotFound);
            }
            AND_THEN("The target file should still exists")
            {
                REQUIRE(File::exists(target));
            }

            File::remove(target);
        }

        WHEN("The source file does exists and the target path does exists")
        {
            File::create(path);
            File::create(target);

            THEN("Throw a FileAlreadyExists exception")
            {
                REQUIRE_THROWS_AS(File::copy(path, target), FileAlreadyExists);
            }
            AND_THEN("The source file should still exists")
            {
                REQUIRE(File::exists(target));
            }
            AND_THEN("The target file should still exists")
            {
                REQUIRE(File::exists(target));
            }

            File::remove(path);
            File::remove(target);
        }
    }
}

SCENARIO("File::rename", "[File]")
{
    GIVEN("Two valid paths")
    {
        const Path path("foo.txt");
        const Path target("bar.txt");

        WHEN("The source file exists and the target path does not exists")
        {
            File::create(path);
            File::rename(path, target);

            THEN("The source file should not exists anymore")
            {
                REQUIRE_FALSE(File::exists(path));
            }
            AND_THEN("The target file should exists")
            {
                REQUIRE(File::exists(target));
            }

            File::remove(target);
        }

        WHEN("The source file does not exists and the target path does not exists")
        {
            THEN("Throw a FileNotFound exception")
            {
                REQUIRE_THROWS_AS(File::rename(path, target), FileNotFound);
            }
            AND_THEN("The target file should still not exists")
            {
                REQUIRE_FALSE(File::exists(target));
            }
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