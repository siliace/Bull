
#include <Bull/Render/OpenGL.hpp>
#include <Bull/Render/Shader/Shader.hpp>
#include <Bull/Render/Target/RenderWindow.hpp>
#include <Bull/Render/Texture/Texture.hpp>

#include <Cube.hpp>

using namespace Bull;

int main(int argc, char* argv[])
{
    Shader phong;
    WindowEvent event;
    Texture diffuse, specular, emission;
    RenderWindow window(VideoMode(800, 600), "Bull Application");
    Matrix4F camera = Matrix4F::makeLookAt(Vector3F(2.f, 1.f, 30.f), Vector3F::Zero);

    diffuse.loadFromPath(Path("../resources/textures/container.png"));
    diffuse.enableSmooth();

    specular.loadFromPath(Path("../resources/textures/container_specular.png"));
    specular.enableSmooth();

    emission.loadFromPath(Path("../resources/textures/container_emission.png"));
    emission.enableSmooth();

    phong.attachFromPath(Path("../resources/shaders/phong/phong.vert"), ShaderStageType::Vertex);
    phong.attachFromPath(Path("../resources/shaders/phong/phong.frag"), ShaderStageType::Fragment);
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
        }

        if(!window.isOpen())
        {
            break;
        }

        window.clear();

        phong.bind();

        Matrix4F projection = Matrix4F::makePerspective(AngleF::degree(45.f), window.getSize().getRatio(), Vector2F(0.1f, 100.f));

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