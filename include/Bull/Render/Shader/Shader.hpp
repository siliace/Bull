#ifndef BULL_SHADER_HPP
#define BULL_SHADER_HPP

#include <Bull/Math/Matrix/Matrix4.hpp>
#include <Bull/Math/Vector/Vector2.hpp>
#include <Bull/Math/Vector/Vector3.hpp>
#include <Bull/Math/Vector/Vector4.hpp>

#include <Bull/Render/Export.hpp>
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

        /*! \brief Load a ShaderStage from a file and attach to this Shader
         *
         * \param path The path of the file of the ShaderStage to load and attach
         * \param type The type of the ShaderStage to load
         *
         * \return True if the stage was attached successfully
         *
         */
        bool attachFromPath(const Path& path, ShaderStage::Type type);

        /*! \brief Load a ShaderStage from its code and attach to this Shader
         *
         * \param path The source code of the ShaderStage to load
         * \param type The type of the ShaderStage to load
         *
         * \return True if the stage was attached successfully
         *
         */
        bool attachFromCode(const String& code, ShaderStage::Type type);

        /*! \brief Load a ShaderStage from a stream and attach to this Shader
         *
         * \param path The stream to read to load the ShaderStage
         * \param type The type of the ShaderStage to load
         *
         * \return True if the stage was attached successfully
         *
         */
        bool attachFromStream(InStream& stream, ShaderStage::Type type);

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
         * \return True if the Shader is valis
         *
         */
        bool isValid() const;

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

        /*! \brief Get the Shader system handler
         *
         * \return The native ShaderStage system handler
         *
         */
        unsigned int getSystemHandler() const;

    protected:

        /*! \brief Check if the program as an error
         *
         * \return True if the program has an error
         *
         */
        bool hasError() const;

        /*! \brief Get the current error code of the program
         *
         * \return The error code
         *
         */
        unsigned int getErrorCode() const;

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

#endif // BULL_SHADER_HPP
