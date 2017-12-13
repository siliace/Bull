#ifndef BULL_RENDER_SHADER_SHADER_HPP
#define BULL_RENDER_SHADER_SHADER_HPP

#include <Bull/Core/Memory/ByteVector.hpp>
#include <Bull/Core/Utility/Color.hpp>

#include <Bull/Math/Matrix/Matrix4.hpp>
#include <Bull/Math/Vector/Vector.hpp>

#include <Bull/Render/Export.hpp>
#include <Bull/Render/Shader/ShaderBinary.hpp>
#include <Bull/Render/Shader/ShaderStage.hpp>

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
        virtual ~Shader();

        /*! \brief Create a Shader from a ShaderBinary
         *
         * \param shaderBinary The binary of the Shader
         *
         * \return True if the Shader was created successfully
         *
         */
        bool create(const ShaderBinary& shaderBinary);

        /*! \brief Create a Shader by loading both vertex stage and fragment stage from their Path
         *
         * \param vertex   The Path of the vertex shader
         * \param fragment The Path of the fragment shader
         *
         * \return True if the Shader was created successfully
         *
         */
        bool create(const Path& vertex, const Path& fragment);

        /*! \brief Create a Shader by loading both vertex stage and fragment stage from streams
         *
         * \param vertex   The stream of the vertex shader
         * \param fragment The stream of the fragment shader
         *
         * \return True if the Shader was created successfully
         *
         */
        bool create(InStream& vertex, InStream& fragment);

        /*! \brief Attach a ShaderStage to this Shader
         *
         * \param stage The stage to attach to this Shader
         *
         * \return True if the stage was attached successfully
         *
         */
        bool attach(const ShaderStage& stage);

        bool attachFromPath(const Path& path, ShaderStageType type);

        bool attachFromStream(InStream& stream, ShaderStageType type);

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
        bool setUniformVector(const String& name, const Vector<float, 2>& uniform);

        /*! \brief Set an uniform variable
         *
         * \param name    The name of the uniform variable in the shader
         * \param uniform The value to set to the uniform variable
         *
         * \return Return true if the uniform variable was found, false otherwise
         *
         */
        bool setUniformVector(const String& name, const Vector<float, 3>& uniform);

        /*! \brief Set an uniform variable
         *
         * \param name    The name of the uniform variable in the shader
         * \param uniform The value to set to the uniform variable
         *
         * \return Return true if the uniform variable was found, false otherwise
         *
         */
        bool setUniformVector(const String& name, const Vector<float, 4>& uniform);

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
