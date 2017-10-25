#ifndef BULL_RENDER_RENDERPRIMITIVE_HPP
#define BULL_RENDER_RENDERPRIMITIVE_HPP

namespace Bull
{
    enum RenderPrimitive
    {
        RenderPrimitive_Points,
        RenderPrimitive_Lines,
        RenderPrimitive_LineLoop,
        RenderPrimitive_LineStrip,
        RenderPrimitive_Triangles,
        RenderPrimitive_TriangleFan ,
        RenderPrimitive_TriangleStrip,
        RenderPrimitive_LinesAdjacency,
        RenderPrimitive_LineStripAdjacency,
        RenderPrimitive_TrianglesAdjacency,
        RenderPrimitive_TriangleStripAdjacency,
    };
}

#endif // BULL_RENDER_RENDERPRIMITIVE_HPP
