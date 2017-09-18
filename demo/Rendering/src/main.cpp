#include <Bull/Core/Log/Log.hpp>

#include <Bull/Math/TransformationPipeline/Camera.hpp>
#include <Bull/Math/TransformationPipeline/PerspectiveProjection.hpp>
#include <Bull/Math/TransformationPipeline/Transformation3D.hpp>

#include <Bull/Render/Mesh.hpp>
#include <Bull/Render/Shader/Shader.hpp>
#include <Bull/Render/Target/RenderWindow.hpp>
#include <Bull/Render/Texture/Texture.hpp>

#include <Bull/Utility/Logger/ConsoleLogger.hpp>

using namespace Bull;

std::vector<Vertex> vertices = {
        /// front
        Vertex(Vector3F( 0.5f,  0.5f,  0.5f), Vector4F(1.f, 1.f, 1.f, 0.f), Vector2F(1.f, 1.f), Vector3F::Forward), /// 0
        Vertex(Vector3F(-0.5f,  0.5f,  0.5f), Vector4F(1.f, 1.f, 1.f, 0.f), Vector2F(0.f, 1.f), Vector3F::Forward), /// 1
        Vertex(Vector3F( 0.5f, -0.5f,  0.5f), Vector4F(1.f, 1.f, 1.f, 0.f), Vector2F(1.f, 0.f), Vector3F::Forward), /// 2
        Vertex(Vector3F(-0.5f, -0.5f,  0.5f), Vector4F(1.f, 1.f, 1.f, 0.f), Vector2F(0.f, 0.f), Vector3F::Forward), /// 3

        /// back
        Vertex(Vector3F( 0.5f,  0.5f, -0.5f), Vector4F(1.f, 1.f, 1.f, 0.f), Vector2F(1.f, 1.f), Vector3F::Backward), /// 4
        Vertex(Vector3F(-0.5f,  0.5f, -0.5f), Vector4F(1.f, 1.f, 1.f, 0.f), Vector2F(0.f, 1.f), Vector3F::Backward), /// 5
        Vertex(Vector3F( 0.5f, -0.5f, -0.5f), Vector4F(1.f, 1.f, 1.f, 0.f), Vector2F(1.f, 0.f), Vector3F::Backward), /// 6
        Vertex(Vector3F(-0.5f, -0.5f, -0.5f), Vector4F(1.f, 1.f, 1.f, 0.f), Vector2F(0.f, 0.f), Vector3F::Backward), /// 7

        /// right
        Vertex(Vector3F( 0.5f,  0.5f,  0.5f), Vector4F(1.f, 1.f, 1.f, 0.f), Vector2F(0.f, 1.f), Vector3F::Right), /// 8
        Vertex(Vector3F( 0.5f, -0.5f,  0.5f), Vector4F(1.f, 1.f, 1.f, 0.f), Vector2F(0.f, 0.f), Vector3F::Right), /// 9
        Vertex(Vector3F( 0.5f,  0.5f, -0.5f), Vector4F(1.f, 1.f, 1.f, 0.f), Vector2F(1.f, 1.f), Vector3F::Right), /// 10
        Vertex(Vector3F( 0.5f, -0.5f, -0.5f), Vector4F(1.f, 1.f, 1.f, 0.f), Vector2F(1.f, 0.f), Vector3F::Right), /// 11

        /// left
        Vertex(Vector3F(-0.5f,  0.5f,  0.5f), Vector4F(1.f, 1.f, 1.f, 0.f), Vector2F(0.f, 1.f), Vector3F::Left), /// 12
        Vertex(Vector3F(-0.5f, -0.5f,  0.5f), Vector4F(1.f, 1.f, 1.f, 0.f), Vector2F(0.f, 0.f), Vector3F::Left), /// 13
        Vertex(Vector3F(-0.5f,  0.5f, -0.5f), Vector4F(1.f, 1.f, 1.f, 0.f), Vector2F(1.f, 1.f), Vector3F::Left), /// 14
        Vertex(Vector3F(-0.5f, -0.5f, -0.5f), Vector4F(1.f, 1.f, 1.f, 0.f), Vector2F(1.f, 0.f), Vector3F::Left), /// 15

        /// top
        Vertex(Vector3F(-0.5f,  0.5f,  0.5f), Vector4F(1.f, 1.f, 1.f, 0.f), Vector2F(0.f, 0.f), Vector3F::Up), /// 16
        Vertex(Vector3F( 0.5f,  0.5f,  0.5f), Vector4F(1.f, 1.f, 1.f, 0.f), Vector2F(1.f, 0.f), Vector3F::Up), /// 17
        Vertex(Vector3F(-0.5f,  0.5f, -0.5f), Vector4F(1.f, 1.f, 1.f, 0.f), Vector2F(0.f, 1.f), Vector3F::Up), /// 18
        Vertex(Vector3F( 0.5f,  0.5f, -0.5f), Vector4F(1.f, 1.f, 1.f, 0.f), Vector2F(1.f, 1.f), Vector3F::Up), /// 19

        /// bottom
        Vertex(Vector3F( 0.5f, -0.5f,  0.5f), Vector4F(1.f, 1.f, 1.f, 0.f), Vector2F(0.f, 0.f), Vector3F::Down), /// 20
        Vertex(Vector3F(-0.5f, -0.5f,  0.5f), Vector4F(1.f, 1.f, 1.f, 0.f), Vector2F(1.f, 0.f), Vector3F::Down), /// 21
        Vertex(Vector3F( 0.5f, -0.5f, -0.5f), Vector4F(1.f, 1.f, 1.f, 0.f), Vector2F(0.f, 1.f), Vector3F::Down), /// 22
        Vertex(Vector3F(-0.5f, -0.5f, -0.5f), Vector4F(1.f, 1.f, 1.f, 0.f), Vector2F(1.f, 1.f), Vector3F::Down), /// 23
};

