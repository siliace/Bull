#ifndef Bull_Context_hpp
#define Bull_Context_hpp

#include <memory>

#include <Bull/Core/Pattern/NonCopyable.hpp>
#include <Bull/Core/System/Export.hpp>

#include <Bull/Render/Context/ContextResource.hpp>
#include <Bull/Render/Context/ContextSettings.hpp>

#include <Bull/Utility/Window/VideoMode.hpp>

namespace Bull
{
    namespace prv
    {
        class GlContext;
    }

    class BULL_API Context : public ContextResource, public NonCopyable
    {
    public:

        /*! \brief Get the active context in this thread
         *
         * \return Return the context is available, nullptr otherwise
         *
         */
        static const Context* getActive();

    private:

        static thread_local Context* s_active;

    public:

        /*! \brief Default constructor
         *
         */
        Context();

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
        ~Context();

        /*! \brief Activate or deactivate the context
         *
         * \param active True to activate, false to deactivate the context
         *
         * \return Return true if the context's status changed successfully, false otherwise
         *
         */
        bool setActive(bool active = true);

        /*! \brief Get the ContextSettings of the context
         *
         * \return Return the ContextSettings
         *
         */
        const ContextSettings& getSettings() const;

    private:

        std::unique_ptr<prv::GlContext> m_impl;
    };
}

#endif // Bull_Context_hpp
