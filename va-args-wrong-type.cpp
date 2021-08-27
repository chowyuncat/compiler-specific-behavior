#include <stdint.h>
#include <stdio.h>

enum class ChannelStatus : uint64_t
{
    None,
    Good
};


int main()
{
    ChannelStatus channelStatus = ChannelStatus::Good;

    printf("enum class 0%x\n", static_cast<uint64_t>(channelStatus));

    return 0;
}