#include <Bull/Core/Log/Log.hpp>

#include <Bull/Render/Shader/ShaderStage.hpp>
#include <Bull/Render/Shader/ShaderStageManager.hpp>
#include <Bull/Render/Shader/ShaderStageParameters.hpp>

#include <Bull/Utility/Logger/ConsoleLogger.hpp>

using namespace Bull;

int main()
{
    Log::get()->createLogger<ConsoleLogger>();

    ShaderStageManager::Instance manager = ShaderStageManager::get();

    ShaderStage& vertex = manager->loadFromPath(Path("../resources/shaders/core/core.vert"), "core_vertex", ShaderStageParameters(ShaderStage::Vertex));

    return 0;
}