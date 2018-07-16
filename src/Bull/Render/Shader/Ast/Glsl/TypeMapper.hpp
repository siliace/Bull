#ifndef BULL_RENDER_SHADER_AST_GLSL_TYPEMAPPER_HPP
#define BULL_RENDER_SHADER_AST_GLSL_TYPEMAPPER_HPP

#include <Bull/Math/Vector/Vector2.hpp>
#include <Bull/Math/Vector/Vector3.hpp>
#include <Bull/Math/Vector/Vector4.hpp>

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

            template <>
            struct TypeMapper<void>
            {
                static constexpr const char* value = "void";
            };

            template <>
            struct TypeMapper<int>
            {
                static constexpr const char* value = "int";
            };

            template <>
            struct TypeMapper<float>
            {
                static constexpr const char* value = "float";
            };

            template <>
            struct TypeMapper<Vector2F>
            {
                static constexpr const char* value = "vec2";
            };

            template <>
            struct TypeMapper<Vector3F>
            {
                static constexpr const char* value = "vec3";
            };

            template <>
            struct TypeMapper<Vector4F>
            {
                static constexpr const char* value = "vec4";
            };
        }
    }
}

#endif // BULL_RENDER_SHADER_AST_GLSL_TYPEMAPPER_HPP
