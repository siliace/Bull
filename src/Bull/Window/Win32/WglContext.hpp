#ifndef Bull_WglContext_hpp
#define Bull_WglContext_hpp

#include <windows.h>

#include <Bull/Render/Context/ExtensionsLoader.hpp>
#include <Bull/Render/Context/GlContext.hpp>

namespace Bull
{
    namespace prv
    {
        DECLARE_HANDLE(HPBUFFER);

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
            static void requireExtensions(const ExtensionsLoader::Instance& loader);

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
            static int getBestPixelFormat(HDC device, unsigned int bitsPerPixel, const ContextSettings& settings, bool usePbuffer = false);

        public:

            /*! \brief Constructor
             *
             * \param shared The shared context
             *
             */
            WglContext(const std::shared_ptr<WglContext>& shared);

            /*! \brief Constructor
             *
             * \param shared   The shared context
             * \param mode     The VideoMode to use to create the context
             * \param settings Settings to use to create the context
             *
             */
            WglContext(const std::shared_ptr<WglContext>& shared, const VideoMode& mode, const ContextSettings& settings);

            /*! \brief Constructor
             *
             * \param shared       The shared context
             * \param bitsPerPixel The number of bits to use per pixel
             * \param settings     Parameters to create the OpenGL context
             *
             */
            WglContext(const std::shared_ptr<WglContext>& shared, unsigned int bitsPerPixel, const ContextSettings& settings);

            /*! \brief Constructor
             *
             * \param shared The shared context
             * \param window The window to bind the created context
             * \param bitsPerPixel The number of bits to use per pixel
             * \param settings Settings to use to create the OpenGL context
             *
             */
            WglContext(const std::shared_ptr<WglContext>& shared, WindowHandler window, unsigned int bitsPerPixel, const ContextSettings& settings);

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
             * \return Return true if the context is now active, false otherwise
             *
             */
            bool makeCurrent() override;

        private:

            /*! \brief Create the render surface
             *
             * \param window The window to bind to the context
             *
             */
            void createSurface(WindowHandler window);

            /*! \brief Create the render surface
             *
             * \param shared       The shared render context
             * \param width        The width of the surface
             * \param height       The height of the surface
             * \param bitsPerPixel Number of bits per pixel to use
             *
             */
            void createSurface(const std::shared_ptr<WglContext>& shared, unsigned int width, unsigned int height, unsigned int bitsPerPixel);

            /*! \brief Set the best pixel format
             *
             * \param bitsPerPixel Number of bits per pixel to use
             *
             */
            void setPixelFormat(unsigned int bitsPerPixel);

            /*! \brief Create the render context
             *
             * \param shared The shared render context
             *
             */
            void createContext(const std::shared_ptr<WglContext>& shared);

            /*! \brief Update settings according to the pixel format
             *
             */
            void updateSettings();

            HWND     m_window;
            HDC      m_device;
            HGLRC    m_render;
            HPBUFFER m_pbuffer;
            bool     m_ownWindow;
        };
    }
}

#endif // Bull_WglContext_hpp
