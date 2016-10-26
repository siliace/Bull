#ifndef Bull_WglContext_hpp
#define Bull_WglContext_hpp

#include <memory>

#include <windows.h>

#include <Bull/Core/Exception.hpp>

#include <Bull/Render/Context/ExtensionsLoader.hpp>
#include <Bull/Render/Context/GlContext.hpp>

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
            static void requireExtensions(const ExtensionsLoader::Instance& loader = ExtensionsLoader::get());

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

            void createSurface(unsigned int width, unsigned int height);

            void setPixelFormat(unsigned int bitsPerPixel, const ContextSettings& settings);

            void createContext(const std::shared_ptr<WglContext>& shared);

            HWND  m_window;
            HDC   m_device;
            HGLRC m_render;
            bool  m_ownWindow;

            DeclarePublicException(FailToCreateSurface,       "An error occurred during the creation of the internal surface", Log::Critical);
            DeclarePublicException(FailToGetDeviceContext,    "Impossible to get a valid device context",                      Log::Critical);
            DeclarePublicException(FailToSetPixelFormat,      "Impossible to set the pixel format according to settings",      Log::Critical);
            DeclarePublicException(FailToCreateRenderContext, "An error occurred during the creation of the render context",   Log::Critical);
            DeclarePublicException(FailToShareContext,        "Impossible to share the context with others",                   Log::Critical);
            DeclarePublicException(FailToDisableShared,       "Impossible to disable the shared context",                      Log::Critical);
        };
    }
}

#endif // Bull_WglContext_hpp
