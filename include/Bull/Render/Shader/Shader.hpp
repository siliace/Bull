#ifndef BULL_RENDER_SHADER_SHADER_HPP
#define BULL_RENDER_SHADER_SHADER_HPP

#include <Bull/Core/Exception/Exception.hpp>
#include <Bull/Core/Utility/Color.hpp>

#include <Bull/Math/Matrix/Matrix4.hpp>
#include <Bull/Math/Vector/Vector.hpp>

#include <Bull/Render/Shader/ShaderStage.hpp>
#include <Bull/Render/Shader/ShaderBinary.hpp>

namespace Bull
{
    DeclareException(UniformVariableNotFound);

    class BULL_RENDER_API Shader : public NonCopyable, public ContextResource
    {
    public:

        /** \brief Get the maximum vertex attributes available
         *
         * \return Return the max
         *
         */
        static unsigned int getMaxVertexAttribs();

    public:

        /** \brief Default constructor
         *
         */
        Shader();

        /** \brief Constructor by movement
         *
         * \param right The Shader to move
         *
         */
        Shader(Shader&& right) noexcept;

        /** \brief Destructor
         *
         */
        ~Shader();

        /** \brief Basic assignment operator by movement
         *
         * \param right The Shader to move
         *
         * \return This
         *
         */
        Shader& operator=(Shader&& right) noexcept;

        /** \brief Create a Shader from a ShaderBinary
         *
         * \param shaderBinary The binary of the Shader
         *
         */
        void create(const ShaderBinary& shaderBinary) const;

        /** \brief Attach a ShaderStage to this Shader
         *
         * \param stage The stage to attach to this Shader
         *
         */
        void attach(const ShaderStage& stage) const;

        /** \brief Link the shader
         *
         */
        void link() const;

        /** \brief Bind the shader
         *
         */
        void bind() const;

        /** \brief Check whether the Shader is linked
         *
         * \return True if the Shader is linked
         *
         */
        bool isLinked() const;

        /** \brief Set an uniform variable
         *
         * \param name    The name of the uniform variable in the shader
         * \param uniform The value to set to the uniform variable
         *
         */
        void setUniform(const std::string& name, int uniform) const;

        /** \brief Set an uniform variable
         *
         * \param name    The name of the uniform variable in the shader
         * \param uniform The value to set to the uniform variable
         *
         */
        void setUniform(const std::string& name, unsigned int uniform) const;

        /** \brief Set an uniform variable
         *
         * \param name    The name of the uniform variable in the shader
         * \param uniform The value to set to the uniform variable
         *
         */
        void setUniform(const std::string& name, float uniform) const;

        /** \brief Set an uniform variable
         *
         * \param name    The name of the uniform variable in the shader
         * \param uniform The value to set to the uniform variable
         *
         */
        void setUniformColor(const std::string& name, const Color& uniform) const;

        /** \brief Set an uniform variable
         *
         * \param name    The name of the uniform variable in the shader
         * \param uniform The value to set to the uniform variable
         *
         */
        void setUniformVector(const std::string& name, const Vector<float, 2>& uniform) const;

        /** \brief Set an uniform variable
         *
         * \param name    The name of the uniform variable in the shader
         * \param uniform The value to set to the uniform variable
         *
         */
        void setUniformVector(const std::string& name, const Vector<float, 3>& uniform) const;

        /** \brief Set an uniform variable
         *
         * \param name    The name of the uniform variable in the shader
         * \param uniform The value to set to the uniform variable
         *
         */
        void setUniformVector(const std::string& name, const Vector<float, 4>& uniform) const;

        /** \brief Set an uniform variable
         *
         * \param name    The name of the uniform variable in the shader
         * \param uniform The value to set to the uniform variable
         *
         */
        void setUniformMatrix(const std::string& name, const Matrix4F& uniform) const;

        /** \brief Get the program as a binary format
         *
         * \return The binary format
         *
         */
        ShaderBinary getBinary() const;

        /** \brief Get the Shader system handler
         *
         * \return The native ShaderStage system handler
         *
         */
        unsigned int getSystemHandler() const;

    protected:

        /** \brief Get the current error message of the program
         *
         * \return The error message
         *
         */
        std::string getErrorMessage() const;

    private:

        /** \brief Get the location of an uniform variable
         *
         * \param name The name of the uniform variable in the shader
         *
         * \return Return the location of the uniform
         *
         */
        int getUniformLocation(const std::string& name) const;

        unsigned int m_program;
    };
}

#endif // BULL_RENDER_SHADER_SHADER_HPP
