#ifndef BULL_CORE_PROCESS_COMMANDLINE_HPP
#define BULL_CORE_PROCESS_COMMANDLINE_HPP

#include <vector>

#include <Bull/Core/Configuration/OS.hpp>
#include <Bull/Core/Memory/String.hpp>

namespace Bull
{
    class BULL_CORE_API CommandLine
    {
    public:

        #if defined BULL_OS_WINDOWS
            static constexpr char OptionChar = '/';
        #else
            static constexpr char OptionChar = '-';
        #endif

    public:

        /*! \brief Default constructor
         *
         */
        CommandLine() = default;

        /*! \brief Constructor
         *
         * \param program To program to execute
         *
         */
        explicit CommandLine(const String& program);

        /*! \brief Set an option in the CommandLine
         *
         * \param value  The value of the option
         * \param prefix The prefix of the option
         *
         * \return This
         *
         */
        CommandLine& withOption(const String& value, const String& prefix = String(OptionChar));

        /*! \brief Convert the CommandLine to a String
         *
         * \return The CommandLine as a String
         *
         */
        String toString() const;

        /*! \brief Get the program of the CommandLine
         *
         * \return The program
         *
         */
        const String& getProgram() const;

        /*! \brief Get the options of the CommandLine
         *
         * \param withProgram True to add the program at the begining of the option vector
         *
         * \return Options of the CommandLine
         *
         */
        std::vector<String> getOptions(bool withProgram = false) const;

    private:

        struct Option
        {
            String prefix;
            String value;
        };

        String              m_prefix;
        String              m_program;
        std::vector<Option> m_options;
    };
}

#endif // BULL_CORE_PROCESS_COMMANDLINE_HPP
