#ifndef BULL_RENDER_CONTEXT_CONTEXT_HPP
#define BULL_RENDER_CONTEXT_CONTEXT_HPP

#include <memory>

#include <Bull/Core/Pattern/NonCopyable.hpp>

#include <Bull/Render/Context/ContextResource.hpp>
#include <Bull/Render/Context/ContextSettings.hpp>

namespace Bull
{
    class VideoMode;

    namespace prv
    {
        class GlContext;
    }

    class BULL_RENDER_API Context : public ContextResource, public NonCopyable
    {
    public:

        /*! \brief Get the active context in this thread
         *
         * \return Return the context is available, nullptr otherwise
         *
         */
        static const Context* getActive();

    public:

        /*! \brief Default constructor
         *
         */
        Context();

        /*! \brief Constructor by movement
         *
         * \param move The Context to move
         *
         */
        Context(Context&& move) noexcept = default;

        /*! \brief Constructor
         *
         * \param mode     The VideoMode to use to create the context
         * \param settings Settings to use to create the context
         *
         */
        Context(const VideoMode& mode, const ContextSettings& settings);

        /*! \brief Constructor
         *
         * \param bitsPerPixel Number of bits per pixel to use
         * \param settings     Settings to use to create the context
         *
         */
        Context(unsigned int bitsPerPixel, const ContextSettings& settings);

        /*! \brief Destructor
         *
         */
        virtual ~Context();

        /*! \brief Basic assignment operator by movement
         *
         * \param move The Context to move
         *
         * \return This
         *
         */
        Context& operator=(Context&& move) noexcept = default;

        /*! \brief Activate or deactivate the context
         *
         * \param active True to activate, false to deactivate the context
         *
         */
        void setActive(bool active = true);

        /*! \brief Get the ContextSettings of the context
         *
         * \return Return the ContextSettings
         *
         */
        const ContextSettings& getSettings() const;

    protected:

        std::unique_ptr<prv::GlContext> m_context; /*!< The concrete implementation of the context */
    };
}

#endif // BULL_RENDER_CONTEXT_CONTEXT_HPP
