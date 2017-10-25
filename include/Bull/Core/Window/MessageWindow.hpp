#ifndef BULL_CORE_WINDOW_MESSAGEWINDOW_HPP
#define BULL_CORE_WINDOW_MESSAGEWINDOW_HPP

#include <memory>

#include <Bull/Core/Memory/String.hpp>
#include <Bull/Core/Pattern/NonCopyable.hpp>
#include <Bull/Core/Window/MessageWindowButtons.hpp>
#include <Bull/Core/Window/MessageWindowDefaultButton.hpp>
#include <Bull/Core/Window/MessageWindowIcon.hpp>
#include <Bull/Core/Window/MessageWindowResponse.hpp>
#include <Bull/Core/Window/Window.hpp>

namespace Bull
{
    struct BULL_CORE_API MessageWindow : public NonCopyable
    {
        /*! \brief Default constructor
         *
         */
        MessageWindow();

        /*! \brief Constructor
         *
         * \param message The message to display in the MessageWindow
         * \param title   The title of the MessageWindow
         * \param parent  The parent Window
         *
         */
        MessageWindow(const String& message, const String& title, const Window* parent = nullptr);

        /*! \brief Open the MessageWindow
         *
         * \param message The message to display in the MessageWindow
         * \param title   The title of the MessageWindow
         * \param parent  The parent Window
         *
         * \return The user's response
         *
         */
        MessageWindowResponse open(const String& message, const String& title, const Window* parent = nullptr);

        MessageWindowIcon          icon;
        MessageWindowButtons       buttons;
        MessageWindowDefaultButton defaultButton;
    };
}

#endif //BULL_CORE_WINDOW_MESSAGEWINDOW_HPP
