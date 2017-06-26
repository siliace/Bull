#include <Bull/Network/Win32/WSA.hpp>

namespace Bull
{
    namespace prv
    {
        namespace
        {
            WSA wsa;
        }

        WSA::WSA()
        {
            WSAStartup(MAKEWORD(2, 0), &m_data);
        }

        WSA::~WSA()
        {
            WSACleanup();
        }
    }
}