#ifndef BULL_GRAPHICS_LIGHT_SPOTLIGHT_HPP
#define BULL_GRAPHICS_LIGHT_SPOTLIGHT_HPP

#include <Bull/Graphics/Light/AbstractLight.hpp>

#include <Bull/Math/Vector/Vector3.hpp>

namespace Bull
{
    class BULL_GRAPHICS_API SpotLight : public AbstractLight
    {
    public:

        /*! \brief Default constructor
         *
         */
        SpotLight();

        /*! \brief Constructor
         *
         * \param position  The position
         * \param direction The direction
         * \param color     The Color emitted
         *
         */
        SpotLight(const Vector3F& position, const Vector3F& direction, const Color& color = Color::White);

        /*! \brief Send uniforms values to a Shader
         *
         * \param shader The Shader
         * \param name   The name of the uniform
         *
         */
        virtual void setUniforms(Shader& shader, const String& name) const override;

        float    linear;
        float    constant;
        Vector3F position;
        Vector3F direction;
        float    quadratic;
        AngleF   innerCutOff;
        AngleF   outerCutOff;
    };
}

#endif // BULL_GRAPHICS_LIGHT_SPOTLIGHT_HPP
