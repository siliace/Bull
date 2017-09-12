#include <Bull/Core/Log/Log.hpp>

#include <Bull/Render/Shader/Shader.hpp>
#include <Bull/Render/Target/RenderWindow.hpp>
#include <Bull/Render/Texture/Texture.hpp>

#include <Bull/Utility/Image/ImageManager.hpp>
#include <Bull/Utility/Logger/ConsoleLogger.hpp>

int main()
{
    Bull::Log::get()->createLogger<Bull::ConsoleLogger>();

    Bull::Shader core;
    Bull::Texture wall;
    Bull::WindowEvent event;
    Bull::ShaderStage vertex, fragment;
    Bull::ImageManager::Instance imageManager = Bull::ImageManager::get();
    Bull::RenderWindow window(Bull::VideoMode(800, 600), Bull::String("Bull Application"));

    Bull::Image& icon = imageManager->loadFromPath(Bull::Path("../resources/icon/heart.png"), "icon");
    window.setIcon(icon);

    if(!wall.loadFromImage(imageManager->loadFromPath(Bull::Path("../resources/textures/wall.jpg"), "wall")))
    {
        return -1;
    }

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