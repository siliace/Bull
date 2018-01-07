#include <Bull/Core/Utility/Random.hpp>
#include <Bull/Core/Time/Date.hpp>

namespace Bull
{
    RandomGenerator::RandomGenerator() :
        RandomGenerator(Date::now().second.asMicroseconds())
    {
        /// Nothing
    }

    RandomGenerator::RandomGenerator(Uint64 seed) :
        m_generator(seed)
    {
        /// Nothing
    }

    template <>
    char RandomGenerator::number<char>(char min, char max)
    {
        std::uniform_int_distribution<char> distribution(min, max);
        return distribution(m_generator);
    }

    template <>
    unsigned char RandomGenerator::number<unsigned char>(unsigned char min, unsigned char max)
    {
        std::uniform_int_distribution<unsigned char> distribution(min, max);
        return distribution(m_generator);
    }

    template <>
    short RandomGenerator::number<short>(short min, short max)
    {
        std::uniform_int_distribution<short> distribution(min, max);
        return distribution(m_generator);
    }

    template <>
    unsigned short RandomGenerator::number<unsigned short>(unsigned short min, unsigned short max)
    {
        std::uniform_int_distribution<unsigned short> distribution(min, max);
        return distribution(m_generator);
    }

    template <>
    int RandomGenerator::number<int>(int min, int max)
    {
        std::uniform_int_distribution<int> distribution(min, max);
        return distribution(m_generator);
    }

    template <>
    unsigned int RandomGenerator::number<unsigned int>(unsigned int min, unsigned int max)
    {
        std::uniform_int_distribution<unsigned int> distribution(min, max);
        return distribution(m_generator);
    }

    template <>
    long RandomGenerator::number<long>(long min, long max)
    {
        std::uniform_int_distribution<long> distribution(min, max);
        return distribution(m_generator);
    }

    template <>
    unsigned long RandomGenerator::number<unsigned long>(unsigned long min, unsigned long max)
    {
        std::uniform_int_distribution<unsigned long> distribution(min, max);
        return distribution(m_generator);
    }

    template <>
    float RandomGenerator::number<float>(float min, float max)
    {
        std::uniform_real_distribution<float> distribution(min, max);
        return distribution(m_generator);
    }

    template <>
    double RandomGenerator::number<double>(double min, double max)
    {
        std::uniform_real_distribution<double> distribution(min, max);
        return distribution(m_generator);
    }

    String RandomGenerator::string(std::size_t length)
    {
        String str(length, String::NullByte);
        static String charset = "ABCEDFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

        for(std::size_t i = 0; i < str.getSize(); i++)
        {
            str[i] = number<char>();
        }

        return str;
    }
}
