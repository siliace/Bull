#include <Bull/Core/Log/Log.hpp>

#include <Bull/Render/Shader/ShaderStage.hpp>
#include <Bull/Render/Shader/ShaderStageManager.hpp>
#include <Bull/Render/Shader/ShaderStageParameters.hpp>
#include <Bull/Render/Target/RenderWindow.hpp>

#include <Bull/Utility/Logger/ConsoleLogger.hpp>

using namespace Bull;

int main()
{
    Log::get()->createLogger<ConsoleLogger>();

    int count = 0;
    Directory shaders;

    if(shaders.open(Path("../resources/shaders/core")))
    {
        ShaderStageManager::Instance manager = ShaderStageManager::get();

        count = manager->loadFromDirectory(shaders);
    }

    return count;
}