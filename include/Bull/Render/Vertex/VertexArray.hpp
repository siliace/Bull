#ifndef BULL_RENDER_VERTEX_VERTEXARRAY_HPP
#define BULL_RENDER_VERTEX_VERTEXARRAY_HPP

#include <vector>

#include <Bull/Math/Polygon/Polygon.hpp>

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

            /*! \brief Set the Color of the VertexStripe
             *
             * \param color The Color
             *
             */
            void setColor(const Color& color)
            {
                Vector4F vectorColor = Vector4F::makeFromColor(color);

                for(std::size_t i = 0; i < Count; i++)
                {
                    std::next(m_it, i)->color = vectorColor;
                }
            }

            /*! \brief Set the normal Vector of the VertexStripe
             *
             * \param normal The normal
             *
             */
            void setNormal(const Vector3F& normal)
            {
                for(std::size_t i = 0; i < Count; i++)
                {
                    std::next(m_it, i)->normal = normal;
                }
            }

            /*! \brief Get a sub stripe from the VertexStripe
             *
             * \tparam U    The size of the sub VertexStripe
             * \param index The index of the VertexStripe
             *
             * \return The VertexStripe
             *
             */
            template <std::size_t U>
            VertexStripe<U> getSubStripe(std::size_t index) const
            {
                static_assert(U < S, "Sub stripe size cannot be prior to the parent stripe");

                return VertexStripe<U>(std::next(m_it, index));
            }

            /*! \brief Advance the VertexStripe into the parent VertexArray
             *
             * \param offset The offset to advance
             *
             */
            void advance(std::size_t offset = 1)
            {
                std::advance(m_it, offset);
            }

            /*! \brief Get a next VertexStripe
             *
             * \param offset The offset of the VertexStripe to get
             *
             * \return The VertexStripe
             *
             */
            VertexStripe<S> next(std::size_t offset = 1)
            {
                return VertexStripe<S>(std::next(m_it, offset));
            }

        private:

            /*! \brief Constructor
             *
             * \param it The Vertex iterator to iterate on
             *
             */
            explicit VertexStripe(std::vector<Vertex>::iterator it) :
                m_it(it)
            {
                /// Nothing
            }

        private:

            std::vector<Vertex>::iterator m_it;
        };

    public:

        static VertexArray createPolygon(const Polygon<float>& polygon, const Color& color = Color::White, const Vector3F& normal = Vector3F::Zero, float depth = 0.f);

    public:

        /*! \brief Default constructor
         *
         */
        VertexArray() = default;

        /*! \brief Constructor
         *
         * \param size The size of the VertexArray
         *
         */
        explicit VertexArray(std::size_t size);

        /*! \brief Constructor
         *
         * \param vertices Vertices inside the VertexArray
         *
         */
        VertexArray(const std::initializer_list<Vertex>& vertices);

        void add(const Vertex& vertex);

        /*! \brief Get a VertexStripe from the VertexArray
         *
         * \tparam S The size of the VertexStripe
         * \param index The index of the VertexStripe to get
         *
         * \return The VertexStripe
         *
         */
        template <std::size_t S>
        VertexStripe<S> getStripe(std::size_t index)
        {
            return VertexStripe<S>(m_vertices.begin() + index);
        }

        /*! \brief Get the size of the VertexArray
         *
         * \return The size
         *
         */
        std::size_t getSize() const;

        /*! \brief
         *
         * \return
         *
         */
        Vertex* getBuffer();

        /*! \brief
         *
         * \return
         *
         */
        const Vertex* getBuffer() const;

    private:

        std::vector<Vertex> m_vertices;
    };
}

#endif // BULL_RENDER_VERTEX_VERTEXARRAY_HPP
