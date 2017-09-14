#include <Bull/Render/Target/RenderWindow.hpp>

using namespace Bull;

int main()
{
    WindowEvent event;
    RenderWindow window(VideoMode(800, 600), "Bull Application");

    while(window.isOpen())
    {
        while(window.pollEvent(event))
        {
            if(event.type == WindowEvent::Closed)
            {
                window.close();
            }
        }

        window.clear();

        window.display();
    }

    return 0;
}