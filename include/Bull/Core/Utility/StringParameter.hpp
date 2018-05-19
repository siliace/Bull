#ifndef BULL_CORE_UTILITY_STRINGPARAMETER_HPP
#define BULL_CORE_UTILITY_STRINGPARAMETER_HPP

namespace Bull
{
    enum StringParameter
    {
        StringParameter_Space        = 0x1,
        StringParameter_Numbers      = 0x2,
        StringParameter_Lowercase    = 0x4,
        StringParameter_Uppercase    = 0x8,
        StringParameter_SpecialChars = 0x16,
        StringParameter_All = StringParameter_Space | StringParameter_Numbers | StringParameter_Lowercase | StringParameter_Uppercase | StringParameter_SpecialChars,
    };
}

#endif // BULL_CORE_UTILITY_STRINGPARAMETER_HPP
