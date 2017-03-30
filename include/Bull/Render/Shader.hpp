#ifndef Bull_Shader_hpp
#define Bull_Shader_hpp

#include <Bull/Core/Memory/String.hpp>
#include <Bull/Core/Pattern/NonCopyable.hpp>

#include <Bull/Math/Matrix/Matrix4.hpp>

#include <Bull/Render/ShaderStage.hpp>

#include <Bull/Utility/Color.hpp>

#include <Bull/Window/ContextResource.hpp>

namespace Bull
{
    class Shader : public NonCopyable, public ContextResource
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
         * @param stage The stage to attach to this Shader
         *
         */
        void attach(const ShaderStage& stage);

        /*! \brief
         *
         * @return
         *
         */
        bool link();

        /*! \brief Bind the shader
         *
         */
        void bind() const;

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
        bool setUniform(const String& name, const Color& uniform);

        /*! \brief Set an uniform variable
         *
         * \param name    The name of the uniform variable in the shader
         * \param uniform The value to set to the uniform variable
         *
         * \return Return true if the uniform variable was found, false otherwise
         *
         */
        bool setUniform(const String& name, const Matrix4F& uniform);

        /*! \brief Get the Shader system handler
         *
         * \return The native ShaderStage system handler
         *
         */
        unsigned int getSystemHandler() const;

    protected:

        /*! \brief Check if the program as an error
         *
         * @return True if the program has an error
         *
         */
        bool hasError() const;

        /*! \brief Get the current error code of the program
         *
         * @return The error code
         *
         */
        unsigned int getErrorCode() const;

        /*! \brief Get the current error message of the program
         *
         * @return The error message
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

#endif // Bull_Shader_hpp
