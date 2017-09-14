#include <Bull/Core/Log/Log.hpp>

#include <Bull/Math/Clamp.hpp>
#include <Bull/Math/TransformationPipeline/Camera.hpp>
#include <Bull/Math/TransformationPipeline/PerspectiveProjection.hpp>
#include <Bull/Math/TransformationPipeline/Transformation3D.hpp>

#include <Bull/Render/Mesh.hpp>
#include <Bull/Render/Shader/Shader.hpp>
#include <Bull/Render/Shader/ShaderStageManager.hpp>
#include <Bull/Render/Target/RenderWindow.hpp>
#include <Bull/Render/Texture/Texture.hpp>

#include <Bull/Utility/Image/ImageManager.hpp>
#include <Bull/Utility/Logger/ConsoleLogger.hpp>
#include <Bull/Utility/Logger/FileLogger.hpp>

using namespace Bull;

std::vector<Vertex> vertices = {
        Vertex(Vector3F(-0.5f, -0.5f,  0.5f), Vector2F(0.f, 0.f)),
        Vertex(Vector3F( 0.5f, -0.5f,  0.5f), Vector2F(1.f, 0.f)),
        Vertex(Vector3F( 0.5f,  0.5f,  0.5f), Vector2F(1.f, 1.f)),
        Vertex(Vector3F(-0.5f,  0.5f,  0.5f), Vector2F(0.f, 1.f)),
        Vertex(Vector3F(-0.5f, -0.5f, -0.5f), Vector2F(0.f, 0.f)),
        Vertex(Vector3F( 0.5f, -0.5f, -0.5f), Vector2F(1.f, 0.f)),
        Vertex(Vector3F( 0.5f,  0.5f, -0.5f), Vector2F(1.f, 1.f)),
        Vertex(Vector3F(-0.5f,  0.5f, -0.5f), Vector2F(0.f, 1.f)),
};

std::vector<unsigned int> indices = {
        0, 1, 2,
        2, 3, 0,
        1, 5, 6,
        6, 2, 1,
        7, 6, 5,
        5, 4, 7,
        4, 0, 3,
        3, 7, 4,
        4, 5, 1,
        1, 0, 4,
        3, 2, 6,
        6, 7, 3,
};

int main()
{
    Log::get()->createLogger<FileLogger>();
    Log::get()->createLogger<ConsoleLogger>();

    WindowEvent event;
    RenderWindow window(VideoMode(800, 600), "OpenGL");

    Mesh mesh;
    Shader core;
    Texture wall;
    EulerAnglesF rotation;
    CameraF camera(Vector3F(0.f, 0.f, 5.f));
    ImageManager::Instance imageManager = ImageManager::get();
    ShaderStageManager::Instance shaderManager = ShaderStageManager::get();
    PerspectiveProjectionF projection(AngleF::degree(45.f), window.getSize().getRatio(), Vector2F(0.1f, 10.f));

    mesh.create(vertices, indices);

    window.setIcon(imageManager->loadFromPath(Path("../resources/icon/heart.png"), "window_icon"));

    wall.create(imageManager->loadFromPath(Path("../resources/textures/wall.jpg"), "texture_wall"));
    wall.enableSmooth();

    core.attach(shaderManager->loadFromPath(Path("../resources/shaders/core/core.vert"), "core_vert"));
    core.attach(shaderManager->loadFromPath(Path("../resources/shaders/core/core.frag"), "core_frag"));
    core.link();

    while(window.isOpen())
    {
        while(window.pollEvent(event))
        {
            if(event.type == WindowEvent::Closed)
            {
                window.close();
            }

            if(event.type == WindowEvent::Resized)
            {
                projection.setRatio(window.getSize().getRatio());
            }

            if(event.type == WindowEvent::MouseMoved)
            {
                if(Mouse::isButtonPressed(Mouse::Left))
                {
                    rotation.pitch += AngleF::degree(event.mouseMove.xRel);
                    rotation.roll  += AngleF::degree(event.mouseMove.yRel);
                }
                else
                {

                }
            }

            if(event.type == WindowEvent::KeyDown)
            {
                Vector3F offset;

                switch(event.key.code)
                {
                    case Keyboard::Z: offset.z =  0.05f; break;
                    case Keyboard::S: offset.z = -0.05f; break;
                    case Keyboard::D: offset.x =  0.05f; break;
                    case Keyboard::Q: offset.x = -0.05f; break;
                }

                camera.move(offset).setTarget(camera.getTarget() + offset);
            }

            if(event.type == WindowEvent::MouseWheel)
            {
                AngleF fov = projection.getAngle();

                if(event.mouseWheel.up)
                {
                    fov = clamp(fov - AngleF::degree(1.f), AngleF::degree(1.f), AngleF::degree(45.f));
                }
                else
                {
                    fov = clamp(fov + AngleF::degree(1.f), AngleF::degree(1.f), AngleF::degree(45.f));
                }

                projection.setAngle(fov);
            }
        }

        core.bind();
        wall.bind();

        core.setUniformMatrix("view", camera.getMatrix());
        core.setUniformMatrix("projection", projection.getMatrix());
        core.setUniformMatrix("model", Transformation3DF::makeRotation(rotation).getMatrix());

        window.clear();

        mesh.render(Mesh::Triangles);

        window.display();
    }

    return 0;
}