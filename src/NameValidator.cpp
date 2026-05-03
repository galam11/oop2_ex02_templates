#include "NameValidator.h"

#include <iostream>

bool NameValidator::validate(const std::string &value)
{

    if (value.length() < 3)
        return false;

    for (char c : value)
    {
        if (std::isdigit(c))
            return false;
    }

    return true;
}

std::string NameValidator::getErrMessage()
{
    return "\tError: Name must be at length >= 3 and must not contain numbers.";
}
