#ifndef CUBE_HPP
#define CUBE_HPP

#include <Bull/Graphics/Model/Material.hpp>
#include <Bull/Graphics/Model/Mesh.hpp>
#include <Bull/Graphics/Model/Transformable.hpp>

#include <Bull/Render/Shader/Shader.hpp>

class Cube : public Bull::Transformable
{
public:

    explicit Cube(const Bull::Material& material);

    Cube(Cube&& cube) noexcept = default;

    void render(Bull::Shader& shader);

private:

    Bull::Mesh            m_mesh;
    const Bull::Material& m_material;
};

#endif