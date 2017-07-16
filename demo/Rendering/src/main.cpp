#include <vector>

#include <Bull/Render/Mesh.hpp>
#include <Bull/Render/Target/RenderWindow.hpp>
#include <Bull/Render/Texture/Texture.hpp>
#include <Bull/Render/Shader/Shader.hpp>

#include <Bull/Math/EulerAngles.hpp>
#include <Bull/Math/TransformationPipeline/Camera.hpp>
#include <Bull/Math/TransformationPipeline/PerspectiveProjection.hpp>
#include <Bull/Math/TransformationPipeline/Transformation3D.hpp>

#include <Bull/Utility/Vertex.hpp>

using namespace Bull;

std::vector<unsigned int> indices = {
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
    AngleF pitch, yaw;
    EulerAnglesF rotation;
    RenderWindow::Event e;
    std::vector<Vertex> va;
    RenderWindow win(VideoMode(800, 600), "Bull Application");
    CameraF camera(Vector3F(0, 0, 3), Vector3F::Zero, Vector3F::Up);
    PerspectiveProjectionF perspective(AngleF::degree(60.f), win.getSize().getRatio(), Vector2F(0.1f, 100.f));

    Mesh mesh;

    va.push_back(Vertex(Vector3F(-0.5f, -0.5f,  0.5f), Vector4F(0.f, 0.f, 1.f, 1.f), Vector2F(0.f, 0.f)));
    va.push_back(Vertex(Vector3F( 0.5f, -0.5f,  0.5f), Vector4F(1.f, 0.f, 1.f, 1.f), Vector2F(1.f, 0.f)));
    va.push_back(Vertex(Vector3F( 0.5f,  0.5f,  0.5f), Vector4F(1.f, 0.f, 1.f, 1.f), Vector2F(1.f, 1.f)));
    va.push_back(Vertex(Vector3F(-0.5f,  0.5f,  0.5f), Vector4F(0.f, 1.f, 1.f, 1.f), Vector2F(0.f, 1.f)));
    va.push_back(Vertex(Vector3F(-0.5f, -0.5f, -0.5f), Vector4F(0.f, 0.f, 0.f, 1.f), Vector2F(0.f, 0.f)));
    va.push_back(Vertex(Vector3F( 0.5f, -0.5f, -0.5f), Vector4F(1.f, 0.f, 0.f, 1.f), Vector2F(1.f, 0.f)));
    va.push_back(Vertex(Vector3F( 0.5f,  0.5f, -0.5f), Vector4F(1.f, 1.f, 0.f, 1.f), Vector2F(1.f, 1.f)));
    va.push_back(Vertex(Vector3F(-0.5f,  0.5f, -0.5f), Vector4F(0.f, 1.f, 0.f, 1.f), Vector2F(0.f, 1.f)));

    mesh.create(va, indices);

    core.attachFromPath(Path("../resources/shaders/core/core.vert"), ShaderStage::Vertex);
    core.attachFromPath(Path("../resources/shaders/core/core.frag"), ShaderStage::Fragment);
    core.link();

    t.loadFromPath(Path("../resources/textures/wall.jpg"));
    t.enableSmooth();

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
                perspective.setRatio(win.getSize().getRatio());
            }

            if(e.type == RenderWindow::Event::MouseButtonDown && e.mouseButton.button == Mouse::Left)
            {
                Cursor cursor;
                cursor.loadFromSystem(Cursor::Hand);
                win.setMouseCursor(cursor);
            }

            if(e.type == RenderWindow::Event::MouseButtonUp && e.mouseButton.button == Mouse::Left)
            {
                Cursor cursor;
                cursor.loadFromSystem(Cursor::Default);
                win.setMouseCursor(cursor);
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

        core.setUniformMatrix("model", Transformation3DF::makeRotation(rotation).getMatrix());
        core.setUniformMatrix("view", camera.getMatrix());
        core.setUniformMatrix("proj", perspective.getMatrix());

        mesh.render(Mesh::Triangles);

        win.display();
    }

    return 0;
}