#ifndef BULL_RENDER_SHADER_SHADER_HPP
#define BULL_RENDER_SHADER_SHADER_HPP

#include <Bull/Core/Memory/ByteArray.hpp>

#include <Bull/Math/Matrix/Matrix4.hpp>
#include <Bull/Math/Vector/Vector2.hpp>
#include <Bull/Math/Vector/Vector3.hpp>
#include <Bull/Math/Vector/Vector4.hpp>

#include <Bull/Render/Export.hpp>
#include <Bull/Render/Shader/ShaderBinary.hpp>
#include <Bull/Render/Shader/ShaderStage.hpp>

#include <Bull/Utility/Color.hpp>

namespace Bull
{
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

        /*! \brief Attach a ShaderStage to this Shader
         *
         * \param stage The stage to attach to this Shader
         *
         * \return True if the stage was attached successfully
         *
         */
        bool attach(const ShaderStage& stage);

        /*! \brief Attach a ShaderStage loaded from a Path to this Shader
         *
         * \param stage The stage to attach to this Shader
         *
         * \return True if the stage was attached successfully
         *
         */
        bool attachFromPath(const Path& path, const ShaderStageParameterBag& parameters = ShaderStageParameterBag());

        /*! \brief Attach a ShaderStage loaded from a stream to this Shader
         *
         * \param stage The stage to attach to this Shader
         *
         * \return True if the stage was attached successfully
         *
         */
        bool attachFromStream(InStream& stream, const ShaderStageParameterBag& parameters = ShaderStageParameterBag());

        /*! \brief Attach a ShaderStage loaded from memory to this Shader
         *
         * \param stage The stage to attach to this Shader
         *
         * \return True if the stage was attached successfully
         *
         */
        bool attachFromMemory(const void* data, Index length, const ShaderStageParameterBag& parameters = ShaderStageParameterBag());

        /*! \brief Link the shader
         *
         * \return True if the shader was linked successfully
         *
         */
        bool link();

        /*! \brief Bind the shader
         *
         */
        void bind() const;

        /*! \brief Check if the Shader is valid
         *
         * \return True if the Shader is valid
         *
         */
        bool isValid() const;

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
         * \return Return true if the uniform variable was found, false otherwise
         *
         */
        bool setUniform(const String& name, int uniform);

        /*! \brief Set an uniform variable
         *
         * \param name    The name of the uniform variable in the shader
         * \param uniform The value to set to the uniform variable
         *
         * \return Return true if the uniform variable was found, false otherwise
         *
         */
        bool setUniform(const String& name, unsigned int uniform);

        /*! \brief Set an uniform variable
         *
         * \param name    The name of the uniform variable in the shader
         * \param uniform The value to set to the uniform variable
         *
         * \return Return true if the uniform variable was found, false otherwise
         *
         */
        bool setUniform(const String& name, float uniform);

        /*! \brief Set an uniform variable
         *
         * \param name    The name of the uniform variable in the shader
         * \param uniform The value to set to the uniform variable
         *
         * \return Return true if the uniform variable was found, false otherwise
         *
         */
        bool setUniformColor(const String& name, const Color& uniform);

        /*! \brief Set an uniform variable
         *
         * \param name    The name of the uniform variable in the shader
         * \param uniform The value to set to the uniform variable
         *
         * \return Return true if the uniform variable was found, false otherwise
         *
         */
        bool setUniformVector(const String& name, const Vector2F& uniform);

        /*! \brief Set an uniform variable
         *
         * \param name    The name of the uniform variable in the shader
         * \param uniform The value to set to the uniform variable
         *
         * \return Return true if the uniform variable was found, false otherwise
         *
         */
        bool setUniformVector(const String& name, const Vector3F& uniform);

        /*! \brief Set an uniform variable
         *
         * \param name    The name of the uniform variable in the shader
         * \param uniform The value to set to the uniform variable
         *
         * \return Return true if the uniform variable was found, false otherwise
         *
         */
        bool setUniformVector(const String& name, const Vector4F& uniform);

        /*! \brief Set an uniform variable
         *
         * \param name    The name of the uniform variable in the shader
         * \param uniform The value to set to the uniform variable
         *
         * \return Return true if the uniform variable was found, false otherwise
         *
         */
        bool setUniformMatrix(const String& name, const Matrix4F& uniform);

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

        unsigned int m_program;
    };
}

#endif // BULL_RENDER_SHADER_SHADER_HPP
