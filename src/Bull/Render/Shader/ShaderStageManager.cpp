#include <Bull/Render/Shader/BaseShaderStageLoader.hpp>
#include <Bull/Render/Shader/BaseShaderStageSaver.hpp>
#include <Bull/Render/Shader/ShaderStageManager.hpp>

namespace Bull
{
    std::unique_ptr<AbstractShaderStageSaver>& ShaderStageManager::getSaver()
    {
        if(!m_saver)
        {
            m_saver = std::make_unique<prv::BaseShaderStageSaver>();
        }

        return m_saver;
    }

    std::unique_ptr<AbstractShaderStageLoader>& ShaderStageManager::getLoader()
    {
        if(!m_loader)
        {
            m_loader = std::make_unique<prv::BaseShaderStageLoader>();
        }

        return m_loader;
    }

    ShaderStage* ShaderStageManager::getEmptyResource() const
    {
        return new ShaderStage();
    }
}