#ifndef BULL_MATH_TRANSFORMATIONPIPLELINE_ORTHOGRAPHICPROJECTION_HPP
#define BULL_MATH_TRANSFORMATIONPIPLELINE_ORTHOGRAPHICPROJECTION_HPP

#include <Bull/Math/Matrix/Matrix4.hpp>
#include <Bull/Math/Polygon/Rectangle.hpp>

namespace Bull
{
    template <typename T>
    class OrthographicProjection
    {
    public:

        /*! \brief Default constructor
         *
         */
        OrthographicProjection() = default;

        /*! \brief Constructor
         *
         * \param plan    The plan to look through
         * \param zBounds Limits on Z axis
         *
         */
        OrthographicProjection(const Rectangle<T>& plan, const Vector2<T>& zBounds);

        /*! \brief Set the plan of the projection
         *
         * \param plan The new plan
         *
         * \return This
         *
         */
        OrthographicProjection<T>& setPlan(const Rectangle<T>& plan);

        /*! \brief Get the plan of the projection
         *
         * \return The plan
         *
         */
        const Rectangle<T>& getPlan() const;

        /*! \brief Set the Z bounds of the projection
         *
         * \param plan The new Z bounds
         *
         * \return This
         *
         */
        OrthographicProjection<T>& setZBounds(const Vector2<T>& zBounds);

        /*! \brief Get the Z bounds of the projection
         *
         * \return The Z bounds
         *
         */
        const Rectangle<T>& getZBounds() const;

        /*! \brief Convert the PerspectiveProjection to a Matrix4
         *
         * \return The Matrix4
         *
         */
        const Matrix4<T>& getMatrix() const;

    private:

        /*! \brief Update the projection matrix
         *
         */
        void updateProjection();

        Rectangle<T> m_plan;
        Vector2<T>   m_zBounds;
        Matrix4<T>   m_projection;
    };

    typedef OrthographicProjection<int>          OrthographicProjectionI;
    typedef OrthographicProjection<float>        OrthographicProjectionF;
    typedef OrthographicProjection<double>       OrthographicProjectionD;
    typedef OrthographicProjection<unsigned int> OrthographicProjectionUI;
}

#include <Bull/Math/TransformationPipeline/OrthographicProjection.inl>

#endif // BULL_MATH_TRANSFORMATIONPIPLELINE_ORTHOGRAPHICPROJECTION_HPP
