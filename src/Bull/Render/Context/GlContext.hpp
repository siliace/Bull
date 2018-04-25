#ifndef BULL_RENDER_CONTEXT_GLCONTEXT_HPP
#define BULL_RENDER_CONTEXT_GLCONTEXT_HPP

#include <Bull/Core/Window/WindowImpl.hpp>

#include <Bull/Render/Context/ContextSettings.hpp>
#include <Bull/Render/Context/ExtensionsLoader.hpp>
#include <Bull/Render/Context/SurfaceHandler.hpp>

namespace Bull
{
    namespace prv
    {
        class GlContext : public NonCopyable
        {
        public:

            /*! \brief Perform internal initialization
             *
             */
            static void globalInit();

            /*! \brief Ensure there is an active OpenGL context in this thread
             *
             */
            static void ensureContext();

            /*! \brief Create an OS specific instance of GlContext
             *
             * \return Return the created context
             *
             */
            static std::unique_ptr<GlContext> createInstance();

            /*! \brief Create an OS specific instance of GlContext
             *
             * \param mode     The VideoMode to use to create the context
             * \param settings Settings to use to create the context
             *
             * \return Return the created context
             *
             */
            static std::unique_ptr<GlContext> createInstance(const VideoMode& mode, const ContextSettings& settings);

            /*! \brief Create an OS specific instance of GlContext
             *
             * \param bitsPerPixel Number of bits per pixel to use
             * \param settings     Settings to use to create the context
             *
             * \return Return the created context
             *
             */
            static std::unique_ptr<GlContext> createInstance(unsigned int bitsPerPixel, const ContextSettings& settings);

            /*! \brief Create an OS specific instance of GlContext
             *
             * \param window       The window to bind the created context
             * \param bitsPerPixel The number of bits to use per pixel
             * \param settings     Parameters to create the OpenGL context
             *
             * \return Return the created context
             *
             */
            static std::unique_ptr<GlContext> createInstance(const WindowImpl& window, unsigned int bitsPerPixel, const ContextSettings& settings);

            /*! \brief Get an OpenGL function
             *
             * \param function The function name
             *
             * \param Return the function, nullptr if the function is not available
             *
             */
            static void* getFunction(const String& function);

            /*! \brief Check whether an extensions is loaded
             *
             * \param  extension The name of the extension
             *
             * \return Return true if the extension is supported, false otherwise
             *
             */
            static bool isSupported(const String& extension);

            /*! \brief The function called by OpenGL when an error occur
             *
             * \param source
             * \param type
             * \param id
             * \param severity
             * \param length
             * \param message
             * \param userParam
             *
             */
            static void debugProc(unsigned int source, unsigned int type, unsigned int id, unsigned int severity, int length, const char* msg, const void *userParam);

        protected:

            /*! \brief Give a mark to a pixel format
             *
             * \param bitsPerPixel
             * \param depths
             * \param stencil
             * \param antialiasing
             * \param bitsPerPixelWanted
             * \param settingsWanted
             *
             * \return Return the mark of the pixel format
             *
             */
            static int evaluatePixelFormat(unsigned int bitsPerPixel, int depths, int stencil, unsigned int antialiasing, unsigned int bitsPerPixelWanted, const ContextSettings& settingsWanted);

        public:

            /*! \brief Destructor
             *
             */
            virtual ~GlContext();

            /*! \brief Activate or deactivate the context
             *
             * \param active True to activate, false to deactivate
             *
             * \return Return true if the context's status changed successfully, false otherwise
             *
             */
            bool setActive(bool active);

            /*! \brief Display what has been rendered so far
             *
             */
            virtual void display() = 0;

            /*! \brief Activate or deactivate the vertical synchronization
             *
             * \param active True to activate, false to deactivate
             *
             * \return Return true if success, false otherwise
             *
             */
            virtual void enableVsync(bool active) = 0;

            /*! \brief Get the render surface of the context
             *
             * \return Return the render context
             *
             */
            virtual SurfaceHandler getSurfaceHandler() const = 0;

            /*! \brief Get the ContextSettings of the context
             *
             * \return Return the ContextSettings
             *
             */
            const ContextSettings& getSettings() const;

        protected:

            /*! \brief Default constructor
             *
             */
            GlContext() = default;

            /*! \brief Constructor
             *
             * \param settings Settings to use to create the context
             *
             */
            GlContext(const ContextSettings& settings);

            /*! \brief Make the context current
             *
             * \return Return true if the context is now active, false otherwise
             *
             */
            virtual bool makeCurrent() = 0;

            ContextSettings m_settings;

        private:

            /*! \brief Enable and perform initializations
             *
             * \param wanted Settings wanted to create the context
             *
             */
            void initialize(const ContextSettings& wanted = ContextSettings());
        };
    }
}

#endif // BULL_GLCONTEXT_HPP
