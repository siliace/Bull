#include <Bull/Core/Exception/Throw.hpp>

#include <Bull/Render/Buffer/VertexArrayObject.hpp>
#include <Bull/Render/Context/GlFunctions.hpp>
#include <Bull/Render/Context/OpenGLHandlerError.hpp>

namespace Bull
{
    VertexArrayObject::VertexArrayObject() :
        m_vao(0)
    {
        gl::genVertexArrays(1, &m_vao);
        gl::bindVertexArray(m_vao);

        if(!gl::isVertexArray(m_vao))
        {
            Throw(OpenGLHandlerError, "VertexArrayObject::VertexArrayObject", "Failed to create VAO");
        }
    }

    VertexArrayObject::~VertexArrayObject()
    {
        gl::deleteVertexArrays(1, &m_vao);
    }

    void VertexArrayObject::runBound(const std::function<void()>& functor) const
    {
        gl::bindVertexArray(m_vao);
        functor();
        gl::bindVertexArray(0);
    }
}