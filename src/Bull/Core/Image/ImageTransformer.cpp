#include <stb_image/stb_image_resize.h>

#include <Bull/Core/Exception/InternalError.hpp>
#include <Bull/Core/Exception/InvalidParameter.hpp>
#include <Bull/Core/Image/ImageTransformer.hpp>
#include <Bull/Core/Image/EdgeMode.hpp>

namespace Bull
{
    namespace
    {
        stbir_edge edgeModeToStbirEdge(Bull::EdgeMode mode)
        {
            switch(mode)
            {
                case EdgeMode_Wrap:    return STBIR_EDGE_WRAP;
                case EdgeMode_Clamp:   return STBIR_EDGE_CLAMP;
                case EdgeMode_Reflect: return STBIR_EDGE_REFLECT;
                case EdgeMode_None:    return STBIR_EDGE_ZERO;
            }

            return STBIR_EDGE_CLAMP;
        }
    }

    ImageTransformer::ImageTransformer(const Image& image)
    {
        Expect(image.isLoaded(), Throw(InvalidParameter, "ImageTransformer::ImageTransformer", "Can not transform an Image not loaded"));

        m_image = image;
    }

    ImageTransformer& ImageTransformer::resize(const Size& size, EdgeMode mode)
    {
        std::vector<Uint8> pixelsOutput(size.width * size.height * 4);

        int result = stbir_resize_uint8_srgb_edgemode(m_image.getPixels().data(), m_image.getSize().width, m_image.getSize().height, 0,
                                                      &pixelsOutput[0], size.width, size.height, 0,
                                                      4, 1, 0,
                                                      edgeModeToStbirEdge(mode)
        );

        Expect(result, Throw(InternalError, "ImageTransformer::resize", "Failed to resize image"));

        m_image.create(pixelsOutput, size);

        return *this;
    }

    const Image& ImageTransformer::getImage() const
    {
        return m_image;
    }
}