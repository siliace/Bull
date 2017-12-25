#ifndef BULL_GRAPHICS_LIGHT_DIRECTIONALLIGHT_HPP
#define BULL_GRAPHICS_LIGHT_DIRECTIONALLIGHT_HPP

#include <Bull/Graphics/Light/AbstractLight.hpp>

#include <Bull/Math/Vector/Vector3.hpp>

namespace Bull
{
    class BULL_GRAPHICS_API DirectionalLight : public AbstractLight
    {
    public:

        /*! \brief Default constructor
         *
         */
        DirectionalLight();

        /*! \brief Constructor
         *
         * \param direction The direction of the DirectionalLight
         * \param color     The Color of the DirectionalLight
         *
         */
        explicit DirectionalLight(const Vector3F& direction, const Color& color = Color::White);

        /*! \brief Set the direction of the DirectionalLight
         *
         * \param direction The direction
         *
         */
        void setDirection(const Vector3F& direction);

        /*! \brief Get the direction of the DirectionalLight
         *
         * \return The direction
         *
         */
        const Vector3F& getDirection() const;

    private:

        Vector3F m_direction;
    };
}

#endif // BULL_GRAPHICS_LIGHT_DIRECTIONALLIGHT_HPP
