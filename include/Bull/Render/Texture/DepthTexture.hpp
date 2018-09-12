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

        /*! \brief Default constructor
         *
         */
        DepthTexture();

        /*! \brief Constructor
         *
         * \param size  The size of the DepthTexture
         * \param depth The precision of the depth data
         *
         */
        explicit DepthTexture(const Size& size, unsigned int depth = Context::getActive()->getSettings().depths);

        /*! \brief Constructor by movement semantic
         *
         * \param right The DepthTexture to move
         *
         */
        DepthTexture(DepthTexture&& right) noexcept;

        /*! \brief Destructor
         *
         */
        ~DepthTexture();

        /*! \brief Basic assignment operator
         *
         * \param right The DepthTexture to move
         *
         * \return This
         *
         */
        DepthTexture& operator=(DepthTexture&& right) noexcept;

        /*! \brief Create the DepthTexture
         *
         * \param size  The size of the DepthTexture
         * \param depth The precision of the depth data
         *
         */
        void create(const Size& size, unsigned int depth = Context::getActive()->getSettings().depths);

        /*! \brief Tell whether the DepthTexture is valid
         *
         * \return True if valid
         *
         */
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
