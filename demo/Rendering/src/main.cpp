#include <Bull/Core/Assets/AssetManager.hpp>
#include <Bull/Core/FileSystem/Path.hpp>
#include <Bull/Core/Image/ImageLoader.hpp>
#include <Bull/Core/Utility/StringUtils.hpp>
#include <Bull/Core/Utility/Random.hpp>

#include <Bull/Graphics/Model/Material.hpp>
#include <Bull/Graphics/Light/DirectionalLight.hpp>
#include <Bull/Graphics/Light/PointLight.hpp>
#include <Bull/Graphics/Light/SpotLight.hpp>

#include <Bull/Math/Clamp.hpp>

#include <Bull/Render/Target/RenderWindow.hpp>

#include <Cube.hpp>

Bull::RandomGenerator random;
Bull::AssetManager<Bull::Texture> textureManager;

Bull::Material loadMaterialFromPath(const Bull::Path& path)
{
    Bull::Material material;
    Bull::ImageLoader imageLoader;
    Bull::Texture& diffuse = textureManager.add(Bull::Texture::from(imageLoader.loadFromPath(path.getChild("container.png"))), "diffuse");
    Bull::Texture& specular = textureManager.add(Bull::Texture::from(imageLoader.loadFromPath(path.getChild("container_specular.png"))), "specular");

    diffuse.enableSmooth();
    specular.enableSmooth();

    material.setTexture(&diffuse, Bull::TextureType_Diffuse);
    material.setTexture(&specular, Bull::TextureType_Specular);

    return material;
}

Bull::Shader loadShaderFromPath(const Bull::Path& path)
{
    Bull::Shader shader;
    Bull::ShaderStageLoader shaderStageLoader;

    shader.attach(shaderStageLoader.loadFromPath(path.getChild("phong.vert"), Bull::ShaderStageType_Vertex));
    shader.attach(shaderStageLoader.loadFromPath(path.getChild("phong.frag"), Bull::ShaderStageType_Fragment));
    shader.link();

    return shader;
}

void moveRandom(Cube& cube)
{
    cube.rotate(Bull::EulerAnglesF::onX(Bull::AngleF::degree(random.number(0.f, 360.f))));
    cube.move(Bull::Vector3F(random.number(-2.f, 2.f), random.number(-2.f, 2.f), random.number(-6.f, 6.f)));
    cube.scale(Bull::Vector3F::Unit * random.number(1.f, 4.f));
}

int main()
{
    std::vector<Cube> cubes;
    std::vector<Bull::PointLight> points;

    Bull::Vector3F up = Bull::Vector3F::Up;
    Bull::Vector3F forward = Bull::Vector3F::Backward;
    Bull::Vector3F position = Bull::Vector3F::UnitZ * 3.f;

    Bull::DirectionalLight dl(Bull::Vector3F::Down, Bull::Color::Blue);
    Bull::SpotLight sp(Bull::Vector3F::UnitZ * 10.f, Bull::Vector3F::Backward);

    Bull::RenderWindow window(Bull::VideoMode(800, 600), "Demonstration rendering");

    Bull::Shader shader = loadShaderFromPath(Bull::Path("../resources/shaders/phong"));
    Bull::Material material = loadMaterialFromPath(Bull::Path("../resources/textures"));

    points.emplace_back(Bull::Vector3F::Up * 3.f, Bull::Color::Yellow);
    points.emplace_back(Bull::Vector3F::Down * 3.f, Bull::Color::Magenta);
    points.emplace_back(Bull::Vector3F::Forward * 3.f, Bull::Color::White);

    cubes.emplace_back(material); cubes.emplace_back(material); cubes.emplace_back(material);
    cubes.emplace_back(material); cubes.emplace_back(material); cubes.emplace_back(material);
    cubes.emplace_back(material); cubes.emplace_back(material); cubes.emplace_back(material);
    cubes.emplace_back(material); cubes.emplace_back(material); cubes.emplace_back(material);

    std::for_each(cubes.begin(), cubes.end(), &moveRandom);

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
                    position += Bull::Vector3F::crossProduct(forward, up).normalize();
                }

                if(event.key.code == Bull::KeyboardKey_Q)
                {
                    position -= Bull::Vector3F::crossProduct(forward, up).normalize();
                }
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

                    forward.x() = std::cos(yaw) * std::cos(pitch);
                    forward.y() = std::sin(pitch);
                    forward.z() = std::sin(yaw) * std::cos(pitch);
                    forward.normalize();
                }
            }

            if(event.type == Bull::WindowEventType_Resized)
            {
                shader.setUniformMatrix("projection", Bull::Matrix4F::makePerspective(
                        Bull::AngleF::degree(45.f),
                        window.getSize().getRatio(),
                        Bull::Vector2F(0.1f, 100.f)
                ));
            }
        }

        window.clear();

        shader.bind();

        shader.setUniformMatrix("view", Bull::Matrix4F::makeLookAt(position, position + forward, up));

        shader.setUniformVector("eye_position", position);

        sp.position = position;
        sp.direction = forward;
        sp.setUniforms(shader, "sp");

        dl.setUniforms(shader, "dl");

        for(std::size_t i = 0; i < points.size(); i++)
        {
            points.at(i).setUniforms(shader, "pls[" + Bull::StringUtils::number(i) + "]");
        }

        for(Cube& cube : cubes)
        {
            cube.render(shader);
        }

        window.display();
    }

    return 0;
}