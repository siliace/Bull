#include <Bull/Core/IO/OutStringStream.hpp>
#include <Bull/Core/Utility/StringUtils.hpp>
#include <Bull/Core/Utility/Random.hpp>

namespace Bull
{
    namespace
    {
        static String charset = "ABCEDFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
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

    String StringUtils::random(std::size_t length)
    {
        String str;
        RandomGenerator random;

        str.setSize(length);

        for(std::size_t i = 0; i < str.getSize(); i++)
        {
            str[i] = charset[random.number<unsigned int>(0, charset.getSize() - 1)];
        }

        return str;
    }
}