#include <iostream>

#include <Bull/Core/Log/Log.hpp>

#include <Bull/Graphics/Material.hpp>

#include <Bull/Math/EulerAngles.hpp>
#include <Bull/Math/Matrix/Matrix4.hpp>

#include <Bull/Render/Mesh.hpp>
#include <Bull/Render/OpenGL.hpp>
#include <Bull/Render/Shader/Shader.hpp>
#include <Bull/Render/Target/RenderWindow.hpp>

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

void show(const Matrix4F& mat)
{
    for(Index j = 0; j < 4; j++)
    {
        for(Index i = 0; i < 4; i++)
        {
            std::cout << mat.at(i, j);
        }

        std::cout << std::endl;
    }
}

int main(int argc, char* argv[])
{
    Log::get()->createLogger<ConsoleLogger>();

    ContextSettings settings = ContextSettings::Best;
    settings.flags |= ContextSettings::NoError;

    Shader phong;
    WindowEvent event;
    EulerAnglesF rotation;
    Texture diffuse, specular, emission;
    RenderWindow window(VideoMode(800, 600), "Bull Application", WindowStyle::Default, settings);
    Matrix4F camera = Matrix4F::makeLookAt(Vector3F(2.f, 1.f, 3.f), Vector3F::Zero);
    Mesh square;

    square.create(vertices, indices);

    diffuse.loadFromPath(Path("../resources/textures/container.png"));
    diffuse.enableSmooth();

    specular.loadFromPath(Path("../resources/textures/container_specular.png"));
    specular.enableSmooth();

    emission.loadFromPath(Path("../resources/textures/container_emission.png"));
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

            if(event.type == WindowEvent::MouseMoved && Mouse::isButtonPressed(Mouse::Left))
            {
                rotation.roll  += AngleF::degree(event.mouseMove.yRel);
                rotation.pitch += AngleF::degree(event.mouseMove.xRel);
            }
        }

        if(!window.isOpen())
        {
            break;
        }

        window.clear();

        phong.bind();

        Matrix4F projection = Matrix4F::makePerspective(AngleF::degree(45.f), window.getSize().getRatio(), Vector2F(0.1f, 100.f));
        QuaternionF quat(EulerAnglesF::normalize(rotation));

        phong.setUniformMatrix("model", Matrix4F::makeTranslation(Vector3F(1.f, 0.f, 0.f)) * Matrix4F::makeRotation(quat) * Matrix4F::makeScale(Vector3F::Unit));
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

        square.render(Mesh::Triangles);

        window.display();
    }

    return 0;
}