#ifndef Bull_RenderWindow_hpp
#define Bull_RenderWindow_hpp

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
        RenderWindow() = default;

        /*! \brief Constructor
         *
         * \param mode     The VideoMode
         * \param title    The title of the window
         * \param style    The window decorations
         * \param settings Settings to use to create the OpenGL context
         *
         */
        RenderWindow(const VideoMode& mode, const String& title, Uint32 style = Style::Default, const ContextSettings& settings = ContextSettings());

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
        bool open(const VideoMode& mode, const String& title, Uint32 style = Style::Default, const ContextSettings& settings = ContextSettings());

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

        /*! \brief Get ContextSettings used to create the context
         *
         * \return Return the ContextSettings
         *
         */
        const ContextSettings& getSettings() const;
    };
}

#endif // Bull_RenderWindow_hpp
