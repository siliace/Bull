#include <Bull/Render/OpenGL.hpp>

namespace Bull
{
    GLenum OpenGL::attachmentPoint(AttachmentPoint attachmentPoint)
    {
        switch(attachmentPoint)
        {
            case AttachmentPoint::Color:
                return GL_COLOR_ATTACHMENT0;
            case AttachmentPoint::Depth:
                return GL_DEPTH_ATTACHMENT;
            case AttachmentPoint::Stencil:
                return GL_STENCIL_ATTACHMENT;
            case AttachmentPoint::DepthStencil:
                return GL_DEPTH_STENCIL_ATTACHMENT;
        }

        return 0;
    }

    GLenum OpenGL::hardwareBufferType(HardwareBufferType type)
    {
        switch(type)
        {
            case HardwareBufferType::Array:
                return GL_ARRAY_BUFFER;

            case HardwareBufferType::Element:
                return GL_ELEMENT_ARRAY_BUFFER;
        }

        return 0;
    }

    GLenum OpenGL::hardwareBufferUsage(HardwareBufferUsage usage)
    {
        switch(usage)
        {
            case HardwareBufferUsage::StaticDraw:
                return GL_STATIC_DRAW;

            case HardwareBufferUsage::DynamicDraw:
                return GL_DYNAMIC_DRAW;

            case HardwareBufferUsage::StreamDraw:
                return GL_STREAM_DRAW;
        }

        return 0;
    }

    GLenum OpenGL::renderPrimitive(RenderPrimitive primitive)
    {
        switch(primitive)
        {
            case RenderPrimitive::Lines:
                return GL_LINES;

            case RenderPrimitive::Points:
                return GL_POINTS;

            case RenderPrimitive::LineLoop:
                return GL_LINE_LOOP;

            case RenderPrimitive::LineStrip:
                return GL_LINE_STRIP;

            case RenderPrimitive::Triangles:
                return GL_TRIANGLES;

            case RenderPrimitive::TriangleFan:
                return GL_TRIANGLE_FAN;

            case RenderPrimitive::TriangleStrip:
                return GL_TRIANGLE_STRIP;

            case RenderPrimitive::LinesAdjacency:
                return GL_LINES_ADJACENCY;

            case RenderPrimitive::LineStripAdjacency:
                return GL_LINE_STRIP_ADJACENCY;

            case RenderPrimitive::TrianglesAdjacency:
                return GL_TRIANGLES_ADJACENCY;

            case RenderPrimitive::TriangleStripAdjacency:
                return GL_TRIANGLE_STRIP_ADJACENCY;
        }

        return 0;
    }

    GLenum OpenGL::shaderStageType(ShaderStageType type)
    {
        switch(type)
        {
            case ShaderStageType::Fragment:
                return GL_FRAGMENT_SHADER;

            case ShaderStageType::Geometry:
                return GL_GEOMETRY_SHADER;

            case ShaderStageType::Vertex:
                return GL_VERTEX_SHADER;
        }

        return 0;
    }

    GLenum OpenGL::dataType(DataType dataType)
    {
        switch(dataType.getSize())
        {
            case sizeof(Uint8):
                return dataType.isUnsigned() ? GL_UNSIGNED_BYTE : GL_BYTE;

            case sizeof(Uint16):
                return dataType.isUnsigned() ? GL_UNSIGNED_SHORT : GL_SHORT;

            case sizeof(Uint32):
                if(dataType.isFloatingPoint())
                    return GL_FLOAT;
                return dataType.isUnsigned() ? GL_UNSIGNED_INT : GL_INT;

            case sizeof(double):
                return GL_DOUBLE;
        }

        return 0;
    }
}