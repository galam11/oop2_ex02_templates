#include "IdValidator.h"

bool IdValidator::validate(const uint32_t &value)
{
    if (value > 999999999 || value < 10000000)
    {
        return false;
    }

    uint32_t sum = 0;
    uint32_t temp = value;

    for (int i = 0; i < 9; ++i)
    {
        uint32_t digit = temp % 10;
        temp /= 10;

        uint32_t weight = (i % 2 == 0) ? 1 : 2;
        uint32_t res = digit * weight;

        sum += (res > 9) ? (res - 9) : res;
    }

    return (sum % 10 == 0);
}