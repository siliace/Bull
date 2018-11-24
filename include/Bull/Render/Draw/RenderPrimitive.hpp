#ifndef BULL_RENDER_RENDERPRIMITIVE_HPP
#define BULL_RENDER_RENDERPRIMITIVE_HPP

namespace Bull
{
    enum class RenderPrimitive
    {
        Lines,
        Points,
        LineLoop,
        LineStrip,
        Triangles,
        TriangleFan,
        TriangleStrip,
        LinesAdjacency,
        LineStripAdjacency,
        TrianglesAdjacency,
        TriangleStripAdjacency,
    };
}

#endif // BULL_RENDER_RENDERPRIMITIVE_HPP
