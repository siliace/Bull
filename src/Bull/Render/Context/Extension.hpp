#ifndef BULL_RENDER_CONTEXT_EXTENSION_HPP
#define BULL_RENDER_CONTEXT_EXTENSION_HPP

#include <functional>

#include <Bull/Core/Memory/String.hpp>

namespace Bull
{
    namespace prv
    {
        class Extension
        {
        public:

            /*! \brief Constructor
             *
             * \param name The name of the extension
             * \param loader The function to call to load the extension
             *
             */
            Extension(const String& name, const std::function<bool()>& loader);

            /*! \briel Load the extension
             *
             */
            void load();

            /*! \brief Tell whether the Extension is loaded
             *
             * \return True if the Extension is loaded
             *
             */
            bool isLoaded() const;

            /*! \brief Get the name of the Extension
             *
             * \return The name of the Extension
             *
             */
            const String& getName() const;

        private:

            String                m_name;
            std::function<bool()> m_loader;
            bool                  m_loaded;
        };
    }
}

#endif // BULL_RENDER_CONTEXT_EXTENSION_HPP
