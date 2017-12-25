#include <Bull/Graphics/Light/SpotLight.hpp>

namespace Bull
{
    SpotLight::SpotLight() :
        SpotLight(Vector3F::Zero, Vector3F::Zero)
    {
        /// Nothing
    }

    SpotLight::SpotLight(const Vector3F& position, const Vector3F& direction, const Color& color) :
        AbstractLight(LightType_Spot)
    {
        setColor(color);
    }
}