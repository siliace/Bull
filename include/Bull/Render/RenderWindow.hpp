#ifndef Bull_RenderWindow_hpp
#define Bull_RenderWindow_hpp

#include <Bull/Core/Time/Clock.hpp>
#include <Bull/Core/Time/Time.hpp>
#include <Bull/Core/System/Config.hpp>

#include <Bull/Render/RenderTarget.hpp>

#include <Bull/Window/Window.hpp>

namespace Bull
{
    class BULL_API RenderWindow : public RenderTarget, public Window
    {
    public:

        /*! \brief Default constructor
         *
         */
        RenderWindow();

        /*! \brief Constructor
         *
         * \param mode     The VideoMode
         * \param title    The title of the window
         * \param style    The window decorations
         * \param settings Settings to use to create the OpenGL context
         *
         */
        RenderWindow(const VideoMode& mode, const String& title, Uint32 style = Style::Default, const ContextSettings& settings = ContextSettings::Best);

        /*! \brief Open the window. If a window was already opened, its closed
         *
         * \param mode     The VideoMode
         * \param title    The title of the window
         * \param style    The window decorations
         * \param settings Settings to use to create the OpenGL context
         *
         * \return Return true if the window was open successfully
         *
         */
        bool open(const VideoMode& mode, const String& title, Uint32 style = Style::Default, const ContextSettings& settings = ContextSettings::Best);

        /*! \brief Display what has been rendered so far
         *
         */
        void display();

        /*! \brief Activate or deactivate the context
         *
         * \param active True to activate, false to deactivate the context
         *
         * \return Return true if the context's status changed successfully, false otherwise
         *
         */
        bool setActive(bool active = true) override;

        /*! \brief Set the maximum framerate of the RenderWindow
         *
         * \param limit The maximum
         *
         */
        void setFramerateLimit(unsigned int limit);

        /*! \brief Get the maximum framerate of the RenderWindow
         *
         * \param limit The maximum
         *
         */
        unsigned int getFramerateLimit() const;

        /*! \brief Activate or deactivate the vertical synchronization
         *
         * \param active True to activate, false to deactivate
         *
         * \return Return true if success, false otherwise
         *
         */
        void enableVsync(bool active);

        /*! \brief Get ContextSettings used to create the context
         *
         * \return Return the ContextSettings
         *
         */
        const ContextSettings& getSettings() const;

        /*! \brief Get the default viewport of the RenderTarget
         *
         * \return Return the viewport
         *
         */
        Viewport getDefaultViewport() const override;

    private:

        Time  m_frameDelay;
        Clock m_clock;
    };
}

#endif // Bull_RenderWindow_hpp
