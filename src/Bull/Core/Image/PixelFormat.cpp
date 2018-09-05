#include <Bull/Core/Image/PixelFormat.hpp>

namespace Bull
{
    PixelFormat PixelFormat::Luma8 = PixelFormat(PixelFormat::Type::Luma, PixelFormat::Data::UnsignedByte);
    PixelFormat PixelFormat::LumaAlpha8 = PixelFormat(PixelFormat::Type::LumaAlpha, PixelFormat::Data::UnsignedByte);
    PixelFormat PixelFormat::RGB8 = PixelFormat(PixelFormat::Type::Rgb, PixelFormat::Data::UnsignedByte);
    PixelFormat PixelFormat::RGBA8 = PixelFormat(PixelFormat::Type::RgbAlpha, PixelFormat::Data::UnsignedByte);
    PixelFormat PixelFormat::DepthStencil = PixelFormat(PixelFormat::Type::DepthStencil, PixelFormat::Data::UnsignedInt24_8);

    PixelFormat::PixelFormat() :
        PixelFormat(PixelFormat::Type::None, PixelFormat::Data::None)
    {
        /// Nothing
    }

    bool PixelFormat::isValid() const
    {
        return m_type != PixelFormat::Type::None && m_data !=PixelFormat::Data::UnsignedByte;
    }

    PixelFormat::PixelFormat(PixelFormat::Type type, PixelFormat::Data data) :
        m_type(type),
        m_data(data)
    {
        /// Nothing
    }
}