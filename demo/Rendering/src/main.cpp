#include <Bull/Render/Target/RenderWindow.hpp>

using namespace Bull;

int main(int argc, char* argv[])
{
    WindowEvent e;
    RenderWindow window(VideoMode(800, 600), "Bull Application");

    while(window.isOpen())
    {
        while(window.pollEvent(e))
        {
            if(e.type == WindowEvent::Closed)
            {
                window.close();
            }
        }

        window.clear(Color::Red);

        window.display();
    }

    return 0;
}