std::vector<unsigned int> indices = {
        0, 1, 2,
        1, 2, 3,

        4, 5, 6,
        5, 6, 7,

        8, 9, 10,
        9, 10, 11,

        12, 13, 14,
        13, 14, 15,

        16, 17, 18,
        17, 18, 19,

        20, 21, 22,
        21, 22, 23
};

int main(int argc, char* argv[])
{
    Log::get()->createLogger<ConsoleLogger>();

    Shader phong;
    WindowEvent event;
    EulerAnglesF rotation;
    Texture diffuse, specular, emission;
    CameraF camera(Vector3F(0.f, 0.f, 5.f));
    RenderWindow window(VideoMode(800, 600), "Bull Application");
    PerspectiveProjectionF projection(AngleF::degree(45.f), window.getSize().getRatio(), Vector2F(0.1f, 100.f));
    Mesh square;

    square.create(vertices, indices);

    diffuse.loadFromPath(Path("../resources/textures/container.png"));
    diffuse.enableSmooth();

    specular.loadFromPath(Path("../resources/textures/container_specular.png"));
    specular.enableSmooth();

    emission.loadFromPath(Path("../resources/textures/emission_map.jpg"));
    emission.enableSmooth();

    phong.attachFromPath(Path("../resources/shaders/phong/phong.vert"), ShaderStageType::Vertex);
    phong.attachFromPath(Path("../resources/shaders/phong/phong.frag"), ShaderStageType::Fragment);
    phong.link();

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

            if(event.type == WindowEvent::MouseMoved && Mouse::isButtonPressed(Mouse::Left))
            {
                rotation.roll  += AngleF::degree(event.mouseMove.yRel);
                rotation.pitch += AngleF::degree(event.mouseMove.xRel);
            }
        }

        window.clear();

        phong.bind();

        phong.setUniformMatrix("model", Transformation3DF::makeRotation(rotation).getMatrix());
        phong.setUniformMatrix("view", camera.getMatrix());
        phong.setUniformMatrix("projection", projection.getMatrix());

        phong.setUniform("material.shininess", 64.f);

        diffuse.setSampler(Texture::Sampler0);
        diffuse.bind();
        phong.setUniform("material.diffuse", diffuse.getSampler());

        specular.setSampler(Texture::Sampler1);
        specular.bind();
        phong.setUniform("material.specular", specular.getSampler());

        emission.setSampler(Texture::Sampler2);
        emission.bind();
        phong.setUniform("emission_map", emission.getSampler());

        phong.setUniformVector("light.position", Vector3F::UnitX * 3.f);
        phong.setUniformVector("light.ambient", Vector4F::Unit / 5.f);
        phong.setUniformVector("light.diffuse", Vector4F::Unit / 2.f);
        phong.setUniformVector("light.specular", Vector4F(1.f, 1.f, 1.f, 0.f));

        phong.setUniformVector("camera_position", camera.getPosition());

        square.render(Mesh::Triangles);

        window.display();
    }

    return 0;
}