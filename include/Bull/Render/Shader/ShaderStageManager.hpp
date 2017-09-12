#ifndef BULL_RENDER_SHADER_SHADERSTAGEMANAGER_HPP
#define BULL_RENDER_SHADER_SHADERSTAGEMANAGER_HPP

#include <Bull/Core/Loader/ResourceManager.hpp>
#include <Bull/Core/Pattern/Singleton.hpp>

#include <Bull/Render/Shader/AbstractShaderStageLoader.hpp>
#include <Bull/Render/Shader/AbstractShaderStageSaver.hpp>
#include <Bull/Render/Shader/ShaderStage.hpp>

namespace Bull
{
    class BULL_RENDER_API ShaderStageManager : public ResourceManager<ShaderStage, AbstractShaderStageSaver, AbstractShaderStageLoader>, public Singleton<ShaderStageManager>
    {
    protected:

        /*! \brief Get the ResourceSaver for the Resource
         *
         * \return The ResourceSaver
         *
         */
        std::unique_ptr<AbstractShaderStageSaver>& getSaver() override;

        /*! \brief Get the ResourceLoader for the Resource
         *
         * \return The ResourceLoader
         *
         */
        std::unique_ptr<AbstractShaderStageLoader>& getLoader() override;

        /*! \brief Get an empty Resource
         *
         * \return An empty Resource
         *
         */
        ShaderStage* getEmptyResource() const override;

    private:

        std::unique_ptr<AbstractShaderStageSaver>  m_saver;
        std::unique_ptr<AbstractShaderStageLoader> m_loader;
    };
}

#endif // BULL_RENDER_SHADER_SHADERSTAGEMANAGER_HPP
