#include <Bull/Core/Log/Log.hpp>

#include <Bull/Render/OpenGL.hpp>
#include <Bull/Render/HardwareBuffer.hpp>
#include <Bull/Render/Target/RenderWindow.hpp>

#include <Bull/Utility/ConsoleLogger.hpp>

using namespace Bull;

int main(int argc, char* argv[])
{
    Log::get()->createLogger<ConsoleLogger>();

    unsigned int vao;
    RenderWindow::Event e;
    HardwareBuffer vbo(HardwareBuffer::Array);
    RenderWindow win(VideoMode(800, 600), "Bull Application", RenderWindow::Default, ContextSettings::Best);

    float vertices[] = {
            0.5f, 0.5f, 0.f,
            0.5f, -0.5f, 0.f,
            -0.5f, 0.5f, 0.f,
    };

    gl::genVertexArrays(1, &vao);

    gl::bindVertexArray(vao);
        vbo.create(sizeof(vertices));
        vbo.fill(vertices, sizeof(vertices));
        gl::enableVertexAttribArray(0);
        gl::vertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
    gl::bindVertexArray(0);

    while(win.isOpen())
    {
        while(win.pollEvent(e))
        {
            if(e.type == RenderWindow::Event::Closed)
            {
                win.close();
            }
        }

        win.clear(Color::Red);

        gl::bindVertexArray(vao);
            gl::drawArrays(GL_TRIANGLES, 0, 3);
        gl::bindVertexArray(0);

        win.display();
    }

    return 0;
}