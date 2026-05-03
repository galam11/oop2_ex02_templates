#include "HostingTypes.h"

const std::string HostingTypes::NAMES[] = { "", "Breakfast", "Half board", "Full board" };

const int HostingTypes::SIZE = 4;

const int HostingTypes::BREAK_FAST = 1;
const int HostingTypes::HALF_BOARD = 2;
const int HostingTypes::FULL_BOARD = 3;

std::string HostingTypes::getName(int value)
{
    if (value >= 1 && value < SIZE)
    {
        return NAMES[value];
    }
    return "";
}