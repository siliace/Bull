#include <iostream>

#include <Bull/Core/FileSystem/Directory.hpp>

using namespace Bull;

int main(int argc, char* argv[])
{
    Directory current(Path("/home/benjamin"));

    if(current.isOpen())
    {
        for(const Path& p : current.getContent(Directory::Directories))
        {
            std::cout << p.toString().getBuffer() << std::endl;
        }

        return 1;
    }

    return 0;
}