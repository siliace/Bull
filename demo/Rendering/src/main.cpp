#include <Bull/Render/Target/RenderWindow.hpp>

int main()
{
    Bull::Image icon;
    Bull::WindowEvent event;
    Bull::RenderWindow window(Bull::VideoMode(800, 600), Bull::String("Bull Application"));

    if(!icon.loadFromPath(Bull::Path("../resources/icon/heart.png")))
    {
        return -1;
    }

    window.setIcon(icon);

    while(window.isOpen())
    {
        while(window.pollEvent(event))
        {
            if(event.type == Bull::WindowEvent::Closed)
            {
                window.close();
            }
        }

        window.clear();

        window.display();
    }

    return 0;
}