#ifndef BULL_RENDER_SHADER_SHADER_HPP
#define BULL_RENDER_SHADER_SHADER_HPP

#include <Bull/Core/Exception/DeclareException.hpp>
#include <Bull/Core/FileSystem/Path.hpp>
#include <Bull/Core/IO/InStream.hpp>
#include <Bull/Core/Utility/Color.hpp>

#include <Bull/Math/Matrix/Matrix4.hpp>
#include <Bull/Math/Vector/Vector.hpp>

#include <Bull/Render/Shader/ShaderBinary.hpp>
#include <Bull/Render/Shader/ShaderStageLoader.hpp>

namespace Bull
{
    DeclareException(UniformVariableNotFound);

    class BULL_RENDER_API Shader : public NonCopyable, public ContextResource
    {
    public:

        /*! \brief Get the maximum vertex attributes available
         *
         * \return Return the max
         *
         */
        static unsigned int getMaxVertexAttribs();

    public:

        /*! \brief Default constructor
         *
         */
        Shader();

        /*! \brief Destructor
         *
         */
        ~Shader();

        /*! \brief Create a Shader from a ShaderBinary
         *
         * \param shaderBinary The binary of the Shader
         *
         */
        void create(const ShaderBinary& shaderBinary);

        /*! \brief Create a Shader by loading its stages from their Path
         *
         * \param vertex   The Path of the vertex shader
         * \param fragment The Path of the fragment shader
         *
         */
        void create(const Path& vertex, const Path& fragment);

        /*! \brief Create a Shader by loading its stages from their Path
         *
         * \param vertex   The Path of the vertex shader
         * \param fragment The Path of the fragment shader
         * \param geometry The Path of the geometry shader
         *
         */
        void create(const Path& vertex, const Path& fragment, const Path& geometry);

        /*! \brief Attach a ShaderStage to this Shader
         *
         * \param stage The stage to attach to this Shader
         *
         */
        void attach(const ShaderStage& stage);

        /*! \brief Link the shader
         *
         */
        void link();

        /*! \brief Bind the shader
         *
         */
        void bind() const;

        /*! \brief Check whether the Shader is linked
         *
         * \return True if the Shader is linked
         *
         */
        bool isLinked() const;

        /*! \brief Set an uniform variable
         *
         * \param name    The name of the uniform variable in the shader
         * \param uniform The value to set to the uniform variable
         *
         */
        void setUniform(const String& name, int uniform);

        /*! \brief Set an uniform variable
         *
         * \param name    The name of the uniform variable in the shader
         * \param uniform The value to set to the uniform variable
         *
         */
        void setUniform(const String& name, unsigned int uniform);

        /*! \brief Set an uniform variable
         *
         * \param name    The name of the uniform variable in the shader
         * \param uniform The value to set to the uniform variable
         *
         */
        void setUniform(const String& name, float uniform);

        /*! \brief Set an uniform variable
         *
         * \param name    The name of the uniform variable in the shader
         * \param uniform The value to set to the uniform variable
         *
         */
        void setUniformColor(const String& name, const Color& uniform);

        /*! \brief Set an uniform variable
         *
         * \param name    The name of the uniform variable in the shader
         * \param uniform The value to set to the uniform variable
         *
         */
        void setUniformVector(const String& name, const Vector<float, 2>& uniform);

        /*! \brief Set an uniform variable
         *
         * \param name    The name of the uniform variable in the shader
         * \param uniform The value to set to the uniform variable
         *
         */
        void setUniformVector(const String& name, const Vector<float, 3>& uniform);

        /*! \brief Set an uniform variable
         *
         * \param name    The name of the uniform variable in the shader
         * \param uniform The value to set to the uniform variable
         *
         */
        void setUniformVector(const String& name, const Vector<float, 4>& uniform);

        /*! \brief Set an uniform variable
         *
         * \param name    The name of the uniform variable in the shader
         * \param uniform The value to set to the uniform variable
         *
         */
        void setUniformMatrix(const String& name, const Matrix4F& uniform);

        /*! \brief Get the program as a binary format
         *
         * \return The binary format
         *
         */
        ShaderBinary getBinary() const;

        /*! \brief Get the Shader system handler
         *
         * \return The native ShaderStage system handler
         *
         */
        unsigned int getSystemHandler() const;

    protected:

        /*! \brief Get the current error message of the program
         *
         * \return The error message
         *
         */
        String getErrorMessage() const;

    private:

        /*! \brief Get the location of an uniform variable
         *
         * \param name The name of the uniform variable in the shader
         *
         * \return Return the location of the uniform
         *
         */
        int getUniformLocation(const String& name);

        unsigned int                m_program;
        ShaderStageLoader::Instance m_stageLoader;
    };
}

#endif // BULL_RENDER_SHADER_SHADER_HPP
