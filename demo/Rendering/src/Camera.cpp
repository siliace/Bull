#include <Camera.hpp>

Camera::Camera(const Bull::RenderTarget& target) :
    m_target(target)
{
    updateView();
    updatePerspective();
}

Bull::Matrix4F Camera::getViewProjectionMatrix() const
{
    return m_projection * m_view;
}

Bull::Matrix4F Camera::getModelViewProjectionMatrix(const Bull::Transformable& transformable) const
{
    return getViewProjectionMatrix() * transformable.getModelMatrix();
}

void Camera::resize(const Bull::SizeUI& size)
{
    m_projection = Bull::Matrix4F::makePerspective(m_fov, size.getRatio<float>(), Bull::Vector2F(0.1f, 100.f));
}

void Camera::setFieldOfView(const Bull::AngleF& angle)
{
    m_fov = angle;

    updatePerspective();
}

const Bull::Vector3F& Camera::getForward() const
{
    return m_forward;
}

void Camera::setForward(const Bull::Vector3F& forward)
{
    m_forward = Bull::Vector3F::normalize(forward);

    updateView();
}

const Bull::Vector3F& Camera::getPosition() const
{
    return m_position;
}

void Camera::setPosition(const Bull::Vector3F& position)
{
    updateView();

    m_position = position;
}

void Camera::updateView()
{
    m_view = Bull::Matrix4F::makeLookAt(m_position, m_position + m_forward, Bull::Vector3F::Up);
}

void Camera::updatePerspective()
{
    m_projection = Bull::Matrix4F::makePerspective(m_fov, m_target.getDefaultViewport().size.getRatio<float>(), Bull::Vector2F(0.1f, 100.f));
}
