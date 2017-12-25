#ifndef BULL_CORE_SUPPORT_XLIB_ERRORHANDLER_HPP
#define BULL_CORE_SUPPORT_XLIB_ERRORHANDLER_HPP

#include <Bull/Core/Pattern/NonCopyable.hpp>
#include <Bull/Core/Support/Xlib/Display.hpp>
#include <Bull/Core/Concurrency/Lock.hpp>


namespace Bull
{
    namespace prv
    {
        class ErrorHandler : public NonCopyable
        {
        public:

            /*! \brief Handle Xlib errors
             *
             * \param display The connection where the error was sent
             * \param error   The error
             *
             * \return Return always 0
             *
             */
            static int handle(XDisplay* display, XErrorEvent* error);

        private:

            static Mutex s_mutex;
            static bool  s_errorOccurred;

        public:

            /*! \brief Default constructor
             *
             */
            ErrorHandler();

            /*! \brief Destructor
             *
             */
            ~ErrorHandler();

            /*! \brief Tell whether an error occurred
             *
             * \return True if an error occurred during the object life time
             *
             */
            bool errorOccurred() const;

            /*! \brief Reset the error
             *
             */
            void resetError();

            /*! \brief Start to listen errors to handle
             *
             */
            void listen();

            /*! \brief Stop to listen errors
             *
             */
            void close();

        private:

            Lock          m_lock;
            bool          m_isBound;
            XErrorHandler m_previousHandler;
        };
    }
}

#endif // BULL_CORE_SUPPORT_XLIB_ERRORHANDLER_HPP

