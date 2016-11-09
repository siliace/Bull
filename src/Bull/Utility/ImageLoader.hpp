#ifndef Bull_ImageLoader_hpp
#define Bull_ImageLoader_hpp

#include <Bull/Core/String.hpp>
#include <Bull/Core/Integer.hpp>

#include <Bull/Math/Vector/Vector2.hpp>

namespace Bull
{
    namespace prv
    {
        class ImageLoader
        {
        public:

            static bool load(const String& path, std::vector<Uint8>& pixels, Vector2UI& size);
        };
    }
}

#endif // Bull_ImageLoader_hpp
