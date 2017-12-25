#ifndef BULL_GRAPHICS_LIGHT_POINTLIGHT_HPP
#define BULL_GRAPHICS_LIGHT_POINTLIGHT_HPP

#include <Bull/Graphics/Light/AbstractLight.hpp>

#include <Bull/Math/Vector/Vector3.hpp>

namespace Bull
{
    class BULL_GRAPHICS_API PointLight : public AbstractLight
    {
    public:

        /*! \brief Default constructor
         *
         */
        PointLight();

        /*! \brief Constructor
         *
         * \param position The position of the PointLight
         * \param color    The color of the PointLight
         *
         */
        explicit PointLight(const Vector3F& position, const Color& color = Color::White);

        /*! \brief Set the radius of the PointLight
         *
         * \param radius The radius
         *
         */
        void setRadius(float radius);

        /*! \brief Get the radius of the PointLight
         *
         * \return The radius
         *
         */
        float getRadius() const;

        /*! \brief Set the position of the PointLight
         *
         * \param position The position
         *
         */
        void setPosition(const Vector3F& position);

        /*! \brief Get the position of the PointLight
         *
         * \return The position
         *
         */
        const Vector3F& getPosition() const;

    private:

        float    m_radius;
        Vector3F m_position;
    };
}

#endif // BULL_GRAPHICS_LIGHT_POINTLIGHT_HPP
