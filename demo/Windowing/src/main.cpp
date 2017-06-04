#include <Bull/Window/Cursor.hpp>
#include <Bull/Window/Window.hpp>

using namespace Bull;

int main(int argc, char* argv[])
{
    Cursor c;
    Window::Event e;
    Window win(VideoMode(800, 600), "Bull Application");

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