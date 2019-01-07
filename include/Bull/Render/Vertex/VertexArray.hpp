#ifndef BULL_RENDER_VERTEX_VERTEXARRAY_HPP
#define BULL_RENDER_VERTEX_VERTEXARRAY_HPP

#include <vector>

#include <Bull/Math/Polygon/Triangle.hpp>

#include <Bull/Render/Vertex/Vertex.hpp>

namespace Bull
{
    class BULL_RENDER_API VertexArray
    {
    public:

        template <std::size_t S>
        class VertexStripe
        {
        public:

            static constexpr std::size_t Count = S;

        public:

            void setColor(const Color& color)
            {
                Vector4F vectorColor = Vector4F::makeFromColor(color);

                for(std::size_t i = 0; i < Count; i++)
                {
                    std::next(m_it, i)->color = vectorColor;
                }
            }

            void setNormal(const Vector3F& normal)
            {
                for(std::size_t i = 0; i < Count; i++)
                {
                    std::next(m_it, i)->normal = normal;
                }
            }

            template <std::size_t U>
            VertexStripe<U> getSubStripe(std::size_t index) const
            {
                return VertexStripe<U>(std::next(m_it, index));
            }

            void advance()
            {
                std::advance(m_it, Count);
            }

        private:

            explicit VertexStripe(std::vector<Vertex>::iterator it) :
                m_it(it)
            {
                /// Nothing
            }

        private:

            std::vector<Vertex>::iterator m_it;
        };

    public:

        VertexArray() = default;

        explicit VertexArray(std::size_t size);

        VertexArray(const std::initializer_list<Vertex>& vertices);

        template <std::size_t S>
        VertexStripe<S> getStripe(std::size_t index)
        {
            return VertexStripe<S>(m_vertices.begin() + index);
        }

        std::size_t getSize() const;

    private:

        std::vector<Vertex> m_vertices;
    };
}

#endif // BULL_RENDER_VERTEX_VERTEXARRAY_HPP
