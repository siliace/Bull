#include <iostream>

#include <Bull/Render/OpenGL.hpp>
#include <Bull/Render/HardwareBuffer.hpp>
#include <Bull/Render/Target/RenderWindow.hpp>
#include <Bull/Render/Shader/Shader.hpp>
#include <Bull/Render/Texture/Texture.hpp>

#include <Bull/Utility/Camera.hpp>
#include <Bull/Utility/Transformation.hpp>

using namespace Bull;

float vertices[] = {
    -0.5f, -0.5f,  0.5f,  1.f, 1.f, 1.f, 1.f,  0.f, 0.f,
     0.5f, -0.5f,  0.5f,  1.f, 1.f, 1.f, 1.f,  1.f, 0.f,
     0.5f,  0.5f,  0.5f,  1.f, 1.f, 1.f, 1.f,  1.f, 1.f,
    -0.5f,  0.5f,  0.5f,  1.f, 1.f, 1.f, 1.f,  0.f, 1.f,

    -0.5f, -0.5f, -0.5f,  1.f, 1.f, 1.f, 1.f,  0.f, 0.f,
     0.5f, -0.5f, -0.5f,  1.f, 1.f, 1.f, 1.f,  1.f, 0.f,
     0.5f,  0.5f, -0.5f,  1.f, 1.f, 1.f, 1.f,  1.f, 1.f,
    -0.5f,  0.5f, -0.5f,  1.f, 1.f, 1.f, 1.f,  0.f, 1.f,
};

unsigned int indices[] = {
    // front
    0, 1, 2,
    2, 3, 0,

    // top
    1, 5, 6,
    6, 2, 1,

    // back
    7, 6, 5,
    5, 4, 7,

    // bottom
    4, 0, 3,
    3, 7, 4,

    // left
    4, 5, 1,
    1, 0, 4,

    // right
    3, 2, 6,
    6, 7, 3,
};

std::vector<Vector3F> positions = {
    Vector3F( 0.0f,  0.0f,  0.0f),
    Vector3F( 2.0f,  5.0f, -15.0f),
    Vector3F(-1.5f, -2.2f, -2.5f),
    Vector3F(-3.8f, -2.0f, -12.3f),
    Vector3F( 2.4f, -0.4f, -3.5f),
    Vector3F(-1.7f,  3.0f, -7.5f),
    Vector3F( 1.3f, -2.0f, -2.5f),
    Vector3F( 1.5f,  2.0f, -2.5f),
    Vector3F( 1.5f,  0.2f, -1.5f),
    Vector3F(-1.3f,  1.0f, -1.5f)
};

std::vector<EulerAnglesF> rotations = {
    EulerAnglesF(AngleF::Zero, AngleF::Zero, AngleF::degree(45.f)),
    EulerAnglesF(AngleF::degree(17.f), AngleF::degree(198.f), AngleF::Zero),
    EulerAnglesF(AngleF::Zero, AngleF::degree(55.f), AngleF::radian(3.f)),
    EulerAnglesF(AngleF::Zero, AngleF::Zero, AngleF::degree(45.f)),
    EulerAnglesF(AngleF::degree(17.f), AngleF::degree(198.f), AngleF::Zero),
    EulerAnglesF(AngleF::Zero, AngleF::degree(55.f), AngleF::radian(3.f)),
    EulerAnglesF(AngleF::Zero, AngleF::Zero, AngleF::degree(45.f)),
    EulerAnglesF(AngleF::degree(17.f), AngleF::degree(198.f), AngleF::Zero),
    EulerAnglesF(AngleF::Zero, AngleF::degree(55.f), AngleF::radian(3.f)),
};

int main(int argc, char* argv[])
{
    Texture t;
    Shader core;
    unsigned int vao;
    RenderWindow::Event e;
    HardwareBuffer vbo(HardwareBuffer::Array);
    HardwareBuffer ebo(HardwareBuffer::Element);
    RenderWindow win(VideoMode(800, 600), "Bull Application");

    Vector3F position(0.0f, 0.0f, 3.0f);
    Vector3F front(0.0f, 0.0f, -1.0f);
    Vector3F up = Vector3F::makeUp();
    float speed = 0.5f;

    core.attachFromPath(Path("resources/shaders/core/core.vert"), ShaderStage::Vertex);
    core.attachFromPath(Path("resources/shaders/core/core.frag"), ShaderStage::Fragment);
    core.link();

    t.loadFromPath(Path("resources/textures/wall.jpg"));
    t.enableSmooth();

    gl::genVertexArrays(1, &vao);

    gl::bindVertexArray(vao);
        vbo.create(sizeof(vertices));
        vbo.fill(vertices, sizeof(vertices));
        ebo.create(sizeof(indices));
        ebo.fill(indices, sizeof(indices));
        gl::enableVertexAttribArray(0);
        gl::vertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), nullptr);
        gl::enableVertexAttribArray(1);
        gl::vertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)(sizeof(float) * 3));
        gl::enableVertexAttribArray(2);
        gl::vertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)(sizeof(float) * 7));
    gl::bindVertexArray(0);

    while(win.isOpen())
    {
        while(win.pollEvent(e))
        {
            if(e.type == RenderWindow::Event::Closed)
            {
                win.close();
            }

            if(e.type == RenderWindow::Event::Resized)
            {
                win.resetViewport();
            }

            if(e.type == RenderWindow::Event::KeyDown)
            {
                if(e.key.code == Keyboard::Z)
                {
                    position += front * speed;
                }
                else if(e.key.code == Keyboard::S)
                {
                    position -= front * speed;
                }

                if(e.key.code == Keyboard::D)
                {
                    position -= Vector3F::crossProduct(front, up).normalize() * speed;
                }
                else if(e.key.code == Keyboard::Q)
                {
                    position += Vector3F::crossProduct(front, up).normalize() * speed;
                }
            }
        }

        if(win.isOpen())
        {
            Matrix4F proj = Matrix4F::makePerspective(AngleF::degree(90.f), win.getSize().getRatio(), 0.1f, 100.f);

            win.clear();

            t.bind();
            core.bind();

            gl::bindVertexArray(vao);

            core.setUniformMatrix("viewMatrix", Matrix4F::makeLookAt(position,
                                                                     position + front,
                                                                     up));
            core.setUniformMatrix("projMatrix", proj);

            for(unsigned int i = 0; i < 10; i++)
            {
                Matrix4F model = Transformation::make(positions[i], rotations[i]).toMatrix();
                core.setUniformMatrix("modelMatrix", model);

                gl::drawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, nullptr);
            }

            gl::bindVertexArray(0);

            win.display();
        }
    }

    return 0;
}