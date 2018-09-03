#ifndef CUBE_HPP
#define CUBE_HPP

#include <Bull/Graphics/Model/Material.hpp>
#include <Bull/Graphics/Model/Mesh.hpp>
#include <Bull/Graphics/Rendering/Transformable.hpp>
#include <Bull/Graphics/Rendering/Renderable.hpp>

#include <Bull/Render/Shader/Shader.hpp>

class Cube : public Bull::Transformable, public Bull::Renderable
{
public:

    explicit Cube(const Bull::Material& material);

    Cube(Cube&& cube) noexcept = default;

    void render(const Bull::Shader& shader) const override;

private:

    Bull::Mesh            m_mesh;
    const Bull::Material& m_material;
};

#endif