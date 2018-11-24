#include <map>

#include <Bull/Render/Context/GlFunctions.hpp>
#include <Bull/Render/Draw/Drawer.hpp>
#include <Bull/Render/OpenGL.hpp>

namespace Bull
{
    void Drawer::drawArrays(RenderPrimitive primitive, std::size_t start, std::size_t count)
    {
        gl::drawArrays(OpenGL::renderPrimitive(primitive), start, count);
    }

    void Drawer::drawArraysInstanced(Bull::RenderPrimitive primitive, std::size_t instanceCount, std::size_t start, std::size_t count)
    {
        gl::drawArraysInstanced(OpenGL::renderPrimitive(primitive), start, count, instanceCount);
    }

    void Drawer::drawElements(RenderPrimitive primitive, std::size_t count, DataType type, const void* indices)
    {
        gl::drawElements(OpenGL::renderPrimitive(primitive), count, OpenGL::dataType(type), indices);
    }

    void Drawer::drawElementsInstanced(RenderPrimitive primitive, std::size_t instanceCount, std::size_t count, DataType type, const void* indices)
    {
        gl::drawElementsInstanced(OpenGL::renderPrimitive(primitive), count, OpenGL::dataType(type), indices, instanceCount);
    }
}