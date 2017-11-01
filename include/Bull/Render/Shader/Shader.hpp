#ifndef BULL_RENDER_SHADER_SHADER_HPP
#define BULL_RENDER_SHADER_SHADER_HPP

#include <Bull/Core/Memory/ByteArray.hpp>
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
         * \param binary The binary of the Shader
         *
         * \return True if the Shader was created successfully
         *
         */
        bool create(const ShaderBinary& binary);

        /*! \brief Attach a ShaderStage to this Shader
         *
         * \param stage The stage to attach to this Shader
         *
         * \return True if the stage was attached successfully
         *
         */
        bool attach(const ShaderStage& stage);

        /*! \brief Load a ShaderStage form a Path and attach it to this Shader
         *
         * \param path The Path of the File to read
         * \param type The type of the ShaderStage
         *
         * \return True if the ShaderStage was attached successfully
         *
         */
        bool attachFromPath(const Path& path, ShaderStageType type);

        /*! \brief Load a ShaderStage form a stream and attach it to this Shader
         *
         * \param stream The stream to read
         * \param type   The type of the ShaderStage
         *
         * \return True if the ShaderStage was attached successfully
         *
         */
        bool attachFromStream(InStream& stream, ShaderStageType type);

        /*! \brief Load a ShaderStage form a memory area and attach it to this Shader
         *
         * \param data   The memory area to read
         * \param length The length of the memory
         * \param type   The type of the ShaderStage
         *
         * \return True if the ShaderStage was attached successfully
         *
         */
        bool attachFromMemory(const void* data, std::size_t length, ShaderStageType type);

        /*! \brief Load the Shader from a binary form
         *
         * \param binary The binary
         *
         * \return True if the Shader was loaded successfully
         *
         */
        bool loadFromBinary(const ShaderBinary& binary);

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
