#include <Bull/Core/Window/MessageWindow.hpp>
#include <Bull/Core/Window/MessageWindowImpl.hpp>
#include <Bull/Core/Window/WindowImpl.hpp>

namespace Bull
{
    MessageWindow::MessageWindow() :
        icon(MessageWindowIcon_None),
        buttons(MessageWindowButtons_Ok),
        defaultButton(MessageWindowDefaultButton_Button1)
    {
        /// Nothing
    }

    MessageWindow::MessageWindow(const String& message, const String& title, const Window* parent) :
        MessageWindow()
    {
        open(message, title, parent);
    }

    MessageWindowResponse MessageWindow::open(const String& message, const String& title, const Window* parent)
    {
        return prv::MessageWindowImpl::open(message, title, icon, buttons, defaultButton, (parent) ? parent->getImpl()->getSystemHandler() : nullptr);
    }
}