#include <Bull/Core/IO/OutStringStream.hpp>
#include <Bull/Core/Utility/StringUtils.hpp>

namespace Bull
{
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
}