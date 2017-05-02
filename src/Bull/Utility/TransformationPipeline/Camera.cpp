#include <Bull/Utility/TransformationPipeline/Camera.hpp>

namespace Bull
{
    Camera::Camera(const Vector3F& position, const Vector3F& front, const Vector3F& up) :
        m_position(position),
        m_front(front),
        m_up(up)

    {
        /// Nothing
    }

    Camera& Camera::move(const Vector3F &offset)
    {
        return moveX(offset.x).moveY(offset.y).moveZ(offset.z);
    }

    Camera& Camera::moveX(float offset)
    {
        m_position += Vector3F::crossProduct(m_front, m_up).normalize() * offset;

        return (*this);
    }

    Camera& Camera::moveY(float offset)
    {
        m_position += m_up * offset;

        return (*this);
    }

    Camera& Camera::moveZ(float offset)
    {
        m_position += m_front * offset;

        return (*this);
    }

    Vector3F Camera::getTarget() const
    {
        return m_position + m_front;
    }

    Matrix4F Camera::toMatrix() const
    {
        Matrix4F lookAt;

        Vector3F f = Vector3F::normalize(getTarget() - m_position);
        Vector3F s = Vector3F::crossProduct(f, m_up).normalize();
        Vector3F u = Vector3F::crossProduct(s, f);

        lookAt.setColumn(Vector4F(s, -s.dotProduct(m_position)), 0);
        lookAt.setColumn(Vector4F(u, -u.dotProduct(m_position)), 1);
        lookAt.setColumn(Vector4F(-f, f.dotProduct(m_position)), 2);
        lookAt.setColumn(Vector4F(0.0, 0.0, 0.0, 1.0),    3);

        return lookAt;
    }
}