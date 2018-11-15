#include <vector>

#include <Bull/Math/EulerAngles.hpp>

#include <Bull/Render/Context/GlFunctions.hpp>
#include <Bull/Render/Vertex/Vertex.hpp>

#include <Cube.hpp>

namespace
{
    std::vector<Bull::Vertex> vertices = {
            /// front
            Bull::Vertex(Bull::Vector3F( 0.5f,  0.5f,  0.5f), Bull::Vector4F(1.f, 1.f, 1.f, 0.f), Bull::Vector2F(1.f, 1.f), Bull::Vector3F::Forward), /// 0
            Bull::Vertex(Bull::Vector3F(-0.5f,  0.5f,  0.5f), Bull::Vector4F(1.f, 1.f, 1.f, 0.f), Bull::Vector2F(0.f, 1.f), Bull::Vector3F::Forward), /// 1
            Bull::Vertex(Bull::Vector3F( 0.5f, -0.5f,  0.5f), Bull::Vector4F(1.f, 1.f, 1.f, 0.f), Bull::Vector2F(1.f, 0.f), Bull::Vector3F::Forward), /// 2
            Bull::Vertex(Bull::Vector3F(-0.5f, -0.5f,  0.5f), Bull::Vector4F(1.f, 1.f, 1.f, 0.f), Bull::Vector2F(0.f, 0.f), Bull::Vector3F::Forward), /// 3

            /// back
            Bull::Vertex(Bull::Vector3F( 0.5f,  0.5f, -0.5f), Bull::Vector4F(1.f, 1.f, 1.f, 0.f), Bull::Vector2F(1.f, 1.f), Bull::Vector3F::Backward), /// 4
            Bull::Vertex(Bull::Vector3F(-0.5f,  0.5f, -0.5f), Bull::Vector4F(1.f, 1.f, 1.f, 0.f), Bull::Vector2F(0.f, 1.f), Bull::Vector3F::Backward), /// 5
            Bull::Vertex(Bull::Vector3F( 0.5f, -0.5f, -0.5f), Bull::Vector4F(1.f, 1.f, 1.f, 0.f), Bull::Vector2F(1.f, 0.f), Bull::Vector3F::Backward), /// 6
            Bull::Vertex(Bull::Vector3F(-0.5f, -0.5f, -0.5f), Bull::Vector4F(1.f, 1.f, 1.f, 0.f), Bull::Vector2F(0.f, 0.f), Bull::Vector3F::Backward), /// 7

            /// right
            Bull::Vertex(Bull::Vector3F( 0.5f,  0.5f,  0.5f), Bull::Vector4F(1.f, 1.f, 1.f, 0.f), Bull::Vector2F(0.f, 1.f), Bull::Vector3F::Right), /// 8
            Bull::Vertex(Bull::Vector3F( 0.5f, -0.5f,  0.5f), Bull::Vector4F(1.f, 1.f, 1.f, 0.f), Bull::Vector2F(0.f, 0.f), Bull::Vector3F::Right), /// 9
            Bull::Vertex(Bull::Vector3F( 0.5f,  0.5f, -0.5f), Bull::Vector4F(1.f, 1.f, 1.f, 0.f), Bull::Vector2F(1.f, 1.f), Bull::Vector3F::Right), /// 10
            Bull::Vertex(Bull::Vector3F( 0.5f, -0.5f, -0.5f), Bull::Vector4F(1.f, 1.f, 1.f, 0.f), Bull::Vector2F(1.f, 0.f), Bull::Vector3F::Right), /// 11

            /// left
            Bull::Vertex(Bull::Vector3F(-0.5f,  0.5f,  0.5f), Bull::Vector4F(1.f, 1.f, 1.f, 0.f), Bull::Vector2F(0.f, 1.f), Bull::Vector3F::Left), /// 12
            Bull::Vertex(Bull::Vector3F(-0.5f, -0.5f,  0.5f), Bull::Vector4F(1.f, 1.f, 1.f, 0.f), Bull::Vector2F(0.f, 0.f), Bull::Vector3F::Left), /// 13
            Bull::Vertex(Bull::Vector3F(-0.5f,  0.5f, -0.5f), Bull::Vector4F(1.f, 1.f, 1.f, 0.f), Bull::Vector2F(1.f, 1.f), Bull::Vector3F::Left), /// 14
            Bull::Vertex(Bull::Vector3F(-0.5f, -0.5f, -0.5f), Bull::Vector4F(1.f, 1.f, 1.f, 0.f), Bull::Vector2F(1.f, 0.f), Bull::Vector3F::Left), /// 15

            /// top
            Bull::Vertex(Bull::Vector3F(-0.5f,  0.5f,  0.5f), Bull::Vector4F(1.f, 1.f, 1.f, 0.f), Bull::Vector2F(0.f, 0.f), Bull::Vector3F::Up), /// 16
            Bull::Vertex(Bull::Vector3F( 0.5f,  0.5f,  0.5f), Bull::Vector4F(1.f, 1.f, 1.f, 0.f), Bull::Vector2F(1.f, 0.f), Bull::Vector3F::Up), /// 17
            Bull::Vertex(Bull::Vector3F(-0.5f,  0.5f, -0.5f), Bull::Vector4F(1.f, 1.f, 1.f, 0.f), Bull::Vector2F(0.f, 1.f), Bull::Vector3F::Up), /// 18
            Bull::Vertex(Bull::Vector3F( 0.5f,  0.5f, -0.5f), Bull::Vector4F(1.f, 1.f, 1.f, 0.f), Bull::Vector2F(1.f, 1.f), Bull::Vector3F::Up), /// 19

            /// bottom
            Bull::Vertex(Bull::Vector3F( 0.5f, -0.5f,  0.5f), Bull::Vector4F(1.f, 1.f, 1.f, 0.f), Bull::Vector2F(0.f, 0.f), Bull::Vector3F::Down), /// 20
            Bull::Vertex(Bull::Vector3F(-0.5f, -0.5f,  0.5f), Bull::Vector4F(1.f, 1.f, 1.f, 0.f), Bull::Vector2F(1.f, 0.f), Bull::Vector3F::Down), /// 21
            Bull::Vertex(Bull::Vector3F( 0.5f, -0.5f, -0.5f), Bull::Vector4F(1.f, 1.f, 1.f, 0.f), Bull::Vector2F(0.f, 1.f), Bull::Vector3F::Down), /// 22
            Bull::Vertex(Bull::Vector3F(-0.5f, -0.5f, -0.5f), Bull::Vector4F(1.f, 1.f, 1.f, 0.f), Bull::Vector2F(1.f, 1.f), Bull::Vector3F::Down), /// 23
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
}

Cube::Cube()
{
    std::shared_ptr<Bull::Mesh> mesh = std::make_shared<Bull::Mesh>();
    std::shared_ptr<Bull::SubMesh> submesh = std::make_shared<Bull::SubMesh>(Bull::RenderPrimitive_Triangles);
    submesh->create(vertices, indices);

    mesh->addSubMesh(submesh);

    setMesh(mesh);
}

void Cube::render(const Bull::Shader& shader, const Bull::Material& material) const
{
    shader.setUniform("material.shininess", material.getShininess());

    gl::activeTexture(GL_TEXTURE0);
    Bull::Texture::bind(*material.getTexture(Bull::TextureType_Diffuse));
    shader.setUniform("material.diffuse", 0);

    gl::activeTexture(GL_TEXTURE1);
    Bull::Texture::bind(*material.getTexture(Bull::TextureType_Specular));
    shader.setUniform("material.specular", 1);

    Model::render(shader);
}