#include <Bull/Utility/TransformationPipeline/Camera.hpp>

namespace Bull
{
    Camera::Camera() :
        Camera(Vector3F::makeZero())
    {
        /// Nothing
    }

    Camera::Camera(const Vector3F& position) :
        m_up(Vector3F::makeUp()),
        m_right(-Vector3F::makeRight()),
        m_forward(-Vector3F::makeForward())
    {
        move(position);
    }

    Camera& Camera::setForward(const Vector3F& forward)
    {
        m_forward = forward;

        update();

        return (*this);
    }

    const Vector3F& Camera::getForward() const
    {
        return m_forward;
    }

    Camera& Camera::move(const Vector3F& offset)
    {
        m_position += offset.y * m_up;
        m_position += offset.x * m_right;
        m_position += offset.z * m_forward;

        return (*this);
    }

    Matrix4F Camera::toMatrix() const
    {
        Matrix4F lookAt;

        lookAt.setColumn(Vector4F( m_right,  -m_right.dotProduct(m_position)),   0);
        lookAt.setColumn(Vector4F( m_up,     -m_up.dotProduct(m_position)),      1);
        lookAt.setColumn(Vector4F(-m_forward, m_forward.dotProduct(m_position)), 2);
        lookAt.setColumn(Vector4F(0.f, 0.f, 0.f, 1.f),                           3);

        return lookAt;
    }

    void Camera::update()
    {
        m_forward.normalize();
        m_right = Vector3F::crossProduct(m_forward, m_up).normalize();
        m_up    = Vector3F::crossProduct(m_right, m_forward).normalize();
    }
}