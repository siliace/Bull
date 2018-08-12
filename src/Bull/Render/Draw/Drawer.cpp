#include <map>

#include <Bull/Render/Context/GlFunctions.hpp>
#include <Bull/Render/Draw/Drawer.hpp>

namespace Bull
{
    namespace
    {
        std::map<RenderPrimitive, GLenum> primitiveMapper = {
                {RenderPrimitive_Points, GL_POINTS},
                {RenderPrimitive_Lines, GL_LINES},
                {RenderPrimitive_LineLoop, GL_LINE_LOOP},
                {RenderPrimitive_LineStrip, GL_LINE_STRIP},
                {RenderPrimitive_Triangles, GL_TRIANGLES},
                {RenderPrimitive_TriangleFan , GL_TRIANGLE_FAN},
                {RenderPrimitive_TriangleStrip, GL_TRIANGLE_STRIP},
                {RenderPrimitive_LinesAdjacency, GL_LINES_ADJACENCY},
                {RenderPrimitive_LineStripAdjacency, GL_LINE_STRIP_ADJACENCY},
                {RenderPrimitive_TrianglesAdjacency, GL_TRIANGLES_ADJACENCY},
                {RenderPrimitive_TriangleStripAdjacency, GL_TRIANGLE_STRIP_ADJACENCY},
        };

        std::map<DataType, GLenum> datatypeMapper = {
                {DataType_Byte, GL_BYTE},
                {DataType_UnsignedByte, GL_UNSIGNED_BYTE},
                {DataType_Short, GL_SHORT},
                {DataType_UnsignedShort, GL_UNSIGNED_SHORT},
                {DataType_Int, GL_INT},
                {DataType_UnsignedInt, GL_UNSIGNED_INT},
                {DataType_Float, GL_FLOAT},
                {DataType_Double, GL_DOUBLE},
        };
    }

    void Drawer::drawArrays(RenderPrimitive primitive, std::size_t start, std::size_t count)
    {
        gl::drawArrays(primitiveMapper[primitive], start, count);
    }

    void Drawer::drawElements(RenderPrimitive primitive, std::size_t count, DataType type, const void* indices)
    {
        gl::drawElements(primitiveMapper[primitive], count, datatypeMapper[type], indices);
    }
}