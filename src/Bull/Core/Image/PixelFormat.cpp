#include <Bull/Core/Image/PixelFormat.hpp>

namespace Bull
{
    PixelFormat::Info PixelFormat::getPixelFormatTypeInfo(PixelFormatType type)
    {
        switch(type)
        {
            case PixelFormatType_A8:     return {"A8",     PixelDataType_UnsignedInt, 8};
            case PixelFormatType_B8:     return {"B8",     PixelDataType_UnsignedInt, 8};
            case PixelFormatType_G8:     return {"G8",     PixelDataType_UnsignedInt, 8};
            case PixelFormatType_L8:     return {"L8",     PixelDataType_UnsignedInt, 8};
            case PixelFormatType_R8:     return {"R8",     PixelDataType_UnsignedInt, 8};
            case PixelFormatType_AL8:    return {"AL8",    PixelDataType_UnsignedInt, 8};
            case PixelFormatType_B8F:    return {"B8F",    PixelDataType_Half,        8};
            case PixelFormatType_G8F:    return {"G8F",    PixelDataType_Half,        8};
            case PixelFormatType_R8F:    return {"R8F",    PixelDataType_Half,        8};
            case PixelFormatType_B8I:    return {"B8I",    PixelDataType_Int,         8};
            case PixelFormatType_G8I:    return {"G8I",    PixelDataType_Int,         8};
            case PixelFormatType_R8I:    return {"R8I",    PixelDataType_Int,         8};
            case PixelFormatType_B16F:   return {"B16F",   PixelDataType_Float,       16};
            case PixelFormatType_G16F:   return {"G16F",   PixelDataType_Float,       16};
            case PixelFormatType_R16F:   return {"R16F",   PixelDataType_Float,       16};
            case PixelFormatType_B16I:   return {"B16I",   PixelDataType_UnsignedInt, 16};
            case PixelFormatType_G16I:   return {"G16I",   PixelDataType_UnsignedInt, 16};
            case PixelFormatType_R16I:   return {"R16I",   PixelDataType_UnsignedInt, 16};
            case PixelFormatType_B32F:   return {"B32F",   PixelDataType_Float,       32};
            case PixelFormatType_G32F:   return {"G32F",   PixelDataType_Float,       32};
            case PixelFormatType_R32F:   return {"R32F",   PixelDataType_Float,       32};
            case PixelFormatType_B32I:   return {"B32I",   PixelDataType_UnsignedInt, 32};
            case PixelFormatType_G32I:   return {"G32I",   PixelDataType_UnsignedInt, 32};
            case PixelFormatType_R32I:   return {"R32I",   PixelDataType_UnsignedInt, 32};
            case PixelFormatType_RGB8:   return {"RGB8",   PixelDataType_UnsignedInt, 8};
            case PixelFormatType_RGB16:  return {"RGB16",  PixelDataType_UnsignedInt, 16};
            case PixelFormatType_RGB32:  return {"RGB32",  PixelDataType_UnsignedInt, 32};
            case PixelFormatType_RGB8F:  return {"RGB8F",  PixelDataType_Half,        8};
            case PixelFormatType_RGB8I:  return {"RGB8I",  PixelDataType_Int,         8};
            case PixelFormatType_ARGB8:  return {"ARGB8",  PixelDataType_UnsignedInt, 8};
            case PixelFormatType_DXTC1:  return {"DXTC1",  PixelDataType_Compressed,  8};
            case PixelFormatType_DXTC3:  return {"DXTC3",  PixelDataType_Compressed,  16};
            case PixelFormatType_DXTC5:  return {"DXTC5",  PixelDataType_Compressed,  16};
            case PixelFormatType_ARGB8F: return {"ARGB8F", PixelDataType_Half,        8};
            case PixelFormatType_ARGB8I: return {"ARGB8I", PixelDataType_Int,         8};
            case PixelFormatType_RGB16F: return {"RGB16F", PixelDataType_Half,        16};
            case PixelFormatType_RGB16I: return {"RGB16I", PixelDataType_Int,         16};
            case PixelFormatType_RGB32F: return {"RGB32F", PixelDataType_Float,       32};
            case PixelFormatType_RGB32I: return {"RGB32I", PixelDataType_Int,         32};
        }
    }
}