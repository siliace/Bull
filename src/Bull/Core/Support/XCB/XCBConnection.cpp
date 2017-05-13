#include <Bull/Core/Support/XCB/XCBConnection.hpp>

namespace Bull
{
    namespace prv
    {
        XCBConnection::XCBConnection() :
            XCBConnection(nullptr, nullptr)
        {
            /// Nothing
        }

        XCBConnection::XCBConnection(const char* display, int* screen) :
            m_connection(xcb_connect(display, screen))
        {
            if(!m_connection)
            {
                throw std::runtime_error("Failed to create XCBConnection");
            }
        }

        XCBConnection::~XCBConnection()
        {
            xcb_disconnect(m_connection);
        }

        XCBConnection::operator xcb_connection_t*()
        {
            return m_connection;
        }
    }
}