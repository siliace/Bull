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
             *
             * \return Return the pixel format
             *
             */
            static int getBestPixelFormat(HDC device, unsigned int bitsPerPixel, const ContextSettings& settings);

        public:

            /*! \brief Constructor
             *
             * \param shared The shared context
             *
             */
            WglContext(const std::shared_ptr<WglContext>& shared);

            /*! \brief Constructor
             *
             * \param shared The shared context
             * \param bitsPerPixel The number of bits to use per pixel
             * \param settings Parameters to create the OpenGL context
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

            void createSurface(WindowHandler window);

            void createSurface(unsigned int width, unsigned int height, unsigned int bitsPerPixel);

            void setPixelFormat(unsigned int bitsPerPixel);

            void createContext(const std::shared_ptr<WglContext>& shared);

            HWND     m_window;
            HDC      m_device;
            HGLRC    m_render;
            HPBUFFER m_pbuffer;
            bool     m_ownWindow;
        };
    }
}

#endif // Bull_WglContext_hpp
