#include <Bull/Core/IO/OutStringStream.hpp>
#include <Bull/Core/Utility/Random.hpp>
#include <Bull/Core/Utility/StringUtils.hpp>

namespace Bull
{
    String StringUtils::boolean(bool boolean)
    {
        return boolean ? "true" : "false";
    }

    String StringUtils::repeat(const Bull::String& string, std::size_t count)
    {
        return count >= 2 ? string + repeat(string, count - 1) : string;
    }

    String StringUtils::ofSize(std::size_t size)
    {
        String string;
        string.setSize(size);

        return string;
    }
}