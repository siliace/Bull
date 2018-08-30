#include <Bull/Graphics/Light/SpotLight.hpp>

namespace Bull
{
    SpotLight::SpotLight() :
        SpotLight(Vector3F::Zero, Vector3F::Zero)
    {
        /// Nothing
    }

    SpotLight::SpotLight(const Vector3F& position, const Vector3F& direction, const Color& color) :
        AbstractLight(LightType_Spot),
        m_position(position),
        m_direction(direction)
    {
        setColor(color);
        m_constant    = 1.f;
        m_linear      = 0.09f;
        m_quadratic   = 0.0032f;
        m_innerCutOff = AngleF::degree(12.5f);
        m_outerCutOff = AngleF::degree(17.5f);
    }

    void SpotLight::setUniforms(Shader& shader, const String& name) const
    {
        AbstractLight::setUniforms(shader, name);

        shader.setUniform(compose(name, "linear"), m_linear);
        shader.setUniform(compose(name, "constant"), m_constant);
        shader.setUniform(compose(name, "quadratic"), m_quadratic);
        shader.setUniformVector(compose(name, "position"), m_position);
        shader.setUniformVector(compose(name, "direction"), m_direction);
        shader.setUniform(compose(name, "innerCutOff"), std::cos(m_innerCutOff));
        shader.setUniform(compose(name, "outerCutOff"), std::cos(m_outerCutOff));
    }
}