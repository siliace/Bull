#include <Bull/Utility/TransformationPipeline/Camera.hpp>

namespace Bull
{
    Camera::Camera(const Vector3F &position, const EulerAnglesF &rotation) :
        m_up(Vector3F::makeUp()),
        m_right(Vector3F::makeRight()),
        m_forward(Vector3F::makeForward())
    {
        move(position).rotate(rotation);
    }

    Camera& Camera::move(const Vector3F& offset)
    {
        m_position += offset.y * m_up;
        m_position += offset.x * m_right;
        m_position += offset.z * m_forward;

        return (*this);
    }

    Camera& Camera::rotate(const EulerAnglesF &rotation)
    {
        m_rotation += rotation;

        update();

        return (*this);
    }

    Matrix4F Camera::toMatrix() const
    {
        Matrix4F lookAt;

        lookAt.setColumn(Vector4F(m_right, -m_right.dotProduct(m_position)),     0);
        lookAt.setColumn(Vector4F(m_up, -m_up.dotProduct(m_position)),           1);
        lookAt.setColumn(Vector4F(-m_forward, m_forward.dotProduct(m_position)), 2);
        lookAt.setColumn(Vector4F(0.f, 0.f, 0.f, 1.f),                           3);

        return lookAt;
    }

    void Camera::update()
    {
        m_target.x = std::cos(m_rotation.yaw) * std::cos(m_rotation.pitch);
        m_target.y = std::sin(m_rotation.pitch);
        m_target.z = std::sin(m_rotation.yaw) * std::cos(m_rotation.pitch);
        m_target.normalize();

        m_forward = Vector3F::normalize(m_target - m_position);
        m_right   = Vector3F::crossProduct(m_forward, m_up).normalize();
        m_up      = Vector3F::crossProduct(m_right, m_forward).normalize();
    }
}