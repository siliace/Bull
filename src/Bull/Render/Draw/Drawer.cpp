#include <Bull/Render/Context/GlFunctions.hpp>
#include <Bull/Render/Draw/Drawer.hpp>

namespace Bull
{
    void Drawer::drawArrays(RenderPrimitive primitive, std::size_t start, std::size_t count)
    {
        gl::drawArrays(convertPrimitive(primitive), start, count);
    }

    void Drawer::drawElements(RenderPrimitive primitive, std::size_t count, DataType type, const void* indices)
    {
        gl::drawElements(convertPrimitive(primitive), count, convertDataType(type), indices);
    }

    unsigned int Drawer::convertPrimitive(RenderPrimitive primitive)
    {
        switch(primitive)
        {
            case RenderPrimitive_Points: return GL_POINTS;
            case RenderPrimitive_Lines: return GL_LINES;
            case RenderPrimitive_LineLoop: return GL_LINE_LOOP;
            case RenderPrimitive_LineStrip: return GL_LINE_STRIP;
            case RenderPrimitive_Triangles: return GL_TRIANGLES;
            case RenderPrimitive_TriangleFan : return GL_TRIANGLE_FAN;
            case RenderPrimitive_TriangleStrip: return GL_TRIANGLE_STRIP;
            case RenderPrimitive_LinesAdjacency: return GL_LINES_ADJACENCY;
            case RenderPrimitive_LineStripAdjacency: return GL_LINE_STRIP_ADJACENCY;
            case RenderPrimitive_TrianglesAdjacency: return GL_TRIANGLES_ADJACENCY;
            case RenderPrimitive_TriangleStripAdjacency: return GL_TRIANGLE_STRIP_ADJACENCY;
        }

        return 0;
    }

    unsigned int Drawer::convertDataType(DataType type)
    {
        switch(type)
        {
            case DataType_Byte: return GL_BYTE;
            case DataType_UnsignedByte: return GL_UNSIGNED_BYTE;
            case DataType_Short: return GL_SHORT;
            case DataType_UnsignedShort: return GL_UNSIGNED_SHORT;
            case DataType_Int: return GL_INT;
            case DataType_UnsignedInt: return GL_UNSIGNED_INT;
            case DataType_Float: return GL_FLOAT;
            case DataType_Double: return GL_DOUBLE;
        }

        return 0;
    }
}