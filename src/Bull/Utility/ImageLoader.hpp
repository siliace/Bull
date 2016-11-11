#ifndef Bull_ImageLoader_hpp
#define Bull_ImageLoader_hpp

#include <Bull/Core/String.hpp>
#include <Bull/Core/Integer.hpp>

#include <Bull/Math/Vector/Vector2.hpp>

#include <Bull/Utility/Image.hpp>

namespace Bull
{
    namespace prv
    {
        class ImageLoader
        {
        public:

            static bool load(const String& path, std::vector<Uint8>& pixels, Vector2UI& size);

            static bool save(const String& path, Image::Format format, const std::vector<Uint8>& pixels, const Vector2UI& size);

        private:

            static bool saveBmp(const String& path, const std::vector<Uint8>& pixels, const Vector2UI& size);
            static bool savePng(const String& path, const std::vector<Uint8>& pixels, const Vector2UI& size);
            static bool saveTga(const String& path, const std::vector<Uint8>& pixels, const Vector2UI& size);
        };
    }
}

#endif // Bull_ImageLoader_hpp
