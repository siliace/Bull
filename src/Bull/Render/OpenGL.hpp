#ifndef BULL_RENDER_OPENGL_HPP
#define BULL_RENDER_OPENGL_HPP

#include <Bull/Core/Utility/DataType.hpp>

#include <Bull/Render/Buffer/HardwareBufferUsage.hpp>
#include <Bull/Render/Buffer/HardwareBufferType.hpp>
#include <Bull/Render/Context/GlFunctions.hpp>
#include <Bull/Render/Draw/RenderPrimitive.hpp>
#include <Bull/Render/FrameBuffer/AttachmentPoint.hpp>
#include <Bull/Render/Shader/ShaderStageType.hpp>

namespace Bull
{
    class OpenGL
    {
    public:

        static GLenum attachmentPoint(AttachmentPoint attachmentPoint);

        static GLenum dataType(DataType dataType);

        static GLenum hardwareBufferType(HardwareBufferType type);

        static GLenum hardwareBufferUsage(HardwareBufferUsage usage);

        static GLenum renderPrimitive(RenderPrimitive primitive);

        static GLenum shaderStageType(ShaderStageType type);
    };
}

#endif // !BULL_RENDER_OPENGL_HPP
