#include <Bull/Core/Log/Log.hpp>

#include <Bull/Render/OpenGL.hpp>
#include <Bull/Render/HardwareBuffer.hpp>
#include <Bull/Render/Target/RenderWindow.hpp>
#include <Bull/Render/Shader/Shader.hpp>
#include <Bull/Render/Texture/Texture.hpp>

#include <Bull/Utility/ConsoleLogger.hpp>
#include <Bull/Utility/Transformation.hpp>

using namespace Bull;

int main(int argc, char* argv[])
{
    Log::get()->createLogger<ConsoleLogger>();

    Texture t;
    Shader core;
    unsigned int vao;
    RenderWindow::Event e;
    HardwareBuffer vbo(HardwareBuffer::Array);
    HardwareBuffer ebo(HardwareBuffer::Element);
    RenderWindow win(VideoMode(800, 600), "Bull Application");

    float vertices[] = {
             0.5f,  0.5f, 0.f,  1.0f, 1.0f, 1.0f, 1.0f,  1.0f, 1.0f,
             0.5f, -0.5f, 0.f,  1.0f, 1.0f, 1.0f, 1.0f,  1.0f, 0.0f,
            -0.5f,  0.5f, 0.f,  1.0f, 1.0f, 1.0f, 1.0f,  0.0f, 1.0f,
            -0.5f, -0.5f, 0.f,  1.0f, 1.0f, 1.0f, 1.0f,  0.0f, 0.0f,
    };

    unsigned int indices[] = {
            0, 1, 2,
            1, 2, 3
    };

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
        }

        win.clear();

        t.bind();
        core.bind();

        core.setUniformMatrix("modelMatrix", Transformation::makeRotation(EulerAnglesF(AngleF::Zero, AngleF::Zero, AngleF::degree(45.f))).toMatrix());
        core.setUniformMatrix("viewMatrix", Matrix4F::makeIdentity());
        core.setUniformMatrix("projMatrix", Matrix4F::makeIdentity());

        gl::bindVertexArray(vao);
            gl::drawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
        gl::bindVertexArray(0);

        win.display();
    }

    return 0;
}