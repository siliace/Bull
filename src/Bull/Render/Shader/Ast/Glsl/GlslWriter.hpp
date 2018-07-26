#ifndef BULL_RENDER_SHADER_AST_GLSLWRITER_HPP
#define BULL_RENDER_SHADER_AST_GLSLWRITER_HPP

#include <Bull/Core/IO/OutStringStream.hpp>
#include <Bull/Core/Memory/String.hpp>
#include <Bull/Core/Utility/StringUtils.hpp>

#include <Bull/Render/Shader/Ast/Glsl/TypeMapper.hpp>
#include <Bull/Render/Shader/Ast/Type/Array.hpp>
#include <Bull/Render/Shader/Ast/Type/Function.hpp>
#include <Bull/Render/Shader/Ast/Type/InVariable.hpp>
#include <Bull/Render/Shader/Ast/Type/OutVariable.hpp>
#include <Bull/Render/Shader/Ast/Type/Uniform.hpp>

namespace Bull
{
    namespace Ast
    {
        namespace prv
        {
            class GlslWriter
            {
            public:

                template <typename T>
                static String writeInVariable(const InVariable<T>& inVariable)
                {
                    OutStringStream oss;

                    inVariable.getLayout().ifNotEmpty([&oss](const unsigned int& layout) {
                        oss << "layout (location = " << StringUtils::number(layout) << ") ";
                    });

                    oss << "in " << writeVariable(inVariable) + ";\n";

                    return oss.toString();
                }

                template <typename T>
                static String writeOutVariable(const OutVariable<T> outVariable)
                {
                    return "out" + writeVariable(outVariable) + ";\n";
                }

                template <typename T>
                static String writeUniform(const Uniform<T> uniform)
                {
                    return "uniform" + writeVariable(uniform) + ";\n";
                }

                template <typename T, std::size_t N>
                static String writeArray(const Array<T, N> array)
                {
                    return writeVariable(array) + "[" + StringUtils::number(N) + "];\n";
                }

                template <typename T, typename... Args>
                static String writeFunction(const Function<T, Args...>& function)
                {
                    OutStringStream oss;

                    oss << TypeMapper<T>::value << " " << function.getName() << "()\n";
                    oss << "{" << "\n";
                    oss << "}" << "\n";

                    return oss.toString();
                }

            private:

                template <typename T>
                static String writeVariable(const Variable<T>& variable)
                {
                    return String(TypeMapper<T>::value) + " " + variable.getName();
                }
            };
        }
    }
}

#endif // BULL_RENDER_SHADER_AST_GLSLWRITER_HPP
