#include <Catch.hpp>

#include <Bull/Core/Window/Window.hpp>

using namespace Bull;

SCENARIO("Create window and change its settings")
{
    GIVEN("A valid video mode and title")
    {
        String title("Unit test window");
        VideoMode videoMode(SizeUI(800, 600));
        Uint32 style = WindowStyle_Default;

        Window window(videoMode, title, style);

        WHEN("Create the window with the default style")
        {
            THEN("The window should be opened")
            {
                REQUIRE(window.isOpen());
            }
            AND_THEN("The window should have the right size")
            {
                REQUIRE(window.getSize() == videoMode.size);
            }
            AND_THEN("The window should have the right title")
            {
                REQUIRE(window.getTitle() == title);
            }
        }

        WHEN("Change the window size")
        {
            const SizeUI newSize(1360, 768);

            window.setSize(newSize);

            THEN("The new size should be applied to the window")
            {
                REQUIRE(window.getSize() == newSize);
            }
        }

        WHEN("Change the window title")
        {
            const String newTitle("New window test title");

            window.setTitle(newTitle);

            THEN("The new title should be applied to the window")
            {
                REQUIRE(window.getTitle() == newTitle);
            }
        }

        WHEN("Set a maximum size prior than the window's size")
        {
            const SizeUI maxSize(1000, 800);
            const SizeUI initialSize = window.getSize();

            window.setMaxSize(maxSize);

            THEN("The window shouldn't have been resized")
            {
                REQUIRE(window.getSize() == initialSize);
            }
        }

        WHEN("Set a maximum size lowest than the window's size")
        {
            const SizeUI maxSize(600, 400);

            window.setMaxSize(maxSize);

            THEN("The window should have been resized")
            {
                REQUIRE(window.getSize() == maxSize);
            }
        }

        WHEN("Set a minimum size prior than the window's size")
        {
            const SizeUI minSize(1000, 800);

            window.setMinSize(minSize);

            THEN("The window should have been resized")
            {
                REQUIRE(window.getSize() == minSize);
            }
        }

        WHEN("Set a minimum size lowest than the window's size")
        {
            const SizeUI minSize(600, 400);
            const SizeUI initialSize = window.getSize();

            window.setMinSize(minSize);

            THEN("The window shouldn't have been resized")
            {
                REQUIRE(window.getSize() == initialSize);
            }
        }

        WHEN("Change the position of the window")
        {
            const SizeI position(50, 50);

            window.setPosition(position);

            THEN("The window should have move")
            {
                REQUIRE(window.getPosition() == position);
            }
        }

        WHEN("Close the window")
        {
            window.close();

            THEN("The window should be closed")
            {
                REQUIRE_FALSE(window.isOpen());
            }
        }
    }
}