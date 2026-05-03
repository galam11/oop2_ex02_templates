#pragma once
#include <string>

class HostingTypes
{
public:
    static std::string getName(int value);

    static const int SIZE;

    static const int BREAK_FAST;
    static const int HALF_BOARD;
    static const int FULL_BOARD;


private:
    static const std::string NAMES[];

};