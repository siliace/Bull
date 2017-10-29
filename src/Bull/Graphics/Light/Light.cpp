#include <Bull/Graphics/Light/Light.hpp>

namespace Bull
{
    LightType Light::getType() const
    {
        return m_type;
    }

    void Light::setAmbiantFactor(float ambient)
    {
        m_ambient = ambient;
    }

    float Light::getAmbiantFactor() const
    {
        return m_ambient;
    }

    void Light::setDiffuseFactor(float diffuse)
    {
        m_diffuse = diffuse;
    }

    float Light::getDiffuseFactor() const
    {
        return m_diffuse;
    }

    void Light::setColor(const Color& color)
    {
        m_color = color;
    }

    const Color& Light::getColor() const
    {
        return m_color;
    }

    Light::Light(LightType type) :
        m_type(type)
    {
        setDiffuseFactor(1.f);
        setAmbiantFactor((type == LightType_Directional) ? 0.2f : 0.f);
    }
}