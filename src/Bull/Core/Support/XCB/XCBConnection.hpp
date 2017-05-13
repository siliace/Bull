#ifndef BULL_XCBCONNECTION_HPP
#define BULL_XCBCONNECTION_HPP

#include <xcb/xcb.h>

#include <Bull/Core/Pattern/Singleton.hpp>

namespace Bull
{
    namespace prv
    {
        class XCBConnection : public Singleton<XCBConnection>
        {
        public:

            XCBConnection();

            XCBConnection(const char* display, int* screen);

            ~XCBConnection();

            operator xcb_connection_t*();

        private:

            xcb_connection_t* m_connection;
        };
    }
}

#endif //BULL_XCBCONNECTION_HPP
