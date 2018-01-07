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
        position(position),
        direction(direction)
    {
        setColor(color);
        constant    = 1.f;
        linear      = 0.32f;
        quadratic   = 0.07f;
        innerCutOff = AngleF::radian(12.5f);
        outerCutOff = AngleF::radian(17.5f);
    }

    void SpotLight::setUniforms(Shader& shader, const String& name) const
    {
        if(shader.isValid())
        {
            AbstractLight::setUniforms(shader, name);
            shader.setUniform(compose(name, "linear"), linear);
            shader.setUniform(compose(name, "constant"), constant);
            shader.setUniform(compose(name, "quadratic"), quadratic);
            shader.setUniformVector(compose(name, "position"), position);
            shader.setUniformVector(compose(name, "direction"), direction);
            shader.setUniform(compose(name, "innerCutOff"), std::cos(innerCutOff));
            shader.setUniform(compose(name, "outerCutOff"), std::cos(outerCutOff));
        }
    }
}