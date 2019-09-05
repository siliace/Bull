#include <Bull/Core/Window/MessageWindow.hpp>
#include <Bull/Core/Window/MessageWindowImpl.hpp>
#include <Bull/Core/Window/WindowImpl.hpp>

#if defined BULL_OS_WINDOWS
    #define NULL_WINDOW_HANDLER nullptr
#else
    #define NULL_WINDOW_HANDLER 0
#endif

namespace Bull
{
    MessageWindow::MessageWindow() :
            icon(MessageWindowIcon_None),
            buttons(MessageWindowButtons_Ok),
            defaultButton(MessageWindowDefaultButton_Button1)
    {
        /// Nothing
    }

    MessageWindow::MessageWindow(const std::string& message, const std::string& title, const Window* parent) :
            MessageWindow()
    {
        open(message, title, parent);
    }

    MessageWindowResponse MessageWindow::open(const std::string& message, const std::string& title, const Window* parent)
    {
        return prv::MessageWindowImpl::open(message, title,
                                            icon, buttons, defaultButton,
                                            (parent) ? parent->getImpl()->getSystemHandler() : NULL_WINDOW_HANDLER);
    }
}