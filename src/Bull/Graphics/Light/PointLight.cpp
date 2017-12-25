#include <Bull/Graphics/Light/PointLight.hpp>

namespace Bull
{
    PointLight::PointLight() :
        PointLight(Vector3F::Zero)
    {
        /// Nothing
    }

    PointLight::PointLight(const Vector3F& position, const Color& color) :
        AbstractLight(LightType_Point)
    {
        setRadius(5.f);
        setColor(color);
        setPosition(position);
    }

    void PointLight::setRadius(float radius)
    {
        m_radius = radius;
    }

    float PointLight::getRadius() const
    {
        return m_radius;
    }

    void PointLight::setPosition(const Vector3F& position)
    {
        m_position = Vector3F::normalize(position);
    }

    const Vector3F& PointLight::getPosition() const
    {
        return m_position;
    }
}