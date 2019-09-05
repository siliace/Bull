#include <Bull/Core/Assets/AssetManager.hpp>
#include <Bull/Core/FileSystem/Path.hpp>
#include <Bull/Core/Image/ImageLoader.hpp>
#include <Bull/Core/Log/ConsoleLogger.hpp>
#include <Bull/Core/Log/Log.hpp>
#include <Bull/Core/Utility/Random.hpp>

#include <Bull/Graphics/Model/Material.hpp>
#include <Bull/Graphics/Light/DirectionalLight.hpp>
#include <Bull/Graphics/Light/PointLight.hpp>
#include <Bull/Graphics/Light/SpotLight.hpp>

#include <Bull/Math/Clamp.hpp>

#include <Bull/Render/Shader/ShaderStageLoader.hpp>
#include <Bull/Render/Target/RenderWindow.hpp>
#include <Bull/Render/Texture/ImageTexture.hpp>

#include <Camera.hpp>
#include <Cube.hpp>

Bull::RandomGenerator randomGenerator;

Bull::Material loadMaterialFromPath(const Bull::Path& path)
{
    Bull::Material material;
    Bull::ImageLoader<Bull::ImageTexture> imageLoader;
    std::shared_ptr<Bull::ImageTexture> diffuse =  imageLoader.loadFromPath(path.resolve("container.png"));
    std::shared_ptr<Bull::ImageTexture> specular = imageLoader.loadFromPath(path.resolve("container_specular.png"));
    std::shared_ptr<Bull::ImageTexture> emission = imageLoader.loadFromPath(path.resolve("container_emission.png"));

    material.setShininess(32.f);
    material.setTexture(diffuse, Bull::TextureType_Diffuse);
    material.setTexture(specular, Bull::TextureType_Specular);
    material.setTexture(emission, Bull::TextureType_Emission);

    return material;
}

Bull::Shader loadShaderFromPath(const Bull::Path& path)
{
    Bull::Shader shader;
    Bull::ShaderStageLoader shaderStageLoader;
    std::shared_ptr<Bull::ShaderStage> vertex, fragment;

    vertex = shaderStageLoader.loadFromPath(path.resolve("phong.vert"), Bull::ShaderStageType::Vertex);
    fragment = shaderStageLoader.loadFromPath(path.resolve("phong.frag"), Bull::ShaderStageType::Fragment);

    shader.attach(*vertex);
    shader.attach(*fragment);
    shader.link();

    return shader;
}

void moveRandom(Cube& cube)
{
    cube.rotate(Bull::EulerAnglesF::onX(Bull::AngleF::degree(randomGenerator.number(0.f, 360.f))));
    cube.move(Bull::Vector3F(randomGenerator.number(-5.f, 5.f), randomGenerator.number(-5.f, 5.f), randomGenerator.number(-5.f, 5.f)));
}

int main()
{
    Bull::Log::getInstance().createLogger<Bull::ConsoleLogger>();

    std::vector<Cube> cubes;
    std::vector<Bull::PointLight> points;

    Bull::DirectionalLight dl(Bull::Vector3F::Down);
    Bull::SpotLight sp(Bull::Vector3F::UnitZ * 10.f, Bull::Vector3F::Backward);

    Bull::RenderWindow window(Bull::VideoMode(Bull::Size<unsigned int>(800, 600)), "Demonstration rendering");
    window.enableVsync();
    window.setFramerateLimit(60);

    Camera camera(window);
    camera.setForward(Bull::Vector3F::Backward);
    camera.setPosition(Bull::Vector3F::UnitZ * 3.f);
    camera.setFieldOfView(Bull::AngleF::degree(45.f));

    Bull::Shader shader = loadShaderFromPath(Bull::Path("../resources/shaders/phong"));
    Bull::Material material = loadMaterialFromPath(Bull::Path("../resources/textures"));

    points.emplace_back(Bull::Vector3F::Up * 3.f, Bull::Color::Yellow);
    points.emplace_back(Bull::Vector3F::Down * 3.f, Bull::Color::Magenta);
    points.emplace_back(Bull::Vector3F::Forward * 3.f, Bull::Color::White);

    for(std::size_t i = 0; i < 10; i++)
    {
        Cube cube;
        moveRandom(cube);

        cubes.emplace_back(std::move(cube));
    }

    while(window.isOpen())
    {
        Bull::WindowEvent event;

        while(window.pollEvent(event))
        {
            if(event.type == Bull::WindowEventType_Closed)
            {
                window.close();
            }

            if(event.type == Bull::WindowEventType_KeyDown)
            {
                Bull::Vector3F forward = camera.getForward();
                Bull::Vector3F position = camera.getPosition();

                if(event.key.code == Bull::KeyboardKey_S)
                {
                    position -= forward;
                }

                if(event.key.code == Bull::KeyboardKey_Z)
                {
                    position += forward;
                }

                if(event.key.code == Bull::KeyboardKey_D)
                {
                    position += Bull::Vector3F::crossProduct(forward, Bull::Vector3F::Up).normalize();
                }

                if(event.key.code == Bull::KeyboardKey_Q)
                {
                    position -= Bull::Vector3F::crossProduct(forward, Bull::Vector3F::Up).normalize();
                }

                camera.setPosition(position);
            }

            if(event.type == Bull::WindowEventType_MouseMoved)
            {
                if(Bull::Mouse::isButtonPressed(Bull::MouseButton_Left))
                {
                    std::for_each(cubes.begin(), cubes.end(), [event](Cube& cube) {
                        cube.rotate(Bull::EulerAnglesF(
                                Bull::AngleF::degree(-event.mouseMove.yRel),
                                Bull::AngleF::degree(event.mouseMove.xRel)
                        ));
                    });
                }
                else
                {
                    static Bull::AngleF pitch, yaw;

                    Bull::Vector2F offset;
                    offset.x() = event.mouseMove.xRel;
                    offset.y() = -event.mouseMove.yRel;

                    offset *= 0.1f;

                    yaw   += Bull::AngleF::degree(offset.x());
                    pitch += Bull::AngleF::degree(offset.y());

                    pitch = Bull::clamp(pitch, Bull::AngleF::degree(-89.f), Bull::AngleF::degree(89.f));

                    float x = std::cos(yaw) * std::cos(pitch);
                    float y = std::sin(pitch);
                    float z = std::sin(yaw) * std::cos(pitch);

                    camera.setForward({x, y, z});
                }
            }

            if(event.type == Bull::WindowEventType_Resized)
            {
                camera.resize(window.getSize());
            }
        }

        window.clear();

        shader.bind();

        shader.setUniformVector("eye_position", camera.getPosition());

        sp.setPosition(camera.getPosition());
        sp.setDirection(camera.getForward());
        sp.setUniforms(shader, "sp");

        dl.setUniforms(shader, "dl");

        for(std::size_t i = 0; i < points.size(); i++)
        {
            points.at(i).setUniforms(shader, "pls[" +std::to_string(i) + "]");
        }

        for(Cube& cube : cubes)
        {
            shader.setUniformMatrix("mvp", camera.getModelViewProjectionMatrix(cube));
            cube.render(shader, material);
        }

        window.display();
    }

    return 0;
}