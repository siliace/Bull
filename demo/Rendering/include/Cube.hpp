#ifndef CUBE_HPP
#define CUBE_HPP

#include <Bull/Graphics/Model/Mesh.hpp>
#include <Bull/Graphics/Model/Transformable.hpp>

class Cube : public Bull::Transformable
{
public:

    Cube();

    void render();

private:

    Bull::Mesh m_mesh;
};

#endif