#ifndef CUBE_HPP
#define CUBE_HPP

#include <Bull/Graphics/Model/Material.hpp>
#include <Bull/Graphics/Model/Model.hpp>

class Cube : public Bull::Model
{
public:

    Cube();

    Cube(Cube&& cube) noexcept = default;

    Cube& operator=(Cube&& cube) noexcept = default;

    void render(const Bull::Shader& shader, const Bull::Material& material) const;
};

#endif