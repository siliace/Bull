#include <Bull/Render/Context/ShaderStateSaver.hpp>
#include <Bull/Render/OpenGL.hpp>

namespace Bull
{
    /*! \brief Default constructor
     *
     */
    ShaderStateSaver::ShaderStateSaver()
    {
        gl::getIntegerv(GL_CURRENT_PROGRAM, &m_shader);
    }

    /*! \brief Destructor
     *
     */
    ShaderStateSaver::~ShaderStateSaver()
    {
        gl::useProgram(m_shader);
    }
}
