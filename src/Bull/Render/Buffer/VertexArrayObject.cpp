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

        Expect(gl::isVertexArray(m_vao), Throw(OpenGLHandlerError, "Failed to create VAO"));
    }

    VertexArrayObject::VertexArrayObject(VertexArrayObject&& right) noexcept
    {
        std::swap(m_vao, right.m_vao);
    }

    VertexArrayObject::~VertexArrayObject()
    {
        gl::deleteVertexArrays(1, &m_vao);
    }

    VertexArrayObject& VertexArrayObject::operator=(VertexArrayObject&& right) noexcept
    {
        std::swap(m_vao, right.m_vao);

        return *this;
    }

    void VertexArrayObject::runBound(const std::function<void()>& functor) const
    {
        gl::bindVertexArray(m_vao);
        functor();
        gl::bindVertexArray(0);
    }
}