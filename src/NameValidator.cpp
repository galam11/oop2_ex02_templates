#include "NameValidator.h"
#include "macros.h"

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
    return NAME_ERR_MSG;
}
