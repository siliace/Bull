#include <iostream>

#include <Bull/Core/System/Clipboard.hpp>

int main(int argc, char *argv[])
{
    Bull::Clipboard::setContent("Hello world");

    std::cout << "Clipboard contains now : " << Bull::Clipboard::getContent().getBuffer() << std::endl;

    return 0;
}