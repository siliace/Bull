#ifndef BULL_RENDER_TEXTURE_DEPTHTEXTURE_HPP
#define BULL_RENDER_TEXTURE_DEPTHTEXTURE_HPP

#include <Bull/Render/Context/Context.hpp>
#include <Bull/Render/Texture/Texture.hpp>

namespace Bull
{
    enum DepthValue
    {
        DepthValue_16, /*!< 16 bits of depth */
        DepthValue_24, /*!< 24 bits of depth */
        DepthValue_32, /*!< 32 bits of depth */
    };

    class BULL_RENDER_API DepthTexture : public Texture
    {
    public:

        /*! \brief Constructor
         *
         * \param depthValue The StencilValue of the StencilTexture
         *
         */
        explicit DepthTexture(DepthValue depthValue);

        /*! \brief Constructor
         *
         * \param size       The Size of the StencilTexture
         * \param depthValue The StencilValue of the StencilTexture
         *
         */
        DepthTexture(const Size& size, DepthValue depthValue);

        /*! \brief Constructor by movement semantic
         *
         * \param depthTexture The DepthTexture to move
         *
         */
        DepthTexture(DepthTexture&& depthTexture) noexcept;

        /*! \brief Assignment operator by movement semantic
         *
         * \param depthTexture The DepthTexture to move
         *
         * \return This
         *
         */
        DepthTexture& operator=(DepthTexture&& depthTexture) noexcept;

        /*! \brief Create the DepthTexture with a given Size
         *
         * \param size The Size
         *
         */
        void create(const Size& size) override;

        /*! \brief Get the DepthValue of the DepthTexture
         *
         * \return The DepthValue
         *
         */
        inline DepthValue getDepthValue() const
        {
            return m_depthValue;
        }

    private:

        DepthValue m_depthValue;
    };
}

#endif // BULL_RENDER_TEXTURE_DEPTHTEXTURE_HPP
