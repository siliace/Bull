#ifndef BULL_RENDER_CONTEXT_WIN32_WGLCONTEXT_HPP
#define BULL_RENDER_CONTEXT_WIN32_WGLCONTEXT_HPP

#include <Bull/Render/Context/ExtensionsLoader.hpp>
#include <Bull/Render/Context/GlContext.hpp>
#include <Bull/Render/Context/Wgl/PBufferHandler.hpp>

namespace Bull
{
    namespace prv
    {
        class WglContext : public GlContext
        {
        public:

            /*! \brief Get an OpenGL function
             *
             * \param function The function name
             *
             * \param Return the function, nullptr if the function is not available
             *
             */
            static void* getFunction(const String& function);

            /*! \brief Set the list of extensions to load
             *
             * \param loader The instance of the extension loader to use
             *
             */
            static void requireExtensions(ExtensionsLoader::Instance& loader);

        private:

            /*! \brief Get the best pixel format for a device handler
             *
             * \param device       The device handler
             * \param bitsPerPixel The number of bits per pixel to use to create colors
             * \param settings     Settings to use to create the OpenGL context
             * \param usePbuffer   The pixel format must be compatible with Pbuffer
             *
             * \return Return the pixel format
             *
             */
            static int getBestPixelFormat(HDC device, Uint8 bitsPerPixel, const ContextSettings& settings, bool usePbuffer = false);

        public:

            /*! \brief Constructor
             *
             * \param shared The shared context
             *
             */
            explicit WglContext(const WglContext* shared);

            /*! \brief Constructor
             *
             * \param shared   The shared context
             * \param mode     The VideoMode to use to create the context
             * \param settings Settings to use to create the context
             *
             */
            WglContext(const WglContext* shared, const VideoMode& mode, const ContextSettings& settings);

            /*! \brief Constructor
             *
             * \param shared       The shared context
             * \param bitsPerPixel The number of bits to use per pixel
             * \param settings     Parameters to create the OpenGL context
             *
             */
            WglContext(const WglContext* shared, Uint8 bitsPerPixel, const ContextSettings& settings);

            /*! \brief Constructor
             *
             * \param shared The shared context
             * \param window The window to bind the created context
             * \param bitsPerPixel The number of bits to use per pixel
             * \param settings Settings to use to create the OpenGL context
             *
             */
            WglContext(const WglContext* shared, const WindowImpl& window, Uint8 bitsPerPixel, const ContextSettings& settings);

            /*! \brief Destructor
             *
             */
            ~WglContext();

            /*! \brief Display what has been rendered so far
             *
             */
            void display() override;

            /*! \brief Activate or deactivate the vertical synchronization
             *
             * \param active True to activate, false to deactivate
             *
             * \return Return true if success, false otherwise
             *
             */
            void enableVsync(bool active) override;

            /*! \brief Get the render surface of the context
             *
             * \return Return the render context
             *
             */
            SurfaceHandler getSurfaceHandler() const override;

        protected:

            /*! \brief Make the context current
             *
             */
            void makeCurrent() override;

        private:

            /*! \brief Create the render surface
             *
             * \param window The window to bind to the context
             *
             */
            void createSurface(const WindowImpl& window);

            /*! \brief Create the render surface
             *
             * \param shared       The shared render context
             * \param width        The width of the surface
             * \param height       The height of the surface
             * \param bitsPerPixel Number of bits per pixel to use
             *
             */
            void createSurface(const WglContext* shared, unsigned int width, unsigned int height, Uint8 bitsPerPixel);

            /*! \brief Set the best pixel format
             *
             * \param bitsPerPixel Number of bits per pixel to use
             *
             */
            void setPixelFormat(Uint8 bitsPerPixel);

            /*! \brief Create the render context
             *
             * \param shared The shared render context
             *
             */
            void createContext(const WglContext* shared);

            /*! \brief Update settings according to the pixel format
             *
             */
            void updateSettings();

            Log::Instance m_log;
            HWND          m_window;
            HDC           m_device;
            HGLRC         m_render;
            HPBUFFER      m_pbuffer;
            bool          m_ownWindow;
        };
    }
}

#endif // BULL_RENDER_CONTEXT_WIN32_WGLCONTEXT_HPP
