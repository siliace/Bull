#include <Bull/Core/Image/ImageLoader.hpp>
#include <Bull/Core/Log/ConsoleLogger.hpp>
#include <Bull/Core/Log/Log.hpp>

#include <Bull/Graphics/Light/DirectionalLight.hpp>
#include <Bull/Graphics/Light/PointLight.hpp>
#include <Bull/Graphics/Light/SpotLight.hpp>

#include <Bull/Math/Clamp.hpp>

#include <Bull/Render/Context/GlFunctions.hpp>
#include <Bull/Render/Target/RenderWindow.hpp>
#include <Bull/Render/Texture/Texture.hpp>

#include <Cube.hpp>

using namespace Bull;

int main(int argc, char* argv[])
{
    Log::getInstance()->createLogger<ConsoleLogger>();

    Shader phong;
    WindowEvent event;
    SpotLight spotLight;
    AngleF fov = AngleF::degree(45.f);
    Texture diffuse, specular, emission;
    RenderWindow window(VideoMode(800, 600), "Bull Application");
    Vector3F position(0, 0, 3), forward = Vector3F::Backward, up = Vector3F::Up;

    ImageLoader::getInstance()->loadFromPath(diffuse, Path("../resources/textures/container.png"));
    ImageLoader::getInstance()->loadFromPath(specular, Path("../resources/textures/container_specular.png"));
    ImageLoader::getInstance()->loadFromPath(emission, Path("../resources/textures/container_emission.png"));

    if(!ImageLoader::getInstance()->wait())
    {
        return -1;
    }

    diffuse.enableSmooth();
    specular.enableSmooth();
    emission.enableSmooth();

    phong.create(Path("../resources/shaders/phong/phong.vert"), Path("../resources/shaders/phong/phong.frag"));

    std::vector<Cube> cubes(10);

    //window.setMouseCursorVisible(false);
    window.setPosition(100, 200);

    while(window.isOpen())
    {
        while(window.pollEvent(event))
        {
            if(event.type == WindowEventType_Closed)
            {
                window.close();
            }

            if(event.type == WindowEventType_KeyDown)
            {
                if(event.key.code == KeyboardKey_S)
                {
                    position -= forward;
                }

                if(event.key.code == KeyboardKey_Z)
                {
                    position += forward;
                }

                if(event.key.code == KeyboardKey_D)
                {
                    position += Vector3F::crossProduct(forward, up).normalize();
                }

                if(event.key.code == KeyboardKey_Q)
                {
                    position -= Vector3F::crossProduct(forward, up).normalize();
                }
            }

            if(event.type == WindowEventType_MouseMoved)
            {
                static AngleF pitch, yaw;

                Vector2F offset;
                offset.x() = event.mouseMove.xRel;
                offset.y() = -event.mouseMove.yRel;

                offset *= 0.1f;

                yaw   += AngleF::degree(offset.x());
                pitch += AngleF::degree(offset.y());

                pitch = clamp(pitch, AngleF::degree(-89.f), AngleF::degree(89.f));

                forward.x() = std::cos(yaw) * std::cos(pitch);
                forward.y() = std::sin(pitch);
                forward.z() = std::sin(yaw) * std::cos(pitch);
                forward.normalize();

                //Mouse::center(window);
            }

            if(event.type == WindowEventType_MouseWheel)
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

        spotLight.position = position;
        spotLight.direction = forward;
        spotLight.setUniforms(phong, "light");
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