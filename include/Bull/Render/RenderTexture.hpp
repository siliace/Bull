#ifndef Bull_RenderTexture_hpp
#define Bull_RenderTexture_hpp

#include <memory>

#include <Bull/Core/Pattern/NonCopyable.hpp>
#include <Bull/Core/System/Export.hpp>

#include <Bull/Math/Vector/Vector2.hpp>

#include <Bull/Render/Color.hpp>
#include <Bull/Render/Context/ContextResource.hpp>
#include <Bull/Render/RenderTarget.hpp>
#include <Bull/Render/Texture.hpp>

namespace Bull
{
    namespace prv
    {
        class RenderTextureImpl;
    }

    class BULL_API RenderTexture : public RenderTarget
    {
    public:

        /*! \brief Default constructor
         *
         */
        RenderTexture();

        /*! \brief Destructor
         *
         */
        virtual ~RenderTexture();

        /*! \brief Create the RenderTexture
         *
         * \param size  The size of RenderTexture
         * \param color The color to fill the RenderTexture
         *
         * \return Return true if the RenderTexture was created successfully, false otherwise
         *
         */
        bool create(const Vector2UI size, Color color = Color::Black);

        /*! \brief Create the RenderTexture
         *
         * \param width  The width of the RenderTexture
         * \param height The height of the RenderTexture
         * \param color  The color to fill the RenderTexture
         *
         * \return Return true if the RenderTexture was created successfully, false otherwise
         *
         */
        bool create(unsigned int width, unsigned int height, Color color = Color::Black);

        /*! \brief Get the default viewport of the RenderTarget
         *
         * \return Return the viewport
         *
         */
        Viewport getDefaultViewport() const override;

        /*! \brief Activate or deactivate the context
         *
         * \param active True to activate, false to deactivate the context
         *
         * \return Return true if the context's status changed successfully, false otherwise
         *
         */
        bool setActive(bool active = true) override;

        /*! \brief Display what has been rendered so far into the target texture
         *
         */
        void display() override;

        /*! \brief Get the size of the RenderTexture
         *
         * \return Return the size
         *
         */
        const Vector2UI& getSize() const;

        /*! \brief Get the target texture
         *
         * \return Return the texture
         *
         */
        const Texture& getTexture() const;

        /*! \brief Convert the RenderTexture to a texture
         *
         * \return Return the texture
         *
         */
        operator const Texture&() const;

    private:

        std::unique_ptr<prv::RenderTextureImpl> m_impl;
        Texture                                 m_target;
    };
}

#endif // Bull_RenderTexture_hpp
