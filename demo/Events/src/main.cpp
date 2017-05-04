#include <iostream>

#include <Bull/Core/Memory/String.hpp>
#include <Bull/Core/Pattern/Signal.hpp>

class Button
{
public:

    Button()
    {
        m_onPush.connect(this, &Button::ok);
    }

    void push()
    {
        m_onPush.emit();
    }

    void ok()
    {
        std::cout << "ok" << std::endl;
    }

private:

    Bull::Signal<> m_onPush;
};

int main(int argc, char* argv[])
{
    Button b;

    b.push();

    return 0;
}