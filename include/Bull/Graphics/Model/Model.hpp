#ifndef BULL_GRAPHICS_MODEL_MODEL_HPP
#define BULL_GRAPHICS_MODEL_MODEL_HPP

#include <memory>

#include <Bull/Graphics/Model/Mesh.hpp>
#include <Bull/Graphics/Rendering/Renderable.hpp>
#include <Bull/Graphics/Rendering/Transformable.hpp>

namespace Bull
{
    class BULL_GRAPHICS_API Model : public Renderable, public Transformable
    {
    public:

        /*! \brief Default constructor
         *
         */
        Model() = default;

        /*! \brief Constructor
         *
         * \param mesh The Mesh of the Model
         *
         */
        explicit Model(const std::shared_ptr<Mesh>& mesh);

        /*! \brief Render the Mesh of the Model thought a Shader
         *
         * \param shader The Shader
         *
         */
        void render(const Shader& shader) const override;

        /*! \brief Set the Mesh of the Model
         *
         * \param mesh The Mesh
         *
         */
        inline void setMesh(const std::shared_ptr<Mesh>& mesh)
        {
            m_mesh = mesh;
        }

        /*! \brief Get the Mesh of the Model
         *
         * \return The Mesh
         *
         */
        inline const Mesh* getMesh() const
        {
            return m_mesh.get();
        }

    private:

        std::shared_ptr<Mesh> m_mesh;
    };
}

#endif // BULL_GRAPHICS_MODEL_MODEL_HPP
