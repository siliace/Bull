#include <Bull/Render/Context/ShaderStateSaver.hpp>
#include <Bull/Render/OpenGL.hpp>

namespace Bull
{
    ShaderStateSaver::ShaderStateSaver()
    {
        gl::getIntegerv(GL_CURRENT_PROGRAM, &m_shader);
    }

    ShaderStateSaver::~ShaderStateSaver()
    {
        gl::useProgram(m_shader);
    }
}
