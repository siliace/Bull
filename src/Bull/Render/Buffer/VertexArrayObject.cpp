#include <Bull/Core/Exception/RuntimeError.hpp>

#include <Bull/Render/Buffer/VertexArrayObject.hpp>
#include <Bull/Render/Context/GlFunctions.hpp>

namespace Bull
{
    VertexArrayObject::VertexArrayObject() :
        m_vao(0)
    {
        gl::genVertexArrays(1, &m_vao);

        if(!m_vao)
        {
            throw RuntimeError("Failed to create VAO");
        }
    }

    VertexArrayObject::~VertexArrayObject()
    {
        gl::deleteVertexArrays(1, &m_vao);
    }

    void VertexArrayObject::runBound(const Functor<void>& functor) const
    {
        gl::bindVertexArray(m_vao);
        functor();
        gl::bindVertexArray(0);
    }
}