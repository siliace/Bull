#ifndef BULL_GRAPHICS_LIGHT_SPOTLIGHT_HPP
#define BULL_GRAPHICS_LIGHT_SPOTLIGHT_HPP

#include <Bull/Graphics/Light/Light.hpp>

#include <Bull/Math/Vector/Vector3.hpp>

namespace Bull
{
    class BULL_GRAPHICS_API SpotLight : public Light
    {
    public:

        /*! \brief Default constructor
         *
         */
        SpotLight();

        /*! \brief Constructor
         *
         * \param position  The position of the SpotLight
         * \param direction
         * \param color
         *
         */
        SpotLight(const Vector3F& position, const Vector3F& direction, const Color& color = Color::White);

    private:

        Vector3F m_position;
        Vector3F m_direction;
    };
}

#endif // BULL_GRAPHICS_LIGHT_SPOTLIGHT_HPP
