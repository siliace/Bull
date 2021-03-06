#ifndef BULL_RENDER_TARGET_RENDERWINDOW_HPP
#define BULL_RENDER_TARGET_RENDERWINDOW_HPP

#include <Bull/Core/Time/Clock.hpp>
#include <Bull/Core/Time/Duration.hpp>
#include <Bull/Core/Window/Window.hpp>
#include <Bull/Core/Window/VideoMode.hpp>

#include <Bull/Render/Export.hpp>
#include <Bull/Render/Target/RenderTarget.hpp>

namespace Bull
{
    class BULL_RENDER_API RenderWindow : public Window, public RenderTarget
    {
    public:

        /** \brief Default constructor
         *
         */
        RenderWindow() = default;

        /** \brief Constructor
         *
         * \param mode     The VideoMode
         * \param title    The title of the window
         * \param WindowStyle    The window decorations
         * \param settings Settings to use to create the OpenGL context
         *
         */
        RenderWindow(const VideoMode& mode, const std::string& title, Uint32 WindowStyle = WindowStyle_Default, const ContextSettings& settings = ContextSettings::Best);

        /** \brief Constructor by movement
         *
         * \param move The RenderWindow to move
         *
         */
        RenderWindow(RenderWindow&& move) noexcept = default;

        /** \brief Basic assignment operator by movement
         *
         * \param move The RenderWindow to move
         *
         * \return This
         *
         */
        RenderWindow& operator=(RenderWindow&& move) noexcept = default;

        /** \brief Create the window. If the Window was already opened, its closed
         *
         * \param mode     The VideoMode
         * \param title    The title of the window
         * \param style    The window decorations
         * \param settings Settings to use to create the OpenGL context
         *
         */
        void create(const VideoMode& mode, const std::string& title, Uint32 style = WindowStyle_Default, const ContextSettings& settings = ContextSettings::Best);

        /** \brief Display what has been rendered so far
         *
         */
        void display() override;

        /** \brief Set the maximum framerate of the RenderWindow
         *
         * \param limit The maximum
         *
         */
        void setFramerateLimit(unsigned int limit);

        /** \brief Get the maximum framerate of the RenderWindow
         *
         * \return limit The maximum
         *
         */
        unsigned int getFramerateLimit() const;

        /** \brief Activate or deactivate the vertical synchronization
         *
         * \param active True to activate, false to deactivate
         *
         */
        void enableVsync(bool active = true);

        /** \brief Get the default viewport of the RenderTarget
         *
         * \return Return the viewport
         *
         */
        Viewport getDefaultViewport() const override;

    protected:

        /** \brief Function called when the Window is opened
         *
         */
        void onOpen() override;

        /** \brief Function called when the Window is resized
         *
         */
        void onResize() override;

        /** \brief Function called when the Window is closed
         *
         */
        void onClose() override;

    private:

        Clock m_clock;
        Duration m_frameDelay;
    };
}

#endif // BULL_RENDER_TARGET_RENDERWINDOW_HPP
