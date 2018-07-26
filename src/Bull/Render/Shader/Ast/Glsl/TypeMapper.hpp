#ifndef BULL_RENDER_SHADER_AST_GLSL_TYPEMAPPER_HPP
#define BULL_RENDER_SHADER_AST_GLSL_TYPEMAPPER_HPP

#include <Bull/Math/Matrix/Matrix2.hpp>
#include <Bull/Math/Matrix/Matrix3.hpp>
#include <Bull/Math/Matrix/Matrix4.hpp>
#include <Bull/Math/Vector/Vector2.hpp>
#include <Bull/Math/Vector/Vector3.hpp>
#include <Bull/Math/Vector/Vector4.hpp>

#define DeclareTypeMapper(Type, Out)          \
template <>                                   \
struct TypeMapper<Type>                       \
{                                             \
    static constexpr const char* value = Out; \
}                                             \

namespace Bull
{
    namespace Ast
    {
        namespace prv
        {
            template <typename T>
            struct TypeMapper
            {

            };

            DeclareTypeMapper(void,  "void");
            DeclareTypeMapper(bool,  "bool");
            DeclareTypeMapper(int,   "int");
            DeclareTypeMapper(float, "float");

            DeclareTypeMapper(Vector2F, "vec2");
            DeclareTypeMapper(Vector3F, "vec3");
            DeclareTypeMapper(Vector4F, "vec4");

            DeclareTypeMapper(Vector2I, "ivec2");
            DeclareTypeMapper(Vector3I, "ivec3");
            DeclareTypeMapper(Vector4I, "ivec4");

            DeclareTypeMapper(Matrix2F, "mat2");
            DeclareTypeMapper(Matrix3F, "mat3");
            DeclareTypeMapper(Matrix4F, "mat4");
        }
    }
}

#endif // BULL_RENDER_SHADER_AST_GLSL_TYPEMAPPER_HPP
