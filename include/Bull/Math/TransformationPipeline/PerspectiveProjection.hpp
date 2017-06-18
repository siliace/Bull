#ifndef BULL_MATH_TRANSFORMATIONPIPLELINE_PERSPECTIVEPROJECTION_HPP
#define BULL_MATH_TRANSFORMATIONPIPLELINE_PERSPECTIVEPROJECTION_HPP

namespace Bull
{
    template <typename T>
    class PerspectiveProjection
    {
    public:

        /*! \brief Default constructor
         *
         */
        PerspectiveProjection();

        /*! \brief Constructor
         *
         * \param angle
         * \param ratio
         * \param zBounds
         *
         */
        PerspectiveProjection(const Angle<T>& angle, float ratio, const Vector2<T>& zBounds);

        /*! \brief
         *
         * \param angle
         *
         * \return
         *
         */
        PerspectiveProjection<T>& setAngle(const Angle<T>& angle);

        /*! \brief
         *
         * \return
         *
         */
        const Angle<T>& getAngle() const;

        /*! \brief
         *
         * \param ratio
         *
         * \return
         *
         */
        PerspectiveProjection<T>& setRatio(float ratio);

        /*! \brief
         *
         * \return
         *
         */
        float getRatio() const;

        /*! \brief
         *
         * \param zBounds
         *
         * \return
         *
         */
        PerspectiveProjection<T>& setZBounds(const Vector2<T>& zBounds);

        /*! \brief
         *
         * \return
         *
         */
        const Vector2<T>& getZBounds() const;

        /*! \brief Convert the PerspectiveProjection to a Matrix4F
         *
         * \return The Matrix4F representing the projection
         *
         */
        const Matrix4<T>& getMatrix() const;

    private:

        /*! \brief Update the projection
         *
         */
        void updateProjection() const;

        AngleF             m_angle;
        float              m_ratio;
        bool               m_isValid;
        Vector2<T>         m_zBounds;
        mutable Matrix4<T> m_projection;
    };

    typedef PerspectiveProjection<int>          PerspectiveProjectionI;
    typedef PerspectiveProjection<float>        PerspectiveProjectionF;
    typedef PerspectiveProjection<double>       PerspectiveProjectionD;
    typedef PerspectiveProjection<unsigned int> PerspectiveProjectionUI;
}

#include <Bull/Math/TransformationPipeline/PerspectiveProjection.inl>

#endif // BULL_MATH_TRANSFORMATIONPIPLELINE_PERSPECTIVEPROJECTION_HPP
