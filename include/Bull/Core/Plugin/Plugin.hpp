#ifndef BULL_CORE_PLUGIN_PLUGIN_HPP
#define BULL_CORE_PLUGIN_PLUGIN_HPP

#include <functional>

#include <Bull/Core/Exception/InvalidParameter.hpp>
#include <Bull/Core/FileSystem/Path.hpp>
#include <Bull/Core/System/Library.hpp>

namespace Bull
{
    class BULL_CORE_API Plugin : public NonCopyable
    {
    public:

        /** \brief Constructor
         *
         * \param path       The path of the Plugin to load
         * \param entryPoint The name of the entry point function in the plugin
         *
         */
        Plugin(const Path& path, const std::string& entryPoint);

        /** \brief Constructor by movement semantic
         *
         * \param plugin The Plugin to move
         *
         */
        Plugin(Plugin&& plugin) noexcept = default;

        /** \brief Assignment operator by movement semantic
         *
         * \param plugin The Plugin to move
         *
         * \return This
         *
         */
        Plugin& operator=(Plugin&& plugin) noexcept = default;

        /** \brief Call a free function from a Plugin
         *
         * \tparam R    The return type of the function
         * \tparam Args Arguments types of the function
         *
         * \param function The name of the function to call
         * \param args     Arguments to send to the function to call
         *
         * \return The value returned by the plugin's function or nothing if R is void
         *
         * \throw InvalidParameter if the function does not exists in the plugin
         *
         */
        template <typename R, typename... Args>
        R call(const std::string& function, Args&& ... args) const
        {
            std::function<R(Args...)> func = m_library.getFunction<R(Args...)>(function);

            Expect(func, Throw(InvalidParameter, "No function " + function + " found in plugin"));

            if(std::is_void<R>::value)
            {
                func(std::forward<Args>(args)...);
            }
            else
            {
                return func(std::forward<Args>(args)...);
            }
        }

    private:

        Library m_library;
    };
}

#endif // BULL_CORE_PLUGIN_PLUGIN_HPP
