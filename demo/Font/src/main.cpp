#include <Bull/Utility/Font/Font.hpp>

using namespace Bull;

int main(int argc, char* argv[])
{
    Font f;

    if(!f.loadFromPath(Path("DK Full Blast.otf")))
    {
        return 1;
    }

    return 0;
}