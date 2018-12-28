#include <Bull/Core/Window/Window.hpp>

int main()
{
    Bull::Window window(Bull::VideoMode(Bull::SizeUI(800, 600)), "Toto");

    window.setMinSize(Bull::SizeUI(1000, 800));

    while(window.isOpen())
    {
        Bull::WindowEvent e;
        while(window.pollEvent(e))
        {
            if(e.type == Bull::WindowEventType_Closed)
            {
                window.close();
            }
        }
    }

    return 0;
}