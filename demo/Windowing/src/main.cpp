#include <Bull/Window/Window.hpp>

using namespace Bull;

int main(int argc, char* argv[])
{
    Window win(VideoMode(800, 600), "Bull Application");
    Window::Event e;

    while(win.isOpen())
    {
        while(win.pollEvent(e))
        {
            if(e.type == Window::Event::Closed)
            {
                win.close();
            }
        }
    }

    return 0;
}