#include <Bull/Core/Log/Log.hpp>

#include <Bull/Utility/Image/ImageManager.hpp>

#include <Bull/Utility/Logger/ConsoleLogger.hpp>

using namespace Bull;

int main()
{
    Log::get()->createLogger<ConsoleLogger>();

    int count = 0;
    Directory shaders;

    if(shaders.open(Path("../resources")))
    {
        ImageManager::Instance manager = ImageManager::get();

        count = manager->loadFromDirectory(shaders);
    }

    return count;
}