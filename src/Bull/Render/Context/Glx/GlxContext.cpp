#include <Bull/Render/Context/Glx/GlxContext.hpp>

namespace Bull
{
    namespace prv
    {
        /*! \brief Determine the best FrameBuffer configuration
         *
         * \return Return the framebuffer configuration
         *
         */
        GLXFBConfig GlxContext::getBestConfig()
        {
            Display::Instance display = Display::get();
            int glxMajor, glxMinor;

            if(!glXQueryVersion(display->getHandler(), &glxMajor, &glxMinor) || glxMajor < 1 || (glxMajor == 1 && glxMinor < 3))
            {
                ThrowException(InvalidGlxVersion);
            }

            int fbConfigCount = 0;
            int visualAttributes[] =
            {
                GLX_X_RENDERABLE , True,
                GLX_DRAWABLE_TYPE, GLX_WINDOW_BIT,
                GLX_RENDER_TYPE  , GLX_RGBA_BIT,
                GLX_X_VISUAL_TYPE, GLX_TRUE_COLOR,
                GLX_RED_SIZE     , 8,
                GLX_GREEN_SIZE   , 8,
                GLX_BLUE_SIZE    , 8,
                GLX_ALPHA_SIZE   , 8,
                GLX_DEPTH_SIZE   , 24,
                GLX_STENCIL_SIZE , 8,
                GLX_DOUBLEBUFFER , True,
                0
            };

            GLXFBConfig* configs = glXChooseFBConfig(display->getHandler(),
                                                     display->getDefaultScreen(),
                                                     visualAttributes,
                                                     &fbConfigCount);

            if(!configs)
            {
                ThrowException(NoFBConfigFound);
            }

            int bestFBConfigIndex = -1;
            int bestSamples       = -1;
            for(int i = 0; i < fbConfigCount; i++)
            {
                XVisualInfo* vi = glXGetVisualFromFBConfig(display->getHandler(), configs[i]);

                if(vi)
                {
                    int samples, sampleBuffers;
                    glXGetFBConfigAttrib(display->getHandler(), configs[i], GLX_SAMPLE_BUFFERS, &sampleBuffers);
                    glXGetFBConfigAttrib(display->getHandler(), configs[i], GLX_SAMPLES, &samples);

                    if(bestFBConfigIndex < 0 || (sampleBuffers && bestSamples < samples))
                    {
                        bestFBConfigIndex = i;
                        bestSamples       = samples;
                    }
                }

                XFree(vi);
            }

            GLXFBConfig best = configs[bestFBConfigIndex];
            XFree(configs);

            return best;
        }

        /*! \brief Determine the best XVisualInfo
         *
         * \return The XVisualInfo
         *
         */
        XVisualInfo* GlxContext::getBestVisual()
        {
            return glXGetVisualFromFBConfig(Display::get()->getHandler(), getBestConfig());
        }

        /*! \brief Constructor
         *
         * \param shared The shared context
         * \param window The window to bind the created context
         * \param bitsPerPixel The number of bits to use per pixel
         *
         */
        GlxContext::GlxContext(const std::shared_ptr<GlxContext>& shared, WindowHandler window, unsigned int bitsPerPixel) :
            m_display(Display::get()),
            m_window(window),
            m_render(0),
            m_ownWindow(m_window == 0)
        {
            m_render = glXCreateNewContext(m_display->getHandler(), getBestConfig(), GLX_RGBA_TYPE, 0, True);
        }

        /*! \brief Destructor
         *
         */
        GlxContext::~GlxContext()
        {
            if(m_render)
            {
                if(glXGetCurrentContext() == m_render)
                {
                    glXMakeCurrent(m_display->getHandler(), 0, 0);
                }

                glXDestroyContext(m_display->getHandler(), m_render);
            }

            if(m_window && m_ownWindow)
            {
                XDestroyWindow(m_display->getHandler(), m_window);
            }
        }

        /*! \brief Display what has been rendered so far
         *
         */
        void GlxContext::display()
        {
            if(m_render && m_window)
            {
                glXSwapBuffers(m_display->getHandler(), m_window);
            }
        }

        /*! \brief Make the context current
         *
         * \return Return true if the context is now active, false otherwise
         *
         */
        bool GlxContext::makeCurrent()
        {
            return glXMakeCurrent(Display::get()->getHandler(), m_window, m_render);
        }
    }
}
