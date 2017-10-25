#include <vector>

#include <Bull/Core/Utility/Random.hpp>
#include <Bull/Core/Utility/Vertex.hpp>

#include <Bull/Math/EulerAngles.hpp>

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
    m_mesh.create(vertices, indices);

    Bull::Vector3F translation;
    Bull::EulerAnglesF rotation;

    rotation.roll  = Bull::AngleF::degree(Bull::Random::get()->random(0, 360));
    rotation.pitch = Bull::AngleF::degree(Bull::Random::get()->random(0, 360));
    rotation.yaw   = Bull::AngleF::degree(Bull::Random::get()->random(0, 360));

    translation.x() = int(Bull::Random::get()->random(0, 12)) - 6;
    translation.y() = int(Bull::Random::get()->random(0, 12)) - 6;
    translation.z() = int(Bull::Random::get()->random(0, 12)) - 6;

    rotate(rotation).move(translation);
}

void Cube::render()
{
    m_mesh.render(Bull::RenderPrimitive_Triangles);
}