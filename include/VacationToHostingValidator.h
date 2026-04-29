#pragma once
#include "Validator.h"
#include "Date.h"
#include <string>

class VacationToHostingValidator : Validator<Date>
{
public:
    bool validate(const Date& value) override;
};