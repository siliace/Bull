#ifndef BULL_CORE_SIGNALS_SCOPEDCONNECTION_HPP
#define BULL_CORE_SIGNALS_SCOPEDCONNECTION_HPP

#include <Bull/Core/Signals/Connection.hpp>

namespace Bull
{
    template <typename T>
    class BULL_CORE_API ScopedConnection
    {
    public:

        ScopedConnection(Connection& connection) :
            m_connection(connection)
        {
            /// Nothing
        }

        ~ScopedConnection()
        {
            m_connection.disconnect();
        }

    private:

        Connection& m_connection;
    }
}

#endif // BULL_CORE_SIGNALS_SCOPEDCONNECTION_HPP
