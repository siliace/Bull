#ifndef BULL_RENDER_BUFFER_VERTEXARRAYOBJECT_HPP
#define BULL_RENDER_BUFFER_VERTEXARRAYOBJECT_HPP

#include <functional>

#include <Bull/Core/Pattern/NonCopyable.hpp>

#include <Bull/Render/Export.hpp>

namespace Bull
{
    class BULL_RENDER_API VertexArrayObject : public NonCopyable
    {
    public:

        /*! \brief Default constructor
         *
         */
        VertexArrayObject();

        /*! \brief Constructor by movement semantic
         *
         * \param right The VertexArrayObject to move
         *
         */
        VertexArrayObject(VertexArrayObject&& right) noexcept;

        /*! \brief Destructor
         *
         */
        ~VertexArrayObject();

        /*! \brief Basic assignment operator by movement semantic
         *
         * \param right The VertexArrayObject to move
         *
         * \return This
         *
         */
        VertexArrayObject& operator=(VertexArrayObject&& right) noexcept;

        /*! \brief Run a Functor with the VertexArrayObject bound
         *
         * \param functor The Functor to run
         *
         */
        void runBound(const std::function<void()>& functor) const;

    private:

        unsigned int m_vao;
    };
}

#endif // BULL_RENDER_BUFFER_VERTEXARRAYOBJECT_HPP
