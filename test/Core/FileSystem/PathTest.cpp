#include <catch/catch.hpp>

#include <Bull/Core/Exception/InternalError.hpp>
#include <Bull/Core/FileSystem/File.hpp>
#include <Bull/Core/FileSystem/Directory.hpp>

using namespace Bull;

SCENARIO("Path::copy", "[PATH]")
{
    GIVEN("Two valid paths")
    {
        const Path path("foo.txt");
        const Path target("bar.txt");

        WHEN("The source file exists and the target path does not exists")
        {
            File::create(path);
            Path::copy(path, target);

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
                REQUIRE_THROWS_AS(Path::copy(path, target), FileNotFound);
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
                REQUIRE_THROWS_AS(Path::copy(path, target), FileNotFound);
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
                REQUIRE_THROWS_AS(Path::copy(path, target), FileAlreadyExists);
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

SCENARIO("Path::rename", "[PATH]")
{
    GIVEN("Two valid paths")
    {
        const Path path("foo.txt");
        const Path target("bar.txt");

        WHEN("The source file exists and the target path does not exists")
        {
            File::create(path);
            Path::rename(path, target);

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
                REQUIRE_THROWS_AS(Path::rename(path, target), FileNotFound);
            }
            AND_THEN("The target file should still not exists")
            {
                REQUIRE_FALSE(File::exists(target));
            }
        }
    }
}