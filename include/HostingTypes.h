#pragma once
#include <string>

class HostingTypes
{
public:
    static std::string getName(int value);

    static const int SIZE;
private:
    static const std::string NAMES[];

};