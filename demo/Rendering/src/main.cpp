#include <Bull/Render/HardwareBuffer.hpp>
#include <Bull/Render/Target/RenderWindow.hpp>
#include <Bull/Render/Shader/Shader.hpp>
#include <Bull/Render/Texture/Texture.hpp>

#include <Bull/Math/EulerAngles.hpp>
#include <Bull/Math/TransformationPipeline/Camera.hpp>
#include <Bull/Math/TransformationPipeline/PerspectiveProjection.hpp>
#include <Bull/Math/TransformationPipeline/Transformation3D.hpp>

using namespace Bull;

float vertices[] = {
    -0.5f, -0.5f,  0.5f,  0.f, 0.f, 1.f, 1.f,  0.f, 0.f,
     0.5f, -0.5f,  0.5f,  1.f, 0.f, 1.f, 1.f,  1.f, 0.f,
     0.5f,  0.5f,  0.5f,  1.f, 0.f, 1.f, 1.f,  1.f, 1.f,
    -0.5f,  0.5f,  0.5f,  0.f, 1.f, 1.f, 1.f,  0.f, 1.f,

    -0.5f, -0.5f, -0.5f,  0.f, 0.f, 0.f, 1.f,  0.f, 0.f,
     0.5f, -0.5f, -0.5f,  1.f, 0.f, 0.f, 1.f,  1.f, 0.f,
     0.5f,  0.5f, -0.5f,  1.f, 1.f, 0.f, 1.f,  1.f, 1.f,
    -0.5f,  0.5f, -0.5f,  0.f, 1.f, 0.f, 1.f,  0.f, 1.f,
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

int main(int argc, char* argv[])
{
    Texture t;
    Shader core;
    unsigned int vao;
    AngleF pitch, yaw;
    EulerAnglesF rotation;
    RenderWindow::Event e;
    HardwareBuffer vbo(HardwareBuffer::Array);
    HardwareBuffer ebo(HardwareBuffer::Element);
    RenderWindow win(VideoMode(800, 600), "Bull Application");
    CameraF camera(Vector3F(0, 0, 3), Vector3F::Zero, Vector3F::Up);
    PerspectiveProjectionF perspective(AngleF::degree(60.f), win.getSize().getRatio(), Vector2F(0.1f, 100.f));

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
                perspective.setRatio(win.getSize().getRatio());
            }

            if(e.type == RenderWindow::Event::MouseMoved && Mouse::isButtonPressed(Mouse::Left))
            {
                rotation.pitch += e.mouseMove.xRel;
                rotation.roll  += e.mouseMove.yRel;
            }

            if(e.type == RenderWindow::Event::KeyDown)
            {
                Vector3F offsets;

                if(e.key.code == Keyboard::Z)
                {
                    offsets.z = 0.05f;
                }
                else if(e.key.code == Keyboard::S)
                {
                    offsets.z = -0.05f;
                }

                if(e.key.code == Keyboard::Q)
                {
                    offsets.x = -0.05f;
                }
                else if(e.key.code == Keyboard::D)
                {
                    offsets.x = 0.05f;
                }

                camera.move(offsets);
            }
        }

        win.clear();

        t.bind();
        core.bind();

        gl::bindVertexArray(vao);

        core.setUniformMatrix("modelMatrix", Transformation3DF::makeRotation(rotation).getMatrix());
        core.setUniformMatrix("viewMatrix", camera.getMatrix());
        core.setUniformMatrix("projMatrix", perspective.getMatrix());

        gl::drawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, nullptr);

        gl::bindVertexArray(0);

        win.display();
    }

    return 0;
}