#include <Bull/Core/Log/Log.hpp>

#include <Bull/Utility/ConsoleLogger.hpp>

#include <Bull/Render/Target/RenderWindow.hpp>

using namespace Bull;

int main(int argc, char* argv[])
{
    Log::get()->createLogger<ConsoleLogger>();

    RenderWindow::Event e;
    RenderWindow win(VideoMode(800, 600), "Bull Application");

    while(win.isOpen())
    {
        while(win.pollEvent(e))
        {
            if(e.type == RenderWindow::Event::Closed)
            {
                win.close();
            }
        }

        win.clear();

        win.display();
    }

    return 0;
}