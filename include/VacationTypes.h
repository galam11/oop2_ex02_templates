#pragma once
#include <string>

class VacationTypes
{
public:
    static std::string getName(int value);
    static const int SIZE;
    static const int WEEKEND;
    static const int MID_WEEK;
private:
    static const std::string NAMES[];

};