#ifndef Bull_RenderTexture_hpp
#define Bull_RenderTexture_hpp

#include <memory>

#include <Bull/Core/Pattern/NonCopyable.hpp>
#include <Bull/Core/System/Export.hpp>

#include <Bull/Render/RenderTarget.hpp>
#include <Bull/Render/Texture.hpp>

#include <Bull/Utility/Color.hpp>

namespace Bull
{
    namespace prv
    {
        class RenderTextureImpl;
    }

    class BULL_API RenderTexture : public RenderTarget
    {
    public:

        /*! @brief Default constructor
         *
         */
        RenderTexture() = default;

        /*! @brief Destructor
         *
         */
        virtual ~RenderTexture();

        /*! @brief Create the RenderTexture
         *
         * @param size     The size of the RenderTexture
         * @param settings Settings to use to create the RenderTexture
         *
         * @return Return true if the RenderTexture was created successfully, false otherwise
         *
         */
        bool create(const Vector2UI& size, const ContextSettings& settings = ContextSettings::Worst);

        /*! @brief Get the default viewport of the RenderTarget
         *
         * @return Return the viewport
         *
         */
        Viewport getDefaultViewport() const override;

        /*! @brief Display what has been rendered so far into the target texture
         *
         */
        void display() override;

        /*! @brief Get the size of the RenderTexture
         *
         * @return Return the size
         *
         */
        const Vector2UI& getSize() const;

        /*! @brief Get the target texture
         *
         * @return Return the texture
         *
         */
        const Texture& getTexture() const;

        /*! @brief Convert the RenderTexture to a texture
         *
         * @return Return the texture
         *
         */
        operator const Texture&() const;

    private:

        Vector2UI                               m_size;
        std::unique_ptr<prv::RenderTextureImpl> m_impl;
        Texture                                 m_target;
    };
}

#endif // Bull_RenderTexture_hpp
