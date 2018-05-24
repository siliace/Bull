#ifndef BULL_CORE_EXCEPTION_EXPECT_HPP
#define BULL_CORE_EXCEPTION_EXPECT_HPP

#define Expect(BooleanExpression, ThrowStatement) \
if(!(BooleanExpression))                          \
{                                                 \
    ThrowStatement;                               \
}                                                 \

#endif // BULL_CORE_EXCEPTION_EXPECT_HPP
