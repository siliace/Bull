#ifndef CUBE_HPP
#define CUBE_HPP

#include <Bull/Graphics/Model/Node.hpp>

#include <Bull/Render/Mesh.hpp>

class Cube : public Bull::Node
{
public:

    Cube();

    void render();

private:

    Bull::Mesh m_mesh;
};

#endif