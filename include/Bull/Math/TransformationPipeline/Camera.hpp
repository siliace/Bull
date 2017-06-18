#ifndef BULL_MATH_TRANSFORMATIONPIPELINE_CAMERA_HPP
#define BULL_MATH_TRANSFORMATIONPIPELINE_CAMERA_HPP

#include <Bull/Math/Matrix/Matrix4.hpp>
#include <Bull/Math/Vector/Vector3.hpp>

namespace Bull
{
    template <typename T>
    class Camera
    {
    public:

        /*! \brief Constructor
         *
         * \param position The initial position
         * \param target   The target to look at
         * \param up       The up vector
         *
         */
        Camera(const Vector3<T>& position = Vector3<T>::Zero, const Vector3<T>& target = Vector3<T>::Zero, const Vector3<T>& up = Vector3<T>::Up);

        /*! \brief Set the position of the Camera
         *
         * \param position The new position
         *
         * \return This
         *
         */
        Camera<T>& setPosition(const Vector3<T>& position);

        /*! \brief Get the position fo the Camera
         *
         * \return The position
         *
         */
        const Vector3<T>& getPosition() const;

        /*! \brief Set the target of the Camera
         *
         * \param target The new target
         *
         * \return This
         *
         */
        Camera<T>& setTarget(const Vector3<T>& target);

        /*! \brief Get the target of the Camera
         *
         * \return The target
         *
         */
        const Vector3<T>& getTarget() const;

        /*! \brief Convert to a view Matrix
         *
         * \return The view matrix
         *
         */
        const Matrix4<T>& getMatrix() const;

    private:

        /*! \brief Update Camera's vectors
         *
         */
        void updateVectors();

        /*! \brief Recompute the view matrix
         *
         */
        void recomputeMatrix() const;

        Vector3<T>         m_up;       /*!< The up vector */
        mutable Matrix4<T> m_view;     /*!< The view matrix */
        Vector3<T>         m_right;    /*!< The right vector */
        Vector3<T>         m_target;   /*!< The target to look at */
        Vector3<T>         m_forward;  /*!< The forward vector */
        bool               m_isValid;  /*!< Is the view matrix is valid */
        Vector3<T>         m_position; /*!< The position of the Camera */
    };

    typedef Camera<int>          CameraI;
    typedef Camera<float>        CameraF;
    typedef Camera<double>       CameraD;
    typedef Camera<unsigned int> CameraUI;
}

#include <Bull/Math/TransformationPipeline/Camera.inl>

#endif //BULL_MATH_TRANSFORMATIONPIPELINE_CAMERA_HPP
