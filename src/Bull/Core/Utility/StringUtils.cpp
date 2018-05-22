#include <Bull/Core/IO/OutStringStream.hpp>
#include <Bull/Core/Utility/Random.hpp>
#include <Bull/Core/Utility/StringUtils.hpp>
#include <Bull/Core/Utility/StringParameter.hpp>

namespace Bull
{
    namespace
    {
        constexpr char spaceCharset[] = " ";

        constexpr char numberCharset[] = "0123456789";

        constexpr char uppercaseCharset[] = "ABCEDFGHIJKLMNOPQRSTUVWXYZ";

        constexpr char lowercaseCharset[] = "abcdefghijklmnopqrstuvwxyz";

        constexpr char specialCharsCharset[] = "!\"#$%&'()*+,-./:;<=>?[\\]^_`{|}~";
    }

    String StringUtils::boolean(bool boolean)
    {
        return boolean ? "true" : "false";
    }

    String StringUtils::join(const ArrayList<String>& strings, const String& glue)
    {
        OutStringStream oss;
        std::size_t size = strings.getSize();

        for(std::size_t i = 0; i < size; i++)
        {
            oss.write(strings[i]);

            if(i < size - 1)
            {
                oss.write(glue);
            }
        }

        return oss.toString();
    }

    String StringUtils::random(std::size_t length, Uint32 flags)
    {
        String str;
        String charset;
        RandomGenerator random;

        str.setSize(length);

        if(flags & StringParameter_Space) charset += spaceCharset;
        if(flags & StringParameter_Numbers) charset += numberCharset;
        if(flags & StringParameter_Lowercase) charset += lowercaseCharset;
        if(flags & StringParameter_Uppercase) charset += uppercaseCharset;
        if(flags & StringParameter_SpecialChars) charset += specialCharsCharset;

        for(std::size_t i = 0; i < str.getSize(); i++)
        {
            str[i] = charset.at(random.number<int>(0, charset.getSize() - 1));
        }

        return str;
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