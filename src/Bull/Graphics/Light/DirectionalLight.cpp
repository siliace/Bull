#include <Bull/Graphics/Light/DirectionalLight.hpp>

namespace Bull
{
    DirectionalLight::DirectionalLight() :
        DirectionalLight(Vector3F::Zero)
    {
        /// Nothing
    }

    DirectionalLight::DirectionalLight(const Vector3F& direction, const Color& color) :
        AbstractLight(LightType_Directional)
    {
        setColor(color);
        setDirection(direction);
    }

    void DirectionalLight::setDirection(const Vector3F& direction)
    {
        m_direction = Vector3F::normalize(direction);
    }

    const Vector3F& DirectionalLight::getDirection() const
    {
        return m_direction;
    }
}