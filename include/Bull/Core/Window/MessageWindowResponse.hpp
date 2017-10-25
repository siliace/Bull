#ifndef BULL_CORE_WINDOW_MESSAGEWINDOWRESPONSE_HPP
#define BULL_CORE_WINDOW_MESSAGEWINDOWRESPONSE_HPP

namespace Bull
{
    enum MessageWindowResponse
    {
        MessageWindowResponse_Ok,
        MessageWindowResponse_No,
        MessageWindowResponse_Yes,
        MessageWindowResponse_Abort,
        MessageWindowResponse_Retry,
        MessageWindowResponse_Cancel,
        MessageWindowResponse_Ignore,
        MessageWindowResponse_Continue,
        MessageWindowResponse_TryAgain,
    };
}

#endif // BULL_CORE_WINDOW_MESSAGEWINDOWRESPONSE_HPP
