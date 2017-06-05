#include <Bull/Window/Cursor.hpp>
#include <Bull/Window/Window.hpp>

using namespace Bull;

int main(int argc, char* argv[])
{
    Cursor c;
    Image img;
    Window::Event e;
    Window win(VideoMode(800, 600), "Bull Application");

    if(!img.loadFromPath(Path("cursor.jpg")))
    {
        return -1;
    }

    c.loadFromImage(img, Vector2UI());

    win.setMouseCursor(c);

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