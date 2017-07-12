#include <iostream>

#include <Bull/Core/Memory/String.hpp>
#include <Bull/Core/Pattern/Signal.hpp>

using namespace Bull;

class Button
{
public:

    Button(const String& message) :
        m_message(message)
    {
        /// Nothing
    }

    void clic()
    {
        OnClic(m_message);
    }

    Signal<const String&> OnClic;

private:

    String m_message;
};

class Text
{
public:

    Text()
    {
        Update.reset(this, &Text::display);
    }

    void display(const String& message)
    {
        std::cout << message.getBuffer() << std::endl;
    }

    Signal<const String&>::Slot Update;
};

using namespace Bull;

int main()
{
    Text t;
    Button b("Salut les cons");
    Button b2("Salut les PD");
    Button b3("Bouffez moi l'cul");

    b.OnClic.bind(t.Update);
    b2.OnClic.bind(t.Update);
    b3.OnClic.bind(t.Update);

    b.clic();
    b2.clic();
    b3.clic();

    return 0;
}