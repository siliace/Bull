#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <Bull/Graphics/Rendering/AbstractViewer.hpp>

class Camera : public Bull::AbstractViewer
{
public:

    explicit Camera(const Bull::RenderTarget& target);

    void resize(const Bull::SizeUI& size) override;

    void setFieldOfView(const Bull::AngleF& angle);

    const Bull::Vector3F& getForward() const;

    void setForward(const Bull::Vector3F& forward);

    const Bull::Vector3F& getPosition() const;

    void setPosition(const Bull::Vector3F& position);

    Bull::Matrix4F getViewProjectionMatrix() const override;

    Bull::Matrix4F getModelViewProjectionMatrix(const Bull::Transformable& transformable) const override;

private:

    void updateView();

    void updatePerspective();

private:

    Bull::Vector3F m_forward;
    Bull::Vector3F m_position;
    Bull::Matrix4F m_view;

    Bull::AngleF   m_fov;
    Bull::Matrix4F m_projection;

    const Bull::RenderTarget& m_target;
};

#endif // CAMERA_HPP
