#include <vector>

#include <Bull/Render/Mesh.hpp>
#include <Bull/Render/Target/RenderWindow.hpp>
#include <Bull/Render/Shader/Shader.hpp>

#include <Bull/Math/EulerAngles.hpp>
#include <Bull/Math/TransformationPipeline/Camera.hpp>
#include <Bull/Math/TransformationPipeline/PerspectiveProjection.hpp>
#include <Bull/Math/TransformationPipeline/Transformation3D.hpp>

using namespace Bull;

int main(int argc, char* argv[])
{
    EulerAnglesF rotation;
    RenderWindow::Event e;
    std::vector<Vertex> va;
    Shader lightShader, cubeShader;
    AngleF yaw   = AngleF::degree(0);
    AngleF pitch = AngleF::degree(0);
    CameraF camera(Vector3F(0, 0, 6), Vector3F::Zero);
    RenderWindow win(VideoMode(800, 600), "Bull Application");
    PerspectiveProjectionF perspective(AngleF::degree(60.f), win.getSize().getRatio(), Vector2F(0.1f, 100.f));

    Mesh cube, light;

    va.push_back(Vertex(Vector3F(-0.5f, -0.5f, -0.5f), Vector3F( 0.0f,  0.0f, -1.0f)));
    va.push_back(Vertex(Vector3F( 0.5f, -0.5f, -0.5f), Vector3F( 0.0f,  0.0f, -1.0f)));
    va.push_back(Vertex(Vector3F( 0.5f,  0.5f, -0.5f), Vector3F( 0.0f,  0.0f, -1.0f)));
    va.push_back(Vertex(Vector3F( 0.5f,  0.5f, -0.5f), Vector3F( 0.0f,  0.0f, -1.0f)));
    va.push_back(Vertex(Vector3F(-0.5f,  0.5f, -0.5f), Vector3F( 0.0f,  0.0f, -1.0f)));
    va.push_back(Vertex(Vector3F(-0.5f, -0.5f, -0.5f), Vector3F( 0.0f,  0.0f, -1.0f)));
    va.push_back(Vertex(Vector3F(-0.5f, -0.5f,  0.5f), Vector3F( 0.0f,  0.0f,  1.0f)));
    va.push_back(Vertex(Vector3F( 0.5f, -0.5f,  0.5f), Vector3F( 0.0f,  0.0f,  1.0f)));
    va.push_back(Vertex(Vector3F( 0.5f,  0.5f,  0.5f), Vector3F( 0.0f,  0.0f,  1.0f)));
    va.push_back(Vertex(Vector3F( 0.5f,  0.5f,  0.5f), Vector3F( 0.0f,  0.0f,  1.0f)));
    va.push_back(Vertex(Vector3F(-0.5f,  0.5f,  0.5f), Vector3F( 0.0f,  0.0f,  1.0f)));
    va.push_back(Vertex(Vector3F(-0.5f, -0.5f,  0.5f), Vector3F( 0.0f,  0.0f,  1.0f)));
    va.push_back(Vertex(Vector3F(-0.5f,  0.5f,  0.5f), Vector3F(-1.0f,  0.0f,  0.0f)));
    va.push_back(Vertex(Vector3F(-0.5f,  0.5f, -0.5f), Vector3F(-1.0f,  0.0f,  0.0f)));
    va.push_back(Vertex(Vector3F(-0.5f, -0.5f, -0.5f), Vector3F(-1.0f,  0.0f,  0.0f)));
    va.push_back(Vertex(Vector3F(-0.5f, -0.5f, -0.5f), Vector3F(-1.0f,  0.0f,  0.0f)));
    va.push_back(Vertex(Vector3F(-0.5f, -0.5f,  0.5f), Vector3F(-1.0f,  0.0f,  0.0f)));
    va.push_back(Vertex(Vector3F(-0.5f,  0.5f,  0.5f), Vector3F(-1.0f,  0.0f,  0.0f)));
    va.push_back(Vertex(Vector3F( 0.5f,  0.5f,  0.5f), Vector3F( 1.0f,  0.0f,  0.0f)));
    va.push_back(Vertex(Vector3F( 0.5f,  0.5f, -0.5f), Vector3F( 1.0f,  0.0f,  0.0f)));
    va.push_back(Vertex(Vector3F( 0.5f, -0.5f, -0.5f), Vector3F( 1.0f,  0.0f,  0.0f)));
    va.push_back(Vertex(Vector3F( 0.5f, -0.5f, -0.5f), Vector3F( 1.0f,  0.0f,  0.0f)));
    va.push_back(Vertex(Vector3F( 0.5f, -0.5f,  0.5f), Vector3F( 1.0f,  0.0f,  0.0f)));
    va.push_back(Vertex(Vector3F( 0.5f,  0.5f,  0.5f), Vector3F( 1.0f,  0.0f,  0.0f)));
    va.push_back(Vertex(Vector3F(-0.5f, -0.5f, -0.5f), Vector3F( 0.0f, -1.0f,  0.0f)));
    va.push_back(Vertex(Vector3F( 0.5f, -0.5f, -0.5f), Vector3F( 0.0f, -1.0f,  0.0f)));
    va.push_back(Vertex(Vector3F( 0.5f, -0.5f,  0.5f), Vector3F( 0.0f, -1.0f,  0.0f)));
    va.push_back(Vertex(Vector3F( 0.5f, -0.5f,  0.5f), Vector3F( 0.0f, -1.0f,  0.0f)));
    va.push_back(Vertex(Vector3F(-0.5f, -0.5f,  0.5f), Vector3F( 0.0f, -1.0f,  0.0f)));
    va.push_back(Vertex(Vector3F(-0.5f, -0.5f, -0.5f), Vector3F( 0.0f, -1.0f,  0.0f)));
    va.push_back(Vertex(Vector3F(-0.5f,  0.5f, -0.5f), Vector3F( 0.0f,  1.0f,  0.0f)));
    va.push_back(Vertex(Vector3F( 0.5f,  0.5f, -0.5f), Vector3F( 0.0f,  1.0f,  0.0f)));
    va.push_back(Vertex(Vector3F( 0.5f,  0.5f,  0.5f), Vector3F( 0.0f,  1.0f,  0.0f)));
    va.push_back(Vertex(Vector3F( 0.5f,  0.5f,  0.5f), Vector3F( 0.0f,  1.0f,  0.0f)));
    va.push_back(Vertex(Vector3F(-0.5f,  0.5f,  0.5f), Vector3F( 0.0f,  1.0f,  0.0f)));
    va.push_back(Vertex(Vector3F(-0.5f,  0.5f, -0.5f), Vector3F( 0.0f,  1.0f,  0.0f)));

    light.create(va);

    for(unsigned int i = 0; i < va.size(); i++)
    {
        va[i].color = Vector4F(1.0f, 0.5f, 0.31f, 1.0f);
    }

    cube.create(va);

    lightShader.attachFromPath(Path("../resources/shaders/light/light.vert"), ShaderStage::Vertex);
    lightShader.attachFromPath(Path("../resources/shaders/light/light.frag"), ShaderStage::Fragment);
    lightShader.link();

    cubeShader.attachFromPath(Path("../resources/shaders/object/object.vert"), ShaderStage::Vertex);
    cubeShader.attachFromPath(Path("../resources/shaders/object/object.frag"), ShaderStage::Fragment);
    cubeShader.link();

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

            if(e.type == RenderWindow::Event::MouseMoved)
            {
                if(Mouse::isButtonPressed(Mouse::Left))
                {
                    rotation.pitch += e.mouseMove.xRel;
                    rotation.roll  += e.mouseMove.yRel;
                }
                else if(Mouse::isButtonPressed(Mouse::Right))
                {
                    yaw   += e.mouseMove.xRel;
                    pitch += e.mouseMove.yRel;

                    pitch = AngleF::clamp(pitch, AngleF::degree(-89.0f), AngleF::degree(89.0f));

                    Vector3F target = camera.getTarget();

                    target.x = std::cos(yaw) * std::cos(pitch);
                    target.y = std::sin(pitch);
                    target.z = std::sin(yaw) * std::cos(pitch);

                    camera.setTarget(target);
                }
            }

            if(e.type == RenderWindow::Event::KeyDown)
            {
                Vector3F target   = camera.getTarget();
                Vector3F position = camera.getPosition();

                if(e.key.code == Keyboard::Z)
                {
                    position.z -= 0.05f;
                }
                else if(e.key.code == Keyboard::S)
                {
                    position.z += 0.05f;
                }

                if(e.key.code == Keyboard::Q)
                {
                    position.x -= 0.05f;
                }
                else if(e.key.code == Keyboard::D)
                {
                    position.x += 0.05f;
                }

                camera.setPosition(position).setTarget(target);
            }
        }

        win.clear();

        cubeShader.bind();
        cubeShader.setUniformColor("light", Color::White);
        cubeShader.setUniformVector("viewPosition", camera.getPosition());
        cubeShader.setUniformVector("lightPosition", Vector3F::Zero);
        cubeShader.setUniformMatrix("view", camera.getMatrix());
        cubeShader.setUniformMatrix("proj", perspective.getMatrix());
        cubeShader.setUniformMatrix("model", Transformation3DF::make(Vector3F::UnitX * 3.f, rotation).getMatrix());
        cube.render(Mesh::Triangles);

        lightShader.bind();
        lightShader.setUniformMatrix("view", camera.getMatrix());
        lightShader.setUniformMatrix("model", Matrix4F::Identity);
        lightShader.setUniformMatrix("proj", perspective.getMatrix());
        light.render(Mesh::Triangles);

        win.display();
    }

    return 0;
}