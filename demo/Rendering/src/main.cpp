#include <Bull/Math/Clamp.hpp>

#include <Bull/Render/Context/GlFunctions.hpp>
#include <Bull/Render/Shader/Shader.hpp>
#include <Bull/Render/Target/RenderWindow.hpp>
#include <Bull/Render/Texture/Texture.hpp>

#include <Cube.hpp>

using namespace Bull;

int main(int argc, char* argv[])
{
    Shader phong;
    WindowEvent event;
    AngleF fov = AngleF::degree(45.f);
    Texture diffuse, specular, emission;
    RenderWindow window(VideoMode(800, 600), "Bull Application");
    Vector3F position(0, 0, 3), forward = Vector3F::Backward, up = Vector3F::Up;

    diffuse.loadFromPath(Path("../resources/textures/container.png"));
    diffuse.enableSmooth();

    specular.loadFromPath(Path("../resources/textures/container_specular.png"));
    specular.enableSmooth();

    emission.loadFromPath(Path("../resources/textures/container_emission.png"));
    emission.enableSmooth();

    phong.attachFromPath(Path("../resources/shaders/phong/phong.vert"), ShaderStageType_Vertex);
    phong.attachFromPath(Path("../resources/shaders/phong/phong.frag"), ShaderStageType_Fragment);
    phong.link();

    std::vector<Cube> cubes(10);

    while(window.isOpen())
    {
        while(window.pollEvent(event))
        {
            if(event.type == WindowEvent::Closed)
            {
                window.close();
            }

            if(event.type == WindowEvent::KeyDown)
            {
                if(event.key.code == Keyboard::S)
                {
                    position -= forward;
                }

                if(event.key.code == Keyboard::Z)
                {
                    position += forward;
                }

                if(event.key.code == Keyboard::D)
                {
                    position += Vector3F::crossProduct(forward, up).normalize();
                }

                if(event.key.code == Keyboard::Q)
                {
                    position -= Vector3F::crossProduct(forward, up).normalize();
                }
            }

            if(event.type == WindowEvent::MouseMoved)
            {
                static int lastX, lastY;
                static AngleF pitch, yaw;
                static bool firstMouse = true;

                if(firstMouse)
                {
                    lastX = event.mouseMove.x;
                    lastY = event.mouseMove.y;
                    firstMouse = false;
                }

                Vector2F offset;
                offset.x() = event.mouseMove.x - lastX;
                offset.y() = lastY - event.mouseMove.y;
                lastX = event.mouseMove.x;
                lastY = event.mouseMove.y;

                offset *= 0.1f;

                yaw   += AngleF::degree(offset.x());
                pitch += AngleF::degree(offset.y());

                pitch = clamp(pitch, AngleF::degree(-89.f), AngleF::degree(89.f));

                forward.x() = std::cos(yaw) * std::cos(pitch);
                forward.y() = std::sin(pitch);
                forward.z() = std::sin(yaw) * std::cos(pitch);
                forward.normalize();
            }

            if(event.type == WindowEvent::MouseWheel)
            {
                fov += (event.mouseWheel.up) ? AngleF::degree(-0.1f) : AngleF::degree(0.1f);
                fov = clamp(fov, AngleF::degree(0.1f), AngleF::degree(45.f));
            }
        }

        window.clear();

        phong.bind();

        Matrix4F camera = Matrix4F::makeLookAt(position, position + forward, up);
        Matrix4F projection = Matrix4F::makePerspective(fov, window.getSize().getRatio(), Vector2F(0.1f, 100.f));

        phong.setUniformMatrix("view", camera);
        phong.setUniformMatrix("projection", projection);

        phong.setUniform("material.shininess", 64.f);

        gl::activeTexture(GL_TEXTURE0);
        diffuse.bind();
        phong.setUniform("material.diffuse", 0);

        gl::activeTexture(GL_TEXTURE1);
        specular.bind();
        phong.setUniform("material.specular", 1);

        gl::activeTexture(GL_TEXTURE2);
        emission.bind();
        phong.setUniform("material.emission", 2);

        phong.setUniformVector("light.position", Vector3F::UnitX * 3.f);
        phong.setUniformVector("light.ambient", Vector4F::Unit / 5.f);
        phong.setUniformVector("light.diffuse", Vector4F::Unit / 2.f);
        phong.setUniformVector("light.specular", Vector4F(1.f, 1.f, 1.f, 0.f));

        phong.setUniformVector("camera_position", Vector3F(2.f, 1.f, 3.f));

        for(Cube& cube : cubes)
        {
            phong.setUniformMatrix("model", cube.getModelMatrix());

            cube.render();
        }

        window.display();
    }

    return 0;
}