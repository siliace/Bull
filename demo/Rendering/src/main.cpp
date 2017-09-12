#include <Bull/Core/Log/Log.hpp>

#include <Bull/Render/Target/RenderWindow.hpp>

#include <Bull/Utility/Image/ImageManager.hpp>
#include <Bull/Utility/Logger/ConsoleLogger.hpp>

int main()
{
    Bull::Log::get()->createLogger<Bull::ConsoleLogger>();

    Bull::WindowEvent event;
    Bull::ImageManager::Instance imageManager = Bull::ImageManager::get();
    Bull::RenderWindow window(Bull::VideoMode(800, 600), Bull::String("Bull Application"));

    Bull::Image& icon = imageManager->loadFromPath(Bull::Path("../resources/icon/heart.png"), "icon");

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