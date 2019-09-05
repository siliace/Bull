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
        setColor(color);
        setPosition(position);
        setAttenuation(1.f, 0.09f, 0.032f);
    }

    void PointLight::setAttenuation(float constant, float linear, float quadratic)
    {
        m_linear = linear;
        m_constant = constant;
        m_quadratic = quadratic;
    }

    void PointLight::setUniforms(Shader& shader, const std::string& name) const
    {
        if(shader.isLinked())
        {
            AbstractLight::setUniforms(shader, name);
            shader.setUniform(compose(name, "linear"), m_linear);
            shader.setUniform(compose(name, "constant"), m_constant);
            shader.setUniform(compose(name, "quadratic"), m_quadratic);
            shader.setUniformVector(compose(name, "position"), m_position);
        }
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