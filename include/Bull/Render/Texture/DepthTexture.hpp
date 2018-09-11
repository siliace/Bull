#ifndef BULL_RENDER_TEXTURE_DEPTHTEXTURE_HPP
#define BULL_RENDER_TEXTURE_DEPTHTEXTURE_HPP

#include <Bull/Core/Pattern/NonCopyable.hpp>
#include <Bull/Core/Utility/Size.hpp>

#include <Bull/Render/Context/Context.hpp>

namespace Bull
{
    class BULL_RENDER_API DepthTexture : public NonCopyable, public ContextResource
    {
    public:

        DepthTexture();

        explicit DepthTexture(const Size& size, unsigned int depth = Context::getActive()->getSettings().depths);

        DepthTexture(DepthTexture&& right) noexcept;

        ~DepthTexture();

        DepthTexture& operator=(DepthTexture&& right) noexcept;

        void create(const Size& size, unsigned int depth = Context::getActive()->getSettings().depths);

        bool isValid() const;

        /*! \brief Get the size of the DepthTexture
         *
         * \return The Size
         *
         */
        Size getSize() const;

    private:

        unsigned int m_handler;
    };
}

#endif // BULL_RENDER_TEXTURE_DEPTHTEXTURE_HPP
