#include "HostingTypes.h"

const std::string HostingTypes::NAMES[] = { "", "Breakfast", "Half board", "Full board" };
const int HostingTypes::SIZE = 4;

std::string HostingTypes::getName(int value)
{
    if (value >= 1 && value < SIZE)
    {
        return NAMES[value];
    }
    return "";
}