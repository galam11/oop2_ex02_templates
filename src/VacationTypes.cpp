#include "VacationTypes.h"

const std::string VacationTypes::NAMES[] = { "", "Weekend", "Mid-week" };

const int VacationTypes::SIZE = 3;

const int VacationTypes::WEEKEND = 1;
const int VacationTypes::MID_WEEK = 2;

std::string VacationTypes::getName(int value)
{
    if (value >= 1 && value < SIZE)
    {
        return NAMES[value];
    }
    return "";
}