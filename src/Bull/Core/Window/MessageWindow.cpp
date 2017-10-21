#include <Bull/Core/Window/MessageWindow.hpp>
#include <Bull/Core/Window/MessageWindowImpl.hpp>
#include <Bull/Core/Window/WindowImpl.hpp>

namespace Bull
{
    MessageWindow::MessageWindow() :
        icon(Icon::Icon_None),
        buttons(Buttons::Buttons_Ok),
        defaultButton(DefaultButton::DefaultButton_Button1)
    {
        /// Nothing
    }

    MessageWindow::MessageWindow(const String& message, const String& title, const Window* parent) :
        MessageWindow()
    {
        open(message, title, parent);
    }

    MessageWindow::Response MessageWindow::open(const String& message, const String& title, const Window* parent)
    {
        return prv::MessageWindowImpl::open(message, title, icon, buttons, defaultButton, (parent) ? parent->getImpl()->getSystemHandler() : nullptr);
    }
